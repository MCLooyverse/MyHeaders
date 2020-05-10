#ifndef STR_MANIP_H
#define STR_MANIP_H

#include <string>
#include <vector>
#include <sstream>
#include <MyHeaders/TypeMath.h>

typedef unsigned short int usint;

typedef unsigned int uint;

const char* Digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char* WhiteSpaceChars = " \r\n\t";

std::vector<std::string> SplitLines(std::string, char = '\n');

//0: Success;  1: Invalid character;  2: Input too large for output;
short int StoI(std::string, short int&, usint = 10);
short int StoI(std::string, unsigned short int&, usint = 10);
short int StoI(std::string, int&, usint = 10);
short int StoI(std::string, unsigned int&, usint = 10);
short int StoI(std::string, long int&, usint = 10);
short int StoI(std::string, unsigned long int&, usint = 10);
short int StoI(std::string, long long int&, usint = 10);
short int StoI(std::string, unsigned long long int&, usint = 10);

short int StoD(std::string, double&, usint = 10);

short int StoC(std::string, Complex&, usint = 10);

std::string ItoS(long long int, usint = 10, usint = 0);
std::string UItoS(unsigned long long int, usint = 10, usint = 0);

std::string DtoS(double, usint = 10, usint = 0);

std::string CRLFtoLF(std::string);
std::string LFtoCRLF(std::string);


std::string Remove(std::string, std::string);
std::string aRemove(std::string&, std::string);


std::string NVCtoHexRep(std::string, std::string = "");
std::string NVCtoHexRep(unsigned char, std::string = "");
std::string NVCtoBslRep(std::string, std::string = "");
std::string NVCtoBslRep(unsigned char, std::string = "");

std::string ToHex(std::string);


std::string TrimWhitespace(std::string, std::string = WhiteSpaceChars);

std::string StitchLines(std::string, std::string, usint = 0b100);
std::string StitchLines(const std::vector<std::string>, usint = 0b100);

std::string Pad(std::string, uint, usint = 0, char = ' ');

std::string* SplitStr(std::vector<std::string*>, char, bool = 0, int = 0);


template <class T> std::string VtoS(std::vector<T>, std::string = ", ", bool = 1);
template <class T> std::string VtoS(T*, unsigned int, std::string = ", ", bool = 1);


bool ChInStr(char c, std::string s);





//Definitions
std::vector<std::string> SplitLines(std::string Input, char delim)
{
  std::vector<std::string> Output = {""};
  for (char c : Input)
  {
    if (c == delim)
      Output.push_back("");
    else
      Output.back() += c;
  }
  return Output;
}


