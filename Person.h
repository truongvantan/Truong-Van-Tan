#include <iostream>
using namespace std;
class Person
{
    protected:
        string Ten;
        string DiaChi;
        string SoDt;
    public:
        Person(string = "NULL", string = "NULL", string = "NULL");
        ~Person();
        string Get_Ten();
        string Get_DiaChi();
        string Get_SoDt();
};