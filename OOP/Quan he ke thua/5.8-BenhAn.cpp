#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class BenhNhan{
	protected:
		char hoTen[20];
		char queQuan[20];
		int namSinh;
	public:
		void Nhap();
		void Xuat();
};
class BenhAn:public BenhNhan{
	private:
		char tenBenhAn[20];
		float tienVienPhi;
	public:
		void Nhap();
		void Xuat();
		int TinhTuoi();
		friend void SapXepTuoi(BenhAn *x,int n);
		friend void BenhNhanNhoHon10Tuoi(BenhAn *x,int n);
		friend void TienVienPhiCaoNhat(BenhAn *x,int n);
};
void BenhNhan::Nhap(){
	cout <<"\nNhap ten benh nhan: ";	fflush(stdin);		gets(hoTen);
	cout <<"Nhap que quan: ";			fflush(stdin);		gets(queQuan);
	cout <<"Nhap nam sinh: ";								cin >>namSinh;
}
void BenhNhan::Xuat(){
	cout <<setw(20)<<hoTen;
	cout <<setw(15)<<queQuan;
	cout <<setw(15)<<namSinh;
}
void BenhAn::Nhap(){
	BenhNhan::Nhap();
	cout <<"Ten benh an: ";				fflush(stdin);		gets(tenBenhAn);
	cout <<"Tien vien phi: ";								cin >>tienVienPhi;
}
void BenhAn::Xuat(){
	BenhNhan::Xuat();
	cout <<setw(15)<<tenBenhAn;
	cout <<setw(15)<<tienVienPhi<<endl;
}
int BenhAn::TinhTuoi(){
	return 2020-namSinh;
}
void SapXepTuoi(BenhAn *x,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(x[i].TinhTuoi()<x[j].TinhTuoi()){
				BenhAn temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
	}
}
void BenhNhanNhoHon10Tuoi(BenhAn *x,int n){
	int dem=0;
	for(int i=0;i<n;i++){
		if(x[i].TinhTuoi()<10){
			++dem;
		}
	}
	if(dem==0)
		cout <<"\n\n\t\tKHONG CO BENH NHAN NAO NHO HON 10 TUOI"<<endl;
	else{
		cout <<"\n\n\t\tDANH SACH CAC BENH NHAN NHO HON 10 TUOI"<<endl;
		for(int i=0;i<n;i++){
			if(x[i].TinhTuoi()<10){
				x[i].Xuat();
			}
		}
	}	
}
void TienVienPhiCaoNhat(BenhAn *x,int n){
	float max = x[0].tienVienPhi;
	for(int i=1;i<n;i++){
		if(x[i].tienVienPhi>max)
			max = x[i].tienVienPhi;
	}
	cout <<"\n\t\tTHONG TIN BENH NHAN CO VIEN PHI CAO NHAT"<<endl;
	for(int j=0;j<n;j++){
		if(x[j].tienVienPhi==max)
			x[j].Xuat();
	}
}
int main(){
	BenhAn *x;
	int n;
	cout <<"Nhap so benh an: ";
	cin >>n;
	x=new BenhAn[n];
	for(int i=0;i<n;i++){
		x[i].Nhap();
	}
	cout <<"\n\n\t\tDANH SACH CAC BENH AN"<<endl;
	cout <<setw(20)<<"Ho ten"<<setw(15)<<"Que quan"<<setw(15)<<"Nam sinh"<<setw(15)<<"Ten benh an"<<setw(15)<<"Tien vien phi"<<endl;
	for(int i=0;i<n;i++){
		x[i].Xuat();
	}
	SapXepTuoi(x,n);
	cout <<"\n\t\tDANH SACH SAP XEP THEO TUOI GIAM DAN CUA CAC BENH NHAN"<<endl;
	cout <<setw(20)<<"Ho ten"<<setw(15)<<"Que quan"<<setw(15)<<"Nam sinh"<<setw(15)<<"Ten benh an"<<setw(15)<<"Tien vien phi"<<endl;
	for(int i=0;i<n;i++){
		x[i].Xuat();
	}
	BenhNhanNhoHon10Tuoi(x,n);
	TienVienPhiCaoNhat(x,n);
	return 0;
}
