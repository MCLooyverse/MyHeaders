#ifndef BASIC_SERVER_H
#define BASIC_SERVER_H


#include <WS2tcpip.h>
#include <iostream>
#include <fstream>
#include <MyHeaders/strmanip.h>
#include <thread>

bool Talk = 1;


int StartServer(uint16_t Port, std::string (*EvalFunc)(std::string))
{
  while (!Talk) { }
  Talk = 0;
  std::clog << "\nPort" + UItoS(Port) + ": starting server";
  Talk = 1;
  WSADATA wsData;
  WORD ver = MAKEWORD(2,2);

  int wsOk = WSAStartup(ver, &wsData);
  if (wsOk)
    return 1;//wsOk;

  while(!Talk) { }
  Talk = 0;
  std::clog << "\nPort" + UItoS(Port) + ": WinSock intialised";
  Talk = 1;
  while(1)
  {
    SOCKET Listening = socket(AF_INET, SOCK_STREAM, 0);
    if (Listening == INVALID_SOCKET)
    {
      //std::cerr << "\nCan't start server.  Unable to start listeing port.\n\n";
      WSACleanup();
      return 2;
    }
    while(!Talk) { }
    Talk = 0;
    std::clog << "\nPort" + UItoS(Port) + ": Listening socket made";
    Talk = 1;

    sockaddr_in Hint;
    Hint.sin_family = AF_INET;
    Hint.sin_port = htons(Port);
    Hint.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(Listening, (sockaddr*)&Hint, sizeof(Hint));

    while(!Talk) { }
    Talk = 0;
    std::clog << "\nPort" + UItoS(Port) + ": Listening for connection";
    Talk = 1;
    listen(Listening, SOMAXCONN);


    sockaddr_in Client;
    int* ClientSize = new int(sizeof(Client));

    SOCKET ClientSocket = accept(Listening, (sockaddr*)&Client, ClientSize);
    closesocket(Listening);
    if (ClientSocket == INVALID_SOCKET)
    {
      WSACleanup();
      return;// 3;
    }
    
    //Making connection
    while(!Talk) { }
    Talk = 0;
    std::clog << "\nPort" + UItoS(Port) + ": making thread for connection.";
    Talk = 1;
    std::thread Connection(
      [=]() -> void {


        char Host[NI_MAXHOST];
        char Service[NI_MAXSERV];
        ZeroMemory(Host, NI_MAXHOST);
        ZeroMemory(Service, NI_MAXSERV);


        if (getnameinfo((sockaddr*)&Client, sizeof(Client), Host, NI_MAXHOST, Service, NI_MAXSERV, 0) == 0)
        {
          //std::clog << "\n" << Host << " connected on port " << ntohs(Client.sin_port) << "\n\n";
        }
        else
        {
          getnameinfo((sockaddr*)&Client, sizeof(Client), Host, NI_MAXHOST, Service, NI_MAXSERV, NI_NUMERICHOST);
          //std::clog << "\n" << Host << " connected on port " << ntohs(Client.sin_port) << "\n\n";
        }


        char buf[4096];
        ZeroMemory(buf, 4096);

        int RecvCount = recv(ClientSocket, buf, 4096, 0);
        std::string Request = CRLFtoLF((std::string)buf);

        while (RecvCount != 0)
        {
          std::string Message = EvalFunc(Request);
          send(ClientSocket, Message.c_str(), Message.length(), 0);

          ZeroMemory(buf, 4096);
          RecvCount = recv(ClientSocket, buf, 4096, 0);
          Request = CRLFtoLF((std::string)buf);
        }
        closesocket(ClientSocket);

        return;
      }
    );
  }


  WSACleanup();
  return 0;
}


#endif
