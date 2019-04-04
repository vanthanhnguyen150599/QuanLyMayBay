#ifndef _MYLIB_H
#define _MYLIB_H



#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
//=============================HAM GOTOXY==========================
void gotoxy(int x, int y) // Di chuyen toa do con tro trong he toa do De-cat
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
//=====================TRA VE VI TRI X CUA CON TRO==============================
int wherex()
{
HANDLE hConsoleOutput;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
return screen_buffer_info.dwCursorPosition.X;
}
//=========================TRA VE VI TRI Y CUA CON TRO============================
int wherey( void )
{
HANDLE hConsoleOutput;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
return screen_buffer_info.dwCursorPosition.Y;
}
//==============================AN CO TRO MAN HINH CONSOLE=======================
void AnConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
//==============================HIEN CON TRO MAN HINH CONSOLE================
void HienConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
//=============================SO NGAY TRONG THANG===================
int DaysOfMounth(int mm, int yy) // So ngay toi da cua thang
{
	if (mm == 4 || mm == 6 || mm == 9 || mm == 11 ) return 30; // Thang co 30 ngay
	if (mm == 2) // Thang 2
	{
		if (yy%4 == 0) return 29; // Nam nhuan
		return 28; // Nam khong nhuan
	}
	return 31; // Thang co 31 ngay
}
//===========================KIEM TRA NGAY HOP LE====================
bool CheckDay(int dd, int mm, int yy)
{
	if (dd > 31 || dd <= 0) return 0; // Ngay khong am hoac lon hon 31
	if (mm > 12 || mm <= 0) return 0; // Khong co thang am hoac lon hon 12
	if (mm == 4 || mm == 6 || mm == 9 || mm == 11) // Thang co 30 ngay
	{
		if (dd > 30) return 0;
	}
	if (mm == 2) // Thang 2
	{
		if (yy%4 == 0) // Nam nhuan
		{
			if (dd > 29) return 0; // Nam nhuan
		}
		if (dd > 28) return 0; // Nam khong nhuan
	}
	if (dd > 31) return 0; // Thang co 31 ngay
	return 1;
}
//==========================DEM KHOANG CÁCH GIUA 2 NGAY====================
int CountDays(int dd1,int mm1,int yy1,int dd2, int mm2, int yy2) // dd1,mm1,yy1 phai truoc dd2,mm2,yy2. Dem khoang cach ngay giua 2 ngay
{
	int count = 0;
	if (mm1 == mm2 && yy1 == yy2) // Cung thang nam
	{
		for (int i = dd1; i <= dd2; i++)
		{
			count++;
		}
		return count - 1;
	}
	if (yy1 == yy2) // Cung nam
	{ 
		count = count + CountDays(dd1,mm1,yy1,DaysOfMounth(mm1,yy1),mm1,yy1); // Tu ngay dd1 thang mm1 den het thang mm1
		for (int i = mm1 + 1; i < mm2; i++)
		{
			count = count + DaysOfMounth(i,yy1); // Cac thang nam giua mm1 va mm2
		}
		return (count + CountDays(1,mm2,yy2,dd2,mm2,yy2) + 1); // Cong them dau thang mm2 den ngay dd2 thang mm2
	}
	// Khac nam
	count = count + CountDays(dd1,mm1,yy1,31,12,yy1); // Tu dd1,mm1,yy1 den het nam yy1
	for (int i = yy1 +1; i < yy2; i++) // Cac nam giua yy1 va yy2
	{
		if (i%4 == 0) count += 366; // Nam nhuan
		else count += 365; // Nam khong nhuan
	}
	return (count + CountDays(1,1,yy2,dd2,mm2,yy2) + 1); // Tu dau nam yy2 den ngay dd2 thang mm2 nam yy2
}
//============================DO DAI SO DUONG==================
int DoDaiSoDuong(int a)
{
	if (a == 0) return 1;
	int dem = 0;
	while (a != 0)
	{
		a = a/10;
		dem++;
	}
	return dem;
}
//=========================LOC LAY SO=================================
int LaySo(int giatri, bool DiChuyenDeThoat, char &a) // Kiem tra Di chuyen co thoat khong va nhan phim vua nhan
{
	int i = DoDaiSoDuong(giatri); // Chong tran bit + khong cho backspace khong hop le
	HienConTro();
	unsigned int so = giatri;
	int b;
//	if (a <= 0) a = getch(); // clear a
	a = getch();
	while (a != 13)
	{
		if  ((DiChuyenDeThoat && a == -32) || a == 27 || a == 19)
		{
			break;
		}
		if ((a >= 48 && a <= 57) && i < 10) // nuot phim khi khong phai la so
		{
			if (so == 0 && a == 48)
			{
				
			}
			else
			{
				i++;
				b = a - 48;
				cout << b;
				so = so * 10 + b;
			}
		}
		if (a == 8 && i > 0) // Nguoi dung nhan backspace
		{
			i--;
			so = so/10;
			int x = wherex();
   			int y = wherey();
			gotoxy(x-1, y);
			cout << " ";
			if (!x) gotoxy(0,0);
			else gotoxy(x-1,y);
		}
		a = getch();
	}
	return so;
}
//=================================CHU IN HOA=====================
char InHoa(char a)
{
	if (a >= 97 && a <= 122) // tu 'a' toi 'z'
	{
		a = a - 32;
	}
	return a;
}
#endif