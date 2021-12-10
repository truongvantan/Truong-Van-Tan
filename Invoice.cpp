#include "Invoice.h"
#include <iomanip>
#include <iostream>
using namespace std;

Invoice::Invoice()
{
}

Invoice::Invoice(Client c, Item i, int soluong, float tongtien)
    : Purchase(c, i, soluong)
{
    this->TongTien = tongtien;
}

Invoice::~Invoice()
{
}

float Invoice::Get_TongTien()
{
    return this->TongTien;
}


void Invoice::Set_TongTien(float tongtien)
{
    this->TongTien = tongtien;
}


ostream &operator<<(ostream &o, Invoice &i)
{
    o << left << setw(10) << i.Get_KhachHang().Get_MaKh() << setw(20) << i.Get_KhachHang().Get_Ten()
        << setw(20) << i.Get_SanPham().Get_MaSp() << setw(20) << i.Get_SanPham().Get_TenSp() << setw(10)
        << i.Get_SoLuongMua() << setw(10) << i.Get_SanPham().Get_GiaBan() << setw(10) 
        << i.Get_TongTien() << endl;
    return o;
}

void Invoice::Write_1_Invoice(ofstream &fileout, Invoice i)
{
    fileout << left << setw(10) << i.Get_KhachHang().Get_MaKh() << setw(20) << i.Get_KhachHang().Get_Ten()
        << setw(20) << i.Get_SanPham().Get_MaSp() << setw(20) << i.Get_SanPham().Get_TenSp() << setw(10)
        << i.Get_SoLuongMua() << setw(10) << i.Get_SanPham().Get_GiaBan() << setw(10) 
        << i.Get_TongTien() << endl;
}