#include <iostream>
#include <iomanip>
using namespace std;
class Array{
	private:
		float *a;
		int n;
	public:
		friend istream& operator>>(istream &is,Array &A);
		friend ostream& operator<<(ostream &os,Array A);
		Array operator++();
		Array operator--();
};
istream& operator>>(istream &is,Array &A){
	cout <<"Nhap so luong phan tu cua mang: ";
	is >>A.n;
	A.a = new float[A.n];
	for(int i = 0; i < A.n; i++){
		cout <<" A[" <<i + 1<<"]= ";
		is >> A.a[i];
	}
	return is;
}
ostream& operator<<(ostream &os,Array A){
	for(int i = 0;i < A.n; i++){
		os <<A.a[i]<<" ";
	}
	return os;
}
Array Array::operator++(){
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			if(a[i] > a[j]){
				float temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
Array Array::operator--(){
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			if(a[i] < a[j]){
				float temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main(){
	Array A;
	cin >>A;
	cout <<"\n\tMang vua nhap la: "<<A;
	++A;
	cout <<"\n\tMang sau khi sap xep tang dan la: "<<A;
	--A;
	cout <<"\n\tMang sau khi sap xep giam dan la: "<<A;
	return 0;
} 
