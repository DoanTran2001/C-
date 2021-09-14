#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define max 3
struct SinhVien{
	char maSV[10];
	char hoDem[22];
	char ten[10];
	int namSinh;
	float diemTK;
};
struct List{
	int count;
	SinhVien E[max];
};
void Nhap(SinhVien &sv){
	cout <<"Nhap maSV: ";	fflush(stdin);		gets(sv.maSV);
	if(strcmp(sv.maSV,"") == 0)
		return;
	cout <<"Nhap ho dem: ";		fflush(stdin);	gets(sv.hoDem);
	cout <<"Nhap ten: ";	fflush(stdin);		gets(sv.ten);
	cout <<"Nhap nam sinh: ";	cin >>sv.namSinh;
	cout <<"Nhap diem trung binh: ";	cin >>sv.diemTK;
}

void KhoiTao(List &L){
	 L.count = -1;
}
//Kiem tra danh sach day
int Full(List L){
	return L.count==max-1;
}
int Empty(List L){
	return L.count = -1;
}

int Add(List &L,SinhVien sv){
	if(Full(L))
		return 0;
	else{
		L.count ++;
		L.E[L.count] = sv;
		return 1;
	}
}
void NhapDS(List &L){
	KhoiTao(L);
	SinhVien x;
	int i = 0;
	while(1){
		cout <<"Nhap sinh vien thu"<< i + 1<<endl;
		Nhap(x);
		if(strcmp(x.maSV,"") == 0)
			return;
		if(Add(L,x)==1)
			i++;		
		else return;
	}
}
void XuatDS(List &L){
	for(int i = 0; i <= L.count; i ++){
		cout <<setw(10)<<L.E[i].maSV;
	cout <<setw(10)<<L.E[i].hoDem;
	cout <<setw(10)<<L.E[i].ten;
	cout <<setw(10)<<L.E[i].namSinh;
	cout <<setw(10)<<L.E[i].diemTK<<endl;
	}
	

}
//Xoa sv co ma 1
int Search(List L,char ma[10]){
	for(int i = 0; i <= L.count; i ++){
		if(strcmp(ma,L.E[i].maSV)==0)
			return 1;
	}
	return 0;
}
void Xoa(List &L, char ma[10]){
	if(Empty(L))
		cout <<"sdfsd";
	else{
		if(Search(L))
	}
}
int main(){
	List L;
	NhapDS(L);
	XuatDS(L);
	//cout <<Full(L);
	return 0;
}
