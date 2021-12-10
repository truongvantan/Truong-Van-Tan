
#include "Node.h"
#include "Invoice.h"
#include <iostream>
using namespace std;


template <class T>
class List
{
    private:
        Node<T> *pHead;
        Node<T> *pTail;
    public:
        List();
        ~List();
        Node<T>* Get_pHead(); 
        Node<T>* Get_pTail();
        void AddTail(T); // thêm node vào cuối danh sách liên kết
        void AddHead(T);
        void SwapNode(T&, T&); // hoán đổi vị trí 2 node trong danh sách liên kết
        void DeleteHead(); // xóa node đầu tiên trong danh sách liên kết
        void DeleteTail(); // xóa node cuối cùng trong danh sách liên kết
        void ShowList(); // hiển thị danh sách liên kết
        int GetLengthList(); // lấy độ dài của danh sách liên kết(thêm)
        // List Item
        void Search_MaSp(int); // tìm kiếm sản phẩm theo mã sản phẩm trong danh sách Item
        void Search_TenSp(string); // tìm kiếm sản phẩm theo tên sản phẩm trong danh sách Item
        void Sort_GiaBanItem(); // sắp xếp danh sách sản phẩm tăng dần theo giá bán của từng loại sản phẩm
        void Sort_MaSpItem(); // sắp xếp danh sách sản phẩm tăng dần theo mã sản phẩm của từng loại sản phẩm
        void ReadListItem(ifstream&); // đọc dữ liệu toàn bộ danh sách sản phẩm trong file Item.txt
        void WriteListItem(ofstream&); // ghi toàn bộ dữ liệu danh sách sản phẩm ra file ItemOut.txt
        bool CheckListItem(int); // kiểm tra mã sản phẩm có trong danh sách Item
        // List Client
        void ReadListClient(ifstream&);
        void WriteListClient(ofstream&);
        bool CheckListClient(int);  // kiểm tra mã khách hàng có trong danh sách Client
        // List Purchase
        bool CheckListPurchased(int, int); // kiểm tra những khách hàng đã mua sản phẩm 
        void MuaSanPham(List<Client>&, List<Item>&); // lập danh sách mua sản phẩm
// *ràng buộc: cùng một khách hàng với cùng một sản phẩm thì không xuất hiện 2 lần trong danh sách mua sản phẩm*
        
        void WriteListPurchased(ofstream&); // ghi dữ liệu danh sách mua hàng ra file PurchaseOut.txt
        // List Invoice
        bool CheckListInvoice(int, int);
        void LapHoaDon(List<Client>&, List<Purchase>&); // lập hóa đơn từ danh sách mua hàng
        void XuatHoaDon(List<Client>&, List<Purchase>&, ofstream&); /* hiển thị hóa đơn của toàn bộ khách hàng
                                                                    và ghi dữ liệu ra file InvoiceOut.txt*/

};

template <class T>
List<T>::List()
{
    this->pHead = nullptr;
    this->pTail = nullptr;
}
 

template <class T>
List<T>::~List()
{
    if(this->pHead != nullptr)
    {
        Node<T> *p = this->pHead;
        Node<T> *pTemp;
        while(p != nullptr)
        {
            pTemp = p;
            p = p->pNext;
            delete pTemp;
        }
    }
}

template <class T>
Node<T>* List<T>::Get_pHead()
{
    return this->pHead;
}

template <class T>
Node<T>* List<T>::Get_pTail()
{
    return this->pTail;
}

template <class T>
void List<T>::AddTail(T data)
{
    // nếu danh sách rỗng
    if(this->pHead == nullptr)
    {
        // khởi tạo vùng nhó cho node p có data cần thêm vào danh sách liên kết
        Node<T> *p = new Node<T>(data);
        // thực hiện gán node đầu và cuối chính là node p
        this->pHead = this->pTail = p;
    }
    else
    {
        Node<T> *p = new Node<T>(data);
        // cho con trỏ pNext của node cuối trỏ đên p sau đó cập nhật lại pTail chính là p
        this->pTail->pNext = p;
        this->pTail = p;
    }
}

