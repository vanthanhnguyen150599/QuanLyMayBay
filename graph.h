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
	char doc = 186;
	char ngang = 205;
	char traitren = 201;
	char traiduoi = 200;
	char phaitren = 187;
	char phaiduoi = 188;
	gotoxy(24,3);
	for (int i = 1; i <= 45; i++)
	{
		for (int j = 1; j <= 160; j++)
		{
			if (i == 1 || i == 45)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 160)
						{
							cout << phaitren;
						}
						else
						{
							cout << ngang;
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;
					}
					else
					{
						if (j == 160)
						{
							cout << phaiduoi;
						}
						else
						{
							cout << ngang;
						}
					}
				}
			}
			else
			{
				if (j == 1 || j == 160)
				{
					cout << doc;
				}
				else
				{
					cout << " ";
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
	int kytu;
	char a; // Lay ky tu nhap tu ban phim
	int i = 0;
	gotoxy(0,0);
	cout << "->";
	gotoxy(3,0);
	ChangeColor(240);
	cout << "THEM MAY BAY";
	ChangeColor(15);
	gotoxy(3,2);
	cout << "XOA MAY BAY";
	gotoxy(3,4);
	cout << "HIEU CHINH MAY BAY";
	gotoxy(3,6);
	cout << "IN DANH SACH MAY BAY";
	AnConTro();
	a = getch();
	if (a == -32 || a == 0)
	{
		kytu = 0;
		a = getch();
	}
	else
	{
		kytu = 1;
	}
	while (a != 27 && a != 13)
	{
		if (a == 72 && !kytu)
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
		if (a == 80 && !kytu)
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
				cout << "THEM MAY BAY";
				ChangeColor(15);
				gotoxy(0,2);
				cout << "   XOA MAY BAY";
				gotoxy(0,4);
				cout << "   HIEU CHINH MAY BAY";
				gotoxy(0,6);
				cout << "   IN DANH SACH MAY BAY";
				ChangeColor(15); // Tra lai mau mac dinh
			//	gotoxy(0,4); cout << i;
				AnConTro();
				break;
			}
			case 2:
			{
				gotoxy(0,0);
				cout << "   THEM MAY BAY";
				gotoxy(0,i);
				cout << "->";
				ChangeColor(240);
				gotoxy(3,i);
				cout << "XOA MAY BAY";
				ChangeColor(15);
				gotoxy(0,4);
				cout << "   HIEU CHINH MAY BAY";
				gotoxy(0,6);
				cout << "   IN DANH SACH MAY BAY";
				ChangeColor(15); // Tra lai mau mac dinh
			//	gotoxy(0,4); cout << i;
				AnConTro();
				break;
			}
			case 4:
			{
				gotoxy(0,0);
				cout << "   THEM MAY BAY";
				gotoxy(0,2);
				cout << "   XOA MAY BAY";
				gotoxy(0,i);
				cout << "->";
				ChangeColor(240);
				gotoxy(3,i);
				cout << "HIEU CHINH MAY BAY";
				ChangeColor(15);
				gotoxy(0,6);
				cout << "   IN DANH SACH MAY BAY";
				ChangeColor(15); // Tra lai mau mac dinh
			//	gotoxy(0,4); cout << i;
				AnConTro();
				break;
			}
			case 6:
				{
					gotoxy(0,0);
					cout << "   THEM MAY BAY";
					gotoxy(0,2);
					cout << "   XOA MAY BAY";
					gotoxy(0,4);
					cout << "   HIEU CHINH MAY BAY";
					gotoxy(0,i);
					cout << "->";
					ChangeColor(240);
					gotoxy(3,i);
					cout << "IN DANH SACH MAY BAY";
					ChangeColor(15); // Tra lai mau mac dinh
				//	gotoxy(0,4); cout << i;
					AnConTro();
					break;
				}
		}
		a = getch();
		if (a == -32 || a == 0)
		{
			kytu = 0;
			a = getch();
		}
		else
		{
			kytu = 1;
		}
	//	gotoxy(0,4); cout << int(a);
	}
	if (a == 27)
	{
		return -1;
	}
	return i;
}
//==============================DANG NHAP=============================
void DangNhap ()
{
	//=======================FRONT END===============================
	gotoxy(104,19);
	cout << "DANG NHAP";
	char doc = 186;
	char ngang = 205;
	char traitren = 201;
	char traiduoi = 200;
	char phaitren = 187;
	char phaiduoi = 188;
	gotoxy(87,21);
	for (int i = 1; i <= 10; i++) // Ke khung ngoai
	{
		for (int j = 1; j <= 40; j++)
		{
			if (i == 1 || i == 10)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 40)
						{
							cout << phaitren;
						}
						else
						{
							cout << ngang;
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;	
					}
					else
					{
						if (j == 40)
						{
							cout << phaiduoi;
						}
						else
						{
							cout << ngang;
						}
					}	
				}
			}
			else
			{
				if (j == 1 || j == 40)
				{
					cout << doc;
				}
				else
				{
					cout << " ";
				}
			}
		}
		gotoxy(87,21+i);
	}
	traitren = 218;
	phaitren = 191;
	traiduoi = 192;
	phaiduoi = 217;
	ngang = 196;
	doc = 179;
	gotoxy(89,21+3);
	cout << "Ten dang nhap "; // 14 kytu
	gotoxy(89+14,2+21);
