#include<iostream>
using namespace std;


// ==================class 1 sinh vien======================
class SinhVien{
	private:
		string HoTen, MSSV, GioiTinh, QueQuan;
		int Ngay, Thang, Nam;
	public:
		SinhVien();
		SinhVien(string HoTen, string MSSV, string GioiTinh, string QueQuan, int Ngay, int Thang, int Nam);
		~SinhVien();	
		void Nhap();
		void Xuat();
};

// ham tao mac dinh
SinhVien::SinhVien(){
	HoTen = "";
	MSSV = "";
	GioiTinh = "";
	QueQuan = "";
	Ngay = 0;
	Thang = 0;
	Nam = 0;	
}

//ham tao day du tham so
SinhVien::SinhVien(string HoTen, string MSSV, string GioiTinh, string QueQuan, int Ngay, int Thang, int Nam){
	this->HoTen = HoTen;
	this->MSSV = MSSV;
	this->GioiTinh = GioiTinh;
	this->QueQuan = QueQuan;
	this->Ngay = Ngay;
	this->Thang = Thang;
	this->Nam = Nam;
}
//ham huy
SinhVien::~SinhVien(){
	
}

//ham nhap 1 sinh vien
void SinhVien::Nhap(){
	cout <<"Ho va ten: ";
	getline(cin, HoTen);
	cout <<"Ma so sinh vien: ";
	getline(cin, MSSV);
	cout <<"Gioi tinh: ";
	getline(cin, GioiTinh);
	cout <<"Que quan: ";
	getline(cin, QueQuan);
	cout <<"Ngay sinh: ";
	cout <<"Ngay ";
	cin >> Ngay;
	cout <<"Thang ";
	cin >> Thang;
	cout <<"Nam ";
	cin >> Nam;
}

//ham xuat 1 sinh vien
void SinhVien::Xuat(){
	cout <<"Ho va ten: "<<HoTen<<endl;
	cout <<"Ma so sinh vien: "<<MSSV<<endl;
	cout <<"Gioi tinh: "<< GioiTinh <<endl;
	cout <<"Que quan: "<< QueQuan <<endl;
	cout <<"Ngay sinh: "<<Ngay<<" "<<Thang<<" "<<Nam<<endl;
}


//============================class diem ============================
class Diem:public SinhVien{
	private:
		float DTB, DRL, DC;
	public:
		Diem(float DTB, float DRL, float DC);
		~Diem();
		void Nhap();
		void Xuat();
};

//ham tao day du tham so
Diem::Diem(float DTB, float DRL, float DC){
	this->DTB = DTB;
	this->DRL = DRL;
	this->DC = DC;
}

//ham huy
Diem::~Diem(){
	
}

//ham nhap diem 1 sinh vien
void Diem::Nhap(){
	SinhVien::Nhap();
	cout <<"Diem trung binh: ";
	cin >> DTB;
	cout <<"Diem ren luyen: ";
	cin >> DRL;
	cout <<"Diem cong: ";
	cin >> DC;
	
}

//ham xuat diem 1 sinh vien
void Diem::Xuat(){
	SinhVien::Xuat();
	cout <<"Diem trung binh: "<<DTB<<endl;
	cout <<"Diem ren luyen: "<<DRL<<endl;	
	cout <<"Diem cong: "<<DC<<endl;	
}



//=============================class node ==============================
class Node:public SinhVien{	
	private:
		SinhVien sv;
		Node *next;	
	public:
		Node(SinhVien sv);
		~Node();
		Node *getnode(); //tra ve Node *next
		void In();
};

//ham tao du lieu 
Node::Node(SinhVien sv){
	this->sv = sv;

}

//tra ve Node *next
Node *Node::getnode(){
	return this->next;
}


//ham nhap du lieu sinh vien vao node
void Node::In(){
	this->SinhVien::Nhap();
	
}


// ====================class danh sach =================================
class List:public Node{
	private:
		Node *Head;
		Node *Tail;
		int size;
	public:
		Slist();
		Node* CreateNode(SinhVien sv);
		void AddSV(SinhVien sv);
		void DeleteSV(SinhVien sv);
		void SearchName(SinhVien sv);
		void SearchID(SinhVien sv);
		void SapXepDTB();
		void XuatDS(SinhVien sv);			
};

//ham tao mac dinh
List::Slist(){
	Head = NULL;
	Tail = NULL;
	size = 0;
}

//ham tao ra 1 node
Node* List::CreateNode(SinhVien sv){

}

//ham them 1 sinh vien
void List::AddSV(SinhVien sv){
	
}

//ham xoa 1 sinh vien
void List::DeleteSV(SinhVien sv){
	
}

//ham tim kiem sinh vien theo ten
void List::SearchName(SinhVien sv){
	
}

//ham tim kiem sinh vien theo mssv
void List::SearchID(SinhVien sv){
	
}

//ham sap xep sinh vien theo diem trung binh
void List::SapXepDTB(){
	
}

//ham xuat ra danh sach sinh vien
void List::XuatDS(SinhVien sv){
	
}



//========================== ham main ============================

int main(){
	
}
	
	


