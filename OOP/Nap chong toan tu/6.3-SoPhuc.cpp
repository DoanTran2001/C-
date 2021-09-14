#include <iostream>
#include <iomanip>
using namespace std;
class SoPhuc{
	private:
		int thuc,ao;
	public:
		SoPhuc(){
			thuc=ao=0;
		}
		SoPhuc(int thuc,int ao){
			this->thuc = thuc;
			this->ao = ao;
		}
		friend ostream& operator<<(ostream &os, SoPhuc x);
		SoPhuc operator+(SoPhuc x);
		SoPhuc operator-(SoPhuc x);
};
ostream& operator<<(ostream &os, SoPhuc x){
	os <<x.thuc<<" + "<<x.ao<<"i";
	return os;
}
SoPhuc SoPhuc::operator+(SoPhuc x){
	SoPhuc tong;
	tong.thuc = this->thuc + x.thuc;
	tong.ao = this->ao + x.ao;
	return tong;
}
SoPhuc SoPhuc::operator-(SoPhuc x){
	SoPhuc hieu;
	hieu.thuc = this->thuc - x.thuc;
	hieu.ao = this->ao - x.ao;
	return hieu;
}
int main(){
	SoPhuc A(2,3), B(-4,6);
	cout <<"So Phuc A: "<<A<<endl;
	cout <<"So Phuc B: "<<B<<endl;
	SoPhuc C = A + B;
	cout <<"Ket qua phep cong hai so phuc: "<<C<<endl;
	SoPhuc D = A - B;
	cout <<"Ket qua phep tru hai so phuc: "<<D<<endl;
	return 0;
}
