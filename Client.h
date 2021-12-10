#include "Person.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
class Client : public Person
{
    private:
        int MaKh; // gồm 5 chữ số
    public:
        Client(int = 0, string = "NULL", string = "NULL", string = "NULL");
        ~Client();
        int Get_MaKh();
        void Set_MaKh(int);
        friend ostream &operator<<(ostream&, const Client&);
        friend istream &operator>>(istream&, Client&);
        void Read_1_Client(ifstream&, Client&); // đọc vào dữ liệu 1 khách hàng từ file Client.txt
        void Write_1_Client(ofstream&, Client); // ghi dữ liệu 1 khách hàng ra file ClientOut.txt
};

