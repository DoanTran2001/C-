#include <iostream>
#include <iomanip>
using namespace std;
class SinhVien{
	private:
		char maSV[10];
		char hoTen[20];
		float diemToan,diemLy,diemHoa;
	public:
		void Nhap();
		void Xuat();
		friend void SapXep(SinhVien *a,int n);
};
void SinhVien::Nhap(){
	cout <<"\nNhap ma sinh vien: ";	fflush(stdin);	gets(maSV);
	cout <<"Nhap ten sinh vien: ";	fflush(stdin);	gets(hoTen);
	cout <<"Nhap diem toan: ";						cin >>diemToan;
	cout <<"Nhap diem ly: ";						cin >>diemLy;
	cout <<"Nhap diem hoa: ";						cin >>diemHoa;
}
void SinhVien::Xuat(){
	cout <<setw(10)<<maSV;
	cout <<setw(15)<<hoTen;
	cout <<setw(10)<<diemToan;
	cout <<setw(10)<<diemLy;
	cout <<setw(10)<<diemHoa;
	cout <<setw(10)<<diemToan+diemLy+diemHoa<<endl;
}
void SapXep(SinhVien *a,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].diemToan+a[i].diemLy+a[i].diemHoa>a[j].diemToan+a[j].diemLy+a[j].diemHoa){
				SinhVien tg=a[i];
				a[i]=a[j];
				a[j]=tg;
			}
		}
	}
}
int main() {
	SinhVien *a;
	int n;
	cout <<"Nhap so luong sinh vien: ";		cin >>n;
	a=new SinhVien[n];
	for(int i=0;i<n;i++){
		a[i].Nhap();
	}
	SapXep(a,n);
	cout <<"\n\n\t\tDANH SACH SINH VIEN"<<endl;
	cout <<setw(10)<<"MaSV"<<setw(15)<<"Ho ten"<<setw(10)<<"Diem toan"<<setw(10)<<"Diem ly"<<setw(10)<<"Diem hoa"<<setw(10)<<"Tong"<<endl;
	for(int i=0;i<n;i++){
		a[i].Xuat();
	}
	return 0;
}
