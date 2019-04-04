#ifndef _OBJECT_H
#define _OBJECT_H


#include<iostream>
#include<windows.h>
#include<string>
#include"object.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include"graph.h"
#include<string.h>
using namespace std;
const int MAXLIST = 300;
//==================================STRUCT NGAY===========================
struct Day
{
	int dd,mm,yy;	
};
//==================================STRUCT GIO=============================
struct Time
{
	int hour,min;
};
//=================================STRUCT KHACH HANG=================================
struct KhachHang
{
	string name;
	char SoCMND[10];
};
//====================================STRUCT VE===========================================
struct Ticket
{
	int trangthai; // Trang thai ve 0: chua dat, 1: da dat
	KhachHang KhachHang;
	
};
//============================CLASS MAY BAY=================================
class MayBay
{
	public:
		void DatSoHieu(string a); // Chinh sua so hieu
		string LaySoHieu(); // Lay so hieu
		void DatLoai(string a); // Chinh sua loai may bay
		string LayLoai(); // Lay loai may bay
		void DatSoCho(int a); // Chinh sua so cho may bay
		int LaySoCho(); // Lay so cho ngoi may bay, toi da 624 cho ngoi
	//	void DatTrangThai(int a); // Chinh sua trang thai
	//	int LayTrangThai(); // lay trang thai
		
	protected:
		string SoHieu; // So hieu may bay
		string Loai; // Loai may bay
		int SoCho; // So cho ngoi
	//	int TrangThai; // Trang thai may bay; 0 la huy chuyen, 1 la con ve, 2 la het ve, 3 la hoan tat
};

//==========================FUNCTION MAY BAY==================================

void MayBay :: DatSoHieu(string a)
{
	SoHieu = a;
}
string MayBay::LaySoHieu()
{
	return SoHieu;
}
void MayBay::DatLoai(string a)
{
	Loai = a;
}
string MayBay::LayLoai()
{
	return Loai;
}
void MayBay::DatSoCho(int a)
{
	SoCho = a;
}
int MayBay::LaySoCho()
{
	return SoCho;
}
//void MayBay::DatTrangThai();
//int MayBay::LayTrangThai();

