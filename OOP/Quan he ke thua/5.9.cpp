#include <iostream>
#include <iomanip>
using namespace std;
class SanPham{
	protected:
		char tenSP[20];
		int namSX;
		float giaThanh;
	public:
		void Nhap();
		void Xuat();
};
class HoaDon:public SanPham{
	private:
		int soLuong;
		float giaBan;
	public:
		void Nhap();
		void Xuat();
		float ThanhTien(){
			return soLuong * giaBan;
		}
		float TinhThue(){
			return 0.1 * ThanhTien();
		}
		float TinhLai(){
			return (giaBan - giaThanh) * soLuong;
		}
		friend void SapXep(HoaDon *x, int n);
		friend float TongTien(HoaDon *x, int n);
		friend void TienThueMax(HoaDon *x, int n);
};
void SanPham::Nhap(){
	cout <<"\nNhap ten san pham: ";	fflush(stdin);	gets(tenSP);
	cout <<"Nhap nam san xuat: ";	cin >>namSX;
	cout <<"Nhap gia thanh: ";		cin >>giaThanh;
}
void SanPham::Xuat(){
	cout <<setw(20)<<tenSP;
	cout <<setw(15)<<namSX;
	cout <<setw(10)<<giaThanh;
}
void HoaDon::Nhap(){
	SanPham::Nhap();
	cout <<"Nhap so luong ban: ";	cin >>soLuong;
	cout <<"Nhap gia ban: ";		cin >>giaBan;
}
void HoaDon::Xuat(){
	SanPham::Xuat();
	cout <<setw(10)<<soLuong;
	cout <<setw(10)<<giaBan;
	cout <<setw(15)<<ThanhTien();
	cout <<setw(15)<<TinhThue();
	cout <<setw(15)<<TinhLai()<<endl;
}
void SapXep(HoaDon *x, int n){
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			if(x[i].TinhLai()<x[j].TinhLai()){
				HoaDon y = x[i];
				x[i] = x[j];
				x[j] = y;
			}
		}
	}
}
float TongTien(HoaDon *x, int n){
	float tong = 0;
	for(int i = 0; i < n; i ++){
		tong += x[i].ThanhTien();
	}
	return tong;
}
void TienThueMax(HoaDon *x, int n){
	int max = x[0].TinhThue();
	for(int i = 0; i < n; i ++){
		if(x[i].TinhLai() > max){
			max = x[i].TinhLai();
		}
	}
	for( int i = 0; i < n; i ++){
		if(x[i].TinhLai() == max){
			x[i].Xuat();
		}
	}
}
void TieuDe(){
	cout <<setw(5)<<"STT";
	cout <<setw(20)<<"Ten SP";
	cout <<setw(15)<<"Nam SX";
	cout <<setw(10)<<"Gia Thanh";
	cout <<setw(10)<<"So Luong";
	cout <<setw(10)<<"Gia Ban";
	cout <<setw(15)<<"Thanh Tien";
	cout <<setw(15)<<"Thue";
	cout <<setw(15)<<"Lai"<<endl;
}
int main(){
	HoaDon *x;
	int n;
	cout <<"Nhap so luong hoa don: ";
	cin >>n;
	x = new HoaDon[n];
	for(int i = 0; i < n; i++){
		x[i].Nhap();
	}
	cout <<"\n\n\t\tTHONG TIN CAC HOA DON VUA NHAP"<<endl;
	TieuDe();
	for(int i = 0; i < n; i++){
		cout <<setw(5)<<i+1;
		x[i].Xuat();
	}
	SapXep(x,n);
	cout <<"\n\n\t\tSAP XEP DANH SACH THEO TIEN LAI GIAM DAN"<<endl;
	TieuDe();
	for(int i = 0; i < n; i++){
		cout <<setw(5)<<i + 1;
		x[i].Xuat();
	}
	cout <<"\n\tTong tien cua cac hoa don: "<<TongTien(x,n)<<endl;
	TienThueMax(x,n);
	return 0;
}
