#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

void gotoxy(int x, int y){
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1, y-1};
	hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition (hConsoleOutput, Cursor_an_Pos); 
}
void ReSizeConsole (int width, int height){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect (console, &r);
	MoveWindow (console, r.left, r.top, width, height, TRUE);
}
void TextColor(int x){
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