short int StoI(std::string sNum, short int& Num, usint Base)
{
  bool Neg = sNum[0] == '-';
  if (Neg)
    sNum.erase(0,1);

  auto GetCharVal = [&](char c) -> short int{
    for (short int i = 0; i < Base; i++)
    {
      if (Digits[i] == c)
        return i;
    }
    return -1;
  };

  Num = 0;
  auto Old = Num;
  for (char c : sNum)
  {
    short int Val = GetCharVal(c);
    if (Val == -1)
      return 1;
    (Num *= Base) += Val;
    if (Num < Old)
      return 2;
  }

  if (Neg)
    Num *= -1;
  return 0;
}
short int StoI(std::string sNum, unsigned short int& Num, usint Base)
{
  auto GetCharVal = [&](char c) -> short int{
    for (short int i = 0; i < Base; i++)
    {
      if (Digits[i] == c)
        return i;
    }
    return -1;
  };

  Num = 0;
  auto Old = Num;
  for (char c : sNum)
  {
    short int Val = GetCharVal(c);
    if (Val == -1)
      return 1;
    (Num *= Base) += Val;
    if (Num < Old)
      return 2;
  }

  return 0;
}
short int StoI(std::string sNum, int& Num, usint Base)
{
  bool Neg = sNum[0] == '-';
  if (Neg)
    sNum.erase(0,1);

  auto GetCharVal = [&](char c) -> short int{
    for (short int i = 0; i < Base; i++)
    {
      if (Digits[i] == c)
        return i;
    }
    return -1;
  };

  Num = 0;
  auto Old = Num;
  for (char c : sNum)
  {
    short int Val = GetCharVal(c);
    if (Val == -1)
      return 1;
    (Num *= Base) += Val;
    if (Num < Old)
      return 2;
  }

  if (Neg)
    Num *= -1;
  return 0;
}
short int StoI(std::string sNum, unsigned int& Num, usint Base)
{
  auto GetCharVal = [&](char c) -> short int{
    for (short int i = 0; i < Base; i++)
    {
      if (Digits[i] == c)
        return i;
    }
    return -1;
  };

  Num = 0;
  auto Old = Num;
  for (char c : sNum)
  {
    short int Val = GetCharVal(c);
    if (Val == -1)
      return 1;
    (Num *= Base) += Val;
    if (Num < Old)
      return 2;
  }

  return 0;
}
short int StoI(std::string sNum, long int& Num, usint Base)
{
  bool Neg = sNum[0] == '-';
  if (Neg)
    sNum.erase(0,1);

  auto GetCharVal = [&](char c) -> short int{
    for (short int i = 0; i < Base; i++)
    {
      if (Digits[i] == c)
        return i;
    }
    return -1;
  };

  Num = 0;
  auto Old = Num;
  for (char c : sNum)
  {
    short int Val = GetCharVal(c);
    if (Val == -1)
      return 1;
    (Num *= Base) += Val;
    if (Num < Old)
      return 2;
  }

  if (Neg)
    Num *= -1;
  return 0;
}
short int StoI(std::string sNum, unsigned long int& Num, usint Base)
{
  auto GetCharVal = [&](char c) -> short int{
    for (short int i = 0; i < Base; i++)
    {
      if (Digits[i] == c)
        return i;
    }
    return -1;
  };

  Num = 0;
  auto Old = Num;
  for (char c : sNum)
  {
    short int Val = GetCharVal(c);
    if (Val == -1)
      return 1;
    (Num *= Base) += Val;
    if (Num < Old)
      return 2;
  }

  return 0;
}
short int StoI(std::string sNum, long long int& Num, usint Base)
{
  bool Neg = sNum[0] == '-';
  if (Neg)
    sNum.erase(0,1);

  auto GetCharVal = [&](char c) -> short int{
    for (short int i = 0; i < Base; i++)
    {
      if (Digits[i] == c)
        return i;
    }
    return -1;
  };

  Num = 0;
  auto Old = Num;
  for (char c : sNum)
  {
    short int Val = GetCharVal(c);
    if (Val == -1)
      return 1;
    (Num *= Base) += Val;
    if (Num < Old)
      return 2;
  }

  if (Neg)
    Num *= -1;
  return 0;
}
short int StoI(std::string sNum, unsigned long long int& Num, usint Base)
{
  auto GetCharVal = [&](char c) -> short int{
    for (short int i = 0; i < Base; i++)
    {
      if (Digits[i] == c)
        return i;
    }
    return -1;
  };

  Num = 0;
  auto Old = Num;
  for (char c : sNum)
  {
    short int Val = GetCharVal(c);
    if (Val == -1)
      return 1;
    (Num *= Base) += Val;
    if (Num < Old)
      return 2;
  }

  return 0;
}


