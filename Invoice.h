#include "Purchase.h"

class Invoice : public Purchase
{
    private:
        float TongTien;
    public:
        Invoice();
        Invoice(Client, Item, int, float = 0);
        ~Invoice();
        float Get_TongTien();
        void Set_TongTien(float);
        friend ostream &operator<<(ostream&, Invoice&);
        void Write_1_Invoice(ofstream&, Invoice);
};


