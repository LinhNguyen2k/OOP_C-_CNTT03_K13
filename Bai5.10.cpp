#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
using namespace std;
class GiangVien;
class CanBo;
class Person
{
protected:
    char MaCb[10];
    char MaDv[10];
    int NamSinh;
    int HeSoLuong;
    double PhuCapAnCa;
    double BaoHiem;
    double LuongCoBan;
public:
    void nhap();
    void xuat();
};
class CanBo:public Person
{
public:
    void nhap();
    void xuat();
    double TinhLuong();
    friend void DisplayBySalary(CanBo x[],GiangVien y[],int n,int m);
};
void CanBo::nhap(){
    Person::nhap();
}
void CanBo::xuat(){
    Person::xuat();
}
double CanBo::TinhLuong(){
    return  HeSoLuong*LuongCoBan + PhuCapAnCa-BaoHiem;
}
class GiangVien:public Person
{
private:
    double PhuCapDungLop;
    double PhuCapDocHai;
public:
    void nhap();
    void xuat();
    double TinhLuong();
    friend void DisplayBySalary(CanBo x[],GiangVien y[],int n,int m);
};
void GiangVien::nhap(){
    Person::nhap();
    do{
        cout<<"Co phu cap doc hai khong (0.Khong/1.Co): ";
        cin>>PhuCapDocHai;
        if(PhuCapDocHai!=0&&PhuCapDocHai!=1)
            cout<<"Nhap lai!";
    }while(PhuCapDocHai!=0&&PhuCapDocHai!=1);
}
void GiangVien::xuat(){
    PhuCapDungLop = 0.25*LuongCoBan;
    if(PhuCapDocHai==0){
        PhuCapDocHai=0;
    }
    else{
        PhuCapDocHai=0.1*LuongCoBan;
    }
    Person::xuat();
    cout<<setw(15)<<PhuCapDocHai;
    cout<<setw(15)<<PhuCapDungLop<<endl;
}
double GiangVien::TinhLuong(){
    PhuCapDungLop = 0.25*LuongCoBan;
      if(PhuCapDocHai == 0){
        return HeSoLuong*LuongCoBan + PhuCapAnCa + PhuCapDungLop-BaoHiem;
    }
    if(PhuCapDocHai == 1){
        PhuCapDocHai = 0.1*LuongCoBan;
        return HeSoLuong*LuongCoBan + PhuCapAnCa + PhuCapDocHai+PhuCapDungLop-BaoHiem;
    }
}
void Person::nhap(){
    cout<<"Nhap ma cb: ";       fflush(stdin); gets(MaCb);
    cout<<"Nhap ma don vi: ";   fflush(stdin); gets(MaDv);
    cout<<"Nhap nam sinh: ";    cin>>NamSinh;
    cout<<"Nhap he so luong : "; cin>>HeSoLuong;
    cout<<"Nhap phu cap an ca: ";cin>>PhuCapAnCa;
    cout<<"Nhap bao hiem: ";    cin>>BaoHiem;
    cout<<"nhap luong co ban: "; cin>>LuongCoBan;
}
void Person::xuat(){
    cout<<setw(15)<<MaCb;
    cout<<setw(15)<<MaDv;
    cout<<setw(15)<<NamSinh;
    cout<<setw(15)<<HeSoLuong;
    cout<<setw(15)<<PhuCapAnCa;
    cout<<setw(15)<<LuongCoBan;
}
void titleOfCb(){
    cout<<setw(15)<<"MaCb";
    cout<<setw(15)<<"MaDv";
    cout<<setw(15)<<"NamSinh";
    cout<<setw(15)<<"HeSoLuong";
    cout<<setw(15)<<"PcAnCa";
    cout<<setw(15)<<"LuongCoBan"<<endl;
}
void titleOfGv(){
    cout<<setw(15)<<"MaCb";
    cout<<setw(15)<<"MaDv";
    cout<<setw(15)<<"NamSinh";
    cout<<setw(15)<<"HeSoLuong";
    cout<<setw(15)<<"PcAnCa";
    cout<<setw(15)<<"LuongCoBan";
    cout<<setw(15)<<"PcDocHai";
    cout<<setw(15)<<"PcDungLop"<<endl;
}
void DisplayBySalary(CanBo x[], GiangVien y[], int n,int m){
	titleOfCb();
	for(int i=0;i<n;i++){
		if (x[i].TinhLuong() > 5000000){
			x[i].xuat();
		}
	}
	titleOfGv();
	for(int i=0;i<m;i++){
		if (y[i].TinhLuong() > 5000000){
			y[i].xuat();
		}
	}
}
int main()
{
    GiangVien a[100];
    int n;
    cout<<"Nhap so giang vien: ";cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin cua giang vien thu "<<i+1<<endl;
        a[i].nhap();
    }
    titleOfGv();
    for(int i=0;i<n;i++){
        a[i].xuat();
    }
    CanBo b[100];
    int m;
    cout<<"Nhap so Can Bo: ";cin>>m;
    for(int i=0;i<m;i++){
        cout<<"Nhap thong tin cua giang vien thu "<<i+1<<endl;
        b[i].nhap();
    }
    titleOfCb();
    for(int i=0;i<m;i++){
        b[i].xuat();
        cout<<endl;
    }
    cout<<"\nDanh sach can bo va giang vien phai dong thue thu nhap:\n";
    DisplayBySalary(b,a,n,m);
    return 0;
}
