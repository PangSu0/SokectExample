#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Chatting.h"
#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32")

using namespace std;
DWORD WINAPI SendThread(LPVOID lpData);

#define BUFFERSIZE 1024
string name;

Chatting Chatting::StaticChatting;

int main()
{
	// ���� ���̺귯�� �ʱ�ȭ
	WSADATA wsaData;
	int token = WSAStartup(WINSOCK_VERSION, &wsaData);
	char PORT[5];
	char IP[15];
	// ���� ����
	SOCKET socket_client = socket(AF_INET, SOCK_STREAM, 0);

	cout << "����� IP �ּ� : " << endl;
	cin >> IP;

	cout << "����� ��Ʈ ��ȣ : " << endl;
	cin >> PORT;

	cout << "�̸��� �Է��ϼ���. " << endl;
	cin >> name;

	
	// ���� �ּ� ����
	SOCKADDR_IN servAddr = { 0 };
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(IP);
	servAddr.sin_port = htons(atoi(PORT)); // ��Ʈ

	// ���� ����
	if (connect(socket_client, (struct sockaddr*) & servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		closesocket(socket_client);
		printf("������ ���� �Ҽ� �����ϴ�.");
		return SOCKET_ERROR;
	}

	DWORD dwTmp;

	CreateThread(NULL, 0, SendThread, (LPVOID)socket_client, 0, NULL);
	// ���� ���
	Chatting::StaticChatting.DrawWindow();
	Gotoxy(22, 4);
	// ���� & ���� ��Ǫ
	while (true)
	{
		
		char buffer[1024] = { 0 };
		int len = recv(socket_client, buffer, sizeof(buffer), 0);
		if (len <= 0)
		{
			printf("���� ����.");
			break;
		}
		// �޽��� ���
		string str = buffer;
		Chatting::StaticChatting.Chat(str);
		Chatting::StaticChatting.DrawWindow();
		Gotoxy(22, 4);
	}
	//���� ����
	closesocket(socket_client);
	return 0;
}


DWORD WINAPI SendThread(LPVOID lpData)
{
	SOCKET socket_client = (SOCKET)lpData;
	while (1)
	{
		DWORD dwTmp;
		char text[BUFFERSIZE] = { 0 };
		ReadFile(GetStdHandle(STD_INPUT_HANDLE), text, 1024, &dwTmp, NULL);
		string outputText = name + " : " + text;
		send(socket_client, outputText.c_str(), outputText.length(), 0);
		string str = outputText;
		Chatting::StaticChatting.Chat(str);
		Chatting::StaticChatting.DrawWindow();
		Gotoxy(22, 4);
	}
	
	return 0;
}