//	gotoxy(0,15);
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 22; j++)
		{
			if (i == 1 || i == 3)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 22)
						{
							cout << phaitren;
						}
						else
						{
							cout << ngang;
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;	
					}
					else
					{
						if (j == 22)
						{
							cout << phaiduoi;
						}
						else
						{
							cout << ngang;
						}
					}	
				}
			}
			else
			{
				if (j == 1 || j == 22)
				{
					cout << doc;
				}
				else
				{
					cout << " ";
				}
			}
		}
	//	cout << endl;
		gotoxy(14+89,i+2+21);
	} 
	gotoxy(89,21+6);
	cout << "Mat khau "; // 9 kytu
	gotoxy(89+14,5+21);
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 22; j++)
		{
			if (i == 1 || i == 3)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 22)
						{
							cout << phaitren;
						}
						else
						{
							cout << ngang;
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;	
					}
					else
					{
						if (j == 22)
						{
							cout << phaiduoi;
						}
						else
						{
							cout << ngang;
						}
					}	
				}
			}
			else
			{
				if (j == 1 || j == 22)
				{
					cout << doc;
				}
				else
				{
					cout << " ";
				}
			}
		}
	//	cout << endl;
		gotoxy(14+89,21+i+5);
	}
	//=======================BACK END=================================
	char a; // Bat phim
	bool kytu;
	int line = 0;
	string user = ""; // Luu ten nguoi dung
	string pass = ""; // Luu password
