#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

class XeHoi
{

private:
    char nhanHieu[20];
    char HangSX[20];
    char KieuDang[20];
    char MauSon[20];
    int NamSX;
    char XuatXu[20];
    float GiaBan;
public:
    void Nhap();
    void Xuat();
    friend  void ShowToyota(XeHoi a[], int n);
    friend  void Sort(XeHoi a[], int n);
    friend void Title();
};
void XeHoi::Nhap()
{
    cout<<"\nNhap nhan hieu:";
    fflush(stdin);
    gets(nhanHieu);
    cout<<"\nNhap Hang San Xuat:";
    fflush(stdin);
    gets(HangSX);
    cout<<"\nNhap Kieu Dang:";
    fflush(stdin);
    gets(KieuDang);
    cout<<"\nNhap Mau Son:";
    fflush(stdin);
    gets(MauSon);
    cout<<"\nNhap Xuat Xu:";
    fflush(stdin);
    gets(XuatXu);
    cout<<"\nNhap nam San Xuat:";
    cin>>NamSX;
    cout<<"\nNhap Gia Ban:";
    cin>>GiaBan;

}
void Title()
{
    cout<<setw(10)<<"Nhan Hieu"<<setw(10)<<"Hang SX"<<setw(10)<<"Kieu Dang"<<setw(10)<<"Mau Son"<<setw(10)<<"Xuat Xu"<<setw(10)<<"Nam SX"<<setw(10)<<"Gia Ban"<<endl;

}
void XeHoi::Xuat()
{
    cout<<setw(10)<<nhanHieu<<setw(10)<<HangSX<<setw(10)<<KieuDang<<setw(10)<<MauSon<<setw(10)<<XuatXu<<setw(10)<<NamSX<<setw(10)<<GiaBan<<endl;

}
void ShowToyota(XeHoi a[], int n)
{

    for(int i=0; i<n; i++)
    {
        if(stricmp(a[i].HangSX,"Toyota")==0)
        {
            a[i].Xuat();
        }
    }
}

void Sort(XeHoi a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i].GiaBan > a[j].GiaBan)
            {

                float b = a[i].GiaBan;
                a[i].GiaBan = a[j].GiaBan;
                a[j].GiaBan = b;
            }

        }
    }
}

int main()
{
    int n;
    cout<<"Nhap So Xe: ";
    cin>>n;
    XeHoi XH[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Nhap thong tin xe thu "<<i+1<<": "<<endl;
        XH[i].Nhap();
    }

    cout<<"\n\t=========Thong Tin Vua Nhap La==========="<<endl;
    Title();
    for(int j=0; j<n; j++)
    {
        XH[j].Xuat();
    }
    cout<<endl;
    cout<<"======================================="<<endl;
    cout<<"=========Show Hang San Xuat Toyota========="<<endl;
    Title();
    ShowToyota(XH,n);
     cout<<"======================================="<<endl;
    cout<<"=========Sort Theo Chieu Gia Ban========="<<endl;
    Title();
    Sort(XH,n);
     for(int j=0; j<n; j++)
    {
        XH[j].Xuat();
    }
    return 0;
}
