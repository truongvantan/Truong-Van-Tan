#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(string ten, string diachi, string sodt)
    : Ten(ten), DiaChi(diachi), SoDt(sodt)
{   

}

Person::~Person()
{

}

string Person::Get_Ten()
{
    return this->Ten;
}

string Person::Get_DiaChi()
{
    return this->DiaChi;
}

string Person::Get_SoDt()
{
    return this->SoDt;
}