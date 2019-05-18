#include<iostream>
#include<string>
#include"mylib.h"
#include"object.h"
#include"graph.h"
#include<fstream>
using namespace std;
int main()
{
//=======================DOC DU LIEU CAC MAY BAY TU FILE=======================
	ListMayBay maybay;
	ifstream infile;
	infile.open("dsmaybay.txt");
	infile >> maybay.n;
	for (int i = 0; i < maybay.n; i++) // Doc du lieu cac may bay tu file
	{
		string SoHieu;
		string Loai;
		int SoCho;
		infile >> SoHieu >> Loai >> SoCho;
		maybay.data[i] = CreateData();
		maybay.data[i]->DatSoHieu(SoHieu);
		maybay.data[i]->DatLoai(Loai);
		maybay.data[i]->DatSoCho(SoCho);
	}
	infile.close();
//=========================== DOC DU LIEU CHUYEN BAY TU FILE ==============================
	ListChuyenBay chuyenbay;
	string MaChuyen = "";
	string SoHieu = "";
	string Den = "";
	Day Ngay;
	Time Gio;
	int TrangThai;
	infile.open("dschuyenbay.txt");
	if (infile.fail())
	{
		cout << "That Bai";
		return 0;
	}
	infile >> chuyenbay.SoLuong;
	CacChuyenBay *p = NULL;
	for (int i = 1; i <= chuyenbay.SoLuong; i++)
	{
	//	CacMayBay *temp;
		CacChuyenBay *p = NewChuyenBay();
		if (chuyenbay.Head == NULL)
		{
			chuyenbay.Head = p;
		}
		else
		{
		//	temp = p;
			p->next = chuyenbay.Head;
			chuyenbay.Head = p;
		}
		infile >> MaChuyen;
		infile >> SoHieu;
		infile >> Den;
		infile >> Gio.hour;
		infile >> Gio.min;
		infile >> Ngay.dd;
		infile >> Ngay.mm;
		infile >> Ngay.yy;
		infile >> TrangThai;
		p->chuyenbay.DatMaChuyen(MaChuyen);
		p->chuyenbay.DatSoHieu(SoHieu);
		for (int j = 0; j < maybay.n; j++) // Tim chuyen bay co SoHieu trung de copy du lieu
		{
			if (p->chuyenbay.LaySoHieu() == maybay.data[j]->LaySoHieu())
			{
				p->chuyenbay.DatLoai(maybay.data[j]->LayLoai());
				p->chuyenbay.DatSoCho(maybay.data[j]->LaySoCho());
			}
		} 
		p->chuyenbay.DatDiemDen(Den);
		p->chuyenbay.DatGio(Gio);
		p->chuyenbay.DatNgay(Ngay);
		p->chuyenbay.DatTrangThai(TrangThai);
		p = p->next;
	}
	infile.close();
//==============================DANG NHAP======================================
//	VeKhung();
//	DangNhap();
//	system("cls");
//==================================MAIN MENU=====================================
/*	int a;
	a = MainMenu();
	while (a != -1)
	{
		if (a == 0)
		{
			system("cls");
			if (!ThemMayBay(maybay))
			{
				system("cls");
				cout << "Danh sach day khong the them" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "Them thanh cong!!!" << endl;
				system("pause");
				
			}
		}
		if (a == 2)
		{
			system("cls");
			if (!XoaMayBay(maybay))
			{
				system("cls");
				cout << "Danh sach day khong the xoa" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "Xoa thanh cong!!!" << endl;
				//	cout << maybay.n;
				system("pause");
			}
		}
		if (a == 4)
		{
			ChinhSuaMayBay(maybay);
			//system("pause");
		}
		if (a == 6)
		{
			system("cls");
			int trang = 1;
			InDanhSachMayBay(maybay,trang);
			bool kytu;
			char x;
			x = getch();
			if (x == -32 || x == 0)
			{
				kytu = 0;
				x = getch();
			}
			else
			{
				kytu = 1;
			}
			while (x != 27) // Chua nhan Esc
			{
				if (x == 75 && !kytu) // Left
				{
					if (trang > 1)
					{
						trang--;
					}
				}
				if (x == 77 && !kytu) // Right
				{
					if (maybay.n % 30 != 0)
					{
						if (trang < maybay.n/30 + 1)
						{
							trang++;
						}
					}
					else
					{
						if (trang < maybay.n/30)
						{
							trang++;
						}
					}
				}
				gotoxy(0,0);
				InDanhSachMayBay(maybay,trang);
				x = getch();
				AnConTro();
				if (x == -32 || x == 0)
				{
					kytu = 0;
					x = getch();
				}
				else
				{
					kytu = 1;
				}
			}
		}
		system("cls");
		a = MainMenu();
	} */
/*	KhungChuyenBay();
	while (1)
	{
		AnConTro();
		gotoxy(105,1);
		InThoiGian();
	} */
//	cout << chuyenbay.Head->chuyenbay.LayMaChuyen();
	InDanhSachChuyenBay(chuyenbay,1);
//	VeKhung();
//	int a = LaySo();
//	cout << endl << a;
}	
