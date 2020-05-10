#ifndef GET_FROM_JSON_H
#define GET_FROM_JSON_H

#include <string>
#include <vector>
#include <MyHeaders/Math.h>


//GetJSONVal(name of .json file, {"name", "child of name",...}, ref to string) return success state
bool GetJSONVal(std::string FileName, std::vector<std::string> VarTree, std::string& Output)
{
  std::ifstream File(FileName);
  if (!File.is_open())
  {
    Output = "File Not Open";
    File.close();
    return 0;
  }

  std::vector<char> WhiteSpace = { ' ', '\n', '\r', '\t' };
  std::vector<char> BreakChars = { ',', '}'};
  int TreeLevel = -1;
  int LookLevel = 0;
  char NextChar = '\0';
  while(File)
  {
    NextChar = (char)File.peek();
    std::string Var = "";

    if ((NextChar == '"') && (LookLevel == TreeLevel))
    {
      File.ignore();
      Var = "";
      while (File.peek() != '"')
        Var.push_back(File.get());
      File.ignore();

      if (Var == VarTree[LookLevel])
      {
        ++LookLevel;
        if (LookLevel == VarTree.size())
        {
          NextChar = (char)File.peek();
          while (NextChar == ' ' || NextChar == ':' || NextChar == '\t')
          {
            File.ignore();
            NextChar = (char)File.peek();
          }


          Output = "";

          if (NextChar == '"')
          {
            File.ignore();
            while (Output.back() != '"')
              Output.push_back(File.get());
          }
          else
          {
            while (!MCL::elem((char)File.peek(), BreakChars))
              Output.push_back(File.get());
          }


          while (MCL::elem(Output.back(), WhiteSpace))
            Output.pop_back();
          if (Output.back() == '"')
            Output.pop_back();

          File.close();
          return 1;
        }
      }
    }
    else if (NextChar == '{')
    {
      ++TreeLevel;
      File.ignore();
    }
    else if (NextChar == '}')
    {
      --TreeLevel;
      if (TreeLevel < LookLevel)
      {
        std::ostringstream sOutput;
        sOutput << "Variable " << VarTree[LookLevel] << " [" << LookLevel << "] Not Found in " << FileName;
        Output = sOutput.str();

        File.close();
        return 0;
      }
      File.ignore();
    }
    else
      File.ignore();
  }

  Output = "Variable ";
  Output += VarTree[0] + " [0] Not Found in " + FileName;

  File.close();
  return 0;
}



#endif