template <class T>
void List<T>::AddHead(T data)
{
    if(this->pHead == nullptr)
    {
        // khởi tạo vùng nhó cho node p có data cần thêm vào danh sách liên kết
        Node<T> *p = new Node<T>(data);
        // thực hiện gán node đầu và cuối chính là node p
        this->pHead = this->pTail = p;
    }
    else
    {
        Node<T> *p = new Node<T>(data);
        p->pNext = this->pHead;
        this->pHead = p;
    }
}

template <class T>
void List<T>::SwapNode(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <class T>
void List<T>::DeleteHead()
{
    // nếu danh sách rỗng thì thoát khỏi hàm
    if(this->pHead == nullptr)
    {
        return;
    }
    else
    {
        // nếu danh sách chỉ có 1 node thì gán node đầu tiên = nullptr sau đó thoát khỏi hàm
        if(this->pHead->pNext == nullptr)
        {
            this->pHead = nullptr;
            cout << "\nDelete head successfully !\n";
            return;
        }
        else
        {
            /* nếu danh danh có nhiều hơn 2 node thì tạo node tạm pTemp trỏ đến node đầu tiên,
            cho node đầu tiên trỏ đến node kế tiếp sau nó, sau đó thực hiện xóa node tạm pTemp*/
            Node<T> *pTemp = this->pHead;
            this->pHead = this->pHead->pNext;
            delete pTemp;
            cout << "\nDelete head successfully !\n";
            return;
        }
    }
    
}



template <class T>
void List<T>::DeleteTail()
{
    // nếu danh sách rỗng thì thoát khỏi hàm
    if(this->pHead == nullptr)
    {
        return;
    }
    else
    {
        // nếu danh sách chỉ có 1 node thì gọi hàm xóa đầu
        if(this->pHead->pNext == nullptr)
        {
            this->DeleteHead();
            return;
        }
        else
        {
            // nếu danh sách có nhiều hơn 2 node thì tạo node tạm pTemp để duyệt toàn bộ danh sách
            Node<T> *pTemp = this->pHead;
            while(pTemp != nullptr)
            {
                /* khi pTemp duyệt đến node kế cuối thì thực hiện xóa node cuối cùng pTail,
                sau đó cập nhật lại pTail chính là node pTemp*/
                if(pTemp->pNext == this->pTail)
                {
                    delete this->pTail;
                    pTemp->pNext = nullptr;
                    this->pTail = pTemp;
                    cout << "\nDelete tail successfully !\n";
                    return;
                }
                pTemp = pTemp->pNext;
            }
        }
    }
}


template<class T>
void List<T>::ShowList()
{
    if(this->pHead == nullptr)
    {
        cout << "\nList is empty!!!\n";
    }
    else
    {
        Node<T> *pTemp = this->pHead;
        while(pTemp != nullptr)
        {
            cout << pTemp->data;
            pTemp = pTemp->pNext;
        }
        cout << endl;
    }
}

template<class T>
int List<T>::GetLengthList()
{
    int LengthList = 0;
    Node<T> *pTemp = this->pHead;
    while(pTemp != nullptr)
    {
        LengthList++;
        pTemp = pTemp->pNext;
    }
    return LengthList;
}

/*****************************************************************************************************************************/

template<>
void List<Item>::Search_MaSp(int Id)
{
    // tạo node tạm pTemp để duyệt danh sách
    Node<Item> *pTemp = this->pHead;
    while(pTemp != nullptr)
    {
        /* khi giá trị mã sản phẩm của pTemp chính là mã sản phẩm đã nhập thì
         thực hiển thị ra thông tin sản phẩm đó*/
        if(pTemp->data.Get_MaSp() == Id)
        {
            cout << pTemp->data;
            return;
        }
        pTemp = pTemp->pNext;
    }
    cout << "\nKhong tim thay san pham !\n";
}

// tương tự tìm theo mã sản phẩm
template<>
void List<Item>::Search_TenSp(string s)
{
    int count = 0;
    Node<Item> *pTemp = this->pHead;
    while(pTemp != nullptr)
    {
        if(pTemp->data.Get_TenSp() == s)
        {
            count++;
            cout << pTemp->data;
        }
        pTemp = pTemp->pNext;
    }
    if(count == 0)
    {
        cout << "\nKhong tim thay san pham vua nhap !\n";
    }
}

template<>
void List<Item>::Sort_GiaBanItem()
{
    // cho node k trỏ đến đầu danh sách
    for(Node<Item> *k = this->pHead; k != nullptr; k = k->pNext)
    {
        // cho node h trỏ đến node kế tiếp sau node k trong danh sách
        for(Node<Item> *h = k->pNext; h != nullptr; h = h->pNext)
        {
            // nếu giá trị giá bán của node k > giá trị giá bán của node h thì hoán đổi 2 node
            if(k->data.Get_GiaBan() > h->data.Get_GiaBan())
            {
                this->SwapNode(k->data, h->data);
            }
        }
    }
}

// tương tự sắp xếp theo giá bán
template<>
void List<Item>::Sort_MaSpItem()
{
    for(Node<Item> *k = this->pHead; k != nullptr; k = k->pNext)
    {
        for(Node<Item> *h = k->pNext; h != nullptr; h = h->pNext)
        {
            if(k->data.Get_MaSp() > h->data.Get_MaSp())
            {
                this->SwapNode(k->data, h->data);
            }
        }
    }
}

template<>
void List<Item>::ReadListItem(ifstream &filein)
{
    while(!filein.eof())
    {
        Item x;
        // đọc dữ liệu 1 Item từ file Item.txt
        x.Read_1_Item(filein, x);
        // thiết lập mã sản phẩm gồm 5 chữ số
        x.Set_MaSp(10000 + x.Get_MaSp());
        // thêm vào cuối danh sách Item
        this->AddTail(x);
    }
}

template<>
void List<Item>::WriteListItem(ofstream &fileout)
{
    // ghi các trường dữ liệu vào file ItemOut.txt
    fileout << left << setw(20) << "Ma san pham" << setw(25) << "Ten san pham" << setw(25) 
        << "Ten nha san xuat" << setw(20) << "Gia nhap" << setw(10) 
        << "Gia ban" << endl << endl;
    string temp = "===========================================================================================================\n";
    /* tạo node tạm pTemp để duyệt toàn bộ danh sách,
    với mỗi vị trí mà pTemp duyệt qua thì thực hiện ghi thông tin 1 sản phẩm tại vị trí đó ra file ItemOut.txt */
    Node<Item> *pTemp = this->pHead;
    while(pTemp != nullptr)
    {
        pTemp->data.Write_1_Item(fileout, pTemp->data);
        pTemp = pTemp->pNext;
    }
    fileout << temp;
    cout << "\nSao luu thanh cong.\n";
    cout << "\nMo file ItemOut.txt de xem ket qua !\n";
}

/* kiểm tra xem IdItem vừa nhập có tồn tại trong danh sách Item không ?
 nếu có thì trả về true, không thì trả về false*/
template<>
bool List<Item>::CheckListItem(int IdItem)
{
    Node<Item> *pTemp = this->pHead;
    while(pTemp != nullptr)
    {
        if(pTemp->data.Get_MaSp() == IdItem)
        {
            return true;
        }
        pTemp = pTemp->pNext;
    }
    return false;
}

/*****************************************************************************************************************************/
// tương tự đọc dữ liệu danh sách Item
template<>
void List<Client>::ReadListClient(ifstream &filein)
{
    while(!filein.eof())
    {
        Client x;
        x.Read_1_Client(filein, x);
        x.Set_MaKh(10000 + x.Get_MaKh());
        this->AddTail(x);
    }
}

// tương tự ghi dữ liệu danh sách Item
template<>
void List<Client>::WriteListClient(ofstream &fileout)
{
    fileout << left << setw(10) << "Ma KH" << setw(25) << "Ten KH" << setw(25) << "Dia Chi" 
        << setw(25) << "So dt" << endl << endl;
    string temp = "====================================================================================\n";
    Node<Client> *pTemp = this->pHead;
    while(pTemp != nullptr)
    {
        pTemp->data.Write_1_Client(fileout, pTemp->data);
        pTemp = pTemp->pNext;
    }
    fileout << temp;
    cout << "\nSao luu thanh cong.\n";
    cout << "\nMo file ClientOut.txt de xem ket qua !\n";
}

// tương tự kiểm tra IdItem trong danh sách Item
template<>
bool List<Client>::CheckListClient(int IdClient)
{
    Node<Client> *pTemp = this->pHead;
    while(pTemp != nullptr)
    {
        if(pTemp->data.Get_MaKh() == IdClient)
        {
            return true;
        }
        pTemp = pTemp->pNext;
    }
    return false;
}

/*****************************************************************************************************************************/

/* kiểm tra xem MaKh vừa nhập và MaSp vừa nhập có tồn tại trong danh sách mua hàng không?
nếu có thì trả về true, không thì trả về false */ 
template<>
bool List<Purchase>::CheckListPurchased(int MaKh, int MaSp)
{
    Node<Purchase> *pTemp = this->pHead;
    while(pTemp != nullptr)
    {
        if(pTemp->data.Get_KhachHang().Get_MaKh() == MaKh && pTemp->data.Get_SanPham().Get_MaSp() == MaSp)
        {
            return true;
        }
        pTemp = pTemp->pNext;
    }
    return false;
}


template<>
void List<Purchase>::MuaSanPham(List<Client> &l_client, List<Item> &l_item)
{
    int IdItem;
    int IdClient;

    while(true)
    {
        TryAgain:
        cout << "\n\t*Nhap ma khach hang can mua san pham(nhan 0 de thoat): "; 
        cin >> IdClient;
        if(IdClient == 0)
        {
            return;
        }
        if(l_client.CheckListClient(IdClient) == false)
        {
            cout << "\n\t\t*Ma khach hang khong ton tai. Hay thu lai !\n";
            goto TryAgain;
        }
        else
        {
            for(Node<Client> *k = l_client.Get_pHead(); k != nullptr; k = k->GetpNext())
            {
                if(k->GetData().Get_MaKh() == IdClient)
                {
                    cout << "\n\t\t*Nhap thong tin mua hang cho khach hang " << k->GetData().Get_Ten() << ":\n";
                    while(true)
                    {
                        cout << "\n\t\t\t*Nhap vao ma san pham(nhap 0 de ket thuc): ";
                        cin >> IdItem;

                        if(IdItem == 0)
                        {
                            break;
                        }

                        if(l_item.CheckListItem(IdItem) == false)
                        {
                            cout << "\n\t\t\t\t*Nhap sai ma san pham. Thu lai !\n";
                        }
                        else
                        {
                            Node<Item> *index;
                            int soluongmua;
                            /* nếu khách hàng có IdClient vừa nhập chưa mua sản phẩm có IdItem vừa nhập thì
                            thêm vào danh sách mua hàng*/  
                            if(this->CheckListPurchased(k->GetData().Get_MaKh(), IdItem) == false)
                            {
                                for(Node<Item> *p = l_item.Get_pHead(); p != nullptr; p = p->GetpNext())
                                {
                                    if(p->GetData().Get_MaSp() == IdItem)
                                    {
                                        index = p;
                                        break;
                                    }
                                }
                                
                                do
                                {
                                    cout << "\n\t\t\t\t*Nhap so luong san pham(so luong > 0): ";
                                    cin >> soluongmua;
                                } while (soluongmua <= 0);
                                
                                Purchase pur(k->GetData(), index->GetData(), soluongmua);
                                
                                this->AddTail(pur);
                            }
                            /* ngược lại, nếu khách hàng đó đã mua sản phẩm có IdItem vừa nhập thì
                            duyệt danh sách tìm khách hàng đó để cộng dồn số lượng sản phẩm đã mua */
                            else
                            {  
                                do
                                {
                                    cout << "\n\t\t\t\t*Nhap so luong san pham(so luong > 0): ";
                                    cin >> soluongmua;
                                } while (soluongmua <= 0);

                                for(Node<Purchase> *g = this->pHead; g != nullptr; g = g->pNext)
                                {
                                    if(g->data.Get_KhachHang().Get_MaKh() == IdClient && g->data.Get_SanPham().Get_MaSp() == IdItem)
                                    {
                                        g->data.Set_SoLuongMua(g->data.Get_SoLuongMua() + soluongmua);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// tương tự ghi dữ liệu danh sách Item
template<>
void List<Purchase>::WriteListPurchased(ofstream &fileout)
{
    fileout << left << setw(10) << "Ma KH" << setw(20) << "Ten KH" << setw(20) << "Ma san pham" << setw(20) 
        << "Ten san pham" << setw(10) << "So luong mua" << endl << endl;
    string temp = "====================================================================================\n";
    Node<Purchase> *pTemp = this->pHead;
    while(pTemp != nullptr)
    {
        pTemp->data.Write_1_Purchase(fileout, pTemp->data);
        pTemp = pTemp->pNext;
    }
    fileout << temp;
    cout << "\nSao luu thanh cong.\n";
    cout << "\nMo file PurchaseOut.txt de xem ket qua !\n";
}

/*****************************************************************************************************************************/
template<>
bool List<Invoice>::CheckListInvoice(int MaKh, int MaSp)
{
    Node<Invoice> *pTemp = this->pHead;
    while(pTemp != nullptr)
    {
        if(pTemp->data.Get_KhachHang().Get_MaKh() == MaKh && pTemp->data.Get_SanPham().Get_MaSp() == MaSp)
        {
            return true;
        }
        pTemp = pTemp->pNext;
    }
    return false;
}


template<>
void List<Invoice>::LapHoaDon(List<Client> &l_client, List<Purchase> &l_purchase)
{
    //duyệt đồng thời danh sách Client và danh sách mua hàng
    if(this->pHead == nullptr)
    {
        for(Node<Client> *k = l_client.Get_pHead(); k != nullptr; k = k->GetpNext())
        {
            for(Node<Purchase> *h = l_purchase.Get_pHead(); h != nullptr; h = h->GetpNext())
            {
                /*nếu mã khách hàng của danh sách mua hàng trùng với mã khách hàng trong danh sách Client 
                thì thực hiện thêm dữ liệu mua hàng của khách hàng đó vào danh sách hóa đơn*/
                if(k->GetData().Get_MaKh() == h->GetData().Get_KhachHang().Get_MaKh())
                {
                    Invoice inv(h->GetData().Get_KhachHang(), h->GetData().Get_SanPham(), h->GetData().Get_SoLuongMua(), h->GetData().Get_SoLuongMua() * h->GetData().Get_SanPham().Get_GiaBan());
                    this->AddTail(inv);
                }
            }
        }
    }
    else
    {
        for(Node<Client> *k = l_client.Get_pHead(); k != nullptr; k = k->GetpNext())
        {
            for(Node<Purchase> *h = l_purchase.Get_pHead(); h != nullptr; h = h->GetpNext())
            {
                if(k->GetData().Get_MaKh() == h->GetData().Get_KhachHang().Get_MaKh())
                {
                    if(this->CheckListInvoice(h->GetData().Get_KhachHang().Get_MaKh(), h->GetData().Get_SanPham().Get_MaSp()) == true)
                    {
                        if(this->pHead->data.Get_KhachHang().Get_MaKh() == h->GetData().Get_KhachHang().Get_MaKh() && this->pHead->data.Get_SanPham().Get_MaSp() == h->GetData().Get_SanPham().Get_MaSp() && this->pHead->data.Get_SoLuongMua() != h->GetData().Get_SoLuongMua())
                        {
                            this->DeleteHead();
                            Invoice inv(h->GetData().Get_KhachHang(), h->GetData().Get_SanPham(), h->GetData().Get_SoLuongMua(), h->GetData().Get_SoLuongMua() * h->GetData().Get_SanPham().Get_GiaBan());
                            this->AddTail(inv);
                        }
                        else
                        {
                            if(this->pTail->data.Get_KhachHang().Get_MaKh() == h->GetData().Get_KhachHang().Get_MaKh() && this->pTail->data.Get_SanPham().Get_MaSp() == h->GetData().Get_SanPham().Get_MaSp() && this->pTail->data.Get_SoLuongMua() != h->GetData().Get_SoLuongMua())
                            {
                                this->DeleteTail();
                                Invoice inv(h->GetData().Get_KhachHang(), h->GetData().Get_SanPham(), h->GetData().Get_SoLuongMua(), h->GetData().Get_SoLuongMua() * h->GetData().Get_SanPham().Get_GiaBan());
                                this->AddTail(inv); 
                            }
                            else
                            {
                                Node<Invoice> *pTemp;
                                for(Node<Invoice> *t = this->pHead; t != nullptr; t = t->pNext)
                                {
                                    if(h->GetData().Get_KhachHang().Get_MaKh() == t->data.Get_KhachHang().Get_MaKh() && h->GetData().Get_SanPham().Get_MaSp() == t->data.Get_SanPham().Get_MaSp() && h->GetData().Get_SoLuongMua() != t->data.Get_SoLuongMua())
                                    {
                                        pTemp->pNext = t->pNext;
                                        delete t;
                                        Invoice inv(h->GetData().Get_KhachHang(), h->GetData().Get_SanPham(), h->GetData().Get_SoLuongMua(), h->GetData().Get_SoLuongMua() * h->GetData().Get_SanPham().Get_GiaBan());
                                        this->AddTail(inv);
                                        break;
                                    }
                                    pTemp = t;
                                }
                            }
                        }
                    }
                    else
                    {
                        Invoice inv(h->GetData().Get_KhachHang(), h->GetData().Get_SanPham(), h->GetData().Get_SoLuongMua(), h->GetData().Get_SoLuongMua() * h->GetData().Get_SanPham().Get_GiaBan());
                        this->AddTail(inv);
                    }
                }
            }
        }
    }
}



template<>
void List<Invoice>::XuatHoaDon(List<Client> &l_client, List<Purchase> &l_purchase, ofstream &fileout)
{
    string temp = "==================================================================================================\n";
    
    //duyệt đồng thời danh sách Client và danh sách hóa đơn
    for(Node<Client> *k = l_client.Get_pHead(); k != nullptr; k = k->GetpNext())
    {
        cout << left << setw(10) << "Ma KH" << setw(20) << "Ten KH" << setw(20) << "Ma san pham" << setw(20) 
        << "Ten san pham" << setw(10) << "So luong" << setw(10) << "Don Gia" << setw(10) 
        << "Tong Tien" << endl;

        fileout << left << setw(10) << "Ma KH" << setw(20) << "Ten KH" << setw(20) << "Ma san pham" << setw(20) 
        << "Ten san pham" << setw(10) << "So luong" << setw(10) << "Don Gia" << setw(10) 
        << "Tong Tien" << endl;

        int TongSoLuong = 0; // tính tổng số lượng các sản phẩm mà 1 khách hàng đã mua
        float TongCong = 0; // tỉnh tổng số tiền mà khách hàng đó phải trả
        
        cout << left << setw(10) << k->GetData().Get_MaKh() << setw(20) << k->GetData().Get_Ten() << endl;
        fileout << left << setw(10) << k->GetData().Get_MaKh() << setw(20) << k->GetData().Get_Ten() << endl;

        for(Node<Invoice> *h = this->pHead; h != nullptr; h = h->pNext)
        {
            //nếu mã khách hàng trong danh sách hóa đơn trùng với mã khách hàng trong danh sách Client
            if(k->GetData().Get_MaKh() == h->data.Get_KhachHang().Get_MaKh())
            {
                // hiển thị thông tin hóa đơn của khách hàng đó ra màn hình
                cout << left << setw(30) << " " << setw(20) << h->data.Get_SanPham().Get_MaSp() 
                << setw(20) << h->data.Get_SanPham().Get_TenSp() << setw(10) << h->data.Get_SoLuongMua() 
                << setw(10) << h->data.Get_SanPham().Get_GiaBan() << setw(10) << h->data.Get_TongTien() << endl;
                // ghi thông tin hóa đơn của khách hàng đó ra file InvoiceOut.txt
                fileout << left << setw(30) << " " << setw(20) << h->data.Get_SanPham().Get_MaSp() 
                << setw(20) << h->data.Get_SanPham().Get_TenSp() << setw(10) << h->data.Get_SoLuongMua() 
                << setw(10) << h->data.Get_SanPham().Get_GiaBan() << setw(10) << h->data.Get_TongTien() << endl;
                // tính tổng số lượng sản phẩm mà khách hàng đó đã mua
                TongSoLuong += h->data.Get_SoLuongMua();
                // tính tổng số tiền mà khách hàng đó phải trả
                TongCong += h->data.Get_TongTien();
            }
        }
        cout << setw(70) << " " << setw(10) << "TongSl" << setw(10) << " " << setw(10) << "TongCong" << endl;
        cout << setw(70) << " " << setw(10) << TongSoLuong << setw(10) << " " << setw(10) << TongCong << endl;
        cout << temp;
        // ghi các trường dữ liệu của danh sách hóa đơn ra file InvoiceOut.txt
        fileout << setw(70) << " " << setw(10) << "TongSl" << setw(10) << " " << setw(10) << "TongCong" << endl;
        fileout << setw(70) << " " << setw(10) << TongSoLuong << setw(10) << " " << setw(10) << TongCong << endl;
        fileout << temp;
    }
}
