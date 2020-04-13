#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
class PTB2{
	private:
		float a,b,c;
	public:
		void nhap();
		void xuat();
		void giai();
		PTB2(){
			a = b = c = 0;
		}
		PTB2(float x, float y, float z){
			a = x;b = y;c = z;
		}
};
void PTB2::nhap(){
	cout<<"\n nhap he so a: ";cin>>a;
	cout<<"\n nhap he so b: ";cin>>b;
	cout<<"\n nhap he so c: ";cin>>c;
}
void PTB2::xuat(){
	cout<<"\n PT: "<<a<<"*x^2 + "<<b<<"*x";
	if (c>=0) cout<<" + ";
	else cout<<" ";
	cout<<c<<" = 0"<<endl;

}
void PTB2::giai(){
	if (a==0){
		if (b == 0 ){
			if(c == 0){
				cout<<"\n Phuong trinh co vo so nghiem"<<endl;
			}else cout<<"\n Phuong trinh vo nghiem"<<endl;
		}else cout<<"\n Phuong trinh co nghiem duy nhat: "<<-c/b;
	}else{
		float delta = b*b - 4*a*c;
		if (delta <0){
			cout<<"\n Phuong trinh vo nghiem"<<endl;
		}else if(delta == 0){
			float x = -b / 2 / a;
			cout<<"\n Phuong trinh co nghiem kep x1 = x2 = "<<setprecision(3)<<x<<endl;
		}else{
			float x1 = (-b + sqrt(delta))/2/a;
			float x2 = (-b - sqrt(delta))/2/a;
			cout<<"\n Phuong trinh co 2 nghiem phan biet: "<<endl;
			cout<<"\t\t x1 = "<<setprecision(3)<<x1<<"\t x2 =  "<<setprecision(3)<<x2;
		}
	}
}
int main(){
	PTB2 P;
	P = PTB2(1,2,1);
	P.xuat();
	P.giai();
	PTB2 Q;
	cout<<"\n\t\tNhap phuong trinh Q"<<endl;
	Q.nhap();
	Q.xuat();
	Q.giai();
	return 0;
}
