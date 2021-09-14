#include <iostream>
#include <iomanip>

using namespace std;
class SinhVien{
	private:
		char maSV[15];
		char tenSV[30];
		char lop[15];
		char khoa[10];
	public:
		void Nhap();
		void Xuat();
};
class Mon{
	private:
		char tenMon[30];
		int soTrinh;
		float diem;
	public:
		friend class PhieuBaoDiem;
};
class PhieuBaoDiem{
	private:
		SinhVien x;
		Mon *y;
		int n;
	public:
		void Nhap();
		void Xuat();
};
void SinhVien::Nhap(){
	cout <<"Nhap ma sinh vien: ";		fflush(stdin);		gets(maSV);
	cout <<"Nhap ten sinh vien: ";		fflush(stdin);		gets(tenSV);
	cout <<"Nhap lop: ";				fflush(stdin);		gets(lop);
	cout <<"Nhap khoa: ";				fflush(stdin);		gets(khoa);
}
void SinhVien::Xuat(){
	cout <<"Ma sinh vien: "<<maSV;
	cout <<"\tTen sinh vien: "<<tenSV<<endl;
	cout <<"Lop: "<<lop;
	cout <<"\t\tKhoa: "<<khoa<<endl;
}
void PhieuBaoDiem::Nhap(){
	x.Nhap();
	cout <<"\nNhap bang diem";
	cout <<"\nNhap so luong mon hoc: ";
	cin >>n;
	y = new Mon[n];
	for(int i = 0;i < n;i ++){
		cout <<"\tNhap mon thu "<<i+1<<endl;
		cout <<"Nhap ten mon: ";		fflush(stdin);		gets(y[i].tenMon);
		cout <<"Nhap so trinh: ";		cin >>y[i].soTrinh;
		cout <<"Nhap diem: ";			cin >>y[i].diem;
	}
}
void PhieuBaoDiem::Xuat(){
	x.Xuat();
	cout <<"Bang diem"<<endl;
	cout <<setw(15)<<"Ten mon"<<setw(10)<<"So trinh"<<setw(10)<<"Diem"<<endl;
	for(int i =0;i < n;i ++){
		cout <<setw(15)<<y[i].tenMon;
		cout <<setw(10)<<y[i].soTrinh;
		cout <<setw(10)<<y[i].diem<<endl;
	}
	float dtb = 0;
	int tongSoTrinh = 0;
	for(int i = 0;i < n;i ++){
		dtb += y[i].soTrinh * y[i].diem;
		tongSoTrinh += y[i].soTrinh;
	}
	cout <<"\t\tDiem trung binh: "<<dtb/tongSoTrinh;
}
int main(){
	PhieuBaoDiem A;
	A.Nhap();
	cout <<"\n\n\t\tPHIEU BAO DIEM"<<endl;
	A.Xuat();
	return 0;
}