//=====================================DANH SACH MAY BAY===========================================
struct ListMayBay
{
	int n;
	MayBay *data[MAXLIST];
};
//=====================================TAO MOT MAY BAY MOI========================================
MayBay *CreateData()
{
	MayBay *a = new MayBay;
	return a;	
}
//======================================CLASS CHUYEN BAY============================================
class ChuyenBay : public MayBay
{
	protected:
		string MaChuyen; // Ma chuyen bay
		Ticket *Ve;
		Day Ngay; // Ngay thang nam
		Time Gio; // Gio phut
		int TrangThai; // 0: Huy chuyen, 1: Con ve, 2: Het ve, 3: Hoan tat
	public:
		void DatMaChuyen(string a);
		void DatNgay(Day a);
		void DatGio(Time a);
		void DatTrangThai(int a);
		void TaoDanhSachVe();
		string LayMaChuyen();
		Day LayNgay();
		Time LayGio();
		int LayTrangThai();
		Ticket *LayDanhSachVe();
};
//===============================FUNCTION CHUYEN BAY=====================================
void ChuyenBay::DatMaChuyen(string a)
{
	MaChuyen = a;
}
void ChuyenBay::TaoDanhSachVe()
{
	Ve = new Ticket [SoCho]; // Ket thua tu MayBay
}
void ChuyenBay::DatNgay(Day a)
{
	Ngay.dd = a.dd;
	Ngay.mm = a.mm;
	Ngay.yy = a.yy;
}
void ChuyenBay::DatGio(Time a)
{
	Gio.hour = a.hour;
	Gio.min = a.min;
}
void ChuyenBay::DatTrangThai(int a)
{
	TrangThai = a;
}
string ChuyenBay::LayMaChuyen()
{
	return MaChuyen;
}
Day ChuyenBay::LayNgay()
{
	return Ngay;
}
Time ChuyenBay::LayGio()
{
	return Gio;
}
int ChuyenBay::LayTrangThai()
{
	return TrangThai;
}
Ticket *ChuyenBay::LayDanhSachVe()
{
	return Ve;
}
//===================================DANH SACH VE===========================================
struct DsVe
{
	int n;
	Ticket *Dau = NULL;
};
//====================================TAO DU VE MOI==========================================
Ticket *NewTicket()
{
	Ticket *p = new Ticket;
	p = NULL;
	return p;	
};
//=============================KIEM TRA DANH SACH MAY BAY RONG================================
bool DanhSachRong(ListMayBay &a)
{
	if (a.n == 0) 
	return 1;
	return 0;
}
//=============================KIEM TRA DANH SACH MAY BAY DAY=================================
bool DanhSachDay(ListMayBay &a)
{
	if (a.n == MAXLIST)
	return 1;
	return 0;
}
//================================NHAP DU LIEU MAY BAY=======================================
void NhapDuLieuMayBay(MayBay *a)
{
	char x; // De chay ham lay so
	string SoHieu;
	string Loai;
	int SoCho;
	cout << "Nhap So hieu: ";
	cin >> SoHieu;
	cout << "Nhap Loai: ";
	cin >> Loai;
	cout << "Nhap So cho: ";
	SoCho = LaySo(0,0,x);
	a->DatSoHieu(SoHieu);
	a->DatLoai(Loai);
	a->DatSoCho(SoCho);
}
//====================================THEM MAY BAY=======================================
int ThemMayBay(ListMayBay &a)
{
	char kytu; // Dung de lay so thoi =))
	if (DanhSachDay(a)) return 0; // Tra ve 0 neu khong the them
	int x;
	cout << "Chon vi tri muon them: ";
	x = LaySo(0,0,kytu);
	if (!DanhSachRong(a))
	{
		while  (x < 1 || x > a.n + 1) // Vi tri khong hop le
		{
			system("cls");
			cout << "Vi tri khong hop le, xin vui long thu lai " << endl;
			cout << "Chon vi tri muon them: ";
			x = LaySo(0,0,kytu);
		}
	}
	else
	{
		while (x != 1)
		{
			system("cls");
			cout << "Vi tri khong hop le, xin vui long thu lai " << endl;
			cout << "Chon vi tri muon them: ";
			x = LaySo(0,0,kytu);
		}
	}
	cout << endl << endl;
	{
		a.n++;
		a.data[a.n - 1] = CreateData(); // Tao vung nho moi cho con tro vua them vao
		if (x == a.n)
		{
			NhapDuLieuMayBay(a.data[x-1]);
			return 1;
		}
		for (int i = a.n - 1; i >= x; i--) // Doi du lieu
		{
			a.data[i] = a.data[i-1];
		}
		a.data[x-1] = CreateData(); // Tao o nho moi
		NhapDuLieuMayBay(a.data[x-1]);
		return 1;
	}
}
//====================================XOA MAY MAY KHOI DANH SACH============================
int XoaMayBay(ListMayBay &a)
{
	char kytu; // Dung de lay so thoi =))
	if (DanhSachRong(a)) return 0;
	int x;
	cout << "Chon vi tri muon xoa: ";
	x = LaySo(0,0,kytu);
	while  (x < 1 || x > a.n)
	{
		system("cls");
		cout << "Vi tri khong hop le, xin vui long thu lai " << endl;
		cout << "Chon vi tri muon xoa: ";
		x = LaySo(0,0,kytu);
	} 
	if (x == a.n) // xoa cuoi
	{
		delete a.data[a.n - 1];
		a.n--;
		return 1;
	}
	if (x == 1 && a.n == 1) // Xoa phan tu cuoi cung
	{
		delete a.data[x-1];
		a.n--;
		return 1;
	} 
	for (int i = x - 1 ; i < a.n - 1; i++) // xoa giua
	{
		a.data[i] = a.data[i+1];
		delete a.data[a.n - 1];
		a.n--;
		return 1;
	} 
}
//====================================IN DANH SACH MAY BAY===================================
void InDanhSachMayBay(ListMayBay a)
{
	gotoxy(0,0);
	for (int i = 0; i < a.n; i++)
	{
		cout << "So hieu: " << a.data[i]->LaySoHieu() << endl;
		cout << "Loai: " << a.data[i]->LayLoai() << endl;
		cout << "So cho: " << a.data[i]->LaySoCho() << endl << endl;
	}
}
//===================================CHINH SUA MAY BAY=======================================
int ChinhSuaMayBay(ListMayBay &a)
{
	if (a.n == 0) return 0;
	system("cls");
	gotoxy(0,0);
	InDanhSachMayBay(a);
	HienConTro();
	MayBay MangPhu[a.n]; // Chua data	
    //======================SAO CHEP DU LIEU====================
	for (int i = 0; i < a.n; i++) // Sao chep du lieu vao mang phu
	{
		MangPhu[i].DatSoHieu(a.data[i]->LaySoHieu());
		MangPhu[i].DatLoai(a.data[i]->LayLoai());
		MangPhu[i].DatSoCho(a.data[i]->LaySoCho());
	}
//	MangPhu[0].DatSoHieu("Hello");                     // test ok
//	a.data[0]->DatSoHieu(MangPhu[0].LaySoHieu());      // test ok
	int line = 0;
	gotoxy(9+MangPhu[0].LaySoHieu().length(),line); // Di chuyen con tro toi vi tri dau tien
	bool kytu;
	char x = getch();
	if (x != -32 && x != 8) // Khong phai chuc nang hoac Backspace
	{
		kytu = 1;
	}
	if (x == -32 || x == 0) // Phim chuc nang
	{
		kytu = 0;
		x = getch();
	} 
//	x = GetKeyboard();
	while (x != 19 && x != 27)
	{
		if (x == 72 && !kytu ) // Up
		{
			if (line == 0)
			{
				line = a.n*4 - 2; // Di ve line cuoi cung
			}
			else
			{
				if (line%4 == 0)
				{
					line = line - 2;
				}
				else
				{
					line--;
				}
			}
		}
		if (x == 80 && !kytu) // Down
		{
			if (line == a.n*4 - 2)
			{
				line = 0; // Di ve line dau
			}
			else
			{
				if (line%4 == 2)
				{
					line  = line + 2;
				}
				else
				{
					line++;
				}
			}	
		}
		if (line%4 == 0) // So Hieu
		{
			gotoxy(9+MangPhu[line/4].LaySoHieu().length(),line);
			int dodaichuoi = MangPhu[line/4].LaySoHieu().length();
		//================NHAN BACKSPACE TU NGOAI VONG==============
			if (x == 8 && line == 0) // Backspace
			{
				if (dodaichuoi > 0) // Duoc quyen xoa
				{
				//=============XU LY HINH ANH=========
					int a = wherex();
					int b = wherey();
					gotoxy(a-1,b);
					cout << " ";
					gotoxy(a-1,b);
				//=============XU LY CHUOI===========
					dodaichuoi--;
					string SoHieu = MangPhu[line/4].LaySoHieu();
					SoHieu.erase(SoHieu.end()-1,SoHieu.end());
					MangPhu[line/4].DatSoHieu(SoHieu);
					}
				else
				{
					int a = wherex();
					int b = wherey();
					cout << "Khong the xoa";
					Sleep(500);
					gotoxy(a,b);
					cout << "               ";
					gotoxy(a,b);
				} 
			}
		//===============NHAN KY TU VONG NGOAI=====================
			if (((x >= 94 && x <= 122) || (x >= 65 && x <= 90) || (x >= 48 && x <=57)) && kytu && line == 0) // a toi z, A toi Z, 0 toi 9
			{
				dodaichuoi++;
				cout << InHoa(x);
				MangPhu[line/4].DatSoHieu(MangPhu[line/4].LaySoHieu() + InHoa(x));
			} 
			x = getch(); // Ban muon thao tac gi voi line nay?
			while (1)
			{
			//============XU LY NHAN PHIM=================
				if (x != -32 && x != 0)
				{
					kytu = 1;
				}
				else
				{
					kytu = 0;
					x = getch();
				}
			//================NHAN BACKSPACE==============
				if (x == 8 && kytu) // Backspace
				{
					if (dodaichuoi > 0) // Duoc quyen xoa
					{
						//=============XU LY HINH ANH=========
							int a = wherex();
							int b = wherey();
							gotoxy(a-1,b);
							cout << " ";
							gotoxy(a-1,b);
						//=============XU LY CHUOI===========
							dodaichuoi--;
							string SoHieu = MangPhu[line/4].LaySoHieu();
							SoHieu.erase(SoHieu.end()-1,SoHieu.end());
							MangPhu[line/4].DatSoHieu(SoHieu);
					}
					else
					{
						int a = wherex();
						int b = wherey();
						cout << "Khong the xoa";
						Sleep(500);
						gotoxy(a,b);
						cout << "                           ";
						gotoxy(a,b);
					} 
				}
			//===============NHAN PHIM CHUC NANG==============
				if ((x == 72 || x == 80) && !kytu || x == 27 || x == 19) // 19 la Ctrl + S
				{
					break; // Khong con thao tac tren dong nay nua
				}
			//===============NHAN KY TU=====================
				if (((x >= 94 && x <= 122) || (x >= 65 && x <= 90) || (x >= 48 && x <=57)) && kytu) // a toi z, A toi Z, 0 toi 9
				{
					dodaichuoi++;
					cout << InHoa(x);
					MangPhu[line/4].DatSoHieu(MangPhu[line/4].LaySoHieu() + InHoa(x));
				}
				x = getch();
			}
		}
		if (line%4 == 1) // Loai
		{
			gotoxy(6+MangPhu[line/4].LayLoai().length(),line);
			int dodaichuoi = MangPhu[line/4].LayLoai().length();
			x = getch(); // Ban muon thao tac gi tren dong nay?
			while(1)
			{
				if (x != -32 && x != 0)
				{
					kytu = 1;
				}
				else
				{
					kytu = 0;
					x = getch();
				}
			//==============BACKSPACE=====================
				if (x == 8 && kytu)
				{
					if (dodaichuoi > 0)
					{
					//=================XU LY HINH ANH=================
						int a = wherex();
						int b = wherey();
						gotoxy(a-1,b);
						cout << " ";
						gotoxy(a-1,b);
					//==================XU LY CHUOI===================
						dodaichuoi--;
						string Loai = MangPhu[line/4].LayLoai();
						Loai.erase(Loai.end()-1,Loai.end());
						MangPhu[line/4].DatLoai(Loai);
					}	
					else
					{
					int a = wherex();
					int b = wherey();
					cout << "Khong the xoa";
					Sleep(500);
					gotoxy(a,b);
					cout << "              ";
					gotoxy(a,b);
					}	
				}
			//==============CHUC NANG======================
				if ((x == 72 || x == 80) && !kytu  || x == 27 || x == 19)
				{
					break; // Khong con line nay nua
				}	
			//=============NHAN CHU CAI====================
				if (((x >= 94 && x <= 122) || (x >= 65 && x <= 90) || (x >= 48 && x <=57)) && kytu) // a toi z, A toi Z, 0 toi 9 
				{
					dodaichuoi++;
					cout << InHoa(x);
					MangPhu[line/4].DatLoai(MangPhu[line/4].LayLoai() + InHoa(x));
				}
				x = getch();
			}
		}
		if (line%4 == 2) // So Cho
		{
			gotoxy(8+DoDaiSoDuong(MangPhu[line/4].LaySoCho()),line);
			int SoCho = MangPhu[line/4].LaySoCho();
			SoCho = LaySo(SoCho,1,x);
			if (x == -32 || x == 0)
			{
				kytu = 0;
				x = getch();
			}
			MangPhu[line/4].DatSoCho(SoCho);
		}
	}
	if (x == 27)
	{
		int tungdo,hoanhdo = -1;
		while (1) // So nhat la nguoi dung thich mua lua =))
		{
			
			gotoxy(0,a.n*4);
			cout << "Ban co muon luu thay doi?" << endl;
			cout << "Nhan 0 de huy hoac nhan 1 de luu ";
			x = getch();
			if (x == 48) // Phim 0
			{
				cout << endl;
				hoanhdo = wherex();
				tungdo = wherey();
				cout << "Ban co chan khong luu?" << endl;
				cout << "Nhan 0 de huy hoac nhan 1 de xac nhan khong luu ";
				x = getch();
				if (x == 49) // Phim 1
				{
					cout << x;
					return 0;
				}
				if ((hoanhdo!= -1 && tungdo != -1) && x == 48)
				{
					gotoxy(hoanhdo,tungdo);
					cout << "                                      ";
					gotoxy(hoanhdo,tungdo+1);
					cout << "                                                     ";
				}	
			
			}
			if (x == 49) break; // So phim -32 lam =))
		}
	}
	for (int i = 0; i < a.n; i++)
	{
		a.data[i]->DatSoHieu(MangPhu[i].LaySoHieu());
		a.data[i]->DatLoai(MangPhu[i].LayLoai());
		a.data[i]->DatSoCho(MangPhu[i].LaySoCho());
	}
	system("cls");
	cout << "Luu thanh cong!"; // Lam mau choi thoi =))
	Sleep(500);
	return 1;
}
//===================================NHAP DU LIEU CHUYEN BAY===================================
int NhapDuLieuChuyenBay(ChuyenBay &a, MayBay b)
{
	char x; // Nhan phim
	int kytu; // Kiem tra ky tu
	string MaChuyen;
	Ticket *Ve;
	Day Ngay;
	Time Gio; 
	int TrangThai;
	cout << "Nhap Ma chuyen bay ";
	cin >> MaChuyen;
	{
		cout << "Nhap Ma may bay thuc hien chuyen bay ";
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
		if (a == 8) // Backspace
		{
			int hoanhdo = wherex();
			int tungdo = wherey();
			cout << "Khong the xoa";
			Sleep(500);
			gotoxy(hoanhdo,tungdo);
			cout << "                  ";
			gotoxy(hoanhdo,tungdo);
		}
		while (x != 27 && x != 13)
		{
			if ((x >= 97 && x <= 122)  &&  kytu) // tu a den z
			{
				x = InHoa(x);
			}
			if  (((x >= 48 && x <= 57)||(x >= 65 && x >= 90)) && kytu) // Chu cai
			{
				// Chon ma neu co hoac them moi
			}
		}
	}
	
	
}

#endif
