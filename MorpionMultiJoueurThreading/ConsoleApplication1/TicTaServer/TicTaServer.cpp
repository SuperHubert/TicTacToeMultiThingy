#include "TicTaServer.h"

#include <iostream>
#include <cstring>


void TicTacServer::InitServer()
{
    if ((serverSocket = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        std::cout << "socket creation failed" << std::endl;
        return;
    }
    
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);
    
    if (bind(serverSocket, (const sockaddr*)&serverAddr, sizeof(serverAddr)) == -1)
    {
        std::cout << "bind failed" << std::endl;
        return;
    }

    std::cout << "Server initialized. Waiting for clients..." << std::endl;
}

void TicTacServer::Send(const char* message, sockaddr_in& clientAddr)
{
    if (sendto(serverSocket, message, strlen(message), 0, (const sockaddr*)&clientAddr, sizeof(clientAddr)) == -1)
    {
        std::cout << "sendto failed" << std::endl;
    }
}

void TicTacServer::Receive(char* buffer, sockaddr_in& clientAddr)
{
    int len = sizeof(clientAddr);
    memset(buffer, 0, BUFFER_SIZE);
    if (recvfrom(serverSocket, buffer, BUFFER_SIZE, 0, (sockaddr*)&clientAddr, &len) == -1)
    {
        std::cout << "recvfrom failed" << std::endl;
    }
}

void TicTacServer::ProcessRequest(char* buffer, sockaddr_in& clientAddr)
{
    int position = buffer[0] - '0';
    char symbol = buffer[1];
    UpdateBoard(position, symbol);
    PrintBoard();
    int result = CheckWin();
    if (result == 1)
    {
        Send("You win!", clientAddr);
        EndGame();
    }
    else if (result == 2)
    {
        Send("You lose!", clientAddr);
        EndGame();
    }
    else if (IsBoardFull())
    {
        Send("It's a draw!", clientAddr);
        EndGame();
    }
}

void TicTacServer::UpdateBoard(int position, char symbol)
{
    board[position] = symbol;
}

void TicTacServer::PrintBoard()
{
    return;
    std::cout << "Board:" << std::endl;
    for (int i = 0; i < 9; i++)
    {
        std::cout << board[i] << " ";
        if ((i + 1) % 3 == 0)
        {
            std::cout << std::endl;
        }
    }
}

int TicTacServer::CheckWin()
{
    // Check rows
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == board[i + 1] && board[i + 1] == board[i + 2] && board[i] != 0)
            return (board[0] == 'X') ? 1 : 2;
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != 0)
            return (board[0] == 'X') ? 1 : 2;
    }

    // Check diagonals
    if (board[0] == board[4] && board[4] == board[8] && board[0] != 0)
    {
        return (board[0] == 'X') ? 1 : 2;
    }
    return -1;
}

void TicTacServer::ResetBoard()
{
    for (int i = 0; i < 9; i++)
        board[i] = 0;
}

void TicTacServer::StartGame()
{
    ResetBoard();
}

void TicTacServer::EndGame()
{
    // :) je sais pas ce que l'on fait peut etre attendre
}

void TicTacServer::CloseServer()
{
    closesocket(serverSocket);
    WSACleanup();
}

void TicTacServer::Run()
{
    char buffer[BUFFER_SIZE] = {0};
    sockaddr_in clientAddr = {0};
    StartGame();
    while (true)
    {
        Receive(buffer, clientAddr);
        ProcessRequest(buffer, clientAddr);
    }
}

bool TicTacServer::IsBoardFull()
{
    for (int i = 0; i < 9; i++)
        if (board[i] == 0) return false;
    return true;
}

int main()
{
    TicTacServer server;
    server.InitServer();
    // Other game logic can go here
    return 0;
}
