#ifndef TYPE_STRING_MANIP_H
#define TYPE_STRING_MANIP_H

#include <string>
#include <vector>
#include <sstream>
#include <MyHeaders/TypeMath.h>

typedef unsigned short int usint;
typedef unsigned int uint;


const std::string Digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string WhiteSpace = " \r\n\t";

//0:  Success;  1:  Invalid string;  2:  Value too large
template <class N> usint StoN(const std::string& s, N& n, usint b = 10);
template <class I> usint StoI(const std::string& s, I& i, usint b = 10);
template <class R> usint StoR(const std::string& s, R& r, usint b = 10);
usint StoC(const std::string& s, mcl::Complex& c, usint b = 10);


const std::string& NtoS(mcl::Natural n, usint b = 10, usint w = 0);
const std::string& ItoS(mcl::Integer i, usint b = 10, usint w = 0);
const std::string& RtoS(mcl::Real r, usint b = 10, usint w = 0);
const std::string& CtoS(mcl::Complex c, usint b = 10, usint w = 0);


const std::string& CRLFtoLF(std::string s);
const std::string& LFtoCRLF(std::string s);


const std::string& NVCtoHex(const std::string& s, const std::string& keep = "");
const std::string& NVCtoHex(unsigned char c, const std::string& keep = "");

const std::string& NVCtoBsl(const std::string& s, const std::string& keep = "");
const std::string& NVCtoBsl(unsigned char c, const std::string& keep = "");


std::string Trim(const std::string& s, bool all = 0, const std::string& ws = WhiteSpace);

const std::string& Pad(const std::string& s, uint l, usint opt = 0, char pad = ' ');

std::vector<std::string> SplitString(const std::string& s, char d = '\n', bool keep = 0);

std::string StitchLines(const std::string& s0, const std::string& s1, usint opt = 0b100); //opt&0b100 = true => left edge of s1 maintained
std::string StitchLines(std::vector<std::string> vs, usint opt = 0b100); //opt&0b100 = true => left edge of s1 maintained


template <class T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v);


//template <class T> std::string VtoS(const std::vector<std::vector<T>>& v, const std::string& s = ", ", const std::string& b = "{  }");

template <class T> std::string VtoS(const std::vector<T>& v, const std::string& s = ", ", const std::string& b = "{  }");
template <class T> std::string VtoS(const T* v, uint len, const std::string& s = ", ", const std::string& b = "{  }");

//Returns pos, where s[pos] = c, or s.length() if c is not in s
uint ChInStr(char c, const std::string& s);



//===DEFINITITIONS===//

std::vector<std::string> SplitString(const std::string& s, char d, bool keep)
{
  std::vector<std::string> Output(1, "");
  for (char c : s)
  {
    if (c == d)
    {
      if (keep)
        Output.back() += d;
      Output.push_back("");
    }
    else
      Output.back() += c;
  }
  return Output;
}

//0:  Success;  1:  Invalid string;  2:  Value too large
template <class N> usint StoN(const std::string& s, N& n, usint b)
{
  n = 0;
  N old = 0;
  for (char c : s)
  {
    if (c == ' ' || c == ',')
      continue;

    uint pos = ChInStr(c, Digits.substr(0, b));
    if (pos == b)
      return 1;
    else
      (n *= b) += pos;

    if (n < old)
      return 2;
    else
      old = n;
  }

  return 0;
}
template <class I> usint StoI(const std::string& s, I& i, usint b)
{
  i = 0;
  I old = 0;
  short int sign = 0;
  for (char c : s)
  {
    switch (c)
    {
      case ' ':
      case ',':
        continue;
      break;
      case '+':
        if (sign)
          return 1;
        else
          sign = 1;
      break;
      case '-':
        if (sign)
          return 1;
        else
          sign = -1;
      break;
      default:
        uint pos = ChInStr(c, Digits.substr(0, b));
        if (pos == b)
          return 1;
        (i *= b) += pos;

        if (!sign)
          sign = 1;

        if (i < old)
          return 2;
        else
          old = i;
    }
  }

  if (sign == -1)
    i *= -1;

  return 0;
}
template <class R> usint StoR(const std::string& s, R& r, usint b)
{
  r = 0;
  short int sign = 0;
  short int shiftback = 0;
  for (char c : s)
  {
    switch (c)
    {
      case ' ':
      case ',':
        continue;
      break;
      case '+':
        if (sign)
          return 1;
        else
          sign = 1;
      break;
      case '-':
        if (sign)
          return 1;
        else
          sign = -1;
      break;
      case '.':
        if (shiftback)
          return 1;
        else
          shiftback = 1;
      break;
      default:
        uint pos = ChInStr(c, Digits.substr(0, b));
        if (pos == b)
          return 1;

        if (shiftback)
          r += R(pos) / R(shiftback *= b);
        else
          (r *= b) += pos;

        if (!sign)
          sign = 1;
    }
  }

  if (sign == -1)
    r *= -1;

  return 0;
}


