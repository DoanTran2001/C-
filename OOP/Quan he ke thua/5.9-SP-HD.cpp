#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class SanPham{
	protected:
		char tenSP[15];
		int namSX;
		float giaThanh;
	public:
		void Nhap();
		void Xuat();
};
class HoaDon:public SanPham{
	private:
		int soLuong;
		int giaBan;
	public:
		void Nhap();
		void Xuat();
		int ThanhTien(){
			return soLuong*giaBan;
		};
		float TinhLai(){
			return (giaBan-giaThanh)*soLuong;
		}
		friend void SapXepTienLai(HoaDon *x,int n);
		friend void HienThi(HoaDon *x,int n);
};
void SanPham::Nhap(){
	cout <<"\nNhap ten san pham: ";		fflush(stdin);		gets(tenSP);
	cout <<"Nhap nam san xuat: ";							cin >>namSX;
	cout <<"Nhap gia thanh: ";								cin >>giaThanh;
}
void SanPham::Xuat(){
	cout <<setw(15)<<tenSP;
	cout <<setw(10)<<namSX;
	cout <<setw(15)<<giaThanh;
}
void HoaDon::Nhap(){
	SanPham::Nhap();
	cout <<"Nhap so luong ban: ";
	cin >>soLuong;
	cout <<"Nhap gia ban: ";
	cin >>giaBan;
}
void HoaDon::Xuat(){
	SanPham::Xuat();
	cout <<setw(10)<<soLuong;
	cout <<setw(10)<<giaBan<<endl;
}
void SapXepTienLai(HoaDon *x,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(x[i].TinhLai()<x[j].TinhLai()){
				HoaDon tg = x[i];
				x[i] = x[j];
				x[j] =  tg;
			}
		}
	}
}
void HienThi(HoaDon *x,int n){
	for(int i=0;i<n;i++){
		cout <<setw(5)<<i+1;
		cout <<setw(15)<<x[i].tenSP;
		cout <<setw(10)<<x[i].giaThanh;
		cout <<setw(10)<<x[i].soLuong;
		cout <<setw(10)<<x[i].giaBan;
		cout <<setw(10)<<x[i].ThanhTien();
		cout <<setw(15)<<0.1*x[i].ThanhTien();
		cout <<setw(10)<<x[i].TinhLai()<<endl;
	}
}
int main(){
	HoaDon *x;
	int n;
	cout <<"Nhap so luong hoa don: ";
	cin >>n;
	x = new HoaDon[n];
	for(int i=0;i<n;i++){
		x[i].Nhap();
	}
	SapXepTienLai(x,n);
	cout <<setw(15)<<"tenSP";
	cout <<setw(10)<<"namSX";
	cout <<setw(15)<<"giaThanh";
	cout <<setw(10)<<"soLuong";
	cout <<setw(10)<<"giaBan"<<endl;
	for(int i=0;i<n;i++){
		x[i].Xuat();
	}
	cout <<"\n\n\t\tDanh sach hoa don"<<endl;
	cout <<setw(5)<<"STT";
		cout <<setw(15)<<"tenSP";
		cout <<setw(10)<<"giaThanh";
		cout <<setw(10)<<"soLuong";
		cout <<setw(10)<<"giaBan";
		cout <<setw(15)<<"ThanhTien";
		cout <<setw(15)<<"Thue";
		cout <<setw(10)<<"TinhLai"<<endl;
	HienThi(x,n);
	return 0;
}
