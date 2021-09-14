#include <iostream>
#include <string.h>
using namespace std;
class Electronic{
	protected:
		int congSuat;
		int dienAp;
	public:
		Electronic(){
			
		}
		Electronic(int congSuat,int dienAp){
			this->congSuat=congSuat;
			this->dienAp=dienAp;
		}
};
class TuLanh:public Electronic{
	private:
		int dungTich;
		int soNgan;
	public:
		TuLanh(){
			
		}
		TuLanh(int congSuat,int dienAp,int dungTich,int soNgan):Electronic(congSuat,dienAp){
			this->dungTich=dungTich;
			this->soNgan=soNgan;
		}
		void Xuat();
};
class MayGiat:public Electronic{
	private:
		int dungTich;
		char loai[15];
	public:
		MayGiat(){
			
		}
		MayGiat(int congSuat,int dienAp,int dungTich,char *loai):Electronic(congSuat,dienAp){
			this->dungTich=dungTich;
			strcpy(this->loai,loai);
		}
		void Xuat();
};
void MayGiat::Xuat(){
	cout <<"Cong suat: "<<congSuat<<endl;
	cout <<"Dien ap: "<<dienAp<<endl;
	cout <<"Dung tich: "<<dungTich<<endl;
	cout <<"Loai: "<<loai<<endl;
}
void TuLanh::Xuat(){
	cout <<"Cong suat: "<<congSuat<<endl;
	cout <<"Dien ap: "<<dienAp<<endl;
	cout <<"Dung tich: "<<dungTich<<endl;
	cout <<"So ngan: "<<soNgan<<endl;
}
int main(){
	MayGiat x(2,4,5,"He he");
	TuLanh y(3,4,2,2);
	cout <<"\n\n\t\tThong tin may giat"<<endl;
	x.Xuat();
	cout <<"\n\n\t\tThong tin tu lanh"<<endl;
	y.Xuat();
	return 0;
}
