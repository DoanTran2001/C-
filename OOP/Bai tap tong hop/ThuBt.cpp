#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class DoanhNghiep;
class Date{
	int day,month,year;
	public:
		void Nhap();
		void Xuat();
		friend void DoanhThu2015(DoanhNghiep *x,int n);
};
class DiaChi{
	private:
		char dienThoai[12];
		char phuong[30];
		char quan[30];
		char thanhPho[30];
	public:
		friend class DoanhNghiep;
		friend void HienThiHN(DoanhNghiep *x,int n);
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
		friend void HienThiHN(DoanhNghiep *x,int n);
		friend void DoanhThu2015(DoanhNghiep *x,int n);
};
void Date::Nhap(){
	cout <<"\nNhap ngay thanh lap: ";		cin >>day;
	cout <<"Nhap thang thanh lap: ";		cin >>month;
	cout <<"Nhap nam thanh lap: ";			cin >>year;
}
void Date::Xuat(){
	cout <<setw(12)<<day<<"/";
	cout <<setw(2)<<month<<"/";
	cout <<setw(4)<<year;
}
void DoanhNghiep::Nhap(){
	cout <<"\nNhap ma doanh nghiep: ";		cin >>maDN;
	cout <<"Nhap ten doanh nghiep: ";		fflush(stdin);			gets(tenDN);
	ngayTL.Nhap();
	cout <<"\n\tNhap thong tin dia chi"<<endl;
	cout <<"Nhap so dien thoai: ";		fflush(stdin);			gets(diaChi.dienThoai);
	cout <<"Nhap phuong: ";		fflush(stdin);			gets(diaChi.phuong);
	cout <<"Nhap quan: ";		fflush(stdin);			gets(diaChi.quan);
	cout <<"Nhap thanh pho: ";		fflush(stdin);			gets(diaChi.thanhPho);
	cout <<"Nhap ten giam doc: ";		fflush(stdin);			gets(giamDoc);
	cout <<"Nhap tong doanh thu: ";		cin >>doanhThu;
}
void DoanhNghiep::Xuat(){
	cout <<setw(10)<<maDN;
	cout <<setw(15)<<tenDN;
	ngayTL.Xuat();
	cout <<setw(15)<<diaChi.dienThoai;
	cout <<setw(15)<<diaChi.phuong;
	cout <<setw(15)<<diaChi.quan;
	cout <<setw(15)<<diaChi.thanhPho;
	cout <<setw(15)<<giamDoc;
	cout <<setw(15)<<doanhThu<<endl;
}
void TieuDe(){
	cout <<setw(10)<<"Ma DN";
	cout <<setw(15)<<"Ten DN";
	cout <<setw(20)<<"Ngay TL";
	cout <<setw(15)<<"Dien Thoai";
	cout <<setw(15)<<"Phuong";
	cout <<setw(15)<<"Quan";
	cout <<setw(15)<<"Thanh Pho";
	cout <<setw(15)<<"Giam Doc";
	cout <<setw(15)<<"Doanh Thu"<<endl;
	
}
void HienThiHN(DoanhNghiep *x,int n)
{
 	int dem = 0;
 	for(int i=0;i<n;i++){
 		if(strcmpi(x[i].diaChi.thanhPho,"Ha Noi")==0)
 			++dem;
	 }
	 if(dem==0)
	 	cout <<"\n\tKhong co doanh nghiep nao o Ha Noi"<<endl;
	else{
		cout <<"\n\tDanh sach doanh nghiep o Ha Noi"<<endl;
		TieuDe();
		for(int i=0;i<n;i++){
 			if(strcmpi(x[i].diaChi.thanhPho,"Ha Noi")==0)
 				x[i].Xuat();
	 	}
	}
}
void DoanhThu2015(DoanhNghiep *x,int n){
  	int dem = 0;
  	long tong=0;
  	for(int i=0;i<n;i++){
  		if(x[i].ngayTL.year==2015)
  			++dem;
	}
	if(dem==0)
		cout <<"\n\tKhong co doanh nghiep nao thanh lap nam 2015"<<endl;
	else{
		
		for(int i=0;i<n;i++){
  			if(x[i].ngayTL.year==2015)
  				tong +=x[i].doanhThu;
		}
	}
	cout <<"\n\tTong doanh thu cua nhung doanh nghiep thanh lap nam 2015: "<<tong;
}
int main(){
	DoanhNghiep *x;
	int n;
	cout <<"Nhap so luong doanh nghiep: ";
	cin >>n;
	x=new DoanhNghiep[n];
	for(int i=0;i<n;i++){
		x[i].Nhap();
	}
	cout <<"\n\n\t\tDANH SACH DOANH NGHIEP"<<endl;
	TieuDe();
	for(int i=0;i<n;i++){
		x[i].Xuat();
	}
	HienThiHN(x,n);
	DoanhThu2015(x,n);
	return 0;
} 
