#include <iostream>

using namespace std;
class PT_Bac_Nhat_2An{
private:
    int a;
    int b;
    int c;
public:
    PT_Bac_Nhat_2An(){

    }
    PT_Bac_Nhat_2An(int a,int b,int c)
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }
    friend istream &operator>>(istream &is,PT_Bac_Nhat_2An &x);
    friend ostream &operator<<(ostream &os,PT_Bac_Nhat_2An x);

    PT_Bac_Nhat_2An operator+(PT_Bac_Nhat_2An x);
    PT_Bac_Nhat_2An operator-(PT_Bac_Nhat_2An x);
    PT_Bac_Nhat_2An operator--(PT_Bac_Nhat_2An x);
};
istream &operator>>(istream &is,PT_Bac_Nhat_2An &x)
{
    cout <<"Nhap a: ";
    is>>x.a;
    cout <<"Nhap b: ";
    is>>x.b;
    cout <<"Nhap c: ";
    is>>x.c;
    return is;
}
ostream &operator<<(ostream &os,PT_Bac_Nhat_2An x)
{
    if(x.a!=0){
        os<<x.a<<"x";
    }
    if(x.b<0){
        os<<x.b;
    }
        else if(x.b>0)
            os<<"+"<<x.b;
    os<<"y";
    if(x.c<0){
        os<<x.c;
    }
        else if(x.c>0){
            os<<"+"<<x.c;
        }
    os<<" = 0"<<endl;
    return os;
}
PT_Bac_Nhat_2An PT_Bac_Nhat_2An::operator+(PT_Bac_Nhat_2An x)
{
    PT_Bac_Nhat_2An tong;
    tong.a=this->a+x.a;
    tong.b=this->b+x.b;
    tong.c=this->c+x.c;
    return tong;
}
PT_Bac_Nhat_2An PT_Bac_Nhat_2An::operator-(PT_Bac_Nhat_2An x)
{
    PT_Bac_Nhat_2An hieu;
    hieu.a=this->a-x.a;
    hieu.b=this->b-x.b;
    hieu.c=this->c-x.c;
    return hieu;
}

int main()
{
    PT_Bac_Nhat_2An A;
    PT_Bac_Nhat_2An B(3,6,7);
    cin>>A;
    cout <<"Phuong trinh A vua nhap la: ";
    cout<<A;
    cout <<"Phuong trinh B vua nhap la: ";
    cout<<B;
    PT_Bac_Nhat_2An C=A+B;
    cout <<"Phuong trinh C vua nhap la: ";
    cout <<C;
    PT_Bac_Nhat_2An D=A-B;
    cout <<"Phuong trinh D vua nhap la: ";
    cout <<D;
    PT_Bac_Nhat_2An E=A-(A+A);
    cout <<"Phuong trinh E vua nhap la: ";
    cout <<E;
    return 0;
}
