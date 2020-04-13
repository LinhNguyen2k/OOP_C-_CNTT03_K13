#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
class BenhAn;
class BenhNhan {
protected:
    char name[15], country[15];
    int year;
public:
    void nhap();
    void xuat();
    friend int tinhTuoi(BenhAn list[],int index);
};
class BenhAn:public BenhNhan {
private:
    char tenBenhAn[15];
    long long money;
public:
    void nhap();
    void xuat();
    friend int tinhTuoi(BenhAn list[],int index);
    friend void showMaxMoney(BenhAn list[],int index);
};
void BenhNhan::nhap() {
    cout<<"\n Nhap ten: ";
    fflush(stdin);
    gets(name);
    cout<<"\n Nhap que quan: ";
    fflush(stdin);
    gets(country);
    cout<<"\n Nhap nam sinh: ";
    cin>>year;
}
void title() {
    cout<<setw(15)<<"Ten";
    cout<<setw(15)<<"QueQuan";
    cout<<setw(10)<<"NamSinh";
    cout<<setw(15)<<"TenBenhAn";
    cout<<setw(12)<<"TienVienPhi"<<endl;
}
void BenhNhan::xuat() {
    cout<<setw(15)<<name;
    cout<<setw(15)<<country;
    cout<<setw(10)<<year;
}

void BenhAn::nhap() {
    BenhNhan::nhap();
    cout<<"\n Nhap ten benh an: ";
    fflush(stdin);
    gets(tenBenhAn);
    cout<<"\n Nhap tien vien phi: ";
    cin>>money;
}
void BenhAn::xuat() {
    BenhNhan::xuat();
    cout<<setw(15)<<tenBenhAn;
    cout<<setw(12)<<money;
}
int tinhTuoi(BenhAn list[],int index) {
    return 2020 - list[index].year;
}
void sortByAge(BenhAn list[],int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if (tinhTuoi(list,i) < tinhTuoi(list,j)) {
                BenhAn temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}
void showAgeLess10(BenhAn list[], int n) {
    title();
    bool check = false;
    for(int i=0; i<n; i++) {
        if (tinhTuoi(list,i)<=10) {
            list[i].xuat();
            check = true;
        }
    }
    if (!check)
        cout<<"\tKhong co benh nhan nao"<<endl;
}
void showList(BenhAn list[],int n) {
    title();
    for(int i=0; i<n; i++) {
        list[i].xuat();
        cout<<endl;
    }
}
void showMaxMoney(BenhAn list[],int n) {
    long long max = list[0].money;
    int index = 0;
    for(int i=0; i<n; i++) {
        if (list[i].money > max) {
            max = list[i].money;
            index = i;
        }
    }
    cout<<endl;
    title();
    list[index].xuat();
}
int main() {
    int n;
    cout<<"\n Nhap so benh an: ";
    cin>>n;
    BenhAn list[n];
    for(int i=0; i<n; i++) {
        list[i].nhap();
    }

    cout<<"\n\t==================DANH SACH BENH AN=================="<<endl;
    showList(list,n);
    sortByAge(list,n);
    cout<<"\n\t============DANH SACH BENH SAP XEP THEO TUOI============"<<endl;
    showList(list,n);
    cout<<"\n\t============DANH SACH BENH NhAN TUOI NHO HON 10============"<<endl;
    showAgeLess10(list,n);
    cout<<"\n\t============BENH NHAN CO TIEN VIEN PHI LON NHAT============"<<endl;
    showMaxMoney(list,n);
    return 0;
}

