#include <iostream>
using namespace std;
class SoPhuc{
	private:
		int thuc,ao;
	public:
		SoPhuc(){
			thuc=ao=0;
		}
		SoPhuc(int thuc,int ao){
			this->thuc=thuc;
			this->ao=ao;
		}
		~SoPhuc(){
			
		}
		friend ostream& operator<<(ostream &os,SoPhuc x);
		SoPhuc operator+(SoPhuc x);
};
ostream& operator<<(ostream &os,SoPhuc x){
	os <<x.thuc;
	if(x.ao<0)
		os <<x.ao<<"i"<<endl;
	else
		os <<"+"<<x.ao<<"i"<<endl;
	return os;
}
SoPhuc SoPhuc::operator+(SoPhuc x){
	SoPhuc tong;
	tong.thuc = this->thuc + x.thuc;
	tong.ao = this->ao + x.ao;
	return tong;
}
int main(){
	SoPhuc x(2,3),y(-4,-2);
	SoPhuc a;
	cout <<a;
	cout <<"So phuc x: "<<x<<endl;
	cout <<"So phuc y: "<<y<<endl;
	cout <<"So phuc tong: "<<x+y;
}
