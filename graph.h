#ifndef _GRAPH_H // 1 man hinh dai 210, rong 52
#define _GRAPH_H

#include"mylib.h"
#include <iostream>
#include <stdio.h>
#include <windows.h> 
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

//============================VE KHUNG=============================
void VeKhung() // 160:45 (Ti le 16:9)
{
	//gotoxy(1,1);
	gotoxy(24,3);
	for (int i = 1; i <= 45; i++)
	{
		for (int j = 1; j <= 160; j++)
		{
			if (i == 1)
			{
				if (j == 1 || j == 160)
				{
					cout << " ";
				//	Sleep(1000);
				}
				else
				{
					cout << "_";
				}
			}
			else
			{
				if (i == 45)
				{
					if (j == 1 || j == 160)
					{
						cout << "|";
					//	Sleep(1000);
					}
					else
					{
						cout << "_";
					}
				}
				else
				{
					if (j == 1 || j == 160)
					{
						cout << "|";
					//	Sleep(1000);
					}
					else
					{
						cout << " ";
					}
				}
			}
		}
		gotoxy(24,3+i);
//		cout << endl;
	}
}
//=================================HAM DOI MAU====================================
void ChangeColor(int k)
{
	HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, k);
}
//============================MENU CHINH==============================
int MainMenu()
{
//	char b = 26;
	char a; // Lay ky tu nhap tu ban phim
	int i = 0;
	gotoxy(0,0);
	cout << "->";
	gotoxy(3,0);
	ChangeColor(240);
	cout << "Them may bay";
	ChangeColor(15);
	gotoxy(3,2);
	cout << "Xoa may bay";
	gotoxy(3,4);
	cout << "Hieu chinh may bay";
	gotoxy(3,6);
	cout << "In danh sach may bay";
	AnConTro();
	a = GetKeyboard();
	while (a != 27 && a != 13)
	{
		if (a == 72)
		{
			if (i >= 2)
			{
				i = i - 2;
			}
			else
			{
				i = 6;
			}
		}
		if (a == 80)
		{
			if (i <= 4)
			{
				i = i + 2;
			}
			else
			{
				i = 0;
			}
		}
		switch(i)
		{
			case 0 :
			{
				gotoxy(0,i);
				cout << "->";
				gotoxy(3,i);
				ChangeColor(240);
				cout << "Them may bay";
				ChangeColor(15);
				gotoxy(0,2);
				cout << "   Xoa may bay";
				gotoxy(0,4);
				cout << "   Hieu chinh may bay";
				gotoxy(0,6);
				cout << "   In danh sach may bay";
				ChangeColor(15); // Tra lai mau mac dinh
			//	gotoxy(0,4); cout << i;
				AnConTro();
				break;
			}
			case 2:
			{
				gotoxy(0,0);
				cout << "   Them may bay";
				gotoxy(0,i);
				cout << "->";
				ChangeColor(240);
				gotoxy(3,i);
				cout << "Xoa may bay";
				ChangeColor(15);
				gotoxy(0,4);
				cout << "   Hieu chinh may bay";
				gotoxy(0,6);
				cout << "   In danh sach may bay";
				ChangeColor(15); // Tra lai mau mac dinh
			//	gotoxy(0,4); cout << i;
				AnConTro();
				break;
			}
			case 4:
			{
				gotoxy(0,0);
				cout << "   Them may bay";
				gotoxy(0,2);
				cout << "   Xoa may bay";
				gotoxy(0,i);
				cout << "->";
				ChangeColor(240);
				gotoxy(3,i);
				cout << "Hieu chinh may bay";
				ChangeColor(15);
				gotoxy(0,6);
				cout << "   In danh sach may bay";
				ChangeColor(15); // Tra lai mau mac dinh
			//	gotoxy(0,4); cout << i;
				AnConTro();
				break;
			}
			case 6:
				{
					gotoxy(0,0);
					cout << "   Them may bay";
					gotoxy(0,2);
					cout << "   Xoa may bay";
					gotoxy(0,4);
					cout << "   Hieu chinh may bay";
					gotoxy(0,i);
					cout << "->";
					ChangeColor(240);
					gotoxy(3,i);
					cout << "In danh sach may bay";
					ChangeColor(15); // Tra lai mau mac dinh
				//	gotoxy(0,4); cout << i;
					AnConTro();
					break;
				}
		}
		a = GetKeyboard();
	//	gotoxy(0,4); cout << int(a);
	}
	if (a == 27)
	{
		return -1;
	}
	return i;
}

#endif
