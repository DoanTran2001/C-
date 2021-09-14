#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class Nguoi{
	protected:
		char hoTen[20];
		int ngaySinh;
		char queQuan[20];
};
class KySu:public Nguoi{
	private:
		char nganh[20];
		int namTN;
	public:
		void Nhap();
		void Xuat();
};
void KySu::Nhap(){
	cout <<"\nNhap ho ten: ";		fflush(stdin);		gets(hoTen);
	cout <<"Nhap ngay sinh: ";							cin >>ngaySinh;
	cout <<"Nhap que quan: ";		fflush(stdin);		gets(queQuan);
	cout <<"Nhap nganh hoc: ";		fflush(stdin);		gets(nganh);
	cout <<"Nhap nam tot nghiep: ";						cin >>namTN;
}
void KySu::Xuat(){
	cout <<setw(20)<<hoTen;
	cout <<setw(15)<<ngaySinh;
	cout <<setw(15)<<queQuan;
	cout <<setw(15)<<nganh;
	cout <<setw(15)<<namTN<<endl;
}
int main(){
	KySu *x;
	int n;
	cout <<"Nhap so luong ky su: ";
	cin >>n;
	x=new KySu[n];
	for(int i=0;i<n;i++){
		x[i].Nhap();
	}
	cout <<"\n\n\t\tDANH SACH KY SU VUA NHAP"<<endl;
	cout <<setw(20)<<"Ho ten";
	cout <<setw(15)<<"Ngay sinh;
	cout <<setw(15)<<"Que quan";
	cout <<setw(15)<<"Nganh hoc";
	cout <<setw(15)<<"Nam TN"<<endl;
	for(int i=0;i<n;i++){
		x[i].Xuat();
	}
	return 0;
}
