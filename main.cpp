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
	infile.open("ds-may-bay.txt");
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
			InDanhSachMayBay(maybay);
			system("pause");
		}
		system("cls");
		a = MainMenu();
	}  
//	VeKhung();
//	int a = LaySo();
//	cout << endl << a;
}	

