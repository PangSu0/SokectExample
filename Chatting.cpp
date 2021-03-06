#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include "Chatting.h"
using namespace std;

enum color { CYAN = 11, WHITE = 15 };

void SetColor(color col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}
void Gotoxy(int y, int x)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Chatting::Chatting()
{
	chattingLogCount = 0;
}

void Chatting::DrawWindow()
{
	system("cls");
	SetColor(CYAN);
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("早                                                                                        早\n");
	printf("朵收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收此\n");
	printf("早                                                                    早  <message input>  早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收旭\n");
	DrawChattingLog();
}
void Chatting::DrawChattingLog()
{
	SetColor(WHITE);
	for (int i = 0; i < 20; i++)
	{
		Gotoxy(1 + i, 4);
		cout << chattingLog[chattingLogCount];
		chattingLogCount++;
		if (chattingLogCount >= 20)
			chattingLogCount = 0;
	}
}

void Chatting::Chat(string str)
{
	chattingLog[chattingLogCount++] = str;
	if (chattingLogCount >= 20)
		chattingLogCount = 0;
}