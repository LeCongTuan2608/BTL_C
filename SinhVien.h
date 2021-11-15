#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;


//==================== class co so sinh vien ======================
class SinhVien{
	protected:
		
	public:
		virtual void Nhap() = 0;
		virtual void Xuat() = 0;
};

//=========================== class diem so =======================
class DiemSo:public SinhVien{
	private:
		float DTB, DRL, DC;
	public:
		DiemSo();
		~DiemSo();
		
		float getDTB();
		float getDRL();
		float getDC();
		
		void setDTB();
		void setDRL();
		void setDC();
		
		void Nhap();
		void Xuat();
		
};
//ham tao 
DiemSo::DiemSo(){
	DTB = 0;
	DRL = 0;
	DC = 0;
}
//ham huy
DiemSo::~DiemSo(){
	
}
//ham tra ve dtb
float DiemSo::getDTB(){
	return DTB;
}
//ham tra ve drl
float DiemSo::getDRL(){
	return DRL;
}//ham tra ve dc
float DiemSo::getDC(){
	return DC;
}

//ham nhap diem 1 sinh vien
void DiemSo::Nhap(){
	cout <<"\t\tDiem trung binh: ";
	cin >> DTB;
	cout <<"\t\tDiem ren luyen: ";
	cin >> DRL;
	cout <<"\t\tDiem cong: ";
	cin >> DC;
	cin.ignore();
	
}

//ham xuat diem 1 sinh vien
void DiemSo::Xuat(){
	cout <<"Diem trung binh: "<<setw(6) <<left <<DTB <<setw(6);
	cout <<"\tDiem ren luyen: "<<setw(6) <<left <<DRL << setw(6);	
	cout <<"\tDiem cong: "<<setw(7) <<left <<DC <<setw(7);	
}
//===================class nganh ============================
class NGANH: public SinhVien{
	private:
		string Nganh;
		int Khoa;
	public:
		NGANH();
		~NGANH();
		
		string getNganh();
		int getKhoa();
		
		void setNganh();
		void setKhoa();
		
		void Nhap();
		void Xuat();	
};
// ham tao
NGANH::NGANH(){
	Nganh = " ";
	Khoa = 0;
}
// ham huy
NGANH::~NGANH(){
	
}
// ham nhap nganh vs khoa
void NGANH::Nhap(){
	cout <<"\t\tNganh hoc: ";
	getline(cin, Nganh);
	cout <<"\t\tKhoa: ";
	cin >> Khoa;
}
// ham xuat nganh vs khoa
void NGANH::Xuat(){
	cout <<"\tNganh: "<< setw(15) <<left << Nganh;
	cout <<"\tKhoa: "<< setw(10) <<left << Khoa <<endl;
}

// ==================class thong tin======================
class ThongTin: public SinhVien{
	private:
		string HoTen, MSSV, GioiTinh, QueQuan;
		int Ngay, Thang, Nam;	
		DiemSo diemso;
		NGANH nganh;
		
	public:
		ThongTin();
		~ThongTin();
		
		string getHoTen();
		string getMSSV();
		DiemSo getdiemso();
		NGANH getnganh();

		
		void Nhap();
		void Xuat();
};
// Ham tao mac dinh
ThongTin::ThongTin(){
	HoTen = "";
	MSSV = "";
	GioiTinh = "";
	QueQuan = "";
	Ngay = 0;
	Thang = 0;
	Nam = 0;
	
}
// ham huy
ThongTin::~ThongTin(){
	
}

//return ve ho ten
string ThongTin::getHoTen(){
	return HoTen;
}
// return ve class diem so
DiemSo ThongTin::getdiemso(){
	return diemso;
}


// return ve class nganh
NGANH ThongTin::getnganh(){
	return nganh;
}
string ThongTin::getMSSV(){
	return MSSV;
}


//ham nhap thong tin 1 sinh vien
void ThongTin::Nhap(){
	cout <<"\t\tHo va ten: ";
	getline(cin, HoTen);
	cout <<"\t\tMa so sinh vien: ";
	getline(cin, MSSV);
	cout <<"\t\tGioi tinh: ";
	getline(cin, GioiTinh);
	cout <<"\t\tQue quan: ";
	getline(cin, QueQuan);
	cout <<"\t\tNgay sinh: "<<endl;
	cout <<"\t\tNgay ";
	cin >> Ngay;
	cout <<"\t\tThang ";
	cin >> Thang;
	cout <<"\t\tNam ";
	cin >> Nam;
	diemso.Nhap();
	nganh.Nhap();

}
//ham xuat thong tin 1 sinh vien
void ThongTin::Xuat(){
	cout <<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout <<endl;
	cout <<"Ho va ten: "<<setw(15) <<left <<HoTen <<setw(15);
	cout <<"Ma so sinh vien: "<<setw(10) <<MSSV <<setw(10);
	cout <<"Gioi tinh: "<<setw(5) <<left << GioiTinh <<setw(5);
	cout <<"Que quan: "<<setw(15) <<left << QueQuan <<setw(15);
	cout <<"Ngay sinh: "<< Ngay <<"-"<< Thang <<"-"<<Nam <<endl;
	cout <<endl;	
	diemso.Xuat();
	nganh.Xuat();
	cout <<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;

}

