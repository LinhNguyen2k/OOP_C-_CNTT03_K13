#include <iostream>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<iomanip>
using namespace std;
class NhanVien;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    friend class NhanVien;
    friend void title();
    friend void SortName(NhanVien a[], int n);
    friend void Chen(NhanVien a[], int n);
    friend void Delete123(NhanVien a[], int n);
};
class PhongBan
{
private:
    int maPB;
    char tenPb[50];
    char truongPhong[20];
    int soNV;
public:
    friend class NhanVien;
    friend void title();
    friend void SortName(NhanVien a[], int n);
    friend void Chen(NhanVien a[], int n);
    friend void Delete123(NhanVien a[], int n);
};
class NhanVien
{
private:
    int maNv;
    char hoDem[25];
    char ten[10];
    Date ngaySinh;
    PhongBan phong;
public:
    void Nhap();
    void Xuat();
    friend void title();
    friend void SortName(NhanVien a[], int n);
    friend void Chen(NhanVien a[], int n);
    friend void Delete123(NhanVien a[], int n);
};
void NhanVien::Nhap()
{
    cout<<"\nNhap ma nv: ";
    cin>>maNv;
    cout<<"\nNhap ho dem: ";
    fflush(stdin);
    gets(hoDem);
    cout<<"\nNhap ten: ";
    fflush(stdin);
    gets(ten);
    cout<<"\nNhap ngay sinh:\n";
    cout<<"\nNhap ngay: ";
    cin>>ngaySinh.day;
    cout<<"\nNhap thang: ";
    cin>>ngaySinh.month;
    cout<<"\nNhap nam: ";
    cin>>ngaySinh.year;
    cout<<"\nNhap thong tin phong ban: \n";
    cout<<"\nNhap ma phong ban: ";
    cin>>phong.maPB;
    cout<<"\nNhap ten pb: ";
    fflush(stdin);
    gets(phong.tenPb);
    cout<<"\nNhap ten truong phong: ";
    fflush(stdin);
    gets(phong.truongPhong);
    cout<<"\nNhap so nhan vien: ";
    phong.soNV;
}
void NhanVien::Xuat()
{
    cout<<setw(15)<<maNv;
    cout<<setw(15)<<hoDem;
    cout<<setw(15)<<ten;
    cout<<setw(20)<<ngaySinh.day<<"/"<<ngaySinh.month<<"/"<<ngaySinh.year;
    cout<<setw(15)<<phong.maPB;
    cout<<setw(15)<<phong.tenPb;
    cout<<setw(15)<<phong.truongPhong;
    cout<<setw(15)<<phong.soNV<<endl;
}
void title()
{
    cout<<setw(15)<<"maNv";
    cout<<setw(15)<<"hoDem";
    cout<<setw(15)<<"ten";
    cout<<setw(20)<<"NgaySinh";
    cout<<setw(15)<<"MaPb";
    cout<<setw(15)<<"TenPb";
    cout<<setw(15)<<"TruongPhong";
    cout<<setw(15)<<"SoNv"<<endl;
}

void SortName(NhanVien a[], int n)
{
    for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		   if(strcmp(a[i].ten,a[j].ten)<0)
		  {
			NhanVien k=a[i];
            a[i]=a[j];
            a[j]=k;
		  }
		}
	}
}
void chen()
int main()
{
    int n;
    cout<<"\tNhap so nhan vien:";
    cin>>n;
    NhanVien a[n];
     for(int i=0; i<n; i++)
    {
        cout<<"Nhap Thong Tin Nhan Vien Thu "<<i+1<<": "<<endl;
        a[i].Nhap();
    }
    cout<<"\n\t=========Thong Tin Vua Nhap La==========="<<endl;
title();
    for(int j=0; j<n; j++)
    {
        a[j].Xuat();
    }
    cout<<endl;
    return 0;
}
