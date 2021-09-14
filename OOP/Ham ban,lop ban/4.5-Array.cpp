#include <iostream>
using namespace std;
class Array{
	private:
		int *value;
		int n;
	public:
		Array(){
			n=0;
		}
		Array(int n){
			this->n=n;
			value= new int[n];
			for(int i=0;i<n;++i)
				value[i]=0;
		}
		~Array(){
			n=0;
			delete []value;
		}
		void Nhap();
		void Xuat();
};
void Array::Nhap(){
	for(int i=0;i<n;++i){
		cout <<"Arr["<<i+1<<"]= ";
		cin >>value[i];
	}
}
void Array::Xuat(){
	for(int i=0;i<n;++i){
		cout <<value[i]<<" ";
	}
}
int main(){
	Array A(5);
	cout <<"Mang vua khoi tao la: ";
	A.Xuat();
	cout <<"\n\t\tNhap mang"<<endl;
	A.Nhap();
	cout <<"\n\tMang vua nhap la: ";
	A.Xuat();
	return 0;
}
