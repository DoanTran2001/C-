#include <iostream>
#include <iomanip>
using namespace std;
class HocSinh{
	private:
		char ten[25];
		char gioiTinh[5];
		int namSinh;
		float diemTongKet;
	public:
		void Nhap(){
			cout <<"\nNhap ten sinh vien: ";		fflush(stdin);		gets(ten);
			cout <<"Nhap gioi tinh: ";		fflush(stdin);		gets(gioiTinh);
			cout <<"Nhap nam sinh: ";		cin >>namSinh;
			cout <<"Nhap diem tong ket: ";	cin >>diemTongKet;
		}
		void Xuat(){
			cout <<setw(15)<<ten;
			cout <<setw(10)<<gioiTinh;
			cout <<setw(10)<<namSinh;
			cout <<setw(10)<<diemTongKet<<endl;
		}
		friend void TimKiemTheoTen(HocSinh *a, int n, const char *sv);
};
void TimKiemTheoTen(HocSinh *a, int n,const char *sv[15]){
	int dem = 0;
	for(int i = 0; i < n; i ++){
		if(strcmpi(a[i].ten,sv) == 0){
			++dem;
		}
	}
	if(dem == 0){
		cout <<"\nTrong danh sach hoc sinh tren khong co hoc sinh nao ten"<<sv;
	}
	else{
		for(int i = 0; i < n; i ++){
			if(strcmpi(a[i].ten,sv) == 0){
				a[i].Xuat();
			}
		}
	}
}
int main(){
	HocSinh *a;
	int n;
	cout <<"Nhap so luong hoc sinh: ";
	cin >>n;
	a = new HocSinh[n];
	for(int i = 0; i < n; i ++){
		a[i].Nhap();
	}
	for(int i = 0; i < n; i ++){
		a[i].Xuat();
	}
	TimKiemTheoTen(a,n,"Lan");
	return 0;
}
