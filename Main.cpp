#include<iostream>
#include<windows.h>
#include<iomanip>
#include "SList.h"
#include "ToaDo.h"
//========================== ham main ============================
int main(){
	int n;
	SList list ;
	ThongTin sv;
	system("color 30");
		gotoxy(20,5);
		cout <<"                      #                     #";gotoxy(20,6);
		cout <<"     @@@   @    @    @    @    @    @    @    @";gotoxy(20,7);
		cout <<"    @   @  @    @   @ @   @ @  @    @     @  @";gotoxy(20,8);
		cout <<"    @   @  @    @  @@@@@  @  @ @    @      @@";gotoxy(20,9);
		cout <<"     @@@    @@@@  @     @ @   @@    @@@@   @";gotoxy(20,10);
		gotoxy(18,11);
		cout <<"                                            #";gotoxy(18,12);
		cout <<"         #                                #   #";gotoxy(18,13);
		cout <<"  @@@@@  @  @    @  @   @    @     @  @  @@@@@@  @    @";gotoxy(18,14);
		cout <<" @@      @  @@   @  @   @    @     @  @  @       @@   @";gotoxy(18,15);
		cout <<"   @@@   @  @  @ @  @@@@@     @   @   @  @@@@@@  @  @ @";gotoxy(18,16);
		cout <<"     @@  @  @   @@  @   @      @ @    @  @       @   @@";gotoxy(18,17);
		cout <<" @@@@@   @  @    @  @   @       @     @  @@@@@@  @    @";gotoxy(18,18);
	while(true){
		cout <<endl;
		cout <<"\t\t||******************************************************||"<<endl;
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
		cout <<"\t\t||******************************************************||"<<endl;
		cout <<"\t\t\t\tVui long chon: ";
		cin >>n;
		cin.ignore();
		if( n< 1 || n >8 ){
			cout <<endl;
			cout <<"\t\t\tTHONG BAO: Chon sai, vui long chon lai !!!"<<endl;
		}
		
	switch(n){
		case 1:
			system("cls");
			list.AddLast();
			break;
		case 2:
			system("cls");
			list.Updata(); 
			break;
		case 3:
			system("cls");
			list.DeleteSV();
			break;
		case 4:
			system("cls");
			list.SearchName();
			break;
		case 5:
			system("cls");
			list.SearchID();
			break;
		case 6:
			system("cls");
			list.SapXepDTB();
			break;
		case 7:
			system("cls");
			list.XuatDS();
			break;
		case 8:
			exit(0);
			break;
	}
	}
	return 0;
}




