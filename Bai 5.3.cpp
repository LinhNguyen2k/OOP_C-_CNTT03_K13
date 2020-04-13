#include <iostream>
#include<stdio.h>
#include<iomanip>

using namespace std;

class sanPham{
protected:
    char maSP[20];
    char tenSP[20];
    char ngaySX[15];
    int trongLuong;
    char mauSac[10];
};

class hangDienTu:private sanPham{
private:
    long congSuat;
    char dongDien[10];
public:
    void nhap();
    void xuat();
    friend int lowestWeight(hangDienTu x[],int n);
};

void hangDienTu::nhap(){
    cout<<"Nhap ma SP: ";
    fflush(stdin);
    gets(maSP);
    cout<<"Nhap ten SP: ";
    fflush(stdin);
    gets(tenSP);
    cout<<"Nhap ngay SX: ";
    fflush(stdin);
    gets(ngaySX);
    cout<<"Nhap trong luong: ";
    cin>>trongLuong;
    cout<<"Nhap mau sac: ";
    fflush(stdin);
    gets(mauSac);
    cout<<endl;
}

void hangDienTu::xuat(){
    cout<<setw(15)<<maSP<<setw(15)<<tenSP<<setw(15)<<ngaySX<<setw(15)<<trongLuong<<setw(15)<<mauSac<<endl;
}

void tieuDe(){
    cout<<setw(15)<<"MaSP"<<setw(15)<<"TenSP"<<setw(15)<<"NgaySX"<<setw(15)<<"TrongLuong"<<setw(15)<<"MauSac"<<endl;
}

int lowestWeight(hangDienTu x[],int n){
    int m=x[0].trongLuong;
    int vt=0;
    for(int i=1;i<n;i++){
        if(x[i].trongLuong<m){
            m=x[i].trongLuong;
            vt=i;
        }
    }
    return vt;
}

int main()
{
    int n;
    cout<<"Nhap so hang dien tu :";
    cin>>n;
    hangDienTu x[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap hang dien tu thu "<<i+1<<":"<<endl;
        x[i].nhap();
    }
    cout<<"==========THONG TIN VUA NHAP=========="<<endl;
    tieuDe();
    for(int i=0;i<n;i++){
        x[i].xuat();
    }
    cout<<"==========VI TRI CO TRONG LUONG THAP NHAT=========="<<endl;
    tieuDe();
    x[lowestWeight(x,n)].xuat();
    return 0;
}
