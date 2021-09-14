#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class Student;
class School{
	private:
		char name[20];
		char date[20];
	public:
		friend class Faculty;
};
class Faculty{
	private:
		char name[20];
		char date[20];
		School x;
	public:
		void input();
		void output();
		friend void SVCNTT(Student *x, int n);
};
class Person{
	protected:
		char name[20];
		int birth;
		char address[20];
	public:
		void input();
		void output();
		Person(){
			
		}
};
class Student:public Person{
	private:
		char Class[20];
		float Score;
		Faculty y;
	public:
		void input();
		void output();
		Student(){
			
		}
		friend void SVCNTT(Student *x, int n);
};
void Faculty::input(){
	cout <<"Nhap ten truong: ";					fflush(stdin);		gets(x.name);
	cout <<"Nhap ngay thanh lap truong: ";		fflush(stdin);		gets(x.date);
	cout <<"Nhap ten khoa: ";					fflush(stdin);		gets(name);
	cout <<"Nhap ngay thanh lap khoa: ";		fflush(stdin);		gets(date);
}
void Faculty::output(){
	cout <<setw(15)<<x.name;
	cout <<setw(15)<<x.date;
	cout <<setw(15)<<name;
	cout <<setw(15)<<date;
}
void Person::input(){
	cout <<"\nNhap ten: ";		fflush(stdin);		gets(name);
	cout <<"Nhap ngay sinh: ";						cin >>birth;
	cout <<"Nhap dia chi: ";	fflush(stdin);		gets(address);
}
void Person::output(){
	cout <<setw(15)<<name;
	cout <<setw(15)<<birth;
	cout <<setw(15)<<address;
}
void Student::input(){
	Person::input();
	y.input();
	cout <<"Nhap ten lop: ";	fflush(stdin);		gets(Class);
	cout <<"Nhap diem: ";							cin >>Score;
}
void Student::output(){
	Person::output();
	y.output();
	cout <<setw(10)<<Class;
	cout <<setw(10)<<Score<<endl;
}
void SVCNTT(Student *x, int n){
	int dem = 0;
	for(int i = 0;i < n;i ++){
		if(strcmpi(x[i].y.name,"CNTT") ==0){
			++dem;
		}
	}
	if(dem == 0)
		cout <<"\nKhong co sinh vien nao o khoa CNTT"<<endl;
	else{
		cout <<"\nDANH SACH SINH VIEN HOC O KHOA CNTT"<<endl;
		//TieuDe();
		for(int i = 0;i < n;i ++){
			if(strcmpi(x[i].y.name,"CNTT") ==0){
				x[i].output();
			}
		}
	}
}
void TieuDe(){
	cout <<setw(15)<<"Ho ten";
	cout <<setw(15)<<"Ngay sinh";
	cout <<setw(15)<<"Dia chi";
	cout <<setw(15)<<"Ten truong";
	cout <<setw(15)<<"Ngay TL Truong";
	cout <<setw(15)<<"Ten khoa";
	cout <<setw(15)<<"Ngay TL Khoa";
	cout <<setw(10)<<"Lop";
	cout <<setw(10)<<"Diem"<<endl;
}
int main(){
	Student *x;
	int n;
	cout <<"Nhap so luong sinh vien: ";
	cin >>n;
	x = new Student[n];
	for(int i = 0;i < n;i ++){
		x[i].input();
	}
	cout <<"\n\t\tTHONG TIN DANH SACH SINH VIEN VUA NHAP"<<endl;
	TieuDe();
	for(int i = 0;i < n;i ++){
		x[i].output();
	}
	SVCNTT(x,n);
	return 0;
}
