#include<iostream>
using namespace std;


//==================== class co so sinh vien ======================
class SinhVien{
	protected:
		
	public:
		virtual void Nhap() = 0;
		virtual void Xuat() = 0;
};

// ==================class 1 sinh vien======================
class ThongTin: public SinhVien{
	private:
		string HoTen, MSSV, GioiTinh, QueQuan;
		int Ngay, Thang, Nam;	
	public:
		ThongTin();
		~ThongTin();
		void Nhap();
		void Xuat();
};
// Ham tao
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

//ham nhap 1 sinh vien
void ThongTin::Nhap(){
	cout <<"Ho va ten: ";
	getline(cin, HoTen);
	cout <<"Ma so sinh vien: ";
	getline(cin, MSSV);
	cout <<"Gioi tinh: ";
	getline(cin, GioiTinh);
	cout <<"Que quan: ";
	getline(cin, QueQuan);
	cout <<"Ngay sinh: "<<endl;
	cout <<"Ngay ";
	cin >> Ngay;
	cout <<"Thang ";
	cin >> Thang;
	cout <<"Nam ";
	cin >> Nam;

}
//================================ class thong tin =========================
//ham xuat 1 sinh vien
void ThongTin::Xuat(){
	cout <<"\nHo va ten: "<<HoTen<<endl;
	cout <<"Ma so sinh vien: "<<MSSV<<endl;
	cout <<"Gioi tinh: "<< GioiTinh <<endl;
	cout <<"Que quan: "<< QueQuan <<endl;
	cout <<"Ngay sinh: "<<Ngay<<"-"<<Thang<<"-"<<Nam<<endl;

}
//=========================== class diem so =======================
class DiemSo:public SinhVien{
	private:
		float DTB, DRL, DC;
	public:
		DiemSo();
		~DiemSo();
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

//ham nhap diem 1 sinh vien
void DiemSo::Nhap(){
	cout <<"Diem trung binh: ";
	cin >> DTB;
	cout <<"Diem ren luyen: ";
	cin >> DRL;
	cout <<"Diem cong: ";
	cin >> DC;
	cin.ignore();
	
}

//ham xuat diem 1 sinh vien
void DiemSo::Xuat(){
	cout <<"Diem trung binh: "<<DTB<<endl;
	cout <<"Diem ren luyen: "<<DRL<<endl;	
	cout <<"Diem cong: "<<DC<<endl;	
}
//===================class nganh ============================
class NGANH: public SinhVien{
	private:
		string Nganh;
		int Khoa;
	public:
		NGANH();
		~NGANH();
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
	cout <<"Nganh hoc: ";
	getline(cin, Nganh);
	cout <<"Khoa: ";
	cin >> Khoa;
}
// ham xuat nganh vs khoa
void NGANH::Xuat(){
	cout <<"Nganh: "<<Nganh<<endl;
	cout <<"Khoa: "<<Khoa<<endl;
}

//=============================class node ==============================
class Node{
	public:
		int data;
		Node *next;	
};

// ====================class danh sach =================================
class SList{
	private:
		Node *Head;
		Node *Tail;
		int size;
	public:
		SList();
		~SList();
		Node *CreateNode(int data);
		void AddSV(int data);
		void DeleteSV(int data);
		void SearchName(int data);
		void SearchID(int data);
		void SapXepDTB();
		void XuatDS(int data);			
};

//ham tao mac dinh
SList::SList(){
	Head = NULL;
	Tail = NULL;
	size = 0;
}

//ham tao ra 1 node
Node* SList::CreateNode(int data){

}

//ham them 1 sinh vien
void SList::AddSV(int data){
	
}

//ham xoa 1 sinh vien
void SList::DeleteSV(int data){
	
}

//ham tim kiem sinh vien theo ten
void SList::SearchName(int data){
	
}

//ham tim kiem sinh vien theo mssv
void SList::SearchID(int data){
	
}

//ham sap xep sinh vien theo diem trung binh
void SList::SapXepDTB(){
	
}

//ham xuat ra danh sach sinh vien
void SList::XuatDS(int data){
	
}


//========================== ham main ============================

int main(){
	ThongTin tt;
	DiemSo diem;
	NGANH nganh;
	
	SinhVien *sv= &tt;
	sv->Nhap();
	diem.Nhap();
	nganh.Nhap();

	sv->Xuat();
	diem.Xuat();
	nganh.Xuat();

	return 0;
}
