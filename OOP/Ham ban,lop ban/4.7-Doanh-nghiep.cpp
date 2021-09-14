#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class DoanhNghiep;
class Date{
	private:
		int day,month,year;
	public:
		void Nhap();
		void Xuat();
};
class DiaChi{
	private:
		char dienThoai[12];
		char phuong[30];
		char quan[30];
		char thanhPho[30];
	public:
		friend class DoanhNghiep;
		friend void HienThi(DoanhNghiep *dn,int n,const char*thanhPho);
};
class DoanhNghiep{
	private:
		int maDN;
		char tenDN[60];
		Date ngayTL;
		DiaChi diaChi;
		char giamDoc[30];
		long doanhThu;
	public:
		void Nhap();
		void Xuat();
		friend void HienThi(DoanhNghiep *dn,int n,const char*thanhPho);
		friend void Sua(DoanhNghiep *dn,int n);
		friend long TongDoanhThu2015(DoanhNghiep *dn,int n);
};
void Date::Nhap(){
	cout <<"Nhap ngay: ";	cin >>day;
	cout <<"Nhap thang: ";	cin >>month;
	cout <<"Nhap nam: ";	cin >>year;
}
void Date::Xuat(){
	cout <<setw(20)<<day<<"/ "<<month<<"/ "<<year;
}
void DoanhNghiep::Nhap(){
	cout <<"\nNhap ma doanh nghiep: ";	cin >>maDN;
	cout <<"Nhap ten doanh nghiep: ";	fflush(stdin);	gets(tenDN);
	ngayTL.Nhap();
	cout <<"Nhap so dien thoai: ";		fflush(stdin);	gets(diaChi.dienThoai);
	cout <<"Nhap phuong: ";				fflush(stdin);	gets(diaChi.phuong);
	cout <<"Nhap quan: ";				fflush(stdin);	gets(diaChi.quan);
	cout <<"Nhap thanh pho: ";			fflush(stdin);	gets(diaChi.thanhPho);
	cout <<"Nhap ten giam doc: ";		fflush(stdin);	gets(giamDoc);
	cout <<"Nhap doanh thu(ti USD): ";			cin >>doanhThu;
}
void DoanhNghiep::Xuat(){
	cout <<setw(10)<<maDN;
	cout <<setw(20)<<tenDN;
	ngayTL.Xuat();
	cout <<setw(10)<<diaChi.dienThoai;
	cout <<setw(15)<<diaChi.phuong;
	cout <<setw(15)<<diaChi.quan;
	cout <<setw(15)<<diaChi.thanhPho;
	cout <<setw(20)<<giamDoc;
	cout <<setw(15)<<doanhThu<<endl;
}
void HienThi(DoanhNghiep *dn,int n,const char*thanhPho){
	bool kt=true;
	for(int i=0;i<n;i++){
		if(strcmpi(dn[i].diaChi.thanhPho,thanhPho)!=0)
			kt=false;
	}
	if(kt==false)
		cout <<"\n\n\tKHONG CO DOANH NGHIEP NAO O THANH PHO "<<thanhPho<<endl;
	else{
		cout <<"\n\n\t\tCAC DOANH NGHIEP O THANH PHO "<<thanhPho<<endl;
		for(int i=0;i<n;i++){
			if(strcmpi(dn[i].diaChi.thanhPho,thanhPho)==0){
				dn[i].Xuat();
			}
		}
		
	}
}
void Sua(DoanhNghiep *dn,int n){
	int suama,dem=0;
	cout <<"Nhap vao 1 doanh nghiep: ";
	cin >>suama;
	for(int i=0;i<n;i++){
		if(suama==dn[i].maDN){
			dem++;
			dn[i].Nhap();
		}
	}
	if(dem==0){
		cout <<"Khong co doanh nghiep nao co ma "<<suama;
	}
	else{
		for(int i=0;i<n;i++){
			dn[i].Xuat();
		}
	}
}
int main(){
	DoanhNghiep *dn;
	int n;
	cout <<"Nhap so luong doanh nghiep: ";
	cin >>n;
	dn = new DoanhNghiep[n];
	for(int i=0;i<n;i++){
		dn[i].Nhap();
	}
	HienThi(dn,n,"Ha Noi");
	Sua(dn,n);
	return 0;
}
