#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
class PTB2{
	private:
		int a,b,c;
	public:
		PTB2(){
			a=b=c=0;
		}
		PTB2(int a,int b,int c){
			this->a=a;
			this->b=b;
			this->c=c;
		}
		void Nhap();
		void Xuat();
		void Giai();
};
void PTB2::Nhap(){
	cout <<"Nhap he so a: ";	cin >>a;
	cout <<"Nhap he so b: ";	cin >>b;
	cout <<"Nhap he so c: ";	cin >>c;
}
void PTB2::Xuat(){
	cout <<a<<"X^2 ";
	if(b<0){
		cout <<b<<"X ";
	}
	else{
		cout <<"+ "<<b<<"X ";
	}
	if(c<0){
		cout <<c<<" = 0"<<endl;
	}
	else{
		cout <<"+ "<<c<<"= 0"<<endl;
	}
}
void PTB2::Giai(){
	float x1,x2;
	float dental=b*b-4*a*c;
	if(dental<0)
		cout <<"Phuong trinh vo nghiem";
	else if(dental==0){
		x1=x2=-b/(2*a);
		cout <<"PT co nghiem kep: x1=x2="<<x1;
	}
	else{
		x1=(-b+sqrt(dental))/(2*a);
		x2=(-b-sqrt(dental))/(2*a);
		cout <<"PT co 2 nghiem: x1= "<<x1<<"; x2= "<<x2;
	}
}
int main(){
	PTB2 A(1,2,1);
	A.Xuat();
	A.Giai();
	return 0;
}
