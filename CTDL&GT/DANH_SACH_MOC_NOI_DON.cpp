#include <iostream>
#include <stdio.h>
#include<string.h>
#include <iomanip>
using namespace std;
//Khai bao cau truc du lieu cua danh sach
struct SinhVien{
	char maSV[10];
	char hoDem[22];
	char ten[10];
	int namSinh;
	float diemTK;
};
struct Node{
	SinhVien infor;
	Node *next;
};
typedef Node *Tro;
//Ham khoi tao danh sach rong
void Create(Tro &L){
	L = NULL;
}
//Kiem tra danh sach rong
int Empty(Tro L){
	return L == NULL;
}
//Nhap du lieu cho 1 sinh vien
void NhapSV(SinhVien &sv){
	cout <<"\nNhap ma sinh vien: ";		fflush(stdin);		gets(sv.maSV);
	cout <<"Nhap ho dem: ";				fflush(stdin);		gets(sv.hoDem);
	cout <<"Nhap ten SV: ";				fflush(stdin);		gets(sv.ten);
	cout <<"Nhap nam sinh: ";			cin >>sv.namSinh;
	cout <<"Nhap diem tong ket: ";		cin >>sv.diemTK;
}
//Xuat du lieu cua 1 sinh vien
void XuatSV(SinhVien sv){
	cout <<setw(10)<<sv.maSV;
	cout <<setw(10)<<sv.hoDem;
	cout <<setw(10)<<sv.ten;
	cout <<setw(10)<<sv.namSinh;
	cout <<setw(10)<<sv.diemTK<<endl;
}
//Chen 1 nut vao cuoi danh sach
void Add_Last(Tro &L, SinhVien sv){
	Tro P = new Node;
	P->infor = sv;
	P->next = NULL;
	if(L == NULL){
		L = P;
	}
	else{
		Tro Q = L;
		while(Q->next != NULL){
			Q = Q->next;
		}
		Q->next = P;
	}
}
//Nhap danh sach sinh vien, viec nhap ket thuc khi maSV nhap la $
void NhapDS(Tro &L){
	while(true){
		SinhVien tg;
		NhapSV(tg);
		if(strcmp(tg.maSV,"$") == 0){
			break;
		}
		Add_Last(L,tg);
	}
}
//Xuat danh sach sinh vien
void XuatDS(Tro L){
	while(L != 0){
		XuatSV(L->infor);
		L = L->next;
	}
}
//Chen SV vao dau danh sach
void Add_First(Tro &L){
	SinhVien sv;
	NhapSV(sv);
	Tro P = new Node;
	P->infor = sv;
	P->next = L;
	L = P;
}
//Sap xep danh sach theo chieu giam dan cua diem tong ket
void SapXep(Tro L){
	Tro P = L;
	Tro Q = P->next;
	while(P->next != NULL){
		while(Q != NULL){
			if(P->infor.diemTK < Q->infor.diemTK){
				swap(P,Q);
			}
		}
	}
}
//Xoa sinh vien dau tien cua danh sach
void Delete_First(Tro &L){
	Tro P = L;
	L = L->next;
	delete P;
}
int main(){
	Tro L;
	Create(L);
	NhapDS(L);
	cout <<"\n\n\t\tDanh sach sinh vien vua nhap"<<endl;
	XuatDS(L);
//	Add_First(L);
//	XuatDS(L);
//	SapXep(L);
//	XuatDS(L);
	Delete_First(L);
	XuatDS(L);
	return 0;
}
