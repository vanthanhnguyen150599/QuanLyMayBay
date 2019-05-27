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
// ========================= CAC HAM XU LY CUA MENU =====================
void XoayLen (string *Menu)
{
	for (int i = 0; i < 11; i++)
	{
		Menu[i] = Menu[i+1];
	}
/*	Menu[0] = Menu[1]; // Menu[0] vai tro la o nho tam
	Menu[1] = Menu[2];
	Menu[2] = Menu[3];
	Menu[3] = Menu[4];
	Menu[4] = Menu[5]; */
	Menu[11] = Menu[0];
}
void XoayXuong(string *Menu)
{
	Menu[0] = Menu[11]; // Menu[0] vai tro la bien tam
	for (int i = 11; i > 0; i--)
	{
		Menu[i] = Menu[i-1];
	}
	/*
	Menu[5] = Menu[4];
	Menu[4] = Menu[3];
	Menu[3] = Menu[2];
	Menu[2] = Menu[1];
	Menu[1] = Menu[0];  */
}
//============================MENU CHINH==============================
int MainMenu()
{
	string *Menu = new string[12];
	Menu[0] = ""; // bien tam
	Menu[1] = "1.THEM MAY BAY";
	Menu[2] = "2.XOA MAY BAY";
	Menu[3] = "3.HIEU CHINH MAY BAY";
	Menu[4] = "4.LAP CHUYEN BAY MOI";
	Menu[5] = "5.HIEU CHINH CHUYEN BAY";
	Menu[6] = "6.HUY CHUYEN BAY";
	Menu[7] = "7.DAT VE";
	Menu[8] = "8.HUY VE";
	Menu[9] = "9.IN DANH SACH HANH KHACH THUOC CHUYEN BAY";
	Menu[10] = "10.IN DANH SACH GHE CON TRONG CUA CHUYEN BAY";
	Menu[11] = "11.THONG KE LUOT THUC HIEN";
	AnConTro();
	for (int i = 1; i <= 11; i++)
	{
		if (i < 6)
		{
			ChangeColor(8);
			for (int j = 1; j <= i-1; j++)
			{
				cout << "  ";
			}
			cout << Menu[i] << endl << endl;
		}
		if (i == 6)
		{
			ChangeColor(15);
			cout << ">> ";
			for(int j = 3; j <= i -1; j++)
			{
				cout << "  ";
			}
			cout << Menu[6] << endl << endl;
		}
		if (i > 6)
		{
			ChangeColor(8);
			for (int j = 1; j <= 10-2*(i-6); j++)
			{
				cout << " ";
			}
			cout << Menu[i] << endl << endl;
		}
	}
	int i = 6;
	char x = getch();
	bool kytu;
	if (x == -32 || x == 0)
	{
		x = getch();
		kytu = 0;
	}
	else
	{
		kytu = 1;
	}
	while (x != 27 && x != 13) // Enter or Esc
	{
		if (x == 72 && !kytu) // Up
		{
			if (i != 1)
			{
				i--;
			}
			else
			{
				i = 11;
			}
			XoayXuong(Menu);
			gotoxy(0,0);
			for (int i = 1; i <= 11; i++) // Xu ly hinh anh
			{
				if (i < 6)
				{
					ChangeColor(8);
					cout << "                                                         ";
					gotoxy(0,wherey());
					for (int j = 1; j <= i-1; j++)
					{
						cout << "  ";
					}
					cout << Menu[i] << endl << endl;
				}
				if (i == 6)
				{
					ChangeColor(15);
					cout << "                                                         ";
					gotoxy(0,wherey());
					cout << ">> ";
					for(int j = 3; j <= i -1; j++)
					{
						cout << "  ";
					}
					cout << Menu[6] << endl << endl;
				}
				if (i > 6)
				{
					ChangeColor(8);
					cout << "                                                         ";
					gotoxy(0,wherey());
					for (int j = 1; j <= 10-2*(i-6); j++)
					{
						cout << " ";
					}
					cout << Menu[i] << endl << endl;
				}
			}
		//	gotoxy(0,60);
		//	cout << "Phim Up voi char la " << int(x);
		}
		if (x == 80 && !kytu) // Down
		{
			if (i != 11)
			{
				i++;
			}
			else
			{
				i = 1;
			}
			XoayLen(Menu);
			gotoxy(0,0);
			for (int i = 1; i <= 11; i++) // Xu ly hinh anh
			{
				if (i < 6)
				{
					ChangeColor(8);
					cout << "                                                         ";
					gotoxy(0,wherey());
					for (int j = 1; j <= i-1; j++)
					{
						cout << "  ";
					}
					cout << Menu[i] << endl << endl;
				}
				if (i == 6)
				{
					ChangeColor(15);
					cout << "                                                         ";
					gotoxy(0,wherey());
					cout << ">> ";
					for(int j = 3; j <= i -1; j++)
					{
						cout << "  ";
					}
					cout << Menu[6] << endl << endl;
				}
				if (i > 6)
				{
					ChangeColor(8);
					cout << "                                                         ";
					gotoxy(0,wherey());
					for (int j = 1; j <= 10-2*(i-6); j++)
					{
						cout << " ";
					}
					cout << Menu[i] << endl << endl;
				}
			}
		//	gotoxy(0,0);
		//	cout << "Phim Down voi char la " << int(x);
		}
		x = getch();
		int kytu;
		if (x == -32 || x == 0)
		{
			x = getch();
			kytu = 0;
		}
		else
		{
			kytu = 1;
		}
	}
	if (x == 13)
	{
		gotoxy(0,30);
		return i;
	}
	if (x == 27)
	{
		gotoxy(0,30);
		return 0;
	}
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
void KhungMayBay()
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
	for (int i = 1; i <= 23; i++)
	{
		for (int j = 1; j <= 60; j++)
		{
			if (i == 1 || i == 23)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 60)
						{
							cout << phaitren;
						}
						else
						{
							if (j%20 == 0)
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
						if (j == 60)
						{
							cout << phaiduoi;
						}
						else
						{
							if (j%20 == 0)
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
					if (i%2 == 1)
					{
						if (j == 1)
						{
							cout << docphai;
						}
						else
						{
							if (j == 60)
							{
								cout << doctrai;
							}
							else
							{
								if (j%20 == 0)
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
					else // i%2 == 0
					{
						if (j == 1 || j % 20 == 0)
						{
							if (j == 1 || j == 60)
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
	gotoxy(7,1);
	cout << "So Hieu";
	gotoxy(28,1);
	cout << "Loai";
	gotoxy(47,1);
	cout << "So Cho";
}
// ============================================= KHUNG CHUYEN BAY ===============================
void KhungChuyenBay()
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
	for (int i = 1; i <= 23; i++)
	{
		for (int j = 1; j <= 120; j++)
		{
			if (i == 1 || i == 23)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == 120)
						{
							cout << phaitren;
						}
						else
						{
							if (j%20 == 0)
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
						if (j == 120)
						{
							cout << phaiduoi;
						}
						else
						{
							if (j%20 == 0)
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
					if (i%2 == 1)
					{
						if (j == 1)
						{
							cout << docphai;
						}
						else
						{
							if (j == 120)
							{
								cout << doctrai;
							}
							else
							{
								if (j%20 == 0)
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
					else // i%2 == 0
					{
						if (j == 1 || j % 20 == 0)
						{
							if (j == 1 || j == 120)
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
	gotoxy(6,1);
	cout << "Ma Chuyen";
	gotoxy(24,1);
	cout << "Khoi hanh luc";
	gotoxy(49,1);
	cout << "Tu";
	gotoxy(68,1);
	cout << "Den";
	gotoxy(85,1);
	cout << "Trang Thai";
	gotoxy(105,1);
	cout << "Ma May bay";
}
// ======================= HANG GHE =========================================
void InKhungGhe (int SoLuong)
{
	char traitren = 218;
	char phaitren = 191;
	char phaiduoi = 217;
	char traiduoi = 192;
	char ngang = 196;
	char doc = 179;
	AnConTro();
	gotoxy(0,0);
	if (SoLuong%6 == 0)
	{
		for (int i = 1; i <= 32; i++)
		{
			for (int j = 1; j <= 2*(SoLuong/6 - 1) + SoLuong + 4; j++)
			{
				if (i == 1 ||  i == 32)
				{
					if (i == 1)
					{
						if (j == 1)
						{
							cout << traitren;
						}
						else
						{
							if (j == 2*(SoLuong/6 - 1) + SoLuong + 4)
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
							if (j == 2*(SoLuong/6 - 1) + SoLuong + 4)
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
					if (j == 1 || j == 2*(SoLuong/6 - 1) + SoLuong + 4)
					{
						cout << doc;
					}
					else
					{
						cout << " ";
					}
				}
			}
			cout << endl;
		}
	}
}
#endif