const std::string& NtoS(mcl::Natural n, usint b, usint w)
{
  if (n == 0)
    return (w > 1 ? std::string(w, '0') : "0");

  std::string Output = "";
  mcl::Natural val = b;
  while (val <= n)
    val *= b;

  while (val > 1)
  {
    val /= b;
    Output += Digits[n / val];
    n %= val;
  }

  if (Output.length() < w)
    Output.insert(0, w - Output.length(), '0');
  return Output;
}
const std::string& ItoS(mcl::Integer i, usint b, usint w)
{
  if (i == 0)
    return (w > 1 ? std::string(w, '0') : "0");

  bool Neg = i < 0;
  if (Neg)
    i *= -1;

  mcl::Natural val = b;
  while (val <= i)
    val *= b;

  std::string Output(Neg, '-');
  while (val > 1)
  {
    val /= b;
    Output += Digits[i / val];
    i %= val;
  }

  if (Output.length() < w)
    Output.insert(Neg, w - Output.length(), '0');
  return Output;
}
const std::string& RtoS(mcl::Real r, usint b, usint w)
{
  if (r == 0)
  {
    switch (w)
    {
      case 0:
      case 1:
        return "0";
      case 2:
        return "00";
      default:
        return "0." + std::string(w - 2, '0');
    }
  }

  std::string Output("");
  if (r < 0)
  {
    Output += '-';
    r *= -1;
  }

  mcl::Real val = b;
  while (val <= r)
    val *= b;

  int c = r;
  while (val > 1)
  {
    c /= (val /= b);
    Output += Digits[c];
    c = (r -= val * c);
  }

  bool point = 0;
  if (r != 0)
  {
    point = 1;
    Output += '.';
    while (r != 0 && Output.length() < 20)
    {
      c /= (val /= b);
      Output += Digits[c];
      c = (r -= val * c);
    }
  }

  if (Output.length() < w)
  {
    if (Output.length() + 1 == w)
      Output.insert(Output[0] == '-', 1, 0);
    else
    {
      if (!point)
        Output += '.';
      Output.append(w - Output.length(), '0');
    }
  }
  return Output;
}
const std::string& CtoS(mcl::Complex c, usint b, usint w)
{
  if (c == 0)
  {
    switch (w)
    {
      case 0:
      case 1:
        return "0";
      case 2:
        return "00";
      default:
        return "0." + std::string(w - 2, '0');
    }
  }

  if (c.I == 0)
    return RtoS(c.R);
  if (c.R == 0)
    return RtoS(c.I) + "i";
  if (c.I < 0)
    return RtoS(c.R) + " - " + RtoS(-c.I) + "i";
  return RtoS(c.R) + " + " + RtoS(c.I) + "i";
}


const std::string& CRLFtoLF(std::string s)
{
  for (unsigned int i = 1; i < s.length(); i++)
  {
    if (s[i] == '\n' && s[i-1] == '\r')
      s.erase(--i, 1);
  }
  return s;
}
const std::string& LFtoCRLF(std::string s)
{
  for (unsigned int i = 0; i < s.length(); i++)
  {
    if (s[i] == '\n')
      s.insert(i++, 1, '\r');
    else if (s[i] == '\r')
      ++i;
  }
  return s;
}


