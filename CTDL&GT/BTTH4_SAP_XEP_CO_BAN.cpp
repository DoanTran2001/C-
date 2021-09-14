//			**********Bai tap thuc hanh 4: Sap xep co ban**********
#include <iostream>
using namespace std;
void Xuat(int x[]){
	for(int i = 0; i < 9; i ++){
		cout <<x[i]<<" ";
	}
}
void SX_NoiBot(int x[]){
	for(int i = 0; i < 9; i ++){
		for(int j = i + 1; j < 9; j ++){
			if(x[i] < x[j]){
				int tg = x[i];
				x[i] = x[j];
				x[j] = tg;
			}
		}
	}
}
void SX_LuaChon(int x[]){
	for(int i = 0; i < 9; i ++){
		int max = i;
		for(int j = i + 1; j < 9; j ++){
			if(x[j] > x[max])
				max = j;
		}
		if(max != i){
			int tg = x[i];
			x[i] = x[max];
			x[max] = tg;
		}
	}
}
void SX_Chen(int x[]){
	for(int i = 1; i < 9; i ++){
		int t = x[i];
		int j = i - 1;
		while(j >= 0 && t > x[j]){
			x[j + 1] = x[j];
			j = j - 1;
		}
		x[j + 1] = t;
	}
}


int main(){
	int x[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
	SX_NoiBot(x);
	cout <<"\nMang sau khi sap xep giam dan: ";
	Xuat(x);
	SX_LuaChon(x);
	cout <<"\nMang sau khi sap xep giam dan: ";
	Xuat(x);
	SX_Chen(x);
	cout <<"\nMang sau khi sap xep giam dan: ";
	Xuat(x);

	return 0;
}
