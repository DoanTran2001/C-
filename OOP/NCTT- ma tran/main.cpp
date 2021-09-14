#include <iostream>

using namespace std;
class Matrix{
private:
    double **a;
    int dong;
    int cot;
public:
    friend istream &operator>>(istream &is,Matrix &x);
    friend ostream &operator<<(ostream &os,Matrix x);
    Matrix operator+(Matrix x);
    Matrix operator-(Matrix x);
    Matrix operator-();
};
istream &operator>>(istream &is,Matrix &x)
{
    cout <<"Nhap so dong cua ma tran: ";
    is>>x.dong;
    cout <<"Nhap so cot cua ma tran: ";
    is>>x.cot;
    x.a=new double*[x.dong];
    for(int i=0;i<x.dong;i++)
    {
        x.a[i]=new double[x.cot];
    }
    for(int i=0;i<x.dong;i++)
    {
        for(int j=0;j<x.cot;j++)
        {
            cout <<"A["<<i+1<<"]["<<j+1<<"]=";
            cin >>x.a[i][j];
        }
    }
    return is;
}
ostream &operator<<(ostream &os,Matrix x)
{
    for(int i=0;i<x.dong;i++)
    {
        for(int j=0;j<x.cot;j++)
        {
            os <<x.a[i][j]<<" ";
        }
        os <<endl;
    }
    return os;
}
Matrix Matrix::operator+(Matrix x)
{
    Matrix tong;
    if(dong==x.dong&&cot==x.cot)
    {
        tong.dong=dong;
        tong.cot=cot;
        tong.a=new double*[dong];
        for(int i=0;i<dong;i++)
        {
            tong.a[i]=new double[cot];
        }
        for(int i=0;i<tong.dong;i++)
        {
            for(int j=0;j<tong.cot;j++)
            {
                tong.a[i][j]=a[i][j]+x.a[i][j];
            }
        }
    }
    else
    {
        cout <<"Hai ma tran khong cung kich thuoc"<<endl;
        tong.dong=tong.cot=0;

    }
    return tong;
}
Matrix Matrix::operator-(Matrix x)
{
     Matrix hieu;
    if(dong==x.dong&&cot==x.cot)
    {
        hieu.dong=dong;
        hieu.cot=cot;
        hieu.a=new double*[dong];
        for(int i=0;i<dong;i++)
        {
            hieu.a[i]=new double[cot];
        }
        for(int i=0;i<hieu.dong;i++)
        {
            for(int j=0;j<hieu.cot;j++)
            {
                hieu.a[i][j]=a[i][j]-x.a[i][j];
            }
        }
    }
    else
    {
        cout <<"Hai ma tran khong cung kich thuoc"<<endl;
        hieu.dong=hieu.cot=0;
    }
    return hieu;
}
Matrix Matrix::operator-()
{
    Matrix doidau;
    doidau.dong=dong;
    doidau.cot=cot;
    doidau.a=new double*[dong];
    for(int i=0;i<dong;i++)
    {
        doidau.a[i]=new double[cot];
    }
    for(int i=0;i<doidau.dong;i++)
    {
        for(int j=0;j<doidau.cot;j++)
        {
            doidau.a[i][j]=this->a[i][j]-2*this->a[i][j];
        }
    }
    return doidau;
}
int main()
{
    Matrix A;
    cin >>A;
    cout <<"Ma tran A vua nhap la: "<<endl;
    cout <<A;
    Matrix B;
    cin >>B;
    cout <<"Ma tran B vua nhap la: "<<endl;
    cout <<B;
    Matrix C=A+B;
    cout <<"Ma tran tong: "<<endl;
    cout <<C;
    Matrix D=A-B;
    cout <<"Ma tran hieu: "<<endl;
    cout <<D;
    Matrix E=-A;
    cout <<"Ma tran doi dau cua A: "<<endl;
    cout<<E;
    return 0;
}
