#include <iostream>
#include <iomanip>
using namespace std;
class Hang;
class Date{
	private:
		int ngay,thang,nam;
	public:
		friend class Hang;
		friend void InSX2017(Hang *A,int n);
};
class Hang{
	private:
		char maHang[10];
		char tenHang[15];
		Date ngaySX;
	public:
		void Nhap();
		void Xuat();
		friend void InSX2017(Hang *A,int n);
};
void Hang::Nhap(){
	cout <<"\nNhap ma hang: ";	fflush(stdin);	gets(maHang);
	cout <<"Nhap ten hang: ";	fflush(stdin);	gets(tenHang);
	cout <<"Nhap ngay,thang,nam san xuat: ";	cin >>ngaySX.ngay>>ngaySX.thang>>ngaySX.nam;
}
void Hang::Xuat(){
	cout <<setw(10)<<maHang;
	cout <<setw(15)<<tenHang;
	cout <<setw(20)<<ngaySX.ngay<<"/"<<ngaySX.thang<<"/"<<ngaySX.nam<<endl;
}
void InSX2017(Hang *A,int n){
	for(int i=0;i<n;i++){
		if(A[i].ngaySX.nam==2017)
			A[i].Xuat();
	}
}
int main(){
	Hang *A;
	int n;
	cout <<"Nhap so luong hang: ";
	cin >>n;
	A=new Hang[n];
	for(int i=0;i<n;i++){
		A[i].Nhap();
	}
	cout <<"\n\n\tDanh sach cac mat hang san xuat nam 2017"<<endl;
	InSX2017(A,n);
	return 0;
}