//	cout << "Ten dang nhap: " << endl;
//	cout << "Mat khau: ";
//	gotoxy(15,line);
	gotoxy(89+16,21+3);
	a = getch();
	if (a == -32 || a == 0)
	{
		kytu = 0;
		a = getch();
	}
	else
	{
		kytu = 1;
	}
	while (1)
	{
		while (a != 13)
		{
			if (((a == 72 || a == 80) && !kytu)||(a == 9 && kytu))
			{
				if (line) // line = 1
				{
					line--; 
					gotoxy(89+16+user.length(),21+3);
				}
				else // line = 0
				{
					line++;
					gotoxy(89+16 + pass.length(),21+6);
				}
			}
			if (line)
			{
				gotoxy(89+16 + pass.length(),21+6); //line = 1
			}
			else
			{
			 	gotoxy(89+16+user.length(),21+3);//line = 0
			}
			if (a == 8 && kytu) // Backspace
			{
				if (!line)
				{
					if (user.length() == 0)
					{
						int hoanhdo = wherex();
						int tungdo = wherey();
						cout << "Khong the xoa";
						AnConTro();
						Sleep(200);
						gotoxy(hoanhdo,tungdo);
						cout << "              ";
						gotoxy(hoanhdo,tungdo);
						HienConTro();
					}
					else
					{
						int hoanhdo = wherex();
						int tungdo = wherey();
						gotoxy(hoanhdo - 1, tungdo);
						cout << " ";
						gotoxy(hoanhdo - 1, tungdo);
						//===Xu ly chuoi===========
						user.erase(user.end() - 1, user.end());
					}
				}
				else
				{
					if (pass.length() == 0)
					{
						int hoanhdo = wherex();
						int tungdo = wherey();
						cout << "Khong the xoa";
						AnConTro();
						Sleep(200);
						gotoxy(hoanhdo,tungdo);
						cout << "             ";
						gotoxy(hoanhdo,tungdo);
						HienConTro();
					}
					else
					{
						int hoanhdo = wherex();
						int tungdo = wherey();
						gotoxy(hoanhdo - 1, tungdo);
						cout << " ";
						gotoxy(hoanhdo - 1, tungdo);
						//===Xu ly chuoi===========
						pass.erase(pass.end() - 1, pass.end());
					}
				}
			}
			if  (((a >= 48 && a <= 57)||(a >= 65 && a <= 90)||(a >= 97 && a <= 122)) && kytu) // kytu
			{
				if (!line)
				{
					if (user.length() <  15)
					{
						cout << a;
						user = user + a;
					}
					else
					{
						gotoxy(15+90,3+21);
						cout << "Khong qua 15 ky tu";
						AnConTro();
						Sleep(600);
						gotoxy(15+90,3+21);
						cout << "                  ";
						gotoxy(15+90,3+21);
						cout << user;
						HienConTro();
					}
				}
				else
				{
					if (pass.length() < 15 )
					{
						cout << "*";
						pass = pass + a;
					}
					else
					{
						gotoxy(15+90,6+21);
						cout << "Khong qua 15 ky tu";
						AnConTro();
						Sleep(600);
						gotoxy(15+90,6+21);
						cout << "                  ";
						gotoxy(15+90,6+21);
						for (int i = 1; i <= pass.length(); i++)
						{
							cout <<"*";
						}
						HienConTro();
					}
				}
			}
			a = getch();
			if (a == -32 || a == 0)
			{
				kytu = 0;
				a = getch();
			}
			else
			{
				kytu = 1;
			}
		}
		if (user.length() == 0 || pass.length() == 0)
		{
			gotoxy(3+87,8+21);
			cout << "Dien ten dang nhap hoac mat khau";
			AnConTro();
			Sleep(500);
			gotoxy(3+87,8+21);
			cout << "                                 ";
			HienConTro();
			if (user.length() == 0)
			{
				gotoxy(89+16,21+3); //  Quay lai user
				line = 0;
			}
			else
			{
				gotoxy(89+16,21+6); // Quay lai pass
				line = 1;
			}
		}
		else // Co user va pass
		{
			if (user == "admin" && pass == "admin")
			{
				break;
			}
			else
			{
				gotoxy(3+87,8+21);
				cout << "Dang nhap that bai. Xin thu lai";
				AnConTro();
				Sleep(500);
				user = ""; // clear
				pass = ""; // clear
				gotoxy(3+87,8+21);
				cout << "                                ";
				gotoxy(89+16,21+3);
				cout << "                 "; // Clear user
				gotoxy(89+16,21+6);
				cout << "                 "; // Clear pass
				line = 0;
				gotoxy(89+16+user.length(),21+3);
				HienConTro();
			}
		}
		a = getch();
		if (a == -32 || a == 0)
		{
			kytu = 0;
			a = getch();
		}
		else
		{
			kytu = 1;
		}
	}
	gotoxy(10+87,8+21);
	cout << "Dang nhap thanh cong";
	AnConTro();
	Sleep(500);
	HienConTro();
