
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
		void DeleteFirst();
		void DeleteLast();
		void DeleteSV();
		void SearchName();
		void SearchID();
		void SapXepDTB();
		void XuatDS();
		Node *Pre(Node *p);	
				
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
// ham tim node truoc node p
Node* SList::Pre(Node *p){
	Node *pre = Head;
	while(pre != p){ 	// vong lap khi khi nao node pre == node p thi dung`
		pre = pre->next;
		return pre;
	}
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
void SList::DeleteFirst(){
	if(size == 0)
		cout <<"Danh sach rong, khong the xoa"<<endl;
		return;
	Node *p = Head;
	Head = Head->next;
	delete Head;
	size--;
	cout <<"Da xoa xong~"<<endl;
}
void SList::DeleteLast(){
	if(size == 0)
		cout <<"Danh sach rong, khong the xoa"<<endl;
		return;
	if(size == 1){
		delete Head;
		size--;
		cout <<"Da xoa xong~"<<endl;
		return;
	}
	Node *p = Pre(Tail);
	Node *t = Tail;
	p->next = NULL;
	delete t;
	size--;
	cout <<"Da xoa xong~"<<endl;

}


//ham xoa 1 sinh vien
void SList::DeleteSV(){
	int pos; 		// pos vi tri can xoa
	if(Head == Tail && Head == NULL){
		cout <<"Danh sach rong, khong the xoa"<<endl;
		return;
	}
	cout <<"Nhap vi tri can xoa: ";
	cin >> pos;
	if(size < pos)
		cout <<"Ngoai pham vi danh sach"<<endl;
		
//====================dang lam dong` nay`============================
}

//ham tim kiem sinh vien theo ten
void SList::SearchName(){

}

//ham tim kiem sinh vien theo mssv
void SList::SearchID(){
	
}

//ham sap xep sinh vien theo diem trung binh
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
		cout <<"======================================"<<endl;
		cout <<"1. Nhap thong tin sv"<<endl;
		cout <<"2. Xuat thong tin sv"<<endl;
		cout <<"3. Xoa sinh vien"<<endl;
		cout <<"vui long chon: ";
		cin >>n;
		cin.ignore();
	switch(n){
		case 1:
			list.AddLast();
			break;
		case 2:
			list.XuatDS(); 
			break;
		case 3:
			list.DeleteLast();
			break;
		case 4:
			exit(0);
			break;
	}
	}
	return 0;
}




