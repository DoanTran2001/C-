#include <iostream>
#include <iomanip>

using namespace std;
class NhanVien{
	private:
		char tenNhanVien[25];
		char chucVu[15];
	public:
		void Nhap();
		void Xuat();
};
class Phong{
	private:
		char phong[20];
		char maPhong[15];
		char truongPhong[25];
	public:
		void Nhap();
		void Xuat();
};
class TaiSan{
	private:
		char tenTaiSan[15];
		int soLuong;
		char tinhTrang[15];
	public:
		void Nhap();
		void Xuat();
		friend class PhieuKiemKe;
};
class PhieuKiemKe{
	private:
		char maPhieu[10];
		char ngayKiemKe[15];
		NhanVien x;
		Phong y;
		TaiSan *a;
		int n;
	public:
		void Nhap();
		void Xuat();
};
void NhanVien::Nhap(){
	cout <<"Nhap ten nhan vien: ";			fflush(stdin);		gets(tenNhanVien);
	cout <<"Nhap chuc vu nhan vien: ";		fflush(stdin);		gets(chucVu);
}
void NhanVien::Xuat(){
	cout <<"Nhan vien kiem ke: "<<tenNhanVien;
	cout <<"\t\tChuc vu: "<<chucVu<<endl;
}
void Phong::Nhap(){
	cout <<"Nhap phong kiem ke: ";			fflush(stdin);		gets(phong);
	cout <<"Nhap ma phong: ";				fflush(stdin);		gets(maPhong);
	cout <<"Nhap ten truong phong: ";		fflush(stdin);		gets(truongPhong);
}
void Phong::Xuat(){
	cout <<"Kiem ke tai phong: "<<phong;
	cout <<"\t\tMa phong: "<<maPhong<<endl;
	cout <<"Truong phong: "<<truongPhong<<endl;
}
void TaiSan::Nhap(){
	cout <<"Nhap ten tai san: ";			fflush(stdin);		gets(tenTaiSan);
	cout <<"Nhap so luong: ";									cin >>soLuong;
	cout <<"Nhap tinh trang: ";				fflush(stdin);		gets(tinhTrang);
}
void TaiSan::Xuat(){
	cout <<setw(20)<<tenTaiSan;
	cout <<setw(10)<<soLuong;
	cout <<setw(15)<<tinhTrang<<endl;
}
void PhieuKiemKe::Nhap(){
	cout <<"Nhap ma phieu: ";				fflush(stdin);		gets(maPhieu);
	cout <<"Nhap ngay kiem ke: ";			fflush(stdin);		gets(ngayKiemKe);
	x.Nhap();
	y.Nhap();
	cout <<"Nhap so luong tai san: ";
	cin >>n;
	a = new TaiSan[n];
	for(int i = 0; i < n; i ++){
		a[i].Nhap();
	}
}
void PhieuKiemKe::Xuat(){
	cout <<"\n\n\t\t\tPHIEU KIEM KE TAI SAN"<<endl;
	cout <<"Ma phieu: "<<maPhieu;
	cout <<"\t\t\tNgay kiem ke: "<<ngayKiemKe<<endl;
	x.Xuat();
	y.Xuat();
	for(int i = 0; i < n; i ++){
		a[i].Xuat();
	}
	cout <<"So tai san da kiem ke: "<<n;
	int tong = 0;
	for(int i = 0; i < n; i ++){
		tong += a[i].soLuong;
	}
	cout <<"\tTong so luong: "<<tong;
}
int main(){
	PhieuKiemKe A;
	A.Nhap();
	A.Xuat();
	return 0;
}