short int StoD(std::string sNum, double& Num, usint Base)
{
  bool Neg = sNum[0] == '-';
  if (Neg)
    sNum.erase(0,1);

  auto GetCharVal = [&](char c) -> short int{
    for (short int i = 0; i < Base; i++)
    {
      if (Digits[i] == c)
        return i;
    }
    return -1;
  };

  Num = 0;
  auto Old = 0;
  short int Val = 0;
  int i = 0;
  while (i < sNum.length())
  {
    char c = sNum[i++];
    if (c == '.')
      break;
    else
    {
      Val = GetCharVal(c);
      if (Val == -1)
        return 1;
      else
      {
        (Num *= Base) += Val;
        if (Num < Old)
          return 2;
        Old = Num;
      }
    }
  }

  double Shift = Base;
  while (i < sNum.length())
  {
    Val = GetCharVal(sNum[i++]);
    if (Val == -1)
      return 1;
    else
    {
      Num += (double)Val / Shift;
      Shift *= Base;
      if (Num < Old)
        return 2;
      Old = Num;
    }
  }

  if (Neg)
    Num *= -1;
  return 0;
}


short int StoC(std::string s, Complex& c, usint b)
{
  c = 0;
  bool Neg = 0;
  bool Real = 1;
  unsigned int ShiftBack = 0;
  s = TrimWhitespace(s);
  switch (s[0])
  {
    case '-':
      Neg = 1;
    case '+':
      s.erase(s.begin());
  }

  for (char c : s)
  {
    if (Real)
    {

    }
  }
}


std::string ItoS(long long int Num, usint Base, usint MinLen)
{
  if (Num == 0)
    return (MinLen > 1 ? std::string(MinLen, '0') : "0");

  bool Neg = Num < 0;
  if (Neg)
    Num *= -1;

  int Power = 1;
  while (Power <= Num)
    Power *= Base;

  std::string Output(Neg, '-');
  while (Power > 1)
  {
    Power /= Base;
    Output += Digits[Num / Power];
    Num %= Power;
  }

  if (Output.length() < MinLen)
    return std::string(MinLen - Output.length(), '0') + Output;
  return Output;
}
std::string UItoS(unsigned long long int Num, usint Base, usint MinLen)
{
  if (Num == 0)
    return (MinLen > 1 ? std::string(MinLen, '0') : "0");

  int Power = 1;
  while (Power <= Num)
    Power *= Base;

  std::string Output = "";
  while (Power > 1)
  {
    Power /= Base;
    Output += Digits[Num / Power];
    Num %= Power;
  }

  if (Output.length() < MinLen)
    return std::string(MinLen - Output.length(), '0') + Output;
  return Output;
}

std::string DtoS(double Num, usint Base, usint MinLen)
{
  if (Num == 0)
    return (MinLen > 1 ? std::string(MinLen, '0') : "0");

  std::string Output = "";
  if (Num < 0)
  {
    Output = "-";
    Num *= -1;
  }

  double Power = Base;
  while (Power <= Num)
    Power *= Base;

  while (Power > 1)
  {
    Power /= Base;
    Output += Digits[(int)(Num / Power)];
    Num -= Power * (int)(Num / Power);
  }

  if (Num != 0)
    Output += ".";

  while (Num != 0 && Output.length() < 20)
  {
    Power /= Base;
    Output += Digits[(int)(Num / Power)];
    Num -= Power * (int)(Num / Power);
  }

  if (Output.length() < MinLen)
    return std::string(MinLen - Output.length(), '0') + Output;
  return Output;
}

std::string CRLFtoLF(std::string Win)
{
  for (int i = Win.find("\r\n"); i != std::string::npos; i = Win.find("\r\n", i))
  {
    Win.erase(i,1);
  }
  return Win;
}
std::string LFtoCRLF(std::string Nix)
{
  bool PreCR = 0;
  for (int i = 0; i < Nix.length(); i++)
  {
    if (Nix[i] == '\n' && !PreCR)
      Nix.insert(i, "\r");

    if (Nix[i] == '\r')
      PreCR = 1;
    else
      PreCR = 0;
  }
  return Nix;
}


