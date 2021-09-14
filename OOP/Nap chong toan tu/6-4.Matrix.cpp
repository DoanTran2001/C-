#include <iostream>
using namespace std;
class Matrix{
	private:
		double **a;
		int dong,cot;
	public:
		friend istream& operator>>(istream &is,Matrix &A);
		friend ostream& operator<<(ostream &os,Matrix A);
		Matrix operator-();
		Matrix operator+(Matrix X);
		Matrix operator*(Matrix X);
};
istream& operator>>(istream &is,Matrix &A){
	cout <<"Nhap so luong dong: ";		is >>A.dong;
	cout <<"Nhap so luong cot: ";		is >>A.cot;
	A.a = new double*[A.dong];
	for(int i = 0; i < A.dong; i++){
		A.a[i] = new double[A.cot];
	}
	for(int i = 0; i < A.dong; i++){
		for(int j = 0; j < A.cot; j++){
			cout <<"A["<<i+1<<"]["<<j+1<<"]= ";
			is >>A.a[i][j];
		}
	}
	return is;
}
ostream& operator<<(ostream &os,Matrix A){
	for(int i = 0; i < A.dong; i++){
		for(int j = 0; j < A.cot; j++){
			cout <<A.a[i][j]<<" ";
		}
		cout <<endl;
	}
	return os;
}
Matrix Matrix::operator-(){
	Matrix tg;
	tg.dong = dong;
	tg.cot = cot;
	tg.a = new double*[tg.dong];
	for(int i = 0; i < tg.dong; i++){
		tg.a[i] = new double[tg.cot];
	}
	for(int i = 0; i < tg.dong; i++){
		for(int j = 0; j <tg.cot; j++){
			tg.a[i][j] = -a[i][j];
		}
	}
	return tg;
}
Matrix Matrix::operator+(Matrix x){
	Matrix tong;
	if(dong == x.dong && cot == x.cot){
		tong.dong = dong;
		tong.cot = cot;
		tong.a = new double*[tong.dong];
		for(int i = 0; i < tong.dong; i++){
			tong.a[i] = new double[tong.cot];
		}
		for(int i = 0; i < dong; i++){
			for(int j = 0; j < cot; j++){
				tong.a[i][j] = a[i][j] + x.a[i][j];
			}
		}
	}
	else{
		cout <<"\nHai ma tran khong cung kich thuoc, nen khong cong duoc"<<endl;
		tong.dong = tong.cot =0;
	}
	return tong;
}
Matrix Matrix::operator*(Matrix x){
	Matrix nhan;
	if(cot==x.dong){
		nhan.dong = dong;
		nhan.cot = x.cot;
		nhan.a = new double*[nhan.dong];
		for(int i=0;i<dong;i++){
			nhan.a[i] = new double[nhan.cot];
		}
		double sum;
		for(int i=0;i<dong;i++){
			for(int j=0;j<x.cot;j++){
				 sum = 0;
				for(int k=0;k<x.dong;k++){
					sum += a[i][k]*x.a[k][j];
				}
				nhan.a[i][j]=sum;
			}
		}
	}
	else{
		cout<<"2 ma tran k nhan dc.";
	}
	return nhan;
}
int main(){
	Matrix A;
	cin >>A;
	cout <<"\n\tMa tran A vua nhap la"<<endl;
	cout <<A;
	cout <<"\n\tDoi dau ma tran "<<endl;
	cout <<-A;
	Matrix B;
	cin >>B;
	cout <<"\n\tMa tran B vua nhap la"<<endl;
	cout <<B;
	Matrix C = A + B;
	cout <<"\n\tMa tran tong cua A va B la"<<endl;
	cout <<C;
	cout
	return 0;
}
