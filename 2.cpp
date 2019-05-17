#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32")
#define PORT 9999
#define IP "10.10.14.64"
using namespace std;

int main() {
	WSADATA wsdata;
	WSAStartup(MAKEWORD(2, 2), &wsdata);

	SOCKET Sock = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addr;
	ZeroMemory(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(IP);
	addr.sin_port = htons(PORT);

	bind(Sock, (SOCKADDR*)& addr, sizeof(addr));

	char str[20];

	recv(Sock, str, sizeof(str), 0);
	cout << "수신 데이터 : " << str << endl;
	closesocket(Sock);

	WSACleanup();
	return 0;
}
