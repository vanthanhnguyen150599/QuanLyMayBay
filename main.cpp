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
//==============================DANG NHAP======================================
//	VeKhung();
//	DangNhap();
//	system("cls");
//==================================MAIN MENU=====================================
	int a;
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
	}  
//	VeKhung();
//	int a = LaySo();
//	cout << endl << a;
}	
