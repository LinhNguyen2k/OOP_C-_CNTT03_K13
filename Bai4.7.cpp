#include <iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>

using namespace std;

class doanhNghiep;

class date
{
private:
    int d;
    int m;
    int y;
public:
    void nhap();
    void xuat();
    friend class doanhNghiep;
    friend void haNoi(doanhNghiep x[],int n);
    friend void sua(doanhNghiep x[],int n,bool &check);
    friend void tongDoanhThu(doanhNghiep x[],int n);
};

class diaChi
{
private:
    char dt[10];
    char phuong[10];
    char quan[10];
    char thanhPho[10];
public:
    friend class doanhNghiep;
    friend void haNoi(doanhNghiep x[],int n);
    friend void sua(doanhNghiep x[],int n,bool &check);
    friend void tongDoanhThu(doanhNghiep x[],int n);
};

class doanhNghiep
{
private:
    int maDN;
    char tenDN[10];
    date ngayTL;
    diaChi dc;
    char giamDoc[10];
    long doanhThu;
public:
    void nhap();
    void xuat();
    friend void tieuDe();
    friend void haNoi(doanhNghiep x[],int n);
    friend void sua(doanhNghiep x[],int n,bool &check);
    friend void tongDoanhThu(doanhNghiep x[],int n);
};

void tieuDe()
{
    cout<<setw(10)<<"MaDN"<<setw(10)<<"TenDN"<<setw(10)<<"Ngay"<<setw(10)<<"Thang"<<setw(10)<<"Nam"<<setw(10)<<"SDT"<<setw(10)<<"Phuong"<<setw(10)<<"Quan"<<setw(10)<<"TP"<<setw(10)<<"GiamDoc"<<setw(10)<<"DoanhThu";
}

void date::nhap()
{
    cout<<"Nhap ngay: ";
    cin>>d;
    cout<<"Nhap thang: ";
    cin>>m;
    cout<<"Nhap nam: ";
    cin>>y;
}

void date::xuat()
{
    cout<<setw(10)<<d<<setw(10)<<m<<setw(10)<<y;
}

void doanhNghiep::nhap()
{
    cout<<"Nhap ma DN: ";
    cin>>maDN;
    cout<<"Nhap ten DN: ";
    fflush(stdin);
    gets(tenDN);
    cout<<"NHAP NGAY TL "<<endl;
    ngayTL.nhap();
    cout<<"Nhap sdt: ";
    fflush(stdin);
    gets(dc.dt);
    cout<<"Nhap phuong: ";
    fflush(stdin);
    gets(dc.phuong);
    cout<<"Nhap quan: ";
    fflush(stdin);
    gets(dc.quan);
    cout<<"Nhap TP: ";
    fflush(stdin);
    gets(dc.thanhPho);
    cout<<"Nhap ten giam doc: ";
    fflush(stdin);
    gets(giamDoc);
    cout<<"Nhap doanh thu: ";
    cin>>doanhThu;
}

void doanhNghiep::xuat()
{  cout<<endl;
    cout<<setw(10)<<maDN<<setw(10)<<tenDN;
    ngayTL.xuat();
    cout<<setw(10)<<dc.dt<<setw(15)<<dc.phuong<<setw(10)<<dc.quan<<setw(10)<<dc.thanhPho<<setw(10)<<giamDoc<<setw(15)<<doanhThu;
}

void haNoi(doanhNghiep x[],int n)
{
    for(int i=0; i<n; i++)
    {
        if(stricmp(x[i].dc.thanhPho,"Ha Noi")==0)
        {
            x[i].xuat();
        }
    }
}

void tongDoanhThu(doanhNghiep x[],int n)
{
    long sum=0;
    for(int i=0; i<n; i++)
    {
        if(x[i].ngayTL.y==2015)
        {
            sum+=x[i].doanhThu;
        }
    }
    cout<<"Tong doanh thu cac doanh nghiep thanh lap nam 2015 = "<<sum<<endl;
}

void sua(doanhNghiep x[],int n,bool &check)
{
    int ma;
    check=false;
    cout<<"Nhap ma doanh nghiep can sua: ";
    cin>>ma;
    for(int i=0; i<n; i++)
    {
        if(x[i].maDN==ma)
        {
            cout<<"Nhap lai tat ca thong tin doanh nghiep thu "<<i+1<<"voi ma "<<ma<<": ";
            cout<<"Nhap ten DN: ";
            fflush(stdin);
            gets(x->tenDN);
            cout<<"NHAP NGAY TL "<<endl;
            x->ngayTL.nhap();
            cout<<"Nhap sdt: ";
            fflush(stdin);
            gets(x->dc.dt);
            cout<<"Nhap phuong: ";
            fflush(stdin);
            gets(x->dc.phuong);
            cout<<"Nhap quan: ";
            fflush(stdin);
            gets(x->dc.quan);
            cout<<"Nhap TP: ";
            fflush(stdin);
            gets(x->dc.thanhPho);
            cout<<"Nhap ten giam doc: ";
            fflush(stdin);
            gets(x->giamDoc);
            cout<<"Nhap doanh thu: ";
            cin>>x->doanhThu;
            check=true;
        }
    }
}

int main()
{
    int n;
    cout<<"Nhap so Doanh Nghiep: ";
    cin>>n;
    doanhNghiep x[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Nhap thong tin daonh nghiep thu "<<i+1<<": "<<endl;
        x[i].nhap();
    }
    cout<<"==========Thong Tin Vua Nhap=========="<<endl;
    tieuDe();
    for(int j=0; j<n; j++)
    {
        x[j].xuat();
    }
    cout<<endl;
    cout<<"======================================="<<endl;
    cout<<"=========DOANH NGHIEP O HA NOI========="<<endl;
    tieuDe();
    haNoi(x,n);
    cout<<endl;
    cout<<"======================================="<<endl;
    cout<<"=DOANH THU NHUNG DOANH NGHIEP NAM 2015="<<endl;
    tongDoanhThu(x,n);
    cout<<endl;
    cout<<"======================================="<<endl;
    cout<<"=============SUA THONG TIN============="<<endl;
    bool check;
    sua(x,n,check);
    if(check)
    {
        cout<<"=========THONG TIN SAU KHI SUA========="<<endl;
        tieuDe();
        cout<<endl;
        for(int k=0; k<n; k++)
        {
            x[k].xuat();
        }
    }
    else
    {
        cout<<"Khong  co ma trung nhau."<<endl;
    }
    return 0;
}