std::string Remove(std::string Str, std::string List)
{
  for (int i = 0; i < Str.length(); i++)
  {
    for (char c : List)
    {
      if (Str[i] == c)
        Str.erase(i--,1);
    }
  }

  return Str;
}
std::string aRemove(std::string& Str, std::string List)
{
  for (int i = 0; i < Str.length(); i++)
  {
    for (char c : List)
    {
      if (Str[i] == c)
        Str.erase(i--,1);
    }
  }

  return Str;
}


std::string NVCtoHexRep(std::string Str, std::string KeepList)
{
  auto Keep = [KeepList](char c){
    if (!(c < 33 || c >= 127))
      return 1;
    if (KeepList.find(c) != std::string::npos)
      return 1;

    return 0;
  };
  const char* HexChars = "0123456789ABCDEF";

  std::string Output = "";
  for (unsigned char c : Str)
  {
    if (Keep(c))
      Output += c;
    else
      (((Output += "[0x") += HexChars[c >> 4]) += HexChars[c % 0x10]) += "]";
  }
  return Output;
}
std::string NVCtoHexRep(unsigned char c, std::string KeepList)
{
  if (!(c < 33 || c >= 127))
    return std::string(1,c);
  if (KeepList.find(c) != std::string::npos)
    return std::string(1,c);

  const char* HexChars = "0123456789ABCDEF";
  return (std::string)"[0x" + std::string(1, HexChars[c >> 4]) + std::string(1, HexChars[c & 0xF]) + (std::string)"]";
}
std::string NVCtoBslRep(std::string str, std::string keep)
{
  const char* HexChars = "0123456789ABCDEF";
  std::string Output = "";
  for (unsigned char c : str)
  {
    bool Replace = 1;
    for (char k : keep)
    {
      if (k == c)
      {
        Replace = 0;
        break;
      }
    }

    if (Replace)
    {
      switch (c)
      {
      case '\a':
        Output += "\\a";
        break;
      case '\b':
        Output += "\\b";
        break;
      case '\x1B':
        Output += "\\e";
        break;
      case '\f':
        Output += "\\f";
        break;
      case '\t':
        Output += "\\t";
        break;
      case '\n':
        Output += "\\n";
        break;
      case '\v':
        Output += "\\v";
        break;
      case '\r':
        Output += "\\r";
        break;
      case '\\':
        Output += "\\\\";
        break;

      default:
        if (c < 33 || c >= 127)
          Output += std::string("\\x") + HexChars[c >> 4] + HexChars[c & 0xF];
        else
          Output += c;
      }
    }
    else
      Output += c;
  }
  return Output;
}
std::string NVCtoBslRep(unsigned char c, std::string keep)
{
  bool Replace = 1;
  for (char k : keep)
  {
    if ((unsigned char)k == c)
    {
      Replace = 0;
      break;
    }
  }

  if (!Replace || (32 < c && c < 127))
    return std::string(1, c);
  switch (c)
  {
  case '\a':
    return "\\a";
  case '\b':
    return "\\b";
  case '\x1B':
    return "\\e";
  case '\f':
    return "\\f";
  case '\t':
    return "\\t";
  case '\n':
    return "\\n";
  case '\v':
    return "\\v";
  case '\r':
    return "\\r";
  case '\\':
    return "\\\\";
  }
  const char* HexChars = "0123456789ABCDEF";
  return std::string("\\x") + HexChars[c >> 4] + HexChars[c & 0xF];
}

std::string FuckingWork(std::string str)
{
  std::string Output = "";
  const char* HexChars = "0123456789ABCDEF";
  for (char c : str)
  {
    Output += std::string("\\x") + UItoS((unsigned char)c, 16, 2);//HexChars[c >> 4] + HexChars[c & 0xF];
  }
  return Output;
}


