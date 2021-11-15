#include<iostream>
#include<windows.h>
#include<iomanip>
#include "SList.h"

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




