#ifndef MCL_REGULAR_EXPRESSIONS
#define MCL_REGULAR_EXPRESSIONS

#include <string>
#include <vector>
#include <MyHeaders/TypeMath.h>
#include <MyHeaders/strmanip.h>

typedef short int sint;


//std::string Tabs = "";


unsigned int ValidateRegex(std::string r)
{
  if (r.front() == '{' || r.front() == '*' || r.front() == '+' || r.front() == '?')
    return 0;
  unsigned int ParenCount = 0;
  bool Comma;
  std::string sNum0;
  unsigned int Num0, Num1;
  bool Num1Set;
  for (unsigned int i = 1; i < r.length(); i++)
  {
    switch (r[i])
    {
      case '(':
        ++ParenCount;
        break;
      case ')':
        --ParenCount;
        break;
      case '{':
        Comma = 0;
        sNum0 = "";
        Num0 = 0;
        Num1 = 0;
        Num1Set = 0;
        if (r[i+1] == '}')
          return i+1;
        while (r[++i] != '}')
        {
          if (i > r.length())
          {
            return i-1;
          }
          else if ('0' <= r[i] && r[i] <= '9')
          {
            if (Comma)
            {
              (Num1 *= 10) += r[i] - '0';
              Num1Set = 1;
            }
            else
            {
              (Num0 *= 10) += r[i] - '0';
              sNum0 += r[i];
            }
          }
          else if (r[i] == ',' && !Comma)
            Comma = 1;
          else if (r[i] == ' ')
            continue;
          else
            return i;
        }

        /*if (!Comma)
        {
          r.insert(i - 1, "," + sNum0);
          i += sNum0.length();
        }*/

        if (Num0 > Num1 && !Num1Set)
          return i;

        if (r.length() > i+1 && (r[i+1] == '*' || r[i+1] == '+' || r[i+1] == '?'))
          return i+1;
        break;
      case '[':
        if (i+2 > r.length())
          return i+1;
        if (r[++i] == '^')
          ++i;
        while (r[++i] != ']') { }
        break;
      case '*':
        //r.replace(i, 1, "{0,1}");
        //i += 4;
        if (r.length() > i+1 && (r[i+1] == '{' || r[i+1] == '+' || r[i+1] == '?'))
          return i+1;
        break;
      case '+':
        //r.replace(i, 1, "{1,1}");
        //i += 4;
        if (r.length() > i+1 && (r[i+1] == '*' || r[i+1] == '{' || r[i+1] == '?'))
          return i+1;
        break;
      case '?':
        //r.replace(i, 1, "{0,1}");
        //i += 4;
        if (r.length() > i+1 && (r[i+1] == '*' || r[i+1] == '+' || r[i+1] == '{'))
          return i+1;
        break;
      case '\\':
        ++i;
        /*if (r.length() > i+1 && !(r[i+1] == '?' || r[i+1] == '*' || r[i+1] == '+' || r[i+1] == '{'))
        {
          r.insert(i+1, "{1,1}");
          i += 5;
        }*/
        break;
      /*default:
        if (r.length() > i+1 && !(r[i+1] == '?' || r[i+1] == '*' || r[i+1] == '+' || r[i+1] == '{'))
        {
          r.insert(i+1, "{1,1}");
          i += 5;
        }*/
    }
  }

  if (ParenCount != 0)
    return r.length()-1;
  return r.length();
}
int RegexMatch(std::string r, std::string s, bool CheckValidity = 1)
{
  if (CheckValidity)
  {
    if (ValidateRegex(r) < r.length())
      return -1;
  }

  //Tabs += "->";

  //print << Tabs << "(\"" << NVCtoBslRep(r) << "\", \"" << NVCtoBslRep(s) << "\"): " << "Checking \"" << NVCtoBslRep(s) << "\" against \"" << NVCtoBslRep(r) << "\"\n\n";

  if (r == "")
  {
    //Tabs.erase(Tabs.length()-2);
    return 0;
  }

  std::string SubRegex = "";
  unsigned int ParenCount = 0;
  int Min, Max;
  unsigned int ir = 0, is = 0;
  while(ir < r.length())
  {
    switch (r[ir++])
    {
      case '(':
        ParenCount = 1;
        SubRegex = "";
        while (ParenCount != 0)
        {
          SubRegex += r[ir];
          switch (r[ir++])
          {
            case '(':
              ++ParenCount;
              break;
            case ')':
              --ParenCount;
              break;
            case '\\':
              SubRegex += r[ir++];
              break;
            case '[':
              //print << Tabs << "..Encountered open square bracket...";
              SubRegex += r[ir];
              if (r[ir++] == '^')
                SubRegex += r[ir++];
              while (r[ir] != ']')
                SubRegex += r[ir++];
              ++ir;
              SubRegex += ']';
              //print << "\"" << SubRegex << "\"\n\n";
              break;
          }
        }
        //print << Tabs << "..\"" << SubRegex << "\"\n\n";
        SubRegex.erase(SubRegex.end()-1);
        //print << Tabs << "..\"" << SubRegex << "\"\n\n";
        Min = 1;
        Max = 1;
        if (ir < r.length())
        {
          bool Comma = 0;
          switch (r[ir])
          {
            case '*':
              Min = 0;
              Max = -1;
              break;
            case '+':
              Min = 1;
              Max = -1;
              break;
            case '?':
              Min = 0;
              Max = 1;
              break;
            case '{':
              Min = 0;
              Max = -1;
              while (r[++ir] != '}')
              {
                switch (r[ir])
                {
                  case ' ':
                    break;
                  case ',':
                    Comma = 1;
                    break;
                  default:
                    if (Comma)
                    {
                      if (Max == -1)
                        Max = r[ir] - '0';
                      else
                        (Max *= 10) += r[ir] - '0';
                    }
                    else
                      (Min *= 10) += r[ir] - '0';
                }
              }
              if (!Comma)
                Max = Min;
              break;
            default:
              --ir;
          }
          ++ir;
        }
        for (unsigned int c = 0; c < Min; c++)
        {
          int j = RegexMatch(SubRegex, s.substr(is), 0);
          if (j)
          {
            //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": \"" << NVCtoBslRep(s).substr(is, j) << "\" matches against \"" << SubRegex << "\"\n\n";
            is += j;
          }
          else
          {
            //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": \"" << NVCtoBslRep(s.substr(is)) << "\" does not match against \"" << SubRegex << "\"\n\n";
            //Tabs.erase(Tabs.length()-2);
            return 0;
          }
        }
        for (unsigned int c = 0; c != Max - Min; c++)
        {
          int j = RegexMatch(r.substr(ir), s.substr(is), 0);
          if (j != 0)
          {
            //Tabs.erase(Tabs.length()-2);
            return is + j;
          }
          else
          {
            j = RegexMatch(SubRegex, s.substr(is), 0);
            if (j)
            {
              //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << Min << "+" << c << ": \"" << NVCtoBslRep(s.substr(is, j)) << "\" matches against \"" << SubRegex << "\"\n\n";
              is += j;
            }
            else
            {
              //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << Min << "+" << c << ": \"" << NVCtoBslRep(s.substr(is)) << "\" does not match against \"" << SubRegex << "\"\n\n";
              break;
            }
          }
        }
        break;
      case '[':
      {
        std::string CharSet = "";
        bool Not = 0;
        if (r[ir] == '^')
        {
          Not = 1;
          ++ir;
        }
        CharSet += r[ir];
        while (r[++ir] != ']')
        {
          if (r[ir] == '-' && r[ir+1] != ']')
          {
            if (r[ir-1] < r[ir+1])
            {
              for (char k = r[ir-1]+1; k < r[ir+1]; k++)
                CharSet += k;
            }
          }
          else
            CharSet += r[ir];
        }
        Min = 1;
        Max = 1;
        if (++ir < r.length())
        {
          bool Comma = 0;
          switch (r[ir])
          {
            case '*':
              Min = 0;
              Max = -1;
              break;
            case '+':
              Min = 1;
              Max = -1;
              break;
            case '?':
              Min = 0;
              Max = 1;
              break;
            case '{':
              Min = 0;
              Max = -1;
              while (r[++ir] != '}')
              {
                switch (r[ir])
                {
                  case ' ':
                    break;
                  case ',':
                    Comma = 1;
                    break;
                  default:
                    if (Comma)
                    {
                      if (Max == -1)
                        Max = r[ir] - '0';
                      else
                        (Max *= 10) += r[ir] - '0';
                    }
                    else
                      (Min *= 10) += r[ir] - '0';
                }
              }
              if (!Comma)
                Max = Min;
              break;
            default:
              --ir;
          }
          ++ir;
        }
        for (unsigned int c = 0; c < Min; c++)
        {
          if (is >= s.length())
          {
            //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": (Empty String) does not match against [" << (Not ? "^" : "" ) << CharSet << "]\n\n";
            //Tabs.erase(Tabs.length()-2);
            return 0;
          }
          bool in = 0;
          for (char ch : CharSet)
          {
            if (ch == s[is])
            {
              in = 1;
              break;
            }
          }
          if (in != Not)
          {
            //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": \"" << NVCtoBslRep(s[is]) << "\" matches against [" << (Not ? "^" : "" ) << CharSet << "]\n\n";
            ++is;
          }
          else
          {
            //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": \"" << NVCtoBslRep(s[is]) << "\" does not match against [" << (Not ? "^" : "" ) << CharSet << "]\n\n";
            //Tabs.erase(Tabs.length()-2);
            return 0;
          }
        }
        for (unsigned int c = 0; c != Max - Min; c++)
        {
          if (is >= s.length())
          {
            //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": (Empty String) does not match against [" << (Not ? "^" : "" ) << CharSet << "]\n\n";
            break;
          }
          int j = RegexMatch(r.substr(ir), s.substr(is), 0);
          if (j != 0)
          {
            //Tabs.erase(Tabs.length()-2);
            return is + j;
          }
          else
          {
            bool in = 0;
            for (char ch : CharSet)
            {
              if (ch == s[is])
              {
                in = 1;
                break;
              }
            }
            if (in != Not)
            {
              //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << Min << "+" << c << ": \"" << NVCtoBslRep(s[is]) << "\" matches against [" << (Not ? "^" : "" ) << CharSet << "]\n\n";
              ++is;
            }
            else
            {
              //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": \"" << NVCtoBslRep(s[is]) << "\" does not match against [" << (Not ? "^" : "" ) << CharSet << "]\n\n";
              break;
            }
          }
        }
      }
      break;
      case '.':
      {
        Min = 1;
        Max = 1;
        if (ir < r.length())
        {
          bool Comma = 0;
          switch (r[ir])
          {
            case '*':
              Min = 0;
              Max = -1;
              break;
            case '+':
              Min = 1;
              Max = -1;
              break;
            case '?':
              Min = 0;
              Max = 1;
              break;
            case '{':
              Min = 0;
              Max = -1;
              while (r[++ir] != '}')
              {
                switch (r[ir])
                {
                  case ' ':
                  break;
                  case ',':
                    Comma = 1;
                  break;
                  default:
                    if (Comma)
                    {
                      if (Max == -1)
                        Max = r[ir] - '0';
                      else
                        (Max *= 10) += r[ir] - '0';
                    }
                    else
                      (Min *= 10) += r[ir] - '0';
                }
              }
              if (!Comma)
                Max = Min;
            break;
            default:
              --ir;
          }
          ++ir;
        }
        for (unsigned int c = 0; c < Min; c++)
        {
          if (is >= s.length())
          {
            //print << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": (Empty String) does not match against \".\"\n\n";
            return 0;
          }
          else
          {
            //print << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": \"" << s.substr(is) << "\" matches against \".\"\n\n";
            ++is;
          }
        }
        for (unsigned int c = 0; c != Max - Min; c++)
        {
          if (is >= s.length())
          {
            //print << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << Min << "+" << c << ": (Empty String) does not match against \".\"\n\n";
            break;
          }
          int j = RegexMatch(r.substr(ir), s.substr(is), 0);
          if (j != 0)
          {
            //Tabs.erase(Tabs.length()-2);
            return is + j;
          }
          else
          {
            //print << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << Min << "+" << c << ": \"" << s.substr(is) << "\" matches against \".\"\n\n";
            ++is;
          }
        }
      }
      break;
      case '|':
        //Tabs.erase(Tabs.length()-2);
        return max(RegexMatch(r.substr(0, ir-1), s, 0), RegexMatch(r.substr(ir), s, 0));
      break;
      case '\\':
        ++ir;
      default:
      {
        char ch = r[ir-1];
        Min = 1;
        Max = 1;
        if (ir < r.length())
        {
          bool Comma = 0;
          switch (r[ir])
          {
            case '*':
              Min = 0;
              Max = -1;
              break;
            case '+':
              Min = 1;
              Max = -1;
              break;
            case '?':
              Min = 0;
              Max = 1;
              break;
            case '{':
              Min = 0;
              Max = -1;
              while (r[++ir] != '}')
              {
                switch (r[ir])
                {
                  case ' ':
                    break;
                  case ',':
                    Comma = 1;
                    break;
                  default:
                    if (Comma)
                    {
                      if (Max == -1)
                        Max = r[ir] - '0';
                      else
                        (Max *= 10) += r[ir] - '0';
                    }
                    else
                      (Min *= 10) += r[ir] - '0';
                }
              }
              if (!Comma)
                Max = Min;
              break;
            default:
              --ir;
          }
          ++ir;
        }
        for (unsigned int c = 0; c < Min; c++)
        {
          if (is >= s.length())
          {
            //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": (Empty String) does not match against \"" << ch << "\"\n\n";
            //Tabs.erase(Tabs.length()-2);
            return 0;
          }

          if (s[is] == ch)
          {
            //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": \"" << NVCtoBslRep(s[is]) << "\" matches against \"" << ch << "\"\n\n";
            ++is;
          }
          else
          {
            //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": \"" << NVCtoBslRep(s[is]) << "\" does not match against \"" << ch << "\"\n\n";
            //Tabs.erase(Tabs.length()-2);
            return 0;
          }
        }
        for (unsigned int c = 0; c != Max - Min; c++)
        {
          if (is >= s.length())
          {
            //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": (Empty String) does not match against \"" << ch << "\"\n\n";
            break;
          }
          int j = RegexMatch(r.substr(ir), s.substr(is), 0);
          if (j != 0)
          {
            //Tabs.erase(Tabs.length()-2);
            return is + j;
          }
          else
          {
            if (s[is] == ch)
            {
              //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << Min << "+" << c << ": \"" << NVCtoBslRep(s[is]) << "\" matches against \"" << ch << "\"\n\n";
              ++is;
            }
            else
            {
              //print << Tabs << "(\"" << NVCtoBslRep(r.substr(ir)) << "\", \"" << NVCtoBslRep(s.substr(is)) << "\"): " << c << ": \"" << NVCtoBslRep(s[is]) << "\" does not match against \"" << ch << "\"\n\n";
              break;
            }
          }
        }
      }
    }
  }

  //Tabs.erase(Tabs.length()-2);

  if (ir < r.length())
    return 0;
  else
    return is;
}


#endif
