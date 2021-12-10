#include "Client.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

Client::Client(int makh, string ten, string diachi, string sodt)
    : Person(ten, diachi, sodt)
{
    this->MaKh = makh;
}

Client::~Client()
{

}

int Client::Get_MaKh()
{
    return this->MaKh;
}

void Client::Set_MaKh(int id)
{
    this->MaKh = id;
}

ostream &operator<<(ostream &o, const Client &c)
{
    o << left << setw(10) << c.MaKh << setw(25) << c.Ten << setw(25) << c.DiaChi << setw(25) << c.SoDt << endl;
    return o;
}

istream &operator>>(istream &in, Client &c)
{
    cout << "\n\t\tNhap ma khach hang: ";
    in >> c.MaKh;
    cout << "\n\t\tNhap ten khach hang: ";
    fflush(stdin);
    getline(in, c.Ten);
    cout << "\n\t\tNhap dia chi: ";
    fflush(stdin);
    getline(in, c.DiaChi);
    cout << "\n\t\tNhap so dien thoai: ";
    fflush(stdin);
    getline(in, c.SoDt);
    return in;
}

void Client::Read_1_Client(ifstream &filein, Client &c)
{
    filein >> c.MaKh; // đọc vào mã khách hàng
    filein.ignore(); // bỏ qua kí tự ','
    filein.ignore(); // bỏ qua kí tự khoảng trắng

    getline(filein, c.Ten, ','); // đọc vào tên khách hàng, khi đọc đến kí tự ',' thì dừng
    filein.ignore(); // bỏ qua kí tự khoảng trắng

    getline(filein, c.DiaChi, ','); // đọc vào địa chỉ khách hàng, khi đọc đến kí tự ',' thì dừng
    filein.ignore(); // bỏ qua kí tự khoảng trắng

    getline(filein, c.SoDt, '\n'); // đọc vào số đt khách hàng, khi đọc đến kí tự xuống dòng '\n' thì dừng
}

void Client::Write_1_Client(ofstream &fileout, Client c)
{
    fileout << left << setw(10) << c.MaKh << setw(25) << c.Ten << setw(25) << c.DiaChi << setw(25) 
            << c.SoDt << endl;
}
