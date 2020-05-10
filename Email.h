#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <fstream>

bool Send(std::string To, std::string From, std::string Pwd, std::string msg, std::string subj = "")
{
  std::ofstream File("tmpmail.txt");
  File << "From <" << From << ">\n"
    "To: " << To << "\n"
    "Subject: " << subj << "\n"
    "\n" << msg << "\n";
  File.close();
  system((std::string("send-mail.bat ") + To + " tmpmail.txt").c_str());
  return 1;
}


#endif
