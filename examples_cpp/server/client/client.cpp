#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <clocale>
#include <sys/types.h>
#include <memory.h>
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
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
int betriebssystem = 2;
#endif
#define BUF_SIZE 64
#define SERVER_HOST "localhost"
#define SERVER_PORT 1234
#define CLIENT_PORT 1235
#define MSG "Client version 1.0\n"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int ans_len;
    char buffer[BUF_SIZE];
    struct hostent *h;
    struct sockaddr_in client, server;

    const auto sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&client, 0, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = htons(CLIENT_PORT);

    if (bind(sock, (struct sockaddr*)&client, sizeof(client)) == -1) {
        perror("binding failed");
        _close(static_cast<int>(sock));
        exit(EXIT_FAILURE);
    }

    h = gethostbyname(SERVER_HOST);
    if (h == nullptr) {
        perror("gethostbyname failed");
        _close(static_cast<int>(sock));
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    memcpy(&server.sin_addr, h->h_addr, h->h_length);
    server.sin_port = htons(SERVER_PORT);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == -1) {
        perror("connection failed");
        _close(static_cast<int>(sock));
        exit(EXIT_FAILURE);
    }

    ans_len = recv(sock, buffer, BUF_SIZE, 0);
    if (ans_len == -1) {
        perror("recv failed");
        _close(static_cast<int>(sock));
        exit(EXIT_FAILURE);
    }

    _write(1, buffer, ans_len);

    if (send(sock, MSG, static_cast<int>(strlen(MSG)), 0) == -1) {
        perror("send failed");
        _close(static_cast<int>(sock));
        exit(EXIT_FAILURE);
    }

    _close(static_cast<int>(sock));
    return 0;

}

