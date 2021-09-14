#include<iostream>
#include<iomanip>
using namespace std;
class hanghoa{
	private:
		char maHang[20],tenHang[20];
		int soLuong;
		float giaBan;
	public:
		void nhap();
		void xuat();
		friend float tongTien(hanghoa a[],int n);
};
class HOADON{
	private:
		char maHoaDon[20],donViNhanHang[20],nguoiThanhToan[20],nguoiNhan[20];
		float soTien;
		hanghoa HH;
		char ngayThanhToan[10];
	public:
		void nhap();
		void xuat();
		friend float tongTien();				 
};
void hanghoa::nhap{
	cout<<"Nhap ma hang : ";	fflush(stdin)	gets(maHang);
	cout<<"Nhap ten hang : ";	fflush(stdin)	gets(tenHang);
	cout<<"Nhap so luong : ";	fflush(stdin)	cin>>soLuong;
	cout<<"Nhap gia ban : ";	fflush(stdin)	cin>>giaBan;
}
void hanghoa::xuat{
	cout<<setw(10)<<left<<maHang;
	cout<<setw(20)<<left<<tenHang;
	cout<<setw(10)<<left<<soLuong;
	cout<<setw(10)<<left<<giaBan;
}
float tongTien{
	return soLuong*giaBan;
}
void HOADON::nhap(){
	cout<<"Nhap ma hoa don : ";	  		fflush(stdin);				gets(maHoaDon);
	cout<<"Nhap don vi nhan hang : ";	fflush(stdin) ; 				gets(donViNhanHang);
	cout<<"Nhap nguoi thanh toan : ";	fflush(stdin) ;				gets(nguoiThanhToan);
	cout<<"Nhap nguoi nhan  : ";	  	fflush(stdin);				gets(nguoiNhan);
	cout<<"\t\tNhap thong tin hang hoa "<<endl;
	HH.nhap();
	cout<<"Nhap ngay thanh toan (D/M/Y)  : ";	  fflush(stdin)	;	gets(nguoiNhan);
}
void HOADON::xuat(){
	cout<<setw(20)<<left<<gets(maHoaDon);
	cout<<setw(20)<<left<<gets(donViNhanHang);
	cout<<setw(20)<<left<<gets(nguoiThanhToan);
	cout<<setw(20)<<left<<gets(nguoiNhan);
	cout<<"\t\tNhap thong tin hang hoa "<<endl;
	HH.xuat();
	cout<<setw(20)<<left<<gets(nguoiNhan);
}
int main(){
	HOADON x;
	x.nhap();
	return 0;
}
