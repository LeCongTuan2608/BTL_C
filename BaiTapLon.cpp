
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
	cout <<"Nhap thong tin sinh vien";
	sv.Nhap();
	Node *p = CreateNode(sv);
	p->next = Head;
	if(Head == Tail && Head == NULL)
		Tail = p;

}

//ham them 1 sinh vien vao cuoi danh sach
void SList::AddLast(){
	ThongTin sv;
	cout <<"Nhap thong tin sinh vien"<<endl;
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
	cout <<"Da xoa xong~"<<endl;
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
			cout <<"Da xoa xong~"<<endl;
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
	if(Head == Tail && Head == NULL){
		cout <<"Danh sach rong, khong the xoa"<<endl;
		return;
	}
	cout <<"Nhap ID can xoa: ";
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
			cout <<"Da xoa xong~"<<endl;
			return;	
		}
		p = k; // p = k->next, chay tiep' vong` lap
				// neu k = pos thi` lam` lenh if, luc' nay` p van~ la` node nam truoc k
	}
	if(TimKiem(x)){
		cout <<"Khong tim thay sinh vien can xoa!"<<endl;
	}

}

//ham tim kiem sinh vien theo ten
void SList::SearchName(){
	string x;
	if( size == 0 ){
		cout <<"Danh sach trong, khong the tim"<<endl;
		return;
	}
	cout <<"Nhap ten can tim: ";
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
	if( size == 0 ){
		cout <<"Danh sach trong, khong the tim"<<endl;
		return;
	}
	cout <<"Nhap ma so sinh vien can tim: ";
	cin >> x;
	for(Node *p = Head; p != NULL; p = p->next ){
		if( p->data.getMSSV()== x ){
			p->data.Xuat();
		}
	}
}

//  ham sinh sua thong tin sv
void SList::Updata(){
	ThongTin sv;
	string x;
	Node *p;
		
	cout <<"Nhap ID sinh vien can chinh sua:";
	cin >> x;
	if(TimKiem(x)){
		cout <<"Khong tim thay sinh vien!!"<<endl;
	}
	
	if( Head->data.getMSSV() == x){
		cin.ignore();
		sv.Nhap();
		p = Head;
		p->data= sv;
		cout <<"Da chinh sua~"<<endl;
		return;
	}
	
	if( Tail->data.getMSSV() == x ){
		cin.ignore();
		sv.Nhap();
		p = Tail;
		p->data= sv;
		cout <<"Da chinh sua~"<<endl;
		return;
	}
	
	for(Node *k = Head; k != NULL; k = k->next){
		if( k->data.getMSSV() == x ){
			cin.ignore();
			sv.Nhap();
			k->data = sv;
			cout <<"Da chinh sua~"<<endl;
			return;
		}
	}
}


//ham sap xep sinh vien theo diem trung binh cao nhat
void SList::SapXepDTB(){

}

//ham xuat ra danh sach sinh vien
void SList::XuatDS(){
	if(Head == Tail && Head == NULL){
		cout <<"Danh sach trong, khong the hien thi"<<endl;
	}
	
	for(Node *p = Head; p != NULL ; p = p->next){
		p->data.Xuat();
	}
}

//========================== ham main ============================

int main(){
	int n;
	SList list ;
	ThongTin sv;
	
	while(true){
		cout <<"=================== Quan Ly Sinh Vien ===================="<<endl;
		cout <<"||		1. Nhap thong tin sv			||"<<endl;
		cout <<"||		2. Chinh sua thong tin sinh vien 	||"<<endl;
		cout <<"||		3. Xoa sinh vien			||"<<endl;
		cout <<"||		4. Tim sinh vien theo ten		||"<<endl;
		cout <<"||		5. Tim sinh vien theo ID		||"<<endl;
		cout <<"||		6. Sap xep sinh vien theo DTB		||"<<endl;
		cout <<"||		7. Xuat thong tin sv			||"<<endl;
		cout <<"||		8. THOAT!!				||"<<endl;
		cout <<"=========================================================="<<endl;
		cout <<"vui long chon: ";
		cin >>n;
		cin.ignore();
		
	switch(n){
		case 1:
			list.AddLast();
			break;
		case 2:
			list.Updata(); 
			break;
		case 3:
			list.DeleteSV();
			break;
		case 4:
			list.SearchName();
			break;
		case 5:
			list.SearchID();
			break;
		case 6:
			list.SapXepDTB();
			break;
		case 7:
			list.XuatDS();
			break;
		case 8:
			exit(0);
			break;
	}
	}
	return 0;
}




