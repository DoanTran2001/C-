#include <iostream>
#include <string.h>
#include <iomanip>
#include <conio.h>
using namespace std;
class PhongMay;
class MayTinh
{
private:
    char MaMay[10];
    char TenMay[10];
    float TocDoCPU;
    char HangSanXuat[15];
    char DiaChi[30];
public:
    friend class PhongMay;
    friend void SapXep(MayTinh *X,int n);
    friend void HienThi1(MayTinh *X,int n);
};
class PhongMay
{
private:
    char TenPhongMay[20];
    char NguoiQuanLy[30];
    MayTinh *X;
    int n;
public:
    void Nhap();
    void Xuat();

};
void PhongMay::Nhap()
{

    cout <<"Nhap ten phong may: ";
    fflush(stdin);
    gets(TenPhongMay);
    cout <<"Nhap nguoi quan ly: ";
    fflush(stdin);
    gets(NguoiQuanLy);
    cout <<"Nhap so luong may tinh: ";
    cin >>n;
    X=new MayTinh[n];
    for(int i=0;i<n;++i)
    {
         cout <<"Nhap ma may: ";
      fflush(stdin);
    gets(X[i].MaMay);
    cout <<"Nhap ten may: ";
    fflush(stdin);
    gets(X[i].TenMay);
    cout <<"Nhap toc do CPU: ";
    cin >>X[i].TocDoCPU;
    cout <<"Nhap hang san xuat: ";
    fflush(stdin);
    gets(X[i].HangSanXuat);
    cout <<"Nhap dia chi san xuat: ";
    fflush(stdin);
    gets(X[i].DiaChi);
    }
}
void PhongMay::Xuat()
{
    cout <<"Ten phong may: "<<TenPhongMay<<endl;
    cout <<"Nguoi quan ly: "<<NguoiQuanLy<<endl;
    cout <<setw(10)<<"Ma may"<<setw(10)<<"Ten may"<<setw(5)<<"Toc do CPU"<<setw(10)<<"Hang SX"<<setw(20)<<"Dia chi"<<endl;
    for(int i=0;i<n;++i)
    {
        cout <<setw(10)<<X[i].MaMay<<setw(10)<<X[i].TenMay<<setw(5)<<X[i].TocDoCPU<<setw(10)<<X[i].HangSanXuat<<setw(20)<<X[i].DiaChi<<endl;

    }
}
void SapXep(MayTinh *X,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmpi(X[i].TenMay,X[j].TenMay)>0)
                swap(X[i],X[j]);
        }
    }
    cout <<setw(10)<<"Ma may"<<setw(10)<<"Ten may"<<setw(5)<<"Toc do CPU"<<setw(10)<<"Hang SX"<<setw(20)<<"Dia chi"<<endl;
    for(int i=0;i<n;++i)
    {
        cout <<setw(10)<<X[i].MaMay<<setw(10)<<X[i].TenMay<<setw(5)<<X[i].TocDoCPU<<setw(10)<<X[i].HangSanXuat<<setw(20)<<X[i].DiaChi<<endl;

    }

}
void HienThi1(MayTinh *X,int n)
{
    bool check=false;
    for(int i=0;i<n;++i)
    {
        if(strcmpi(X[i].HangSanXuat,"Dell")==0&&strcmpi(X[i].DiaChi,"Ha Noi")==0)
        {
            check =true;
            break;
        }
    }
    if(check=true)
    {
        for(int i=0;i<n;++i)
        {
            if(strcmpi(X[i].HangSanXuat,"Dell")==0&&strcmpi(X[i].DiaChi,"Ha Noi")==0)
            {
               cout <<setw(10)<<X[i].MaMay<<setw(10)<<X[i].TenMay<<setw(5)<<X[i].TocDoCPU<<setw(10)<<X[i].HangSanXuat<<setw(20)<<X[i].DiaChi<<endl;

             }
        }
    }
    else
    {
        cout <<"Khong co may tinh nao co hang san xuat la Dell va dia chi tai Ha Noi"<<endl;
    }
}
int main()
{
    PhongMay A;
    MayTinh *X;
    int n;
    A.Nhap();
    cout <<"------Thong tin phong may tren------ "<<endl;
    A.Xuat();
    //SapXep(X,n);
    HienThi1(X,n);
    return 0;
}
