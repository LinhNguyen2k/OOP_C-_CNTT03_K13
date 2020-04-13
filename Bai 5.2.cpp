#include <iostream>
#include<stdio.h>
#include<iomanip>

using namespace std;

class VEHICLE{
private:
    char nhanHieu[30];
    char namSX[15];
    char hang[30];
public:
    void nhap();
    void xuat();
};

class OTO:private VEHICLE{
private:
    int choNgoi;
    int dungTich;
public:
    void nhap();
    void xuat();
};

class MOTO:private VEHICLE{
private:
    char phanKhoi[10];
public:
    void nhap();
    void xuat();
};

void VEHICLE::nhap(){
    cout<<"Nhap nhan hieu: ";
    fflush(stdin);
    gets(nhanHieu);
    cout<<"Nhap nam SX: ";
    fflush(stdin);
    gets(namSX);
    cout<<"Nhap ten hang: ";
    fflush(stdin);
    gets(hang);
}

void VEHICLE::xuat(){
    cout<<setw(20)<<nhanHieu<<setw(15)<<namSX<<setw(10)<<hang;
}

void OTO::nhap(){
    VEHICLE::nhap();
    cout<<"Nhap so cho ngoi: ";
    cin>>choNgoi;
    cout<<"Nhap dung tich: ";
    cin>>dungTich;
    cout<<endl;
}

void OTO::xuat(){
    VEHICLE::xuat();
    cout<<setw(10)<<choNgoi<<setw(10)<<dungTich<<endl;
}

void MOTO::nhap(){
    VEHICLE::nhap();
    cout<<"Nhap so phan khoi: ";
    cin>>phanKhoi;
}

void MOTO::xuat(){
    VEHICLE::xuat();
    cout<<setw(10)<<phanKhoi<<endl;
}

int main()
{
    OTO a;
    MOTO b;
    cout<<"Nhap thong tin OTO: "<<endl;
    a.nhap();
    cout<<"Nhap thong tin MOTO: "<<endl;
    b.nhap();
    cout<<"==========THONG TIN OTO=========="<<endl;
    cout<<setw(20)<<"NhanHieu"<<setw(15)<<"NamSX"<<setw(10)<<"Hang"<<setw(10)<<"ChoNgoi"<<setw(10)<<"DungTich"<<endl;
    a.xuat();
    cout<<"==========THONG TIN MOTO=========="<<endl;
    cout<<setw(20)<<"NhanHieu"<<setw(15)<<"NamSX"<<setw(10)<<"Hang"<<setw(10)<<"PhanKhoi"<<endl;
    b.xuat();
    return 0;
}
