#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class NhaCungCap{
	private:
		char maNCC[15];
		char tenNCC[15];
	public:
		void Nhap();
		void Xuat();
};
class Hang{
	private:
		char tenHang[20];
		float donGia;
		int soLuong;
		float thanhTien;
	public:
		friend class PhieuNhapHang;
};
class PhieuNhapHang{
	private:
		char maPhieu[10];
		char ngayLap[10];
		char diaChi[30];
		NhaCungCap y;
		Hang *x;
		int n;
	public:
		void Nhap();
		void Xuat();
};
void NhaCungCap::Nhap(){
	cout <<"Nhap ma nha cung cap: ";	fflush(stdin);		gets(maNCC);
	cout <<"Nhap ten nha cung cap: ";	fflush(stdin);		gets(tenNCC);
}
void NhaCungCap::Xuat(){
	cout <<"Ma NCC: "<<maNCC;
	cout <<"\t\tTen NCC: "<<tenNCC<<endl;
}
void PhieuNhapHang::Nhap(){
	cout <<"Nhap ma phieu: ";			fflush(stdin);		gets(maPhieu);
	cout <<"Nhap ngay lap: ";			fflush(stdin);		gets(ngayLap);
	y.Nhap();
	cout <<"Nhap dia chi: ";			fflush(stdin);		gets(diaChi);
	cout <<"Nhap so luong hang: ";
	cin >>n;
	x = new Hang[n];
	for(int i = 0;i < n; i++){
		cout <<"\n\tNhap ten hang: ";	fflush(stdin);		gets(x[i].tenHang);
		cout <<"\tNhap don gia: ";							cin >>x[i].donGia;
		cout <<"\tNhap so luong: ";							cin >>x[i].soLuong;
	}
}
void PhieuNhapHang::Xuat(){
	cout <<"Ma phieu: "<<maPhieu;
	cout <<"\t\tNgay lap: "<<ngayLap<<endl;
	y.Xuat();
	cout <<"Dia chi: "<<diaChi<<endl;
	cout <<setw(10)<<"Ten Hang";
	cout <<setw(10)<<"Don Gia";
	cout <<setw(10)<<"So Luong";
	cout <<setw(15)<<"Thanh Tien"<<endl;
	for(int i = 0;i < n;i ++){
		cout <<setw(10)<<x[i].tenHang;
		cout <<setw(10)<<x[i].donGia;
		cout <<setw(10)<<x[i].soLuong;
		cout <<setw(10)<<x[i].donGia*x[i].soLuong<<endl;
	}
	float tong;
	for(int i = 0;i < n;i ++){
		tong += x[i].donGia*x[i].soLuong;
	}
	cout <<"\t\t\tCong thanh tien: "<<tong<<endl;
}
int main(){
	PhieuNhapHang A;
	A.Nhap();
	cout <<"\n\t\tPHIEU NHAP HANG"<<endl;
	A.Xuat();
	return 0;
}