//	gotoxy(0,3);
//	cout << "Dang nhap thanh cong" << endl;
//	Sleep(500);
}
// ========================== KHUNG MAY BAY ======================================
#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(int x, int y) // Di chuyen toa do con tro trong he toa do De-cat
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
int main()
{
	char ngangngoai = 205;
	char docngoai = 186;
	char traitren = 201;
	char phaitren = 187;
	char traiduoi = 200;
	char phaiduoi = 188;
	char ngangtrong = 196;
	char doctrong = 179;
	char ngangxuong = 209;
	char nganglen = 207;
	char docphai = 199;
	char doctrai = 182;
	char ngatu = 197;
	for (int i = 1; i <= 33; i++)
	{
		for (int j = 1; j <= 90; j++)
		{
			if (i == 1 || i == 33)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 90)
						{
							cout << phaitren;
						}
						else
						{
							if (j%30 == 0)
							{
								cout << ngangxuong;
							}
							else
							{
								cout << ngangngoai;
							}
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;
					}
					else
					{
						if (j == 90)
						{
							cout << phaiduoi;
						}
						else
						{
							if (j%30 == 0)
							{
								cout << nganglen;
							}
							else
							{
								cout << ngangngoai;
							}
						}
					}
				}
			}
			else // khac dong dau va cuoi
			{
					if (i%3 == 0)
					{
						if (j == 1)
						{
							cout << docphai;
						}
						else
						{
							if (j == 90)
							{
								cout << doctrai;
							}
							else
							{
								if (j%30 == 0)
								{
									cout << ngatu;
								}
								else
								{
									cout << ngangtrong;
								}
							}
						}
					}
					else // i%3 == 2
					{
						if (j == 1 || j % 30 == 0)
						{
							if (j == 1 || j == 90)
							{
								cout << docngoai;
							}
							else
							{
								cout << doctrong;
							}
						}
						else
						cout << " ";
					}
			}
		}
		cout << endl;
	}
	gotoxy(11,1);
	cout << "So Hieu";
	gotoxy(41,1);
	cout << "Loai";
	gotoxy(71,1);
	cout << "So Cho";
}
// ============================================= KHUNG CHUYEN BAY ===============================
#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(int x, int y) // Di chuyen toa do con tro trong he toa do De-cat
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
int main()
{
	char ngangngoai = 205;
	char docngoai = 186;
	char traitren = 201;
	char phaitren = 187;
	char traiduoi = 200;
	char phaiduoi = 188;
	char ngangtrong = 196;
	char doctrong = 179;
	char ngangxuong = 209;
	char nganglen = 207;
	char docphai = 199;
	char doctrai = 182;
	char ngatu = 197;
	for (int i = 1; i <= 33; i++)
	{
		for (int j = 1; j <= 90; j++)
		{
			if (i == 1 || i == 33)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 90)
						{
							cout << phaitren;
						}
						else
						{
							if (j%30 == 0)
							{
								cout << ngangxuong;
							}
							else
							{
								cout << ngangngoai;
							}
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;
					}
					else
					{
						if (j == 90)
						{
							cout << phaiduoi;
						}
						else
						{
							if (j%30 == 0)
							{
								cout << nganglen;
							}
							else
							{
								cout << ngangngoai;
							}
						}
					}
				}
			}
			else // khac dong dau va cuoi
			{
					if (i%3 == 0)
					{
						if (j == 1)
						{
							cout << docphai;
						}
						else
						{
							if (j == 90)
							{
								cout << doctrai;
							}
							else
							{
								if (j%30 == 0)
								{
									cout << ngatu;
								}
								else
								{
									cout << ngangtrong;
								}
							}
						}
					}
					else // i%3 == 2
					{
						if (j == 1 || j % 30 == 0)
						{
							if (j == 1 || j == 90)
							{
								cout << docngoai;
							}
							else
							{
								cout << doctrong;
							}
						}
						else
						cout << " ";
					}
			}
		}
		cout << endl;
	}
	gotoxy(11,1);
	cout << "So Hieu";
	gotoxy(37,1);
	cout << "Khoi hanh luc";
	gotoxy(70,1);
	cout << "Trang thai";
}

#endif
