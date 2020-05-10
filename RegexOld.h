#ifndef MCL_REGULAR_EXPRESSIONS_H
#define MCL_REGULAR_EXPRESSIONS_H


#include <string>


typedef unsigned short int usint;
//Match a real number: -?[0-9]+(\.[0-9]+)?
//Parsing:  (char)-, (count)?

//.*a

//[]a]

//abc|def

//abc def ghi
//abcabcdefabc

//[a+]

//aba.cc.ba




//Charsets:  [0-9] = {0,1,2,3,4,5,6,7,8,9}
//Count:  <default> = {1};  ? = {0,1}; + = {1,};  * = {0,};  {n,m} = {n,m};



struct Regex
{
private:
  std::string CharSet;
  bool NotIn; //if CharSet is {'a','b','c'}, but NotIn == 1, then this is equivalent to [^abc]
  //elem(char c, CharSet) != NotIn;
  std::vector<Regex*> LoopStart; // /([ab]c)+d/
  int LoopMin;
  int LoopMax; //-1 for max of infinity

  std::vector<Regex*> Children;

  std::vector<Regex*> Rejoin;  //If the tree splits, it may rejoin.  For example, /c(at|rate)s/ splits after 'c', but rejoins at 's'

  bool Valid;

  Regex(std::string, std::vector<Regex*>, std::vector<Regex*>);

public:
  Regex(std::string);
  ~Regex();

  static bool elem(char c, std::string str);
}


Regex::Regex(std::string Pattern)
{
  CharSet = "";
  NotIn = 0;
  Min = 1;
  Max = 1;

  Children.resize(0);

  Rejoin = 0;

  Valid = 1;



  enum State {
    Default,
    SqrBrackets,
    CurBrackets,
    ParBrackets
  };

  auto Replacer = [](char Char) -> std::string {
    switch (Char)
    {
    case '?':
      return "{,1}";
    case '+':
      return "{1,}";
    case '*':
      return "{0,}";
    default:
      return std::string(1, Char);
    }
  };

  std::vector<State> s = { Default };
  std::vector<std::string> Splits = { "" };
  //First pass;  Mostly looking for splits
  bool BackSlash = 0;
  for (int i = 0; i < Pattern.length(); i++)
  {
    switch (s.back())
    {
    case Default:
      if (BackSlash)
      {
        if (!elem(Pattern[i], "?+*"))
          Splits.back() += '\\';
        Splits.back() += Pattern[i];
        BackSlash = 0;
      }
      else if (Pattern[i] == '|')
      {
        Splits.push_back("");
      }
      else
      {
        Pattern.replace(i, 1, Replacer(Pattern[i]));
        switch (Pattern[i])
        {
        case '\\':
          BackSlash = 1;
          break;

        case '[':
          s.push_back(SqrBrackets);
          Splits.back() += '[';
          break;

        case '{':
          s.push_back(CurBrackets);
          Splits.back() += '{';
          break;

        case '(':
          s.push_back(ParBrackets);
          Splits.back() += '(';
          break;

        default:
          Splits.back() += Pattern[i];
          break;
        }
      }
      break;

    case SqrBrackets:
      Splits.back() += Pattern[i];
      if (Pattern[i] == '^')
        ++i;
      int j;
      for (j = i; j < Pattern.length(); j++)
      {
        Splits.back() += Pattern[j];
        if (j - i > 1 && Pattern[j] == ']')
          s.pop_back();
      }
      i = j;
      break;

    case CurBrackets:
      bool InNumber = 0;
      int NumCount = 0;
      int CommaCount = 0;
      for ( ; i < Pattern.length(); i++)
      {
        if (Pattern[i] == ' ') { }
        else if (elem(Pattern[i], "0123456789"))
        {
          Splits.back() += Pattern[i];
          if (!InNumber)
          {
            ++NumCount;
            InNumber = 1;
          }
        }
        else if (Pattern[i] == ',')
        {
          ++CommaCount;
        }
        else
        {
          Valid = 0;
          return;
        }
      }
      break;

    case ParBrackets:

      break;
    }
  }
  int i = 0;
  for ( ; i < Pattern.length() - 1; i++)
  {
    switch (s.back())
    {
    case Default:
      if (BackSlash)
      {
        CharSet += Pattern[i];
        Pattern.replace(i+1, 1, Replacer(Pattern[i+1]));
      }
      else
      {
        switch (Pattern[i])
        {
        case '[':
          s.push_back(SqrBrackets)
        }
      }
      break;

    case SqrBrackets:

      break;

    case CurBrackets:

      break;

    case ParBrackets:

      break;
    }


  }
}

bool Regex::elem(char c, std::string str)
{
  for (char k : str)
  {
    if (k == c)
      return 1;
  }
  return 0;
}


#endif
