#ifndef HTTP_PROCESSING_H
#define HTTP_PROCESSING_H

#include <string>
#include <vector>
#include <MyHeaders/strmanip.h>


bool HTTPParse(
  std::string Request,
  std::string& Method,
  std::string& Resource,
  std::string& Version,
  std::vector<std::string>& Keys,
  std::vector<std::string>& Values,
  std::string& Body
)
{
  std::vector<std::string> Lines = SplitLines(Request);

  bool Valid = 1;

  int i = 0;
  Method = "";
  while (i < Lines[0].length() && Lines[0][i] != ' ')
    Method += Lines[0][i++];
  if (Method == "")
    Valid = 0;
  aRemove(Method, " \t");

  ++i;

  Resource = "";
  while (i < Lines[0].length() && Lines[0][i] != ' ')
    Resource += Lines[0][i++];
  if (Resource == "")
    Valid = 0;
  aRemove(Resource, " \t");

  ++i;

  Version = "";
  while (i < Lines[0].length())
    Version += Lines[0][i++];
  if (Version == "")
    Valid = 0;
  aRemove(Version, " \t");

  i = 1;
  Keys.resize(0);
  Values.resize(0);
  while (i < Lines.size() && Lines[i] != "")
  {
    Keys.push_back("");
    int j = 0;
    while (j < Lines[i].length() && Lines[i][j] != ':')
      Keys.back() += Lines[i][j++];

    while(Lines[i][++j] != ' ') { }

    Values.push_back("");
    while (j < Lines[i].length())
      Values.back() += Lines[i][j++];

    ++i;
  }

  while (Lines[i] == "")
    ++i;

  Body = "";
  while (i < Lines.size())
    Body += Lines[i++] + "\n";

  if (Body != "")
    Body.pop_back();

  return Valid;
}


#endif
