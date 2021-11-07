#include<iostream>
using namespace std;
// class 1 sinh vien
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
	
}
//ham tao day du tham so
SinhVien::SinhVien(string HoTen, string MSSV, string GioiTinh, string QueQuan, int Ngay, int Thang, int Nam){
	
}
//ham nhap 1 sinh vien
void SinhVien::Nhap(){
	
}
//ham xuat 1 sinh vien
void SinhVien::Xuat(){
	
}


//class diem cua 1 sinh vien
class Diem:public SinhVien{
	private:
		float DTB, DRL, DC;
	public:
		void Nhap();
		void Xuat();
};
//ham nhap diem 1 sinh vien
void Diem::Nhap(){
	
}
//ham xuat diem 1 sinh vien
void Diem::Xuat(){
	
}




// class node 
class Node:public Diem{	
	private:
		SinhVien sv;
		Node *next;	
	public:
		Node(SinhVien sv);
		~Node();
		int getsv(); //tra ve gia tri cho sv
		Node *getnode(); //tra ve Node *next
		void setnode(Node *); //gan *next cho node khac
		void In();
};
//tra ve gia tri cho sv
int Node::getsv(){
	return this->sv;
}
//tra ve Node *next
Node::getnode(){
	return this->next;
}
//ham tao du lieu 
Node::Node(SinhVien sv){
	this->sv = sv;
}

//ham nhap du lieu sinh vien vao node
void Node::In(){
	SinhVien::Nhap();
	Diem::Nhap();
	
}


// class danh sach 
class List:public Node{
	private:
		Node *Head;
		Node *Tail;
		int size;
	public:
		Slist();
		Node* CreateNode(SinhVien sv);
		void AddSV();
		void DeleteSV();
		void Search();
		void SearchID();
		void SapXepDTB();
		void XuatDS();			
};
//ham tao mac dinh
List::Slist(){
	Head = NULL;
	Tail = NULL;
	size = 0;
}

//ham tao node
Node* SList::CreateNode(SinhVien sv){

}
//ham them 1 sinh vien
void List::AddSV(){
	
}
//ham xoa 1 sinh vien
void List::DeleteSV(){
	
}
//ham tim kiem sinh vien theo ten
void List::Search(){
	
}
//ham tim kiem sinh vien theo mssv
void List::SearchID(){
	
}
//ham sap xep sinh vien theo diem trung binh
void List::SapXepDTB(){
	
}
//ham xuat ra danh sach sinh vien
void List::XuatDS(){
	
}


int main(){
	
}


