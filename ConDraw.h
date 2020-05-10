#ifndef CONSOLE_DRAWING_H
#define CONSOLE_DRAWING_H

#include <MyHeaders/TypeStrmanip.h>
#include <windows.h>
#include <conio.h>
#include <cstdio>


namespace Console
{
  typedef unsigned int coord;
  coord Width;
  coord Height;
  void Init();
  void GetSize();
  bool PutC(char c, coord Line = 0, coord Char = 0);
  bool PutS(std::string Str, coord Line = 0, coord Char = 0);
  void cls();
};
namespace Cursor
{
  using namespace Console;
  std::string MoveSeq(coord Line, coord Char);
  bool Move(coord Line, coord Char);
};



void Console::Init()
{
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

  DWORD dwMode = 0;
  GetConsoleMode(hOut, &dwMode);

  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(hOut, dwMode);

  Console::GetSize();
}

void Console::GetSize()
{
  Console::Height = 0;
  Console::Width = 0;
  fputs("\x1B[999;999H\x1B[6n", stdout);
  //exit(0);
  //Console::PutS("a\x1B[6n", 998, 998);
  //Sleep(10000);
  _getch(); //'\x1B'
  _getch(); //'['
  for (char c = _getch(); c != ';'; c = _getch())
    (Console::Height *= 10) += (c - '0');
  for (char c = _getch(); c != 'R'; c = _getch())
    (Console::Width *= 10) += (c - '0');

  Console::PutS("\x1B[J", 0, 0);
}

bool Console::PutC(char c, coord Line, coord Char)
{
  bool r = 1;
  if (Line >= Console::Height || Char >= Console::Width)
  {
    r = 0;
    Line = Console::Height - 1;
    Char = Console::Width - 1;
  }
  fputs(("\x1B[" + NtoS(Line+1) + ";" + NtoS(Char+1) + "H" + std::string(1, c)).c_str(), stdout);
  return r;
}

bool Console::PutS(std::string Str, coord Line, coord Char)
{
  bool r = 1;
  if (Line >= Console::Height || Char >= Console::Width)
  {
    r = 0;
    Line = Console::Height - 1;
    Char = Console::Width - 1;
  }
  fputs(("\x1B[" + NtoS(Line+1) + ";" + NtoS(Char+1) + "H" + Str).c_str(), stdout);
  return r;
}
void Console::cls()
{
  Console::PutS("\x1B[J", 0, 0);
}

std::string Cursor::MoveSeq(coord Line, coord Char)
{
  return "\x1B[" + NtoS(Line+1) + ";" + NtoS(Char+1) + "H";
}
bool Cursor::Move(coord Line, coord Char)
{
  bool r = 1;
  if (Line >= Console::Height || Char >= Console::Width)
  {
    r = 0;
    Line = Console::Height - 1;
    Char = Console::Width - 1;
  }
  fputs(("\x1B[" + NtoS(Line+1) + ";" + NtoS(Char+1) + "H").c_str(), stdout);
  return r;
}



#endif