std::string TrimWhitespace(std::string Str, std::string rm)
{
  std::vector<char> Delims;
  for (char c : rm)
  {
    Delims.push_back(c);
  }

  //while(MCL::elem(Str.front(), Delims))
  while([&Str, &Delims](){
      for (char k : Delims)
      {
        if (k == Str.front())
          return 1;
      }
      return 0;
  }())
    Str.erase(Str.begin());
  while([&Str, &Delims](){
      for (char k : Delims)
      {
        if (k == Str.back())
          return 1;
      }
      return 0;
  }())
    Str.erase(Str.end()-1);

  return Str;
}

std::string StitchLines(std::string str0, std::string str1, usint opt)//Set 0b100 for keeping left edge of str1 intact
{
  //std::cout << "Stitching\n---\n" << str0 << "\n---\nand\n---\n" << str1 << "\n---\n\n";
  std::string Output = "";
  std::vector<std::string> vstr0 = SplitLines(str0);
  uint MaxWidth = 0;
  if (opt & 0b100)
  {
    for (std::string s : vstr0)
    {
      if (s.length() > MaxWidth)
        MaxWidth = s.length();
    }
  }
  std::vector<std::string> vstr1 = SplitLines(str1);
  switch (opt & 0b11)
  {
    case 1: //Center, err up
      //std::cout << "Center, err up  selected.\n\n";
      if (vstr0.size() < vstr1.size())
      {
        const uint dif = vstr1.size() - vstr0.size();
        uint i = 0;
        for ( ; i < dif / 2; i++)
          vstr0.push_back("");
        for (uint j = vstr0.size() - 1; j >= i; j--)
          vstr0[j] = vstr0[j - i];
        for (uint j = 0; j < i; j++)
          vstr0[j] = "";
        for ( ; i < dif; i++)
          vstr0.push_back("");
      }
      else if (vstr1.size() < vstr0.size())
      {
        //std::cout << "Second string holds ";
        const uint dif = vstr0.size() - vstr1.size();
        //std::cout << dif << " fewer lines than the first.\n\n";
        uint i = 0;
        for ( ; i < dif / 2; i++)
          vstr1.push_back("");
        for (uint j = vstr1.size() - 1; j >= i; j--)
        {
          vstr1[j] = vstr1[j - i];
          if (j == i)
            break;
        }
        for (uint j = 0; j < i; j++)
          vstr1[j] = "";
        for ( ; i < dif; i++)
          vstr1.push_back("");

        /*
        std::cout << "Second string has been modified to\n---\n";
        for (std::string s : vstr1)
          std::cout << s << "\n";
        std::cout << "---\n\n";*/
      }
      break;
    case 2: //Center, err down
      if (vstr0.size() < vstr1.size())
      {
        const uint dif = vstr1.size() - vstr0.size();
        uint i = 0;
        for ( ; i < dif - dif / 2; i++)
          vstr0.push_back("");
        for (uint j = vstr0.size() - 1; j >= i; j--)
          vstr0[j] = vstr0[j - i];
        for (uint j = 0; j < i; j++)
          vstr0[j] = "";
        for ( ; i < dif; i++)
          vstr0.push_back("");
      }
      else if (vstr1.size() < vstr0.size())
      {
        const uint dif = vstr0.size() - vstr1.size();
        uint i = 0;
        for ( ; i < dif - dif / 2; i++)
          vstr1.push_back("");
        for (uint j = vstr1.size() - 1; j >= i; j--)
          vstr1[j] = vstr1[j - i];
        for (uint j = 0; j < i; j++)
          vstr1[j] = "";
        for ( ; i < dif; i++)
          vstr1.push_back("");
      }
      break;
    case 3: //Bottom
      if (vstr0.size() < vstr1.size())
      {
        const uint dif = vstr1.size() - vstr0.size();
        uint i = 0;
        for ( ; i < dif; i++)
          vstr0.push_back("");
        for (uint j = vstr0.size() - 1; j >= i; j--)
          vstr0[j] = vstr0[j - i];
        for (uint j = 0; j < i; j++)
          vstr0[j] = "";
      }
      else if (vstr1.size() < vstr0.size())
      {
        const uint dif = vstr0.size() - vstr1.size();
        uint i = 0;
        for ( ; i < dif; i++)
          vstr1.push_back("");
        for (uint j = vstr1.size() - 1; j >= i; j--)
          vstr1[j] = vstr1[j - i];
        for (uint j = 0; j < i; j++)
          vstr1[j] = "";
      }
      break;
    case 0: //Top
    default: //Same as 0
      while (vstr0.size() < vstr1.size())
        vstr0.push_back("");
      while (vstr1.size() < vstr0.size())
        vstr1.push_back("");
  }

  if (opt & 0b100)
  {
    for (uint i = 0; i < vstr0.size(); i++)
      Output += Pad(vstr0[i], MaxWidth) + vstr1[i] + "\n";
  }
  else
  {
    for (uint i = 0; i < vstr0.size(); i++)
      Output += vstr0[i] + vstr1[i] + "\n";
  }
  Output.erase(Output.end() - 1);
  return Output;
}

