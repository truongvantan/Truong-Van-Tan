#include "Purchase.h"
#include <iomanip>
#include <iostream>
using namespace std;

Purchase::Purchase()
{

}

Purchase::Purchase(Client khach_hang, Item san_pham, int soluong)
    : KhachHang(khach_hang), SanPham(san_pham), SoLuongMua(soluong)
{

}

Purchase::~Purchase()
{

}

int Purchase::Get_SoLuongMua()
{
    return this->SoLuongMua;
}

Client Purchase::Get_KhachHang()
{
    return this->KhachHang;
}

Item Purchase::Get_SanPham()
{
    return this->SanPham;
}

void Purchase::Set_SoLuongMua(int soluongmua)
{
    this->SoLuongMua = soluongmua;
}

ostream &operator<<(ostream &o, Purchase &p)
{
    o << left << setw(10) << p.Get_KhachHang().Get_MaKh() << setw(20) <<p.Get_KhachHang().Get_Ten()
        << setw(20) << p.Get_SanPham().Get_MaSp() << setw(20) << p.Get_SanPham().Get_TenSp() << setw(10)
        << p.Get_SoLuongMua() << endl;
    return o;
}

void Purchase::Write_1_Purchase(ofstream &fileout, Purchase p)
{
    fileout << left << setw(10) << p.Get_KhachHang().Get_MaKh() << setw(20) <<p.Get_KhachHang().Get_Ten()
        << setw(20) << p.Get_SanPham().Get_MaSp() << setw(20) << p.Get_SanPham().Get_TenSp() << setw(10)
        << p.Get_SoLuongMua() << endl;
}