#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Item
{
    private:
        int MaSp; // gồm 5 chữ số
        string TenSp;
        string TenNsx;
        double GiaNhap;
        double GiaBan;
    public:
        Item(int = 0, string = "NULL", string = "NULL", double = 0.0, double = 0.0);
        ~Item();
        void Set_MaSp(int);
        void Set_GiaNhap(double);
        void Set_GiaBan(double);
        int Get_MaSp();
        string Get_TenSp();
        string Get_TenNsx();
        double Get_GiaNhap();
        double Get_GiaBan();    // lấy giá trị GiaBan để sắp xếp
        void Read_1_Item(ifstream&, Item&); // đọc dữ liệu 1 đối tượng Item từ file Input.txt
        void Write_1_Item(ofstream&, Item); // ghi dữ liệu 1 đối tượng Item ra file Output.txt
        friend ostream &operator<<(ostream&, const Item&); // hiển thị ra 1 đối tượng Item
        friend istream &operator>>(istream&, Item&); // đọc vào 1 đối tượng Item
};