std::string StitchLines(const std::vector<std::string> List, usint opt)
{
  switch (List.size())
  {
    case 0:
      return "";
    case 1:
      return List[0];
    case 2:
      return StitchLines(List[0], List[1], opt);
    default:
      std::string Output = List.back();
      for (uint i = 2; i <= List.size(); i++)
        Output = StitchLines(List[List.size() - i], Output, opt);
      return Output;
  }
}

std::string Pad(std::string str, uint len, usint opt, char pad)
{
  if (str.length() >= len)
    return str;
  uint dif = len - str.length();
  switch (opt)
  {
    case 0: //Left align
      return str + std::string(dif, pad);
      break;
    case 1: //Center align, err left
      return std::string(dif - (dif / 2), pad) + str + std::string(dif / 2, pad);
      break;
    case 2: //Center align, err right
      return std::string(dif / 2, pad) + str + std::string(dif - (dif / 2), pad);
      break;
    case 3: //Right align
      return std::string(dif, pad) + str;
      break;
    default: //case 0
      return std::string(dif, pad) + str;
  }
}

std::string* SplitStr(std::vector<std::string*> strs, char delim, bool keep, int ret)
{
  if (strs.size() == 0)
    return 0;

  while (ret < 0)
    ret += strs.size();
  ret %= strs.size();

  for (uint i = 0; i < strs.size(); i++)
  {
    uint j = 0;
    for ( ; j < strs[i]->length(); j++)
    {
      if (strs[i]->at(j) == delim)
      break;
    }
    if (j == strs[i]->length())
    {
      while (++i < strs.size())
        strs[i]->assign("");
    }
    else
    {
      strs[i+1]->assign(strs[i]->substr(j+1));
      strs[i]->erase(j + keep);
    }
  }

  return strs[ret];
}


template <class T>
std::string VtoS(std::vector<T> V, std::string Separator, bool Brackets)
{
  if (V.size() == 0)
  {
    if (Brackets)
      return "{ }";
    else
      return "";
  }
  std::ostringstream SS;
  if (Brackets)
    SS << "{ ";
  for (T e : V)
    SS << e << Separator;
  return SS.str().erase(SS.str().length() - Separator.length()) + (Brackets ? " }" : "");
}
template <class T>
std::string VtoS(T* v, unsigned int size, std::string Separator, bool Brackets)
{
  if (size == 0)
  {
    if (Brackets)
      return "{ }";
    else
      return "";
  }
  std::ostringstream SS;
  if (Brackets)
    SS << "{ ";
  for (unsigned int i = 0; i < size; i++)
    SS << v[i] << Separator;
  return SS.str().erase(SS.str().length() - Separator.length()) + (Brackets ? " }" : "");
}

bool ChInStr(char c, std::string s)
{
  for (char k : s)
  {
    if (k == c)
      return 1;
  }
  return 0;
}


#endif
