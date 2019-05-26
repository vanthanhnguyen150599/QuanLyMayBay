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
//================================== STRUCT KHACH HANG ================================
struct KhachHang
{
	string CMND = "";
	string Name = "";
	int GioiTinh; // 1 la nam, 0 la nu	
};
//=================================
//=================================== NHAP THONG TIN KHACH HANG ==================================
void NhapThongTinKhachHang(KhachHang &HanhKhach)
{
	// Thieu Graphic
	cout << "Nhap CMND: ";
	LaySoCMND(HanhKhach.CMND);
	cout << "Nhap Ho Ten: ";
	NhapHoTen(HanhKhach.Name);
	cout << "Nhap gioi tinh: ";
	cin >> HanhKhach.GioiTinh;
	int hoanhdo = wherex();
	int tungdo = wherey();
	while (HanhKhach.GioiTinh != 1 && HanhKhach.GioiTinh != 0)
	{
		gotoxy(hoanhdo,tungdo);
		cout << "Thong tin khong hop le!";
		Sleep(300);
		gotoxy(hoanhdo,tungdo);
		cout << "                       ";
		gotoxy(hoanhdo,tungdo);
		cin >> HanhKhach.GioiTinh;
	}
}
//================================= STRUCT CAC PHAN TU TRONG CAY ==================================
struct NodeKhachHang
{
	KhachHang HanhKhach; // chua thong tin
	NodeKhachHang *left = NULL;
	NodeKhachHang *right = NULL;
};
//==================================== STRUCT CAY KHACH HANG =============================
struct CayKhachHang
{
	int SoLuong;
	NodeKhachHang *root = NULL;
};
// ================================ TAO NODE KHACH HANG ============================
NodeKhachHang *NewKhachHang()
{
	NodeKhachHang *p = new NodeKhachHang;
	return p;
}
// ==================================== SO SANH CMND ========================
int SoSanhCMND(KhachHang a, KhachHang b)
{
	for (int i = 0; i < 10; i++)
	{
		if(a.CMND[i > b.CMND[i]])
		{
			return 1; // a > b
		}
		if (a.CMND[i] > b.CMND[i])
		{
			return -1;
		}
	}
	return 0;
}
// =============================== SUA THONG TIN KHACH HANG =====================
int SuaThongTinKhachHang(KhachHang &HanhKhach)
{
	// Con thieu ne
}
//=================================THEM VAO CAY KHACH HANG====================
int ThemVaoCayKhachHang(NodeKhachHang *root)
{
	// ============ TIEN XU LY =====================
		KhachHang HanhKhach;
		NhapThongTinKhachHang(HanhKhach);
	// ============ 
	if (root == NULL) // Cay rong
	{
		root = new NodeKhachHang;
		root->HanhKhach.CMND = HanhKhach.CMND;
		root->left = NULL;
		root->right = NULL;
		return 1;
	}
	NodeKhachHang *p = root;
	while (p != NULL)
	{
		if (SoSanhCMND(p->HanhKhach, HanhKhach) == 1) // Du lieu can nhap vao  nho hon data tai p
		{
			p = p->left;
		}
		if (SoSanhCMND(p->HanhKhach, HanhKhach) == -1)
		{
			p = p->right; // Du lieu can nhap vao lon hon data tai p
		}
	}
	p = new NodeKhachHang;
	p->HanhKhach.CMND = HanhKhach.CMND;
	p->HanhKhach.GioiTinh = HanhKhach.GioiTinh;
	p->HanhKhach.Name = HanhKhach.Name;
	p->left = NULL;
	p->right = NULL;
	return 1;
}
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
// ===================== DO DAI KY TU CUA NGAY ============================
int DoDaiNgay (Day a)
{
	int dodai = 0;
	dodai = DoDaiSoDuong(a.dd) + DoDaiSoDuong(a.mm) + DoDaiSoDuong(a.yy) + 2; // 2 dau '/'
	return dodai;
}
// ===================== DO DAI KY TU CUA GIO =======================
int DoDaiGio(Time a)
{
	int dodai = 0;
	if (a.min < 10)
	{
		dodai = DoDaiSoDuong(a.hour) + DoDaiSoDuong(a.min) + 2; // Them so '0' voi ':'
	}
	else
	{
		dodai = DoDaiSoDuong(a.hour) + DoDaiSoDuong(a.min) + 1;
	}
	return dodai;
}
// ============================= IN NGAY ============================
void InNgay(Day a)
{
	cout << a.dd << "/" << a.mm << "/" << a.yy;
}
// =================================== IN GIO ====================
void InGio(Time a)
{
	cout << a.hour << ":";
	if (a.min < 10)
	{
		cout << "0" << a.min;
	}
	else
	{
		cout << a.min;
	}
}
//======================================STRUCT VE==================================================
struct Ticket
{
	KhachHang *HanhKhach = NULL;
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
//============================= KIEM TRA TRUNG SO HIEU MAY BAY ==============================
bool KiemTraSoHieu(ListMayBay a, string SoHieu)
{
	for (int i = 0; i < a.n; i++)
	{
		if (a.data[i]->LaySoHieu() == SoHieu)
		{
			return 1;
		}
	}
	return 0;
}
//================================NHAP DU LIEU MAY BAY=======================================
void NhapDuLieuMayBay(MayBay *a,ListMayBay list)
{
//	InDanhSachMayBay(a,list.n/30+1);
	HienConTro();
	char x; // De chay ham lay so
	bool kytu;
	string SoHieu = "";
	string Loai = "";
	int SoCho = 0;
	//==========================SO HIEU=======================================
//	cout << "Nhap So hieu: ";
	int dodai = SoHieu.length();
	gotoxy(10,wherey());
	while (1)
	{
		dodai = SoHieu.length();
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
		while (x != 13) // Chua nhan Enter
		{
			if (x == 8) // Backspace
			{
				if (dodai != 0)
				{
					SoHieu.erase(SoHieu.end() - 1, SoHieu.end());
					dodai--;
					//==========================//
				//	int hoanhdo = wherex();
				//	int tungdo = wherey();
					AnConTro();
					gotoxy(8, wherey());
					cout << "     ";
					CanhGiua(10,dodai);
					cout << SoHieu;
					HienConTro();
				}
				else
				{
					int hoanhdo = wherex();
					int tungdo = wherey();
					gotoxy(3,tungdo);
					cout << "Khong the xoa";
					Sleep(300);
					gotoxy(3,tungdo);
					cout << "             ";
					gotoxy(10,tungdo);
				}
			}
			if ((x >= 97 && x <= 122) && kytu) // In hoa chu thuong len em ei =))
			{
				x = InHoa(x);
			}
			if (((x >= 65 && x <= 90) || (x >= 48 && x <= 57)) && kytu) // 0 den 9, A den Z
			{
				if (dodai < 5)
				{
					dodai++;
					SoHieu = SoHieu + x;
					CanhGiua(10,SoHieu.length());
					for (int i = 0; i < SoHieu.length();i++)
					cout << SoHieu[i];
				}
				else
				{
				//	int hoanhdo = wherex();
				//	int tungdo = wherey();
					gotoxy(2,wherey());
					cout << "Khong qua 5 ky tu";
					Sleep(300);
					gotoxy(2,wherey());
					cout << "                 ";
				//	gotoxy(hoanhdo - 5, tungdo);
				//	cout << SoHieu;
					CanhGiua(10,SoHieu.length());
					for (int i = 0; i < SoHieu.length();i++)
					cout << SoHieu[i];
				}
			}
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
		}
		if (SoHieu.length() != 0)
		{
			if (KiemTraSoHieu(list,SoHieu))
			{
				gotoxy(3,wherey());
				cout << "So hieu bi trung";
				Sleep(500);
				gotoxy(2,wherey());
				cout << "Vui long nhap lai";
				Sleep(500);
				gotoxy(2,wherey());
				cout << "                 ";
				SoHieu = "";
			//	cout << SoHieu;
				gotoxy(10,wherey());
			}
			else
			{
				break;
			}
		}
		else
		{
			gotoxy(1,wherey());
			cout << "Khong the de trong";
			Sleep(300);
			gotoxy(1,wherey());
			cout << "                  ";
			CanhGiua(10,SoHieu.length());
		}
	}
	//=====================LOAI============================
//	cout << endl;
//	cout << "Nhap Loai: ";
	dodai = Loai.length();
	gotoxy(30,wherey());
	while (1)
	{
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
		while (x != 13) // Chua nhan Enter
		{
			if (x == 8) // Backspace
			{
				if (dodai != 0)
				{
					Loai.erase(Loai.end() - 1, Loai.end());
					dodai--;
					//=========================//
				//	int hoanhdo = wherex();
				//	int tungdo = wherey();
				//	gotoxy(hoanhdo - 1, tungdo);
				//	cout << " ";
					AnConTro();
					gotoxy(25, wherey());
					cout << "          ";
					CanhGiua(30,dodai);
					cout << Loai;
					HienConTro();
				}
				else
				{
					int hoanhdo = wherex();
					int tungdo = wherey();
					cout << "Khong the xoa";
					Sleep(300);
					gotoxy(hoanhdo,tungdo);
					cout << "             ";
					gotoxy(30,tungdo);
				}
			}
			if ((x >= 97 && x <= 122) && kytu) // In hoa chu thuong len em ei =))
			{
				x = InHoa(x);
			}
			if (((x >= 65 && x <= 90) || (x >= 48 && x <= 57)) && kytu) // 0 den 9, A den Z
			{
				if (dodai < 10)
				{
					dodai++;
					Loai = Loai + x;
					AnConTro();
					CanhGiua(30,dodai);
					for (int i = 0; i < dodai; i++)
					cout << Loai[i];
					HienConTro();
				}
				else
				{
					AnConTro();
					int hoanhdo = wherex();
					int tungdo = wherey();
					gotoxy(22,tungdo);
					cout << "Khong qua 10 ky tu";
					Sleep(300);
					gotoxy(22,tungdo);
					cout << "                  ";
					CanhGiua(30,dodai);
					cout << Loai;
					HienConTro();
				}
			}
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
		}
		if (Loai.length() != 0)
		{
			break;
		}
		else
		{
			gotoxy(21,wherey());
			cout << "Khong the de trong";
			Sleep(300);
			gotoxy(21,wherey());
			cout << "                  ";
			gotoxy(30,wherey());
		}
	}
	//==================================SO CHO============================== 
//	cout << "Nhap So cho: ";
	gotoxy(50,wherey());
	SoCho = LaySo(0,0,x);
	while(SoCho < 20)
	{
		AnConTro();
		gotoxy(44,wherey());
		cout << "So cho > 20";
		Sleep(300);
		gotoxy(44,wherey());
		cout << "           ";
		gotoxy(50,wherey());
		cout << "  ";
		gotoxy(50,wherey());
		SoCho = 0;
		SoCho = LaySo(0,0,x);
	}
	{
		AnConTro();
		gotoxy(45,wherey());
		cout << "          ";
		CanhGiua(50,DoDaiSoDuong(SoCho));
		cout << SoCho;
	}
	a->DatSoHieu(SoHieu);
	a->DatLoai(Loai);
	a->DatSoCho(SoCho);
}
//====================================IN DANH SACH MAY BAY===================================
void InDanhSachMayBay(ListMayBay a, int trang)
{
	KhungMayBay();
//	ChangeColor(8);
	gotoxy(0,0);
	int maxtrang;
	if (a.n%30 != 0)
	{
		maxtrang = a.n/30 + 1;
	}
	else
	{
		maxtrang = a.n/30;
	}
	if (trang < maxtrang)
	{
		for (int i = (trang - 1)*30; i < trang*30 - 1; i++)
		{
			gotoxy(8,2*(i+1)+1);
			CanhGiua(10,a.data[i]->LaySoHieu().length());
			cout << a.data[i]->LaySoHieu();
			gotoxy(26,2*(i+1)+1);
			CanhGiua(30,a.data[i]->LayLoai().length());
			cout << a.data[i]->LayLoai();
			gotoxy(48,2*(i+1)+1);
			CanhGiua(50,DoDaiSoDuong(a.data[i]->LaySoCho()));
			cout << a.data[i]->LaySoCho();
		}
	}
	else
	{
		for (int i = (trang - 1)*30; i < a.n; i++)
		{
			gotoxy(8,2*(i+1)+1);
			CanhGiua(10,a.data[i]->LaySoHieu().length());
			cout << a.data[i]->LaySoHieu();
			gotoxy(26,2*(i+1)+1);
			CanhGiua(30,a.data[i]->LayLoai().length());
			cout << a.data[i]->LayLoai();
			gotoxy(48,2*(i+1)+1);
			CanhGiua(50,DoDaiSoDuong(a.data[i]->LaySoCho()));
			cout << a.data[i]->LaySoCho();
		}
	}
	gotoxy(25,24);
	cout << "---" << trang << "/";
	if (a.n%10 > 0)
	{
		cout << a.n/10 + 1;
	}
	else
	{
		cout << a.n/10;
	}
	cout << "---" << endl;
}
//====================================THEM MAY BAY=======================================
int ThemMayBay(ListMayBay &a)
{
//	ChangeColor(8);
	char kytu; // Dung de lay so thoi =))
	if (DanhSachDay(a)) return 0; // Tra ve 0 neu khong the them
//	int x;
//	cout << "Chon vi tri muon them: ";
//	x = LaySo(0,0,kytu);
/*	if (!DanhSachRong(a))
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
	cout << endl << endl; */
	{
		a.n++;
		a.data[a.n - 1] = CreateData(); // Tao vung nho moi cho con tro vua them vao
		InDanhSachMayBay(a,(a.n+1)/30+1);
	//	KhungMayBay();
		int x = a.n%10;
	/*	for (int i = 1; i < x; i++) // Tru data vua them vao
		{
			gotoxy(10,2*i+1);
			CanhGiua(10,a.data[a.n/10 * 10 + i - 1]->LaySoHieu().length());
			cout << a.data[a.n/10 * 10 + i - 1]->LaySoHieu();
			gotoxy(30,2*i+1);
			CanhGiua(30,a.data[a.n/10 * 10 + i - 1]->LayLoai().length());
			cout << a.data[a.n/10 * 10 + i - 1]->LayLoai();
			gotoxy(50,2*i+1);
			CanhGiua(50,DoDaiSoDuong(a.data[a.n/10 * 10 + i - 1]->LaySoCho()));
			cout << a.data[a.n/10 * 10 + i - 1]->LaySoCho();
		}*/
		gotoxy(0,2*x + 1);
		NhapDuLieuMayBay(a.data[a.n-1],a);
		return 1;
/*		for (int i = a.n - 1; i >= x; i--) // Doi du lieu
		{
			a.data[i] = a.data[i-1];
		}
		a.data[x-1] = CreateData(); // Tao o nho moi
		NhapDuLieuMayBay(a.data[x-1]);
		return 1; */
	}
	// luon them ve cuoi
}
//====================================XOA MAY MAY KHOI DANH SACH============================
int XoaMayBay(ListMayBay &a)
{
	ChangeColor(8);
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
//=================================== CHINH SUA MAY BAY =======================================
int ChinhSuaMayBay(ListMayBay &a)
{
//	ChangeColor(8);
	int currentpage;
	if (a.n == 0) return 0;
	system("cls");
	gotoxy(0,0);
	InDanhSachMayBay(a,1);
	HienConTro();
	MayBay MangPhu[a.n]; // Chua data	
    //====================== SAO CHEP DU LIEU ====================
	for (int i = 0; i < a.n; i++) // Sao chep du lieu vao mang phu
	{
		MangPhu[i].DatSoHieu(a.data[i]->LaySoHieu());
		MangPhu[i].DatLoai(a.data[i]->LayLoai());
		MangPhu[i].DatSoCho(a.data[i]->LaySoCho());
	}
//	MangPhu[0].DatSoHieu("Hello");                     // test ok
//	a.data[0]->DatSoHieu(MangPhu[0].LaySoHieu());      // test ok

	int line = 0;
	currentpage = line/30;	
	AnConTro();
	gotoxy(0,2*(line/3 + 1) + 1); // Dua con tro den dung hang
	CanhGiua(10,a.data[line/3]->LaySoHieu().length());
	gotoxy(wherex() + a.data[line/3]->LaySoHieu().length(),wherey()); // Di chuyen den dung vi tri
	HienConTro();
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
		currentpage = line/30;
		if (x == 72 && !kytu ) // Up
		{
			if (line > 2)
			{
				line = line - 3;
			}
		}
		if (x == 80 && !kytu) // Down
		{
			if (line <= (a.n - 1)*3 - 1)
			{
				line = line + 3;
			}
			
		}
		if (x == 75 && !kytu) // Left
		{
			if (line > 0)
			{
				line--;
			}
		}
		if (x == 77 && !kytu) // Right
		{
			if (line != a.n*3 - 1)
			{
			//	gotoxy(70,10);
			//	cout << "HELLO";
				line++;
			}
		}
		AnConTro();
		if (line/30 != currentpage)
		{
			gotoxy(0,0);
			InDanhSachMayBay(a,line/30);
		}
	//	gotoxy(70,1);
	//	cout << "line = " << line << " ky tu la " << kytu;
		if (line%3 == 0) // So Hieu
		{
		//	while (1)
		//	{
				AnConTro();
				gotoxy(0,2*((line%30)/3 + 1) + 1);
				CanhGiua(10,MangPhu[line/3].LaySoHieu().length());
				gotoxy(wherex() + MangPhu[line/3].LaySoHieu().length(),wherey());
				HienConTro();
				int dodaichuoi = MangPhu[line/3].LaySoHieu().length();
			//================NHAN BACKSPACE TU NGOAI VONG==============
				if (x == 8 && line == 0) // Backspace
				{
					if (dodaichuoi > 0) // Duoc quyen xoa
					{
						//=============XU LY CHUOI===========
						dodaichuoi--;
						string SoHieu = MangPhu[line/4].LaySoHieu();
						SoHieu.erase(SoHieu.end()-1,SoHieu.end());
						MangPhu[line/4].DatSoHieu(SoHieu);
						
					//=============XU LY HINH ANH=========
						AnConTro();
						gotoxy(8,wherey());
						cout << "     ";
						CanhGiua(10,MangPhu[line/3].LaySoHieu().length());
						cout << MangPhu[line/3].LaySoHieu();
						HienConTro();
					}
					else
					{
						AnConTro();
						gotoxy(4,wherey());
						cout << "Khong the xoa";
						Sleep(500);
						gotoxy(4,wherey());
						cout << "              ";
						gotoxy(10,wherey());
						HienConTro();
					} 
				}
			//===============NHAN KY TU VONG NGOAI=====================
				if (((x >= 94 && x <= 122) || (x >= 65 && x <= 90) || (x >= 48 && x <=57)) && kytu && line == 0) // a toi z, A toi Z, 0 toi 9
				{
					dodaichuoi++;
					InHoa(x);
					MangPhu[line/4].DatSoHieu(MangPhu[line/4].LaySoHieu() + InHoa(x));
					AnConTro();
					CanhGiua(10,MangPhu[line/3].LaySoHieu().length());
					cout << MangPhu[line/3].LaySoHieu();
					HienConTro();
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
							//=============XU LY CHUOI===========
								dodaichuoi--;
								string SoHieu = MangPhu[line/3].LaySoHieu();
								SoHieu.erase(SoHieu.end()-1,SoHieu.end());
								MangPhu[line/3].DatSoHieu(SoHieu);
							//=============XU LY HINH ANH=========
								AnConTro();
								gotoxy(8,wherey());
								cout << "     ";
								CanhGiua(10,dodaichuoi);
								cout << MangPhu[line/3].LaySoHieu();
								HienConTro();
						}
						else
						{
							AnConTro();
							gotoxy(4,wherey());
							cout << "Khong the xoa";
							Sleep(300);
							gotoxy(4,wherey());
							cout << "             ";
							gotoxy(10,wherey());
							HienConTro();
						} 
					}
				//===============NHAN PHIM CHUC NANG==============
					if (((x == 72 || x == 80 || x == 77 || x == 75) && !kytu) || x == 27 || x == 19) // 19 la Ctrl + S
					{
						if (MangPhu[line/3].LaySoHieu() != "")
						{
							if (KiemTraSoHieu(a,MangPhu[line/3].LaySoHieu())) // Trung So Hieu
							{
								AnConTro();
								gotoxy(4,wherey());
								cout << "Trung So Hieu";
								Sleep(500);
								gotoxy(4,wherey());
								cout << "             ";
								gotoxy(7,wherey());
								cout << "Thu lai";
								Sleep(500);
								gotoxy(7,wherey());
								cout << "       ";
								gotoxy(10,wherey());
								dodaichuoi = 0;
								MangPhu[line/3].DatSoHieu("");
								HienConTro();
							}
							else
							{
								break; // Khong con thao tac tren dong nay nua
							}
						}
						else
						{
							AnConTro();
							gotoxy(1,wherey());
							cout << "Khong the bo trong";
							Sleep(300);
							gotoxy(1,wherey());
							cout << "                  ";
							gotoxy(10,wherey());
							HienConTro();
						}
					}
				//===============NHAN KY TU=====================
					if (((x >= 94 && x <= 122) || (x >= 65 && x <= 90) || (x >= 48 && x <=57)) && kytu) // a toi z, A toi Z, 0 toi 9
					{
						if (dodaichuoi == 5)
						{
							AnConTro();
							gotoxy(2,wherey());
							cout << "Khong qua 5 ky tu";
							Sleep(300);
							gotoxy(2,wherey());
							cout << "                 ";
							CanhGiua(10,5);
							cout << MangPhu[line/3].LaySoHieu();
							HienConTro();
							
						}
						else
						{
							dodaichuoi++;
							InHoa(x);
							MangPhu[line/3].DatSoHieu(MangPhu[line/3].LaySoHieu() + InHoa(x));
							AnConTro();
							CanhGiua(10,dodaichuoi);
							cout << MangPhu[line/3].LaySoHieu();
							HienConTro();
						}
					}
					x = getch();
			//	}
				// Kiem tra trung SoHieu
			}
		}
		if (line%3 == 1) // Loai
		{
			AnConTro();
			gotoxy(0,2*((line%30)/3 + 1) + 1);
			CanhGiua(30,MangPhu[line/3].LayLoai().length());
			gotoxy(wherex()+MangPhu[line/3].LayLoai().length(),wherey()); // Dua dung vi tri
			HienConTro();
			int dodaichuoi = MangPhu[line/3].LayLoai().length();
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
					//==================XU LY CHUOI===================
						dodaichuoi--;
						string Loai = MangPhu[line/3].LayLoai();
						Loai.erase(Loai.end()-1,Loai.end());
						MangPhu[line/3].DatLoai(Loai);
					//=================XU LY HINH ANH=================
						AnConTro();
						gotoxy(25,wherey());
						cout << "          ";
						CanhGiua(30,dodaichuoi);
						cout << MangPhu[line/3].LayLoai();
						HienConTro();
					}	
					else
					{
						AnConTro();
						gotoxy(24,wherey());
						cout << "Khong the xoa";
						Sleep(300);
						gotoxy(24,wherey());
						cout << "             ";
						gotoxy(30,wherey());
						HienConTro();
					}	
				}
			//==============CHUC NANG======================
				if (((x == 72 || x == 80 || x == 75 || x == 77) && !kytu)  || x == 27 || x == 19)
				{
					if (MangPhu[line/3].LayLoai() != "")
					{
						break; // Khong con thao tac tren dong nay nua
					}
					else
					{
						AnConTro();
						gotoxy(21,wherey());
						cout << "Khong the bo trong";
						Sleep(300);
						gotoxy(21,wherey());
						cout << "                  ";
						gotoxy(30,wherey());
						HienConTro();
					}
				}	
			//=============NHAN CHU CAI====================
				if (((x >= 94 && x <= 122) || (x >= 65 && x <= 90) || (x >= 48 && x <=57)) && kytu) // a toi z, A toi Z, 0 toi 9 
				{
					if (dodaichuoi == 10)
					{
						AnConTro();
						gotoxy(21,wherey());
						cout << "Khong qua 10 ky tu";
						Sleep(300);
						gotoxy(21,wherey());
						cout << "                  ";
						CanhGiua(30,10);
						cout << MangPhu[line/3].LayLoai();
						HienConTro();
					}
					else
					{
						dodaichuoi++;
						InHoa(x);
						MangPhu[line/3].DatLoai(MangPhu[line/3].LayLoai() + InHoa(x));
						AnConTro();
						CanhGiua(30,dodaichuoi);
						cout << MangPhu[line/3].LayLoai();
						HienConTro();
					}
				}
				x = getch();
			}
		}
		if (line%3 == 2) // So Cho
		{
			AnConTro();
			gotoxy(0,2*((line%30)/3 + 1) + 1);
			CanhGiua(50,DoDaiSoDuong(MangPhu[line/3].LaySoCho()));
			gotoxy(wherex() + DoDaiSoDuong(MangPhu[line/3].LaySoCho()),wherey()); // Dua den dung vi tri
			HienConTro();
			int SoCho = MangPhu[line/3].LaySoCho();
			SoCho = LaySo(SoCho,1,x);
			while (SoCho < 20)
			{
				AnConTro();
				gotoxy(45,wherey());
				cout << "So cho > 20";
				Sleep(300);
				gotoxy(45,wherey());
				cout << "           ";
				gotoxy(50,wherey());
				HienConTro();
				SoCho = LaySo(0,1,x);
			}
			AnConTro();
			gotoxy(40,wherey());
			cout << "                   ";
			CanhGiua(50,DoDaiSoDuong(SoCho));
			cout << SoCho;
			HienConTro();
			if (x == -32 || x == 0)
			{
				kytu = 0;
				if (x == -32 || x == 0)
				{
					x = getch();
				}
			}
			MangPhu[line/3].DatSoCho(SoCho);
		}
	}
	if (x == 27)
	{
		int tungdo,hoanhdo = - 1;
		while (1) // So nhat la nguoi dung thich mua lua =))
		{
			
			gotoxy(0,28);
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
// ========================= TIM MAY BAY MAY BAY BANG SOHIEU============================
int TimKiemMayBay(ListMayBay a) // Tra ve vi tri con tro dang tro ve may bay do
{
	// Chua co front_end
	char x;
	string SoHieu = "";
	bool kytu;
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
	while (x != 13 && x != 27) // Khong phai la Enter or Ecs
	{
		if (((x >= 97 && x <= 122) || (x >= 65 && x <= 90)) && kytu ) // a->z, A->Z
		{
			// front_end cho nay ne
			SoHieu = SoHieu + InHoa(x);
			// Thieu front _ end
			cout << SoHieu;
			for (int i = 0; i < a.n; i++)
			{
				int j = 0;
				for ( j = 0; j < SoHieu.length(); j++)
				{
					if (SoHieu[j] != a.data[i]->LaySoHieu()[j])
					{
						break;
					}
				}
				if (j == SoHieu.length()) // So sanh dung den phan tu cuoi cung
				{
					// front end?
					cout << a.data[i]->LaySoHieu();
				}
			}
		}
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
	}
}
//====================================== CLASS CHUYEN BAY ============================================
class ChuyenBay : public MayBay
{
	protected:
		string DiemDen;
		string MaChuyen; // Ma chuyen bay
		Ticket *Ve;
		Day Ngay; // Ngay thang nam
		Time Gio; // Gio phut
		int TrangThai; // 0: Huy chuyen, 1: Con ve, 2: Het ve, 3: Hoan tat
	public:
		void DatDiemDen(string a);
		void DatMaChuyen(string a);
		void DatNgay(Day a);
		void DatGio(Time a);
		void DatTrangThai(int a);
		void TaoDanhSachVe();
		string LayDiemDen();
		string LayMaChuyen();
		Day LayNgay();
		Time LayGio();
		int LayTrangThai();
		Ticket *LayDanhSachVe();
};
//===============================FUNCTION CHUYEN BAY=====================================
void ChuyenBay::DatDiemDen(string a)
{
	DiemDen = a;
}
void ChuyenBay::DatMaChuyen(string a)
{
	MaChuyen = a;
}
void ChuyenBay::TaoDanhSachVe()
{
	Ve = new Ticket [SoCho]; // Ket thua tu MayBay
	for (int i = 0; i < SoCho; i++)
	{
		Ve[i].HanhKhach = NULL;
	}
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
string ChuyenBay::LayDiemDen()
{
	return DiemDen;
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
// =============================== DANH SACH LIEN KET CHUYEN BAY ====================
struct CacChuyenBay
{
	ChuyenBay chuyenbay;
	CacChuyenBay *next = NULL;
};
// ========================= LIST CHUYEN BAY ========================================
struct ListChuyenBay
{
	int SoLuong;
	CacChuyenBay *Head = NULL;
	CacChuyenBay *Tail = NULL;
};
// ========================== TAO CHUYEN BAY ==========================================
CacChuyenBay *NewChuyenBay()
{
	CacChuyenBay *p = new CacChuyenBay;
	return p;
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
		if (x == 8) // Backspace
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
// ============================== CAP NHAT TRANG THAI ===============================
void CapNhatTrangThaiChuyenBay(ListChuyenBay a)
{
	CacChuyenBay *p = a.Head;
	for (int i = 0; i < a.SoLuong; i++)
	{
		if (p->chuyenbay.LayTrangThai() == 1 || p->chuyenbay.LayTrangThai() == 2)
		{
			// Kiem tra ve con trong khong, neu con gan TrangThai = 1; neu khong con gan TrangThai = 2
			// Kiem tra ngay gio khoi hanh voi ngay gio hien tai neu qua 3h thi gan TrangThai = 3
		}
		p = p->next;
	}
}
// ============================== IN DANH SACH CHUYEN BAY ====================================
void InDanhSachChuyenBay (ListChuyenBay a, int trang)
{
	AnConTro();
	ChangeColor(8);
	int i = 0;
	KhungChuyenBay();
	int maxtrang;
	if (a.SoLuong % 10 == 0)
	{
		maxtrang = a.SoLuong/10;
	}
	else
	{
		maxtrang = a.SoLuong/10 + 1;
	}
	CapNhatTrangThaiChuyenBay(a);
	CacChuyenBay *p = a.Head;
//	cout << p->chuyenbay.LayMaChuyen();
	if (trang == maxtrang) // Nhieu hon 10 chuyen bay
	{
		while (p != NULL)
		{
			if (i >= (maxtrang - 1)*10  && i < a.SoLuong)
			{
				int DoDaiThoiGian = DoDaiNgay(p->chuyenbay.LayNgay()) + DoDaiGio(p->chuyenbay.LayGio()) + 1;
				gotoxy(0,2*(i%10 + 1) + 1);
				CanhGiua(10,p->chuyenbay.LayMaChuyen().length()); // In Ma Chuyen
				cout << p->chuyenbay.LayMaChuyen();
				CanhGiua(30,DoDaiThoiGian); // In Gio Xuat Phat
				InGio(p->chuyenbay.LayGio());
				cout << " ";
				InNgay(p->chuyenbay.LayNgay());
				CanhGiua(50,5); // In Dia Diem xuat phat
				cout << "TPHCM";
				CanhGiua(70,p->chuyenbay.LayDiemDen().length()); // In Dia Diem den
				for (int i = 0; i < p->chuyenbay.LayDiemDen().length(); i++)
				{
					if (p->chuyenbay.LayDiemDen()[i] == 48) // so '0'
					{
						cout << " ";
					}
					else
					{
						cout << p->chuyenbay.LayDiemDen()[i];
					}
				}
				//========= TRANG THAI ================
				switch (p->chuyenbay.LayTrangThai())
				{
					case 0:
						{
							CanhGiua(90,9);
							cout << "Huy Chuyen";
							break;
						}
					case 1:
						{
							CanhGiua(90,6);
							cout << "Con Ve";
							break;
						}
					case 2:
						{
							CanhGiua(90,6);
							cout << "Het Ve";
							break;
						}
					case 3:
						{
							CanhGiua(90,8);
							cout << "Hoan Tat";
							break;
						}
				}
			}
			// ==================== MA MAY BAY ============================
			CanhGiua(110,p->chuyenbay.LaySoHieu().length());
			cout << p->chuyenbay.LaySoHieu();
			i++;
			p = p->next;
		}
	}
	else
	{
		while (p != NULL)
		{
			if (i >= (trang - 1 )*10 && i <= trang*10 - 1)
			{
				int DoDaiThoiGian = DoDaiNgay(p->chuyenbay.LayNgay()) + DoDaiGio(p->chuyenbay.LayGio()) + 1;
				gotoxy(0,2*(i%10 + 1) + 1);
				CanhGiua(10,p->chuyenbay.LayMaChuyen().length()); // In Ma Chuyen
				cout << p->chuyenbay.LayMaChuyen();
				CanhGiua(30,DoDaiThoiGian); // In Gio Xuat Phat
				InGio(p->chuyenbay.LayGio());
				cout << " ";
				InNgay(p->chuyenbay.LayNgay());
				CanhGiua(50,5); // In Dia Diem xuat phat
				cout << "TPHCM";
				CanhGiua(70,p->chuyenbay.LayDiemDen().length()); // In Dia Diem den
				for (int i = 0; i < p->chuyenbay.LayDiemDen().length(); i++)
				{
					if (p->chuyenbay.LayDiemDen()[i] == 48) // so '0'
					{
						cout << " ";
					}
					else
					{
						cout << p->chuyenbay.LayDiemDen()[i];
					}
				}
				//========= TRANG THAI ================
				switch (p->chuyenbay.LayTrangThai())
				{
					case 0:
						{
							CanhGiua(90,9);
							cout << "Huy Chuyen";
							break;
						}
					case 1:
						{
							CanhGiua(90,6);
							cout << "Con Ve";
							break;
						}
					case 2:
						{
							CanhGiua(90,6);
							cout << "Het Ve";
							break;
						}
					case 3:
						{
							CanhGiua(90,8);
							cout << "Hoan Tat";
							break;
						}
				}
			}
			CanhGiua(110,p->chuyenbay.LaySoHieu().length());
			cout << p->chuyenbay.LaySoHieu();
			i++;
			p = p->next;
		}
	}
	gotoxy(56,25);
	cout << "---" << trang << "/" << maxtrang << "---";
}
#endif
