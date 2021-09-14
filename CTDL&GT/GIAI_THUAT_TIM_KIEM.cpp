#include <iostream>

using namespace std;
int TKTT(int a[],int x){
	for(int i = 0; i < 9; i ++){
		if(a[i] == x){
			return i;
		}
	}
	return -1;
}
int TKNP(int a[], int x, int l, int r){
	if(l > r)
		return -1;
	else{
		int m = (l + r)/2;
		
			if(x == a[m])
				return m;
			else if(x < a[m])
				return TKNP(a,x,l,m-1);
			else{
				return TKNP(a,x,m+1,r);
			}
		
	}
}
int main(){
	int a[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
	if(TKTT(a,94) == -1){
		cout <<"Phan tu khong co trong mang"<<endl;
	}
	else{
		cout <<"Phan tu xuat hien o vi tri "<<TKTT(a,94);
	}
	
	int b[] = {04, 14, 24, 34, 54, 64, 74, 84, 94};
	if(TKNP(b,60,0,9) == -1){
		cout <<"Phan tu khong co trong mang"<<endl;
	}
	else{
		cout <<"Phan tu xuat hien o vi tri "<<TKNP(b,60,0,9);
	}
	return 0;
}
