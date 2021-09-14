#include <iostream>
#include <iomanip>
using namespace std;
class Array{
private:
    float *A;
    int n;
public:
    Array operator++();
    friend istream&operator>>(istream &is,Array &x);
    friend ostream&operator<<(ostream &os,Array &x);
};
istream&operator>>(istream &is,Array &x){
    cout <<"Nhap so luong phan tu: ";
    is >> x.n;
    x.A = new float [x.n];
    for(int i=0;i<x.n;++i)
    {
        cout <<"A["<<i+1<<"]= ";
        is >>x.A[i];
    }
    return is;
}
ostream&operator<<(ostream &os,Array &x){
    for(int i=0;i<x.n;i++)
    {
        os <<x.A[i]<<" ";
    }
    return os;
}
Array Array::operator++(){
    Array tang;
    for(int i=0;i<tang.n;++i)
    {
        for(int j=i+1;i<tang.n;++j)
        {
            if(tang.A[i]>tang.A[j])
            {
                float temp=tang.A[i];
                tang.A[i]=tang.A[j];
                tang.A[j]=temp;
            }
        }
    }
    return tang;
}
int main()
{
    Array Arr;
    cin >>Arr;
    cout <<"\n\t\tMang vua nhap la"<<endl;
    cout <<Arr;
    ++Arr;
    cout <<"\n\t\tMang sau khi sap xep tang la: ";
    cout <<Arr;
    return 0;
}
