#ifndef TICTASERVER_H
#define TICTASERVER_H

#include <WinSock2.h>
#include <iostream>
#include <cstring>

#define PORT 8080
#define BUFFER_SIZE 1024

class TicTacServer
{
public:
    void InitServer();
    void Send(const char* message, sockaddr_in& clientAddr);
    void Receive(char* buffer, sockaddr_in& clientAddr);
    void ProcessRequest(char* buffer, sockaddr_in& clientAddr);
    void UpdateBoard(int position, char symbol);
    void PrintBoard();
    int CheckWin();
    bool IsBoardFull();
    void ResetBoard();
    void StartGame();
    void EndGame();
    void CloseServer();
    void Run();

private:
    char board[9] = {0};
    int serverSocket = 0;
    sockaddr_in serverAddr = {0};
};


#endif // TICTASERVER_H
