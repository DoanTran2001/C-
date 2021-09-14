#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Khoa{
	private:
		char maKhoa[15];
		char tenKhoa[15];
		char truongKhoa[20];
	public:
		friend class TruongDH;
};
class Ban{
	private:
		char maBan[15];
		char tenBan[15];
		char ngayThanhLap[20];
	public:
		friend class TruongDH;
};
class Truong{
	protected:
		char maTruong[15];
		char tenTruong[20];
		char diaChi[20];
	public:
		void Nhap();
		void Xuat();
};
class TruongDH:public Truong{
	private:
		Khoa *x;
		int n;
		Ban *y;
		int m;
	public:
		void Nhap();
		void Xuat();
};
void Truong::Nhap(){
	cout <<"Nhap ma truong: ";		fflush(stdin);		gets(maTruong);
	cout <<"Nhap ten truong: ";		fflush(stdin);		gets(tenTruong);
	cout <<"Nhap dia chi truong: ";	fflush(stdin);		gets(diaChi);
}
void Truong::Xuat(){
	cout <<"Ma Truong: "<<maTruong<<endl;
	cout <<"Ten Truong: "<<tenTruong<<endl;
	cout <<"Dia chi truong: "<<diaChi<<endl;
}
void TruongDH::Nhap(){
	Truong::Nhap();
	cout <<"Nhap so luong khoa: ";
	cin >>n;
	x = new Khoa[n];
	for(int i = 0; i < n; i ++){
		cout <<"\nNhap ma khoa: ";	fflush(stdin);		gets(x[i].maKhoa);
		cout <<"Nhap ten khoa: ";	fflush(stdin);		gets(x[i].tenKhoa);
		cout <<"Nhap truong khoa: ";	fflush(stdin);		gets(x[i].truongKhoa);
	}
	cout <<"\nNhap so luong ban: ";
	cin >>m;
	y = new Ban[m];
	for(int j = 0; j < m; j ++){
		cout <<"\nNhap ma ban: ";		fflush(stdin);		gets(y[j].maBan);
		cout <<"Nhap ten ban: ";		fflush(stdin);		gets(y[j].tenBan);
		cout <<"Nhap ngay thanh lap: ";		fflush(stdin);		gets(y[j].ngayThanhLap);
	}
}
void TruongDH::Xuat(){
	Truong::Xuat();
	for(int i = 0; i < n; i ++){
		cout <<setw(10)<<x[i].maKhoa;
		cout <<setw(15)<<x[i].tenKhoa;
		cout <<setw(15)<<x[i].truongKhoa<<endl;
	}
	for(int j = 0; j < m; j ++){
		cout <<setw(10)<<y[j].maBan;
		cout <<setw(15)<<y[j].tenBan;
		cout <<setw(15)<<y[j].ngayThanhLap<<endl;
	}
}
int main(){
	TruongDH A;
	A.Nhap();
	cout <<"\n\n\t\tTHONG TIN TRUONG DAI HOC VUA NHAP"<<endl;
	A.Xuat();
	return 0;
}
