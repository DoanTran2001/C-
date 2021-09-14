#include <iostream>
#include <iomanip>
using namespace std;
class Vector{
	private:
		int x,y;
	public:
		void Nhap();
		void Xuat();
		Vector operator+(Vector a);
		Vector operator-(Vector a);
};
void Vector::Nhap(){
	cout <<"Nhap hoanh do: ";
	cin >>x;
	cout <<"Nhap tung do: ";
	cin >>y;
}
void Vector::Xuat(){
	cout <<"( "<<x<<", "<<y<<")";
}
Vector Vector:: operator+(Vector a){
	Vector tong;
	tong.x = this->x + a.x;
	tong.y = this->y +a.y;
	return tong;
}
Vector Vector:: operator-(Vector a){
	Vector hieu;
	hieu.x = this->x - a.x;
	hieu.y = this->y - a.y;
	return hieu;
}
int main(){
	Vector A,B;
	cout <<"\n\t\tNhap vector A"<<endl;
	A.Nhap();
	cout <<"\n\tVecto A: ";
	A.Xuat();
	cout <<"\n\t\tNhap vector B"<<endl;
	B.Nhap();
	cout <<"\n\tVecto B: ";
	B.Xuat();
	Vector C = A + B;
	cout <<"\n\n\tVector tong";
	C.Xuat();
	Vector D = A - B;
	cout <<"\n\n\tVector hieu";
	D.Xuat();
	return 0;
}
