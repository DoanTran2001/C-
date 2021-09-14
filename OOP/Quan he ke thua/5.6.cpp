#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class HangDienTu;
class SanPham{
	protected:
		char maSP[15];
		char tenSP[25];
		char ngaySX[15];
		float trongLuong;
		char mauSac[10];
	public:
		void Nhap();
		void Xuat();
		friend void TrongLuongMin(HangDienTu *x, int n);
		friend void SapXepGiamTrongLuong(HangDienTu *x, int n);
		friend void HienThi(HangDienTu *x, int n);
};
class HangDienTu:public SanPham{
	private:
		float congSuat;
		int dongDienSuDung;
	public:
		void Nhap();
		void Xuat();
		friend void TrongLuongMin(HangDienTu *x, int n);
		friend void SapXepGiamTrongLuong(HangDienTu *x, int n);
		friend void Them(HangDienTu *x, int &n);
		friend void Xoa(HangDienTu *x, int &n);
		friend void HienThi(HangDienTu *x, int n);
};
void SanPham::Nhap(){
	cout <<"\nNhap ma san pham: ";		fflush(stdin);		gets(maSP);
	cout <<"Nhap ten san pham: ";		fflush(stdin);		gets(tenSP);
	cout <<"Nhap ngay san xuat: ";		fflush(stdin);		gets(ngaySX);
	cout <<"Nhap trong luong: ";		cin >>trongLuong;
	cout <<"Nhap mau sac: ";		fflush(stdin);		gets(mauSac);
}
void SanPham::Xuat(){
	cout <<setw(10)<<maSP;
	cout <<setw(15)<<tenSP;
	cout <<setw(15)<<ngaySX;
	cout <<setw(15)<<trongLuong;
	cout <<setw(15)<<mauSac;
}
void HangDienTu::Nhap(){
	SanPham::Nhap();
	cout <<"Nhap cong suat: ";		cin >>congSuat;
	cout <<"Nhap dong dien su dung: ";		cin >>dongDienSuDung;
}
void HangDienTu::Xuat(){
	SanPham::Xuat();
	cout <<setw(15)<<congSuat;
	cout <<setw(20)<<dongDienSuDung<<endl;
}
void TieuDe(){
	cout <<setw(10)<<"Ma SP";
	cout <<setw(15)<<"Ten SP";
	cout <<setw(15)<<"Ngay SX";
	cout <<setw(15)<<"Trong Luong";
	cout <<setw(15)<<"Mau Sac";
	cout <<setw(15)<<"Cong Suat";
	cout <<setw(20)<<"Dong Dien Su Dung"<<endl;
}
void TrongLuongMin(HangDienTu *x, int n){
	int min = x[0].trongLuong;
	for(int i = 0; i < n; i ++){
		if(x[i].trongLuong < min )
			min = x[i].trongLuong;
	}
	cout <<"\n\n\t\tCac mat hang co trong luong nho nhat"<<endl;
	TieuDe();
	for(int i = 0; i < n; i ++){
		if(x[i].trongLuong == min)
			x[i].Xuat();
	}
}
void SapXepGiamTrongLuong(HangDienTu *x, int n){
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			if(x[i].trongLuong < x[j].trongLuong){
				HangDienTu tg = x[i];
				x[i] = x[j];
				x[j] = tg;
			}
		}
	}
}
void Them(HangDienTu *x, int &n){
	HangDienTu a;
	cout <<"\n\tNhap thong tin cua hang dien tu can them"<<endl;
	a.Nhap();
	int vt;
	do{
		cout <<"Nhap vi tri can them: ";
		cin >>vt;
	}while(vt < 0 || vt > n);
	for(int i = n; i > vt; i --){
		x[i] = x[i - 1];
	}
	x[vt] = a;
	n ++;
}
void Xoa(HangDienTu *x, int &n){
	char xoaMSP[15];
	bool kt = false;
	do{
		
		cout <<"Nhap ma san pham can xoa: ";	fflush(stdin);		gets(xoaMSP);
		for(int i = 0; i< n; i++){
			if(strcmpi(x[i].maSP,xoaMSP) == 0){
				kt = true;
				break;
			}
		}		
	}while(kt == false);
	for(int i = 0; i < n; i ++){
		if(strcmpi(x[i].maSP,xoaMSP) == 0){
			for(int j = i; j < n ; j ++){
				x[j] = x[j + 1];
			}
			--n;
			-- i;
		}
	}
}
void HienThi(HangDienTu *x, int n){
	int dem = 0;
	
	for(int i = 0; i < n; i ++){
		if(strcmpi(x[i].mauSac,"Trang") == 0){
			if(dem == 0){
				TieuDe();
			}
			x[i].Xuat();
			++dem;
		}	
	}
	if(dem == 0){
		cout <<"\n\n\t\tKhong co san pham nao co mau Trang"<<endl;
	}
}

int main(){
	HangDienTu *x;
	int n;
	cout <<"Nhap so luong hang dien tu: ";
	cin >>n;
	x = new HangDienTu[n];
	for( int i = 0; i < n; i ++){
		x[i].Nhap();
	}
	cout <<"\n\n\t\tDANH SACH HANG DIEN TU VUA NHAP "<<endl;
	TieuDe();
	for( int i = 0; i < n; i ++){
		x[i].Xuat();
	}
	TrongLuongMin(x,n);
	SapXepGiamTrongLuong(x,n);
	cout <<"\n\n\t\tDanh sach sap xep theo giam cua trong luong"<<endl;
	TieuDe();
	for( int i = 0; i < n; i ++){
		x[i].Xuat();
	}
	
	cout <<"\n\n\t\tDanh sach sau khi them"<<endl;
	Them(x,n);
	TieuDe();
	for( int i = 0; i < n; i ++){
		x[i].Xuat();
	}
	
	Xoa(x,n);
	cout <<"\n\n\t\tDanh sach sau khi xoa "<<endl;
	TieuDe();
	for(int i = 0; i < n; i ++){
		x[i].Xuat();
	}
	HienThi(x,n);
	return 0;
}
