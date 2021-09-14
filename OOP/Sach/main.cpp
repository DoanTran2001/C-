#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class SachGK;
class TacGia
{
private:
    char TenTacGia[15];
    char DiaChi_TG[15];
public:
    friend class SachGK;
};
class NXB
{
private:
    char TenNXB[15];
    char DiaChi_NXB[15];
public:
    friend class SachGK;
    friend void HienThiNXB(SachGK *sgk,int n,const char *TenNXB);
};
class IDSach
{
protected:
    char TenSach[15];
    char MaSach[15];
public:
    void Nhap();
    void Xuat();
    friend void HienThiTenSach(SachGK *sgk,int n,const char *TenSach);
};
class SachGK:public IDSach
{
private:
    TacGia x;
    NXB y;
public:
    void Nhap();
    void Xuat();
    friend void HienThiNXB(SachGK *sgk,int n,const char *TenNXB);
    friend void HienThiTenSach(SachGK *sgk,int n,const char *TenSach);
    friend void ChenSGK(SachGK *sgk,int &n, int k);
};
void IDSach::Nhap()
{
    cout <<"\nNhap ten sach: ";
    fflush(stdin);
    gets(TenSach);
    cout <<"Nhap ma sach: ";
    fflush(stdin);
    gets(MaSach);
}
void IDSach::Xuat()
{
    cout <<setw(10)<<TenSach<<setw(10)<<MaSach;
}
void SachGK::Nhap()
{
    IDSach::Nhap();
    cout <<"Nhap ten tac gia: ";
    fflush(stdin);
    gets(x.TenTacGia);
    cout <<"Nhap dia chi tac gia: ";
    fflush(stdin);
    gets(x.DiaChi_TG);
    cout <<"Nhap ten nha xuat ban: ";
    fflush(stdin);
    gets(y.TenNXB);
    cout <<"Nhap dia chi nha xuat ban: ";
    fflush(stdin);
    gets(y.DiaChi_NXB);
}
void SachGK::Xuat()
{
    IDSach::Xuat();
    cout <<setw(15)<<x.TenTacGia;
    cout <<setw(15)<<x.DiaChi_TG;
    cout <<setw(15)<<y.TenNXB;
    cout <<setw(15)<<y.DiaChi_NXB<<endl;
}
void HienThiNXB(SachGK *sgk,int n,const char *TenNXB)
{
    bool kt=false;
    for(int i=0;i<n;i++)
    {
        if(strcmpi(sgk[i].y.TenNXB,TenNXB)==0)
            kt=true;
    }
    if(kt==false)
        cout <<"\n\t\tKhong co SGK nao cua NXB "<<TenNXB<<endl;
    else
    {
        cout <<"\n\t\t-----Danh sach sach giao khoa cua NXB Giao Duc-----"<<endl;
        for(int i=0;i<n;i++)
        {
            if(strcmpi(sgk[i].y.TenNXB,TenNXB)==0)
            {


                sgk[i].Xuat();
            }
        }
    }
}
void HienThiTenSach(SachGK *sgk,int n,const char *TenSach)
{
    bool kt=false;
    for(int i=0;i<n;i++)
    {
        if(strcmpi(sgk[i].TenSach,TenSach)==0)
            kt=true;
    }
    if(kt==false)
        cout <<"\n\t\tKhong co SGK nao co ten "<<TenSach<<endl;
    else
    {
        cout <<"\n\t\t-----Danh sach SGK co ten "<<TenSach<<"-----"<<endl;
        for(int i=0;i<n;i++)
        {

            if(strcmpi(sgk[i].TenSach,TenSach)==0)
           {

              sgk[i].Xuat();
           }
        }

    }
}
void ChenSGK(SachGK *sgk,int &n, int k)
{
    SachGK sach;
    cout <<"\n\t-----Nhap thong tin SGK  can chen them-----";
    sach.Nhap();
    for(int i=n;i>=k;i--)
    {
        sgk[i]=sgk[i-1];
    }
    sgk[k]=sach;
    n++;

}
void TieuDe()
{
    cout <<setw(10)<<"Ten Sach";
    cout <<setw(10)<<"Ma Sach";
    cout <<setw(15)<<"Ten Tac Gia";
    cout <<setw(15)<<"Dia Chi TG";
    cout <<setw(15)<<"Ten NXB";
    cout <<setw(15)<<"Dia Chi NXB"<<endl;
}
int main()
{
    SachGK *sgk;
    int n,k;
    cout <<"Nhap so luong sach giao khoa: ";
    cin >>n;
    sgk=new SachGK[n];
    for(int i=0;i<n;++i)
    {
        sgk[i].Nhap();
    }
    cout <<"\n\t\t--------DANH SACH SGK VUA NHAP--------"<<endl;
    TieuDe();
    for(int i=0;i<n;i++)
    {
        sgk[i].Xuat();
    }
    HienThiNXB(sgk,n,"Giao Duc");
    HienThiTenSach(sgk,n,"LTHDT");
    ChenSGK(sgk,n,1);
    cout<<"\n\t\t-----Thong tin danh sach SGK vua them la-----"<<endl;
    for(int i=0;i<n;i++)
    {
        sgk[i].Xuat();
    }
    return 0;
}
