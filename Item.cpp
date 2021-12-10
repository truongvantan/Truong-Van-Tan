#include "Item.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

Item::Item(int Msp, string Tsp, string Nsx, double Gn, double Gb)
    : MaSp(Msp), TenSp(Tsp), TenNsx(Nsx), GiaNhap(Gn), GiaBan(Gb)
{
    
}

Item::~Item()
{

}

void Item::Set_MaSp(int Id)
{
    this->MaSp = Id;
}


void Item::Set_GiaNhap(double GiaNhap)
{
    this->GiaNhap = GiaNhap;
}

void Item::Set_GiaBan(double GiaBan)
{
    this->GiaBan = GiaBan;
}

int Item::Get_MaSp()
{
    return this->MaSp;
}

string Item::Get_TenSp()
{
    return this->TenSp;
}

string Item::Get_TenNsx()
{
    return this->TenNsx;
}



double Item::Get_GiaNhap()
{
    return this->GiaNhap;
}

double Item::Get_GiaBan()
{
    return this->GiaBan;
}

void Item::Read_1_Item(ifstream &filein, Item &x) 
{
    filein >> x.MaSp; // đọc vào mã sản phẩm
    filein.ignore(); // bỏ qua kí tự ','
    filein.ignore(); // bỏ qua kí tự khoảng trắng

    getline(filein, x.TenSp, ','); // đọc vào tên sản phẩm, khi đọc đến kí tự ',' thì dừng
    filein.ignore();

    getline(filein, x.TenNsx,','); // đọc vào tên nhà sản xuất, khi đọc đến kí tự ',' thì dừng;
    filein.ignore(); // bỏ qua kí tự khoảng trắng

    filein >> x.GiaNhap; // đọc vào giá nhập
    filein.ignore(); // bỏ qua kí tự khoảng trắng

    filein >> x.GiaBan; // đọc vào giá bán
    string temp;
    getline(filein, temp); // đọc kí tự xuống dòng "\n"
}




void Item::Write_1_Item(ofstream &fileout, Item x)
{
    fileout << left << setw(20) << x.MaSp << setw(25) << x.TenSp << setw(25) << x.TenNsx 
            << setw(20) << x.GiaNhap << setw(10) << x.GiaBan << endl;
}

ostream& operator<<(ostream &o, const Item &x)
{
    o << left << setw(20) << x.MaSp << setw(25) << x.TenSp << setw(25) << x.TenNsx 
        << setw(20) << x.GiaNhap << setw(10) << x.GiaBan << endl;
    return o;
}

istream &operator>>(istream &in, Item &x)
{
    cout << "\n\t\tNhap ma san pham: ";
    in >> x.MaSp;

    cout << "\n\t\tNhap ten san pham: ";
    fflush(stdin);
    getline(in, x.TenSp);

    cout << "\n\t\tNhap ten nha san xuat: ";
    fflush(stdin);
    getline(in, x.TenNsx);

    cout << "\n\t\tNhap gia nhap: ";
    in >> x.GiaNhap;

    cout << "\n\t\tNhap gia ban: ";
    in >> x.GiaBan;

    return in;
}

