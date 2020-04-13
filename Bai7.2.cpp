#include <iostream>
#include<stdio.h>
#include<iomanip>
#include <string.h>
using namespace std;
class PACULTY;
class STUDENT;

class PERSON
{
protected:
    char Name[30];
    char Birth[20];
    char Address[30];
public:
    void input();
    void output();
    PERSON()
    {
        strcpy(Name,"Linh");
        strcpy(Birth,"27/09");
        strcpy(Address,"Ha Noi");
    };
};
class SCHOOL
{
private:
    char Name[30];
    char Date[20];
    friend class PACULTY;
    friend class STUDENT;
};
class PACULTY
{
private:
    char Name[30];
    char Date[20];
    SCHOOL x;
public:
    void input();
    void output();
    friend class STUDENT;

};

class STUDENT:public PERSON
{
private:
    PACULTY y;
    char class1[20];
    float Score;
public:
    void input();
    void output();
    STUDENT():PERSON()
    {
        strcpy(y.Name,"Cam Ngoan");
        strcpy(y.Date,"02/04");
        strcpy(y.x.Name,"HaUI");
        strcpy(y.x.Date,"09/10");
        strcpy(class1,"CNTT03");
        Score = 10;
    };
};
void PERSON::input()
{
    cout<<"Nhap Ten Person:";
    fflush(stdin);
    gets(Name);
    cout<<"Nhap Nam Sinh:";
     fflush(stdin);
    gets(Birth);
    cout<<"Nhap Dia Chi Person:";
    fflush(stdin);
    gets(Address);
}
void PERSON::output(){
  cout << setw(15) << Name;
    cout << setw(10) << Birth;
    cout << setw(15) << Address;
}
void PACULTY::input()
{
    cout<<"Nhap Ten Giang Vien:";
    fflush(stdin);
    gets(Name);
    cout<<"Nhap Ngay PACULTY:";
    fflush(stdin);
    gets(Date);
    cout<<"Nhap Ten School:";
    fflush(stdin);
    gets(x.Name);
    cout<<"Nhap Ngay School:";
    fflush(stdin);
    gets(x.Date);
};
void PACULTY::output()
{
    cout<<setw(15)<<Name<<setw(12)<<Date<<setw(15)<<x.Name<<setw(12)<<x.Date;
}
void STUDENT::input()
{   PERSON::input();
    y.input();
    cout<<"Nhap Lop:";
    fflush(stdin);
    gets(class1);
    cout<<"Nhap so ban:";
    cin>>Score;
}
void STUDENT::output()
{
    PERSON::output();
    y.output();
    cout<<setw(10)<<class1<<setw(10)<<Score;
}

void title()
{
    cout << setw(15) << "nameStd";
    cout << setw(10) << "birthStd";
    cout << setw(15) << "address";
    cout << setw(15) << "nameFacul";
    cout << setw(12) << "dateFacul";
    cout << setw(15) << "nameSchool";
    cout << setw(12) << "dateSchool";
    cout << setw(10) << "Class";
    cout << setw(10) << "score" << endl;
}
int main()
{
    STUDENT x;
    x.input();
    title();
    x.output();
    return 0;
}
