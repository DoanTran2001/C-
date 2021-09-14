#include <iostream>
#include <string.h>
using namespace std;
void Nhap(string *a, int n){
	for(int i = 0; i < n; i ++){
		fflush(stdin);
		getline(cin,a[i]);
	}
}
void Xuat(string *a, int n){
	for(int i = 0; i < n; i ++){
		cout <<a[i]<<" ";
	}
}
// Thuat toan tim kiem tuan tu
int TKTT(string *a, int n, string x){
	for(int i = 0; i < n; i ++){
		if(a[i] == x)
			return i;
	}
	return -1;
}
// Thuat toan tim kiem nhi phan
int TKNP(string *a, int n, string x, int l, int r){
	if(l > r){
		return -1;
	}
	else{
		int m = (l + r) / 2;
		if(x == a[m])
			return m;
		else if(x > a[m])
			return TKNP(a,n,x,m+1,r);
		else
			return TKNP(a,n,x,l,m-1);
	}
}
int main(){
	string *a;
	int n;
	cout <<"Nhap so luong tu: ";
	cin >>n;
	a = new string[n];
	Nhap(a,n);
	cout <<"Danh sach cac tu vua nhap la: ";
	Xuat(a,n);
	string x;
	cout <<"\nNhap tu can tim kiem: ";
	fflush(stdin);
	getline(cin,x);
	if(TKTT(a,n,x) == -1)
		cout <<"Tu vua nhap khong co trong tu dien"<<endl;
	else{
		cout <<"Tu do co trong tu dien, o vi tri "<<TKTT(a,n,x) + 1<<endl;
	}
	
	if(TKNP(a,n,x,0,n) == -1)
		cout <<"Tu vua nhap khong co trong tu dien"<<endl;
	else{
		cout <<"Tu do co trong tu dien, o vi tri "<<TKNP(a,n,x,0,n) + 1<<endl;
	}
	return 0;
}
