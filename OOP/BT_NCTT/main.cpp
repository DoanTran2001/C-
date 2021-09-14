#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class SanPham{
private:
    char MaSP[20];
    char TenSP[20];
    int NgayNhap;
public:
    void Nhap();
    void Xuat();
};
class DieuHoa:public SanPham{
private:
    int CongSuat;
    char TenHangSX[20];
    double GiaBan;
public:
    void Nhap();
    void Xuat();
    friend void HienThi(DieuHoa *dsdh,int n,const char* TenHangSX);
};
void SanPham::Nhap(){
    cout <<"\nNhap ma san pham: ";
    fflush(stdin);
    gets(MaSP);
    cout <<"Nhap ten san pham: ";
    fflush(stdin);
    gets(TenSP);
    cout <<"Nhap ngay nhap san pham: ";
    cin >>NgayNhap;
}
void SanPham::Xuat(){
    cout <<setw(10)<<MaSP<<setw(15)<<TenSP<<setw(10)<<NgayNhap;
}
void DieuHoa::Nhap(){
    SanPham::Nhap();
    cout <<"Nhap cong suat: ";
    cin >>CongSuat;
    cout <<"Nhap ten hang san xuat: ";
    fflush(stdin);
    gets(TenHangSX);
    cout <<"Nhap gia ban (trieu dong): ";
    cin >>GiaBan;
}
void DieuHoa::Xuat(){
    SanPham::Xuat();
    cout <<setw(10)<<CongSuat<<setw(15)<<TenHangSX<<setw(10)<<GiaBan<<endl;
}
void HienThi(DieuHoa *dsdh,int n,const char* TenHangSX)
{
    double giaMin=0;
    for(int i=0;i<n;i++)
    {
        if(strcmpi(dsdh[i].TenHangSX,TenHangSX)==0)
        {
            giaMin=dsdh[i].GiaBan;
            for(int j= i+1;j<n;j++){
                if(strcmpi(dsdh[j].TenHangSX,TenHangSX)==0&&dsdh[j].GiaBan<giaMin)
                        giaMin=dsdh[j].GiaBan;
            }
            break;
        }
    }
    if(giaMin==0)
    {
        cout <<"\n\t\tKhong co dieu hoa nao hang "<<TenHangSX<<endl;
    }
    else{
        for(int i=0;i<n;i++){
        if(strcmpi(dsdh[i].TenHangSX,TenHangSX)==0&&dsdh[i].GiaBan==giaMin)
            dsdh[i].Xuat();
         }
    }



}
int main()
{
    int n;
    cout <<"Nhap so luong dieu hoa: ";
    cin >>n;
    DieuHoa *dsdh;
    dsdh = new DieuHoa[n];

    for(int i=0;i<n;i++)
    {
        dsdh[i].Nhap();
    }
    cout <<"\n\t\t==========Danh sach dieu hoa vua moi nhap=========="<<endl;
    for(int i=0;i<n;i++)
    {
        dsdh[i].Xuat();
    }
    HienThi(dsdh,n,"Panasonic");
    return 0;
}
