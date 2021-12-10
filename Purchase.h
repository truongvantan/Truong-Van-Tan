#include "Item.h"
#include "Client.h"
#include <iostream>
using namespace std;
class Purchase
{
    protected:
        int SoLuongMua;
        Client KhachHang;
        Item SanPham;
    public:
        Purchase();
        Purchase(Client, Item, int = 0);
        ~Purchase();
        int Get_SoLuongMua();
        Client Get_KhachHang();
        Item Get_SanPham();
        void Set_SoLuongMua(int);
        friend ostream &operator<<(ostream&, Purchase&);
        void Write_1_Purchase(ofstream&, Purchase);
};


