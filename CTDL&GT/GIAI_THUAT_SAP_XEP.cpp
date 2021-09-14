#include <iostream>
#include <conio.h>
#include <string.h>
//***********Cac thuat toan sap xep***********
using namespace std;
void Input(int *A, int n){
	for(int i = 0; i < n; i ++){
		cout <<"A["<<i+1<<"]= ";
		cin >>A[i];
	}
}
void Output(int *A, int n){
	for(int i = 0; i < n; i ++){
		cout <<A[i]<<" ";
	}
}
void BubbleSort(int *A,	int n){
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			if(A[i] > A[j]){
				int tg = A[i];
				A[i] = A[j];
				A[j] = tg;
			}
		}
	}
}
void SelectionSort(int *A, int n){
	for(int i = 0; i < n - 1; i ++){
		int min = i;
		for(int j = i + 1; j < n; j ++){
			if(A[j] < A[min])
				min = A[j];
		}
		if(min != i){
			int tg = A[i];
			A[i] = A[min];
			A[min] = tg;
		}
	}
}
void InsertSort(int *A, int n){
	for(int i = 0; i < n; i ++){
		int t = A[i];
		int j = i - 1;
		while(j >= 0 && t <= A[j]){
			A[j+1] = A[j];
			j = j - 1;
		}
		A[j+1] = t;
	}
	
}
//void Nhap(char *a[10], int n){
//	for(int i = 0; i <= n; i ++){
//		fflush(stdin);
//		gets(*a[i]);
//	}
//}
//void Xuat(char *a[10], int n){
//	for(int i = 0; i <= n; i ++){
//		cout <<a[i]<<" ";
//	}
//}
//void SX_NoiBot(char *a, int n){
//	for(int i = 0; i < n - 1; i ++){
//		for(int j = i + 1; j < n; j ++){
//			if()
//		}
//	}
//}
int main(){
	int *A;
	int n;
	cout <<"\n\tEnter the number of elements for the array: ";
	cin >>n;
	A = new int[n];
	Input(A,n);
	BubbleSort(A,n);
	cout <<"The array after sorting is: ";
	Output(A,n);
	SelectionSort(A,n);
	cout <<"\nThe array after sorting is: ";
	Output(A,n);
	InsertSort(A,n);
	cout <<"\nThe array after sorting is: ";
	Output(A,n);
	
	
	return 0;
}
