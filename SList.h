#include<iostream>
#include<windows.h>
#include<iomanip>
#include "SinhVien.h"
using namespace std;


//============================= class node ==============================
class Node{
	private:
		ThongTin data;
		Node *next;
	public:
		friend class SList;
};

int size = 0;
// ==================== class danh sach =================================
class SList{
	private:
		Node *Head;
		Node *Tail;
	public:
		SList();
		~SList();
		
		Node *CreateNode(ThongTin sv);
		void AddFirst();
		void AddLast();
		
		bool TimKiem(string id);
		void DeleteFirst();
		void DeleteLast();
		void DeleteSV();
		
		void SearchName();
		void SearchID();
		
		void Updata();
		void SapXepDTB();
		void XuatDS();
				
};

//ham tao mac dinh
SList::SList(){
	Head = NULL;
	Tail = NULL;
}
//ham huy
SList::~SList(){
}

//ham tao ra 1 node
Node* SList::CreateNode(ThongTin sv){
	size++;
	Node* p =new Node;
	p->data = sv;
	p->next = NULL;
	return p;
}
//ham them 1 sinh vien vao dau danh sach
void SList::AddFirst(){
	ThongTin sv;
	cout<<endl;
	cout <<"\t\tNHAP THONG TIN SINH VIEN";
	sv.Nhap();
	Node *p = CreateNode(sv);
	p->next = Head;
	if(Head == Tail && Head == NULL)
		Tail = p;

}

//ham them 1 sinh vien vao cuoi danh sach
void SList::AddLast(){
	ThongTin sv;
	cout<<endl;
	cout <<"\t\tNHAP THONG TIN SINH VIEN"<<endl<<endl;;
	sv.Nhap();
	Node*p = CreateNode(sv);
	if(Head == Tail && Head == NULL){
		Tail = Head = p;
		Tail->next = NULL;
		Head->next = NULL;
	}
	else{
		Tail->next = p;
		Tail =p;
	}
}

// ham xoa node dau tien
void SList::DeleteFirst(){
	Node *p = Head;
	Head = Head->next;
	delete p;
	size--;
	cout <<"\t\tDa xoa xong~"<<endl;
}
//ham xoa node cuoi
void SList::DeleteLast(){
	Node *p;
	for( Node *k = Head; k!= NULL; k = k->next){
		if(k == Tail){		
			Tail = p;
			Tail->next = NULL;
			delete k;
			size--;
			cout <<"\t\tDa xoa xong~"<<endl;
			return;
		}
		p = k;
	}
}
bool SList::TimKiem(string id){
	for(Node *k = Head; k != NULL; k = k->next){
		if (k->data.getMSSV() == id){
			return 0;
		}
	}
	return 1;
}
//ham xoa 1 node bat ki
void SList::DeleteSV(){
	string x; 		// pos id can xoa
	cout<<endl;
	if(Head == Tail && Head == NULL){
		cout <<"\t\tDanh sach rong, khong the xoa"<<endl;
		return;
	}
	cout <<"\t\tNhap ID can xoa: ";
	cin >> x;
	
	if(Head->data.getMSSV() == x ){
		DeleteFirst();
		return;
	}
	
	if(Tail->data.getMSSV() == x){
		DeleteLast();
		return;
	}
	
	Node *p; //node *p: la node truoc node can xoa
	for(Node *k = Head; k != NULL; k = k->next){
		if( k->data.getMSSV() == x ){
			p->next = k->next; 
			delete k; 
			size--;
			cout <<"\t\tDa xoa xong~"<<endl;
			return;	
		}
		p = k; // p = k->next, chay tiep' vong` lap
				// neu k = pos thi` lam` lenh if, luc' nay` p van~ la` node nam truoc k
	}
	if(TimKiem(x)){
		cout <<"\t\tKhong tim thay sinh vien can xoa!"<<endl;
	}

}

//ham tim kiem sinh vien theo ten
void SList::SearchName(){
	string x;
	cout<<endl;
	if( size == 0 ){
		cout <<"\t\tDanh sach trong, khong the tim"<<endl;
		return;
	}
	cout <<"\t\tNhap ten can tim: ";
	cin >> x;
	Node *p = Head;
	for(Node *p = Head; p != NULL; p = p->next ){
		if( p->data.getHoTen() == x ){
			p->data.Xuat();
		}
	}
}

//ham tim kiem sinh vien theo mssv
void SList::SearchID(){
	string x;
	cout<<endl;
	if( size == 0 ){
		cout <<"\t\tDanh sach trong, khong the tim"<<endl;
		return;
	}
	cout <<"\t\tNhap ma so sinh vien can tim: ";
	cin >> x;
	for(Node *p = Head; p != NULL; p = p->next ){
		if( p->data.getMSSV()== x ){
			p->data.Xuat();
		}
	}
}

//  ham chinh sua thong tin sv
void SList::Updata(){
	ThongTin sv;
	string x;
	Node *p;
	cout<<endl;	
	if ( Head == Tail && Head == NULL ){
		cout <<"\t\tDang sach rong, khong the chinh sua!!"<<endl;
		return;
	}
			
	cout <<"\t\tNhap ID sinh vien can chinh sua:";
	cin >> x;

	if(TimKiem(x)){
		cout <<"\t\tKhong tim thay sinh vien!!"<<endl;
	}
	
	if( Head->data.getMSSV() == x){
		cin.ignore();
		sv.Nhap();
		p = Head;
		p->data= sv;
		cout <<"\t\tDa chinh sua~"<<endl;
		return;
	}
	
	if( Tail->data.getMSSV() == x ){
		cin.ignore();
		sv.Nhap();
		p = Tail;
		p->data= sv;
		cout <<"\t\tDa chinh sua~"<<endl;
		return;
	}
	
	for(Node *k = Head; k != NULL; k = k->next){
		if( k->data.getMSSV() == x ){
			cin.ignore();
			sv.Nhap();
			k->data = sv;
			cout <<"\t\tDa chinh sua~"<<endl;
			return;
		}
	}
}


//ham sap xep sinh vien theo diem trung binh cao nhat
void SList::SapXepDTB(){
	cout<<endl;
	if ( Head == Tail && Head == NULL ){
		cout <<"\t\tDang sach rong, khong the sap xep!!"<<endl;
		return;
	}
	
	for(Node *k = Head; k != NULL; k = k->next){
		for(Node *t = k->next; t != NULL; t = t->next){
			if( k->data.getdiemso().getDTB() < t->data.getdiemso().getDTB() ){
				swap( k->data, t->data );
			}
		}
	}
	cout <<"\t\tDa sap xep xong~"<<endl;
}

//ham xuat ra danh sach sinh vien
void SList::XuatDS(){
	cout<<endl;
	if(Head == Tail && Head == NULL){
		cout <<"\t\tDanh sach trong, khong the hien thi"<<endl;
	}
	int i=0;
	for(Node *p = Head; p != NULL ; p = p->next){
		cout<<endl;
		i++;
		cout<<"\t\t\t\t\tTHONG TIN SINH VIEN THU "<<i;
		p->data.Xuat();
	}
}
