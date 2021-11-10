#include<iostream>
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

// return ve class diem so
DiemSo ThongTin::getdiemso(){
	return diemso;
}


// return ve class nganh
NGANH ThongTin::getnganh(){
	return nganh;
}


//ham nhap thong tin 1 sinh vien
void ThongTin::Nhap(){
	cout <<"Ho va ten: ";
	cin.ignore();
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
	diemso.Nhap();
	nganh.Nhap();

}
//ham xuat thong tin 1 sinh vien
void ThongTin::Xuat(){
	cout <<"\nHo va ten: "<<HoTen<<endl;
	cout <<"Ma so sinh vien: "<<MSSV<<endl;
	cout <<"Gioi tinh: "<< GioiTinh <<endl;
	cout <<"Que quan: "<< QueQuan <<endl;
	cout <<"Ngay sinh: "<<Ngay<<"-"<<Thang<<"-"<<Nam<<endl;
	diemso.Xuat();
	nganh.Xuat();
}



//============================= class node ==============================
class Node{
	public:
		ThongTin data;
		Node *next;
};


// ==================== class danh sach =================================
class SList{
	public:
		Node *Head;
		Node *Tail;
		int size;
	public:
		SList();
		~SList();
		
		Node *CreateNode(ThongTin sv);
		void AddFirst(ThongTin sv);
		void AddLast(ThongTin sv);
		void DeleteSV(ThongTin sv);
		void SearchName(ThongTin sv);
		void SearchID(ThongTin sv);
		void SapXepDTB();
		void NhapDS(ThongTin &sv);
		void XuatDS();	
				
};

//ham tao mac dinh
SList::SList(){
	Head = NULL;
	Tail = NULL;
	size = 0;
}
SList::~SList(){
}
//ham tao ra 1 node
Node* SList::CreateNode(ThongTin sv){
	Node* p =new Node;
	p->data = sv;
	p->next = NULL;
	return p;
}

//ham them 1 sinh vien vao dau danh sach
void SList::AddFirst(ThongTin sv){
	Node *p = CreateNode(sv);
	p->next = Head;
	if(size == 0)
		Tail = p;
	size++;
}

//ham them 1 sinh vien vao cuoi danh sach
void SList::AddLast(ThongTin sv){
	Node*p = CreateNode(sv);
	
	if(size == 0){
		Tail = Head = p;
		Tail->next = NULL;
		Head->next = NULL;
	}
	else{
		Tail->next = p;
		Tail =p;
	}
	size++;
}

//ham xoa 1 sinh vien
void SList::DeleteSV(ThongTin sv){
	
}

//ham tim kiem sinh vien theo ten
void SList::SearchName(ThongTin sv){
	
}

//ham tim kiem sinh vien theo mssv
void SList::SearchID(ThongTin sv){
	
}

//ham sap xep sinh vien theo diem trung binh
void SList::SapXepDTB(){
	
}

void SList::NhapDS(ThongTin &sv){
	sv.Nhap();
}

//ham xuat ra danh sach sinh vien
void SList::XuatDS(){
	for(Node *t = Head; t != NULL ; t = t->next){
		t->data.Xuat();
	}
}


//========================== ham main ============================

int main(){
	SList list ;
	int n;
	cout <<"So luong sinh vien can nhap: ";
	cin >> n;
	
	//bo vao` vong` lap while ,, thay i<n = list.szie
	for(int i=0; i<n;i++){
		ThongTin sv;
		cout <<"Sinh vien thu "<<i+1<<endl<<endl;
		sv.Nhap();
		list.AddLast(sv);
	}
	
		list.XuatDS();
	
	
	
	
//	ThongTin tt;
//	DiemSo diem;
//	NGANH nganh;
//	
//	SinhVien *sv= &tt;
//	sv->Nhap();
//	diem.Nhap();
//	nganh.Nhap();
//
//	sv->Xuat();
//	diem.Xuat();
//	nganh.Xuat();

	return 0;
}
