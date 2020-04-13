#include <iostream>
#include <conio.h>
#include<stdio.h>
#include<string.h>
#include <iomanip>
using namespace std;
class PERSON
{
public:
    char hoTen[30];
    char ngaySinh[30];
    char queQuan[50];
    friend class KYSU;
};
class KYSU : public PERSON
{
public :
    char nganh[20];
    int NamTN;
    void nhap();
    void xuat();

    void NamTNmax(KYSU a[], int n);
};
void KYSU::nhap()
{
    cout<<"\tNhap thong tin:"<<endl;
    cout<<"Nhap ho ten:";
    fflush(stdin);
    gets(hoTen);
    cout<<"Nhap ngay sinh:";
    fflush(stdin);
    gets(ngaySinh);
    cout<<"Nhap que quan:";
    fflush(stdin);
    gets(queQuan);
    cout<<"Nhap nganh hoc:";
    fflush(stdin);
    gets(nganh);
    cout<<"Nhap nam tot nghiep:";
    cin>>NamTN;
}
void title()
{
    cout<<setw(10)<<"Ho ten"<<setw(10)<<"Ngay Sinh"<<setw(10)<<"Que Quan"<<setw(10)<<"Nganh"<<setw(10)<<"Nam TN"<<endl;
}
void KYSU::xuat()
{    cout<<endl;
title();
    cout<<setw(10)<<hoTen;
    cout<<setw(10)<<ngaySinh;
    cout<<setw(10)<<queQuan;
    cout<<setw(10)<<nganh;
    cout<<setw(10)<<NamTN;
}
void NamTNmax(KYSU a[], int n)
{
    int max1 = a[0].NamTN;
    for(int i=1;i<n;i++)
    {
        if(a[i].NamTN > max1)
            max1 = a[i].NamTN;
    }
    cout<<"\nKy su co nam tot nghiep cao nhat la:";
    for(int i=0;i<n;i++)
    {
        if(a[i].NamTN == max1)
        
            a[i].xuat();
    }
}
int main()
{
    int n;int c,
    KYSU a[100];
    cout<<"\tNhap n:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Ky su thu:"<<i+1<<endl;
        a[i].nhap();
    }
    cout<<endl;
    cout<<"\nThong Tin Vua Nhap:";
    for(int i=0;i<n;i++)
    {
        a[i].xuat();
    }
    cout<<endl;

   NamTNmax(a,n);
    return 0;
}
