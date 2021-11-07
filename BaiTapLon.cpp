#include<iostream>
using namespace std;

class ThongTin{
	private:
		string Ten, MSSV, GioiTinh, QueQuan;
		int Ngay, Thang, Nam;
	public:
		SinhVien();
		SinhVien(string Ten, string MSSV, string GioiTinh, string QueQuan, int Ngay, int Thang, int Nam);
		void Nhap();
		void Xuat();
		void Ghi_file();
		void Doc_file();
		~ThongTin();		
};

class Khoa:public ThonTin{
	private:
		string Nganh;
		int Khoa;
	public:
		void Nhap();
		void Xuat();
		void Ghi_file();
		void Doc_file();		
};

class Diem:public ThongTin{
	private:
		float DTB, DRL, DC;
	public:
		void Nhap();
		void Xuat();
		void Ghi_file();
		void Doc_file();		
		
};

class HoatDong:public ThongTin{
	private:
		string HD;
		int ThanhTinh;
	public:
		
		void Nhap();
		void Xuat();
		void Ghi_file();
		void Doc_file();		
	
};

class SinhVien:public ThongTin{
	private:
		ThongTin *DSSV;
	public:
		void Nhap();
		void Xuat();
		
		void Ghi_file();
		void Doc_file();
		
		void TimKiemTen();
		void TimKiemMS();
		
};


int main(){
	
	
	
}