const std::string& NVCtoHex(const std::string& s, const std::string& keep)
{
  std::string Output("");
  for (unsigned char c : s)
  {
    if ((32 < c && c < 127) || ChInStr(c, keep) != keep.length())
      Output += c;
    else
      Output += std::string("[0x") + Digits[c >> 4] + Digits[c & 0x0F] + "]";
  }
  return Output;
}
const std::string& NVCtoHex(unsigned char c, const std::string& keep)
{
  if ((32 < c && c < 127) || ChInStr(c, keep) != keep.length())
    return std::string(1,c);
  else
    return std::string("[0x") + Digits[c >> 4] + Digits[c & 0x0F] + "]";
}

const std::string& NVCtoBsl(const std::string& s, const std::string& keep)
{
  std::string Output("");
  for (unsigned char c : s)
  {
    if ((32 < c && c < 127) || ChInStr(c, keep) != keep.length())
      Output += c;
    else
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
        Output += std::string("\\x") + Digits[c >> 4] + Digits[c & 0x0F];
      }
    }
  }
  return Output;
}
const std::string& NVCtoBsl(unsigned char c, const std::string& keep)
{
  if ((32 < c && c < 127) || ChInStr(c, keep) != keep.length())
    return std::string(1,c);
  else
  {
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

    default:
      return std::string("\\x") + Digits[c >> 4] + Digits[c & 0x0F];
    }
  }
}


std::string Trim(const std::string& s, bool all, const std::string& ws)
{
  if (all)
  {
    std::string Output("");
    for (char c : s)
    {
      if (ChInStr(c, ws) == ws.length())
        Output += c;
    }
    //std::cout << "Trim(\"" << s << "\") = \"" << Output << "\"\n\n";
    return Output;
  }
  else
  {
    unsigned int i = 0;
    for ( ; i < s.length(); i++)
    {
      if (ChInStr(s[i], ws) == ws.length())
        break;
    }
    unsigned int j = s.length()-i;
    for ( ; j > 0; j--)
    {
      if (ChInStr(s[i+j-1], ws) == ws.length())
        break;
    }
    return s.substr(i,j);
  }
}

const std::string& Pad(const std::string& s, uint l, usint opt, char pad)
{
  if (s.length() >= l)
    return s;

  const uint d = l - s.length();
  switch (opt)
  {
  case 0:
    return s + std::string(d, pad);
  case 1:
    return std::string(d - (d >> 1), pad) + s + std::string(d >> 1, pad);
  case 2:
    return std::string(d >> 1, pad) + s + std::string(d - (d >> 1), pad);
  case 3:
    return std::string(d, pad) + s;

  default:
    return s + std::string(d, pad);
  }
}

