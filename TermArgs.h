#ifndef TERMINAL_ARGUMENTS_H
#define TERMINAL_ARGUMENTS_H


#include <string>


struct NVRTuple
{
  std::string Name;
  //std::string Regex;
  void* Value;
  bool Which;  //0 for bool

  NVRTuple(std::string n, std::string& v) : Name(n), Value(&v), Which(1) { }
  NVRTuple(std::string n, bool& v) : Name(n), Value(&v), Which(0) { }
};


//<> encloses variable names (whereas litterals such as "-n" are not surrounded by <>)
std::string GetArgs(int argc, char** argv, std::string Pattern, std::vector<NVRTuple> VarList)  //Will return an error message, or an empty string if no error is found.
{
  int Layers = 0;
  int tmp = 0;
  for (char c : Pattern)
  {
    tmp += (int)(c == '[') - (int)(c == ']');
    if (tmp > Layers)
      Layers = tmp;
  }
}


#endif
