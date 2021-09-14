#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class NhanVien;
class Date{
	private:
		int day,month,year;
	public:
		friend class NhanVien;
};
class PhongBan{
	private:
		int maPB;
		char tenPB[50];
		char truongPhong[20];
		int soNV;
	public:
		friend class NhanVien;
		friend void HienThiNVTaiChinh(NhanVien *x,int n);
};
class NhanVien{
	private:
		int maNV;
		char hoDem[25];
		char ten[10];
		Date ngaySinh;
		PhongBan phong;
	public:
		void Nhap();
		void Xuat();
		friend void HienThiNVTaiChinh(NhanVien *x,int n);
		friend void SapXepTen(NhanVien *x,int n);
		friend void Chen(NhanVien *x,int &n);
		friend void XoaMaNV(NhanVien *x,int &n);
};
void NhanVien::Nhap(){
	cout <<"\nNhap ma nhan vien: ";									cin >>maNV;
	cout <<"Nhap ho dem nhan vien: ";			fflush(stdin);		gets(hoDem);
	cout <<"Nhap ten nhan vien: ";				fflush(stdin);		gets(ten);
	cout <<"Nhap ngay,thang,nam sinh cua nhan vien "<<endl;
	cout <<"\tNhap ngay sinh: ";									cin >>ngaySinh.day;
	cout <<"\tNhap thang sinh: ";									cin >>ngaySinh.month;
	cout <<"\tNhap nam sinh: ";										cin >>ngaySinh.year;
	cout <<"Nhap phong ban cua nhan vien "<<endl;
	cout <<"\tNhap ma phong ban: ";									cin >>phong.maPB;
	cout <<"\tNhap ten phong ban: ";			fflush(stdin);		gets(phong.tenPB);
	cout <<"\tNhap truong phong: ";				fflush(stdin);		gets(phong.truongPhong);
	cout <<"\tNhap so nhan vien: ";									cin >>phong.soNV;
}
void NhanVien::Xuat(){
	cout <<setw(10)<<maNV;
	cout <<setw(25)<<hoDem<<" "<<ten;
	cout <<setw(20)<<ngaySinh.day<<"/"<<ngaySinh.month<<"/"<<ngaySinh.year;
	cout <<setw(15)<<phong.maPB;
	cout <<setw(15)<<phong.tenPB;
	cout <<setw(20)<<phong.truongPhong;
	cout <<setw(10)<<phong.soNV<<endl;
}
void HienThiNVTaiChinh(NhanVien *x,int n){
	int dem=0;
	for(int i=0;i<n;i++){
		if(strcmpi(x[i].phong.tenPB,"Tai Chinh")==0){
			++dem;
		}
	}
	if(dem==0)
		cout <<"\n\n\t\tKhong co nhan vien nao o phong Tai Chinh"<<endl;
	else{
		cout <<"\n\n\t\tDanh sach nhan vien o phong Tai Chinh"<<endl;
		for(int i=0;i<n;i++){
			if(strcmpi(x[i].phong.tenPB,"Tai Chinh")==0)
				x[i].Xuat();
		}
	}
}
void SapXepTen(NhanVien *x,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(strcmpi(x[i].ten,x[j].ten)>0){
				NhanVien temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
	}
}
void Chen(NhanVien *x,int &n){
	NhanVien a;
	int k;
	cout <<"\n\tNhap thong tin cho nhan vien moi can chen: "<<endl;
	a.Nhap();
	do{
		cout <<"Nhap vi tri can chen: ";
		cin >>k;
	}while(k<0||k>n);
	for(int i=n;i>k;i--){
		x[i]=x[i-1];
	}
	x[k]=a;
	n++;
}
void XoaMaNV(NhanVien *x,int &n){
	int ma;
	cout <<"Nhap ma nhan vien can xoa: ";
	cin >>ma;
	int index;
	for(int i=0;i<n;i++){
		if(x[i].maNV==ma)
			index = i;
	}
	for(int i=index;i<=n;i++){
		x[i]=x[i+1];
	}
	n--;
}
void TieuDe(){
	cout <<setw(10)<<"Ma NV";
	cout <<setw(25)<<"Ho ten nhan vien";
	cout <<setw(20)<<"Ngay sinh";
	cout <<setw(15)<<"Ma phong ban";
	cout <<setw(15)<<"Ten phong ban";
	cout <<setw(20)<<"Truong phong";
	cout <<setw(10)<<"So NV"<<endl;
}
int main(){
	NhanVien *x;
	int n;
	cout <<"Nhap so luong nhan vien: ";			cin >>n;
	x=new NhanVien[n];
	for(int i=0;i<n;i++){
		x[i].Nhap();
	}
	HienThiNVTaiChinh(x,n);
	cout <<"\n\n\t\tDANH SACH NHAN VIEN SAP XEP THEO THU TU TU DIEN CUA TEN NHAN VIEN"<<endl;
	SapXepTen(x,n);
	TieuDe();
	for(int i=0;i<n;i++){
		x[i].Xuat();
	}
	Chen(x,n);
	cout <<"\n\n\t\tDANH SACH NHAN VIEN SAU KHI THEM "<<endl;
	TieuDe();
	for(int i=0;i<n;i++){
		x[i].Xuat();
	}
	cout <<"\n\n\t\tDanh sach nhan vien sau khi xoa "<<endl;
	TieuDe();
	XoaMaNV(x,n);
	for(int i=0;i<n;i++){
		x[i].Xuat();
	}
	return 0;
}