std::string StitchLines(const std::string& s0, const std::string& s1, usint opt)
{
  auto s0lines = SplitString(s0);

  uint MaxWidth = 0;
  if (opt & 0b100)
  {
    for (std::string l : s0lines)
    {
      if (l.length() > MaxWidth)
        MaxWidth = l.length();
    }
  }

  auto s1lines = SplitString(s1);
  switch (opt & 0b11)
  {
  case 0: //Top
    while (s0lines.size() < s1lines.size())
      s0lines.push_back("");
    while (s1lines.size() < s0lines.size())
      s1lines.push_back("");
    break;
  case 1: //Center, err up
    if (s0lines.size() < s1lines.size())
    {
      const uint dif = s1lines.size() - s0lines.size();
      uint i = 0;
      for ( ; i < dif >> 1; i++)
        s0lines.push_back("");
      for (uint j = s0lines.size(); j > i; j--)
        s0lines[j-1] = s0lines[j - i - 1];
      for (uint j = 0; j < i; j++)
        s0lines[i] = "";
      for ( ; i < dif; i++)
        s0lines.push_back("");
    }
    else if (s1lines.size() < s0lines.size())
    {
      const uint dif = s0lines.size() - s1lines.size();
      uint i = 0;
      for ( ; i < dif >> 1; i++)
        s1lines.push_back("");
      for (uint j = s1lines.size(); j > i; j--)
        s1lines[j - 1] = s1lines[j - i - 1];
      for (uint j = 0; j < i; j++)
        s1lines[i] = "";
      for ( ; i < dif; i++)
        s1lines.push_back("");
    }
    break;

  case 2: //Center, err down
    if (s0lines.size() < s1lines.size())
    {
      const uint dif = s1lines.size() - s0lines.size();
      uint i = 0;
      for ( ; i < dif - (dif >> 1); i++)
        s0lines.push_back("");
      for (uint j = s0lines.size() - 1; j >= i; j--)
        s0lines[j] = s0lines[j - i];
      for (uint j = 0; j < i; j++)
        s0lines.push_back("");
    }
    else if (s1lines.size() < s0lines.size())
    {
      const uint dif = s0lines.size() - s1lines.size();
      uint i = 0;
      for ( ; i < dif - (dif >> 1); i++)
        s1lines.push_back("");
      for (uint j = s1lines.size() - 1; j >= i; j--)
        s1lines[j] = s1lines[j - i];
      for (uint j = 0; j < i; j++)
        s1lines[j] = "";
      for ( ; i < dif; i++)
        s1lines.push_back("");
    }
    break;

  case 3: //Bottom
    if (s0lines.size() < s1lines.size())
    {
      const uint dif = s1lines.size() - s0lines.size();
      uint i = 0;
      for ( ; i < dif; i++)
        s0lines.push_back("");
      for (uint j = s0lines.size() - 1; j >= i; j--)
        s0lines[j] = s0lines[j - i];
      for (uint j = 0; j < i; j++)
        s0lines[j] = "";
    }
    else if (s1lines.size() < s0lines.size())
    {
      const uint dif = s0lines.size() - s1lines.size();
      uint i = 0;
      for ( ; i < dif; i++)
        s1lines.push_back("");
      for (uint j = s1lines.size() - 1; j >= i; j--)
        s1lines[j] = s1lines[j - i];
      for (uint j = 0; j < i; j++)
        s1lines[j] = "";
    }
    break;
  }

  std::string Output("");
  if (opt & 0b100)
  {
    for (uint i = 0; i < s0lines.size(); i++)
      Output += Pad(s0lines[i], MaxWidth) + s1lines[i] + "\n";
  }
  else
  {
    for (uint i = 0; i < s0lines.size(); i++)
      Output += s0lines[i] + s1lines[i] + "\n";
  }
  Output.erase(Output.end() - 1);
  return Output;
}
std::string StitchLines(std::vector<std::string> vs, usint opt)
{
  switch (vs.size())
  {
  case 0:
    return "";
  case 1:
    return vs[0];
  case 2:
    return StitchLines(vs[0], vs[1], opt);
  default:
    while (vs.size() != 1)
    {
      uint i = 0;
      for ( ; i < vs.size() >> 1; i++)
        vs[i] = StitchLines(vs[i << 1], vs[(i << 1) + 1], opt);
      if ((uint)vs.size() & 0b1)
        vs[i] = vs[i++ << 1];
      vs.resize(i);
    }
    return vs[0];
  }
}


template <class T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v)
{
  s << VtoS(v);
  return s;
}


/*
template <class T> std::string VtoS(const std::vector<std::vector<T>>& v, const std::string& s = ", ", const std::string& b = "{  }")
{
  if (v.size() == 0)
    return b;

  std::ostringstream
}*/

template <class T> std::string VtoS(const std::vector<T>& v, const std::string& s, const std::string& b)
{
  if (v.size() == 0)
    return b;
  //std::cout << "\"" << b << "\".substr(0, " << b.length() << "/2) = \"" << b.substr(0, b.length() >> 1) << "\"\n";
  std::ostringstream Output;//(b.substr(0, b.length() >> 1));
  Output << b.substr(0, b.length() >> 1);
  for (uint i = 0; i < v.size()-1; i++)
    Output << v[i] << s;
  Output << v.back() << b.substr(b.length() >> 1);
  return Output.str();
}
template <class T> std::string VtoS(const T* v, uint len, const std::string& s, const std::string& b)
{
  if (len == 0)
    return b;
  std::ostringstream Output(b.substr(0, b.length() >> 1));
  for (uint i = 0; i < len-1; i++)
    Output << v[i] << s;
  Output << v[len-1] << b.substr(b.length() >> 1);
  return Output.str();
}


uint ChInStr(char c, const std::string& s)
{
  uint p = 0;
  while (p < s.length())
  {
    if (s[p] == c)
      break;
    ++p;
  }
  return p;
}


#endif
