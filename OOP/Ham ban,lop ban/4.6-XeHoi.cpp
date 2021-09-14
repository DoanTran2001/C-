#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;

class XeHoi{
	private:
		char nhanHieu[15];
		char hangSX[20];
		char kieuDang[15];
		char mauSon[10];
		int namSX;
		char xuatXu[15];
		int giaBan;
	public:
		void Nhap();
		void Xuat();
		friend void HienThi(XeHoi *A,int n,const char*hangSX);
		friend void SapXep(XeHoi *A,int n);
};
void XeHoi::Nhap(){
	cout <<"\nNhap nhan hieu: ";		fflush(stdin);		gets(nhanHieu);
	cout <<"Nhap hang san xuat: ";		fflush(stdin);		gets(hangSX);
	cout <<"Nhap kieu dang: ";			fflush(stdin);		gets(kieuDang);
	cout <<"Nhap mau son: ";			fflush(stdin);		gets(mauSon);
	cout <<"Nhap nam san xuat: ";							cin >>namSX;
	cout <<"Nhap xuat xu: ";			fflush(stdin);		gets(xuatXu);
	cout <<"Nhap gia ban: ";								cin >>giaBan;
}
void XeHoi::Xuat(){
	cout <<setw(15)<<nhanHieu;
	cout <<setw(15)<<hangSX;
	cout <<setw(15)<<kieuDang;
	cout <<setw(10)<<mauSon;
	cout <<setw(7)<<namSX;
	cout <<setw(10)<<xuatXu;
	cout <<setw(15)<<giaBan<<endl;
}
void HienThi(XeHoi *A,int n,const char*hangSX){
	bool kt=true;
	for(int i=0;i<n;i++){
		if(strcmpi(A[i].hangSX,hangSX)!=0)
			kt==false;
	}
	if(kt==false){
		cout <<"Danh sach xe hoi tren khong co xe nao cua hang "<<hangSX;
	}
	else{
		cout <<"\n\t\tDANH SACH XE HOI CUA HANG "<<hangSX<<endl;
		for(int i=0;i<n;i++){
			if(strcmpi(A[i].hangSX,hangSX)==0){
				A[i].Xuat();
			}
		}
	}
}
void SapXep(XeHoi *A,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(A[i].giaBan>A[j].giaBan){
				XeHoi tg=A[i];
				A[i]=A[j];
				A[j]=tg;
			}
		}
	}
}
int main(){
	XeHoi *A;
	int n;
	cout <<"Nhap so luong xe hoi: ";
	cin >>n;
	A=new XeHoi[n];
	for(int i=0;i<n;i++){
		A[i].Nhap();
	}
	cout <<"\n\n\t\tDANH SACH XE HOI VUA NHAP LA"<<endl;
	for(int i=0;i<n;i++){
		A[i].Xuat();
	}
	HienThi(A,n,"Toyota");
	SapXep(A,n);
	cout <<"\n\n\tDANH SACH SAP XEP THEO CHIEU TANG DAN CUA GIA BAN"<<endl;
	for(int i=0;i<n;i++){
		A[i].Xuat();
	}
	return 0;
}
