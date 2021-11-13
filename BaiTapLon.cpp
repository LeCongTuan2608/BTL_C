#include<iostream>
#include<windows.h>

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
	cout <<"\t\tDiem trung binh: "<<DTB<<endl;
	cout <<"\t\tDiem ren luyen: "<<DRL<<endl;	
	cout <<"\t\tDiem cong: "<<DC<<endl;	
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
	cout <<"\t\tNganh: "<<Nganh<<endl;
	cout <<"\t\tKhoa: "<<Khoa<<endl;
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
	cout <<"\t\tHo va ten: "<<HoTen<<endl;
	cout <<"\t\tMa so sinh vien: "<<MSSV<<endl;
	cout <<"\t\tGioi tinh: "<< GioiTinh <<endl;
	cout <<"\t\tQue quan: "<< QueQuan <<endl;
	cout <<"\t\tNgay sinh: "<<Ngay<<"-"<<Thang<<"-"<<Nam<<endl;
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
		
	if ( Head == Tail && Head == NULL ){
		cout <<"\t\t--> Dang sach rong, khong the chinh sua!!"<<endl;
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
	if(Head == Tail && Head == NULL){
		cout <<"\t\tDanh sach trong, khong the hien thi"<<endl;
	}
	int i=0;
	for(Node *p = Head; p != NULL ; p = p->next){
		cout<<endl;
		i++;
		cout<<"\t\tTHONG TIN SINH VIEN THU "<<i;
		p->data.Xuat();
	}
}

//========================== ham main ============================
int main(){
	int n;
	SList list ;
	ThongTin sv;
	system("color 30");
	while(true){
		cout <<endl;
		cout <<"\t\t==================== Quan Ly Sinh Vien ==================="<<endl;
		cout <<"\t\t||		1. Nhap thong tin sinh vien		||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		2. Chinh sua thong tin sinh vien 	||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		3. Xoa sinh vien			||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		4. Tim sinh vien theo ten		||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		5. Tim sinh vien theo ID		||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		6. Sap xep sinh vien theo DTB		||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		7. Xuat thong tin sv			||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		8. THOAT!!				||"<<endl;
		cout <<"\t\t=========================================================="<<endl;
		cout <<"\t\t\t\tVui long chon: ";
		cin >>n;
		cin.ignore();
		if( n< 1 || n >8 ){
			cout <<endl;
			cout <<"\t\t\tTHONG BAO: Chon sai, vui long chon lai !!!"<<endl;
		}
		
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




