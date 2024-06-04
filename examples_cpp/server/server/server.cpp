#ifdef _WIN32
//For Windows
int betriebssystem = 1;
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <ws2def.h>
#pragma comment(lib, "Ws2_32.lib")
#include <windows.h>
#include <io.h>
#include <iostream>
#endif
#define SERVER_PORT 1234
#define BUF_SIZE 64
#define MSG_TI_SEND "Version"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    SOCKET sock1, sock2;
    int ans_len, total = 0;
    char buffer[BUF_SIZE];
    struct sockaddr_in sin;
    struct sockaddr client;
    sock1 = socket(AF_INET, SOCK_STREAM, 0);
    memset((char*)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = SERVER_PORT;
    bind(sock1, (struct sockaddr*)&sin, sizeof(sin));
    wcout << L"Server running..." << endl;
    listen(sock1, 3);
    while (1)
    {
        ans_len = sizeof(client);
        sock2 = accept(sock1, &client, &ans_len);
        _write(static_cast<int>(sock2), MSG_TI_SEND, sizeof(MSG_TI_SEND));
        total += 1;
        ans_len = _read(static_cast<int>(sock2), buffer, BUF_SIZE);
        _write(1, buffer, BUF_SIZE);
        wcout << L"Client number: " << total << endl;
        shutdown(sock2, 0);
        _close(static_cast<int>(sock2));
    }
    return 0;
}

