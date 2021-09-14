#include <iostream>
#include <iomanip>
using namespace std;

class Array{
	protected:
		float *a;
		int n;
	public:
		friend istream& operator >>(istream &is, Array &A);
		friend ostream& operator <<(ostream &os, Array A);
		Array operator++();
		Array operator--();
		Array operator-();
};
istream& operator >>(istream &is, Array &A){
	cout <<"Nhap so luong phan tu: ";			is >>A.n;
	A.a = new float[A.n];
	for(int i = 0; i < A.n; i ++){
		cout <<"A[" << i + 1 <<"]= ";
		is >>A.a[i];
	}
	return is;
}
ostream& operator <<(ostream &os, Array A){
	for(int i = 0; i < A.n; i ++){
		os <<A.a[i]<<" ";
	}
	return os;
}
Array Array::operator++(){
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			if(a[i] > a[j]){
				float tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}
Array Array::operator--(){
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			if(a[i] < a[j]){
				float tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}
Array Array::operator-(){
	for(int i = 0; i < n; i ++){
		a[i] = -a[i];
	}
}

//*************************Mang 2 chieu*************************

class Mang2Chieu{
	private:
		float **a;
		int dong, cot;
	public:
		friend istream& operator>>(istream &is,Mang2Chieu &A);
		friend ostream& operator<<(ostream &os,Mang2Chieu A);
		Mang2Chieu operator+(Mang2Chieu A);
		Mang2Chieu operator-(Mang2Chieu A);
};
istream& operator>>(istream &is,Mang2Chieu &A){
	cout <<"Nhap so dong: ";						is >>A.dong;
	cout <<"Nhap so cot: ";							is >>A.cot;
	A.a = new float*[A.dong];
	for(int i = 0; i < A.dong; i ++){
		A.a[i] = new float[A.cot];
	}
	for(int i = 0; i < A.dong; i ++){
		for(int j = 0; j < A.cot; j ++){
			is >>A.a[i][j];
		}
	}
	return is;
}
ostream& operator <<(ostream &os,Mang2Chieu A){
	for(int i = 0; i < A.dong; i ++){
		for(int j = 0; j < A.cot; j ++){
			os <<"\t\t"<<A.a[i][j]<<" ";
		}
		os <<endl;
	}
	return os;
}
Mang2Chieu Mang2Chieu::operator+(Mang2Chieu A){
	Mang2Chieu tong;
	if(dong == A.dong && cot == A.cot){
		tong.dong = dong;
		tong.cot = cot;
		tong.a = new float*[tong.dong];
		for(int i = 0; i < tong.dong; i ++){
			tong.a[i] = new float[tong.cot];
		}
		for(int i = 0; i < dong; i ++){
			for(int j = 0; j < cot; j ++){
				tong.a[i][j] = a[i][j] + A.a[i][j];
			}
		}
	}
	else{
		cout <<"\n\tHai ma tran khong cung kich thuoc nen khong cong duoc"<<endl;
		tong.dong = tong.cot = 0;
	}
	return tong;
}
Mang2Chieu Mang2Chieu::operator-(Mang2Chieu A){
	Mang2Chieu hieu;
	if(dong == A.dong && cot == A.cot){
		hieu.dong = dong;
		hieu.cot = cot;
		hieu.a = new float*[hieu.dong];
		for(int i = 0; i < hieu.dong; i ++){
			hieu.a[i] = new float[hieu.cot];
		}
		for(int i = 0; i < dong; i ++){
			for(int j = 0; j < cot; j ++){
				hieu.a[i][j] = a[i][j] - A.a[i][j];
			}
		}
	}
	else{
		cout <<"\n\tHai ma tran khong cung kich thuoc nen khong tru duoc";
		hieu.dong = hieu.cot = 0;
	}
	return hieu;
}
int main(){
//	Array a;
//	cin >>a;
//	cout <<"\n\n\tMang vua nhap: ";
//	cout <<a;
//	++a;
//	cout <<"\n\tMang sau khi sap xep tang dan: "<<a;
//	--a;
//	cout <<"\n\tMang sau khi sap xep giam dan: "<<a;
//	-a;
//	cout <<"\n\tMang sau khi doi dau la: "<<a;
	
	
	Mang2Chieu B, C;
	cout <<"\n\tNhap ma tran B"<<endl;
	cin >>B;
	cout <<"\n\t\tMa tran B vua nhap la"<<endl;
	cout <<B;
	cout <<"\n\tNhap ma tran C"<<endl;
	cin >>C;
	cout <<"\n\t\tMa tran C vua nhap la"<<endl;
	cout <<C;
	cout <<"\n\t\tMa tran tong cua B va C la"<<endl;
	Mang2Chieu D = B + C;
	cout << D;
	cout <<endl;
	cout << B - C;
	return 0;
}
