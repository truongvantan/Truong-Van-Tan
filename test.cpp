#include "List.h"
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

// hiển thị các trường dữ liệu của danh sách Item
void OutPutFieldItem()
{
    cout << left << setw(20) << "Ma san pham" << setw(25) << "Ten san pham" << setw(25) 
        << "Ten nha san xuat" << setw(20) << "Gia nhap" << setw(10) 
        << "Gia ban" << endl << endl;
}
// hiển thị các trường dữ liệu của danh sách Client
void OutPutFieldClient()
{
    cout << left << setw(10) << "Ma KH" << setw(25) << "Ten KH" << setw(25) << "Dia Chi" 
        << setw(25) << "So dt" << endl << endl;
}
// hiển thị các trường dữ liệu của danh sách đã mua hàng
void OutPutFieldPurchased()
{
    cout << left << setw(10) << "Ma KH" << setw(20) << "Ten KH" << setw(20) << "Ma san pham" << setw(20) 
        << "Ten san pham" << setw(10) << "So luong mua" << endl << endl;
}

int main()
{
    List<Item> List_Item;
    List<Client> List_Client;
    List<Purchase> List_Purchase;
    List<Invoice> List_Invoice;

    ifstream fileinItem;
    ifstream fileinClient;

    ofstream fileoutItem;
    ofstream fileoutClient;
    ofstream fileoutPurchase;
    ofstream fileoutInvoice;

    fileinClient.open("Client.txt", ios_base::in);
    fileoutClient.open("ClientOut.txt", ios_base::out);

    fileinItem.open("Item.txt", ios_base::in);
    fileoutItem.open("ItemOut.txt", ios_base::out);

    fileoutPurchase.open("PurchaseOut.txt", ios_base::out);
    fileoutInvoice.open("InvoiceOut.txt", ios_base::out);

    List_Item.ReadListItem(fileinItem);
    List_Client.ReadListClient(fileinClient);

    int choose;

    while(true)
    {
        cout << "\n\n====================MENU===================================";
        cout << "\n\n\t1. Xuat danh sach san pham.";
        cout << "\n\t2. Them 1 san pham.";
        cout << "\n\t3. Tim kiem theo ten san pham.";
        cout << "\n\t4. Sap xep theo gia ban.";
        cout << "\n\t5. Sap xep theo ma san pham.";
        cout << "\n\t6. Xoa san pham dau tien trong danh sach san pham.";
        cout << "\n\t7. Xoa san pham cuoi cung trong danh sach san pham.";
        cout << "\n\t8. Xuat danh sach khach hang.";
        cout << "\n\t9. Them 1 khach hang.";
        cout << "\n\t10. Mua san pham.";
        cout << "\n\t11. Xuat danh sach mua san pham.";
        cout << "\n\t12. Lap hoa don.";
        cout << "\n\t13. Xuat danh sach hoa don cua tat ca khach hang co trong danh sach khach hang.";
        cout << "\n\t14. Sao luu du lieu.";
        cout << "\n\t0. Thoat.";
        cout << "\n\n====================END====================================";

        do
        {
            cout << "\nNhap lua chon: ";
            cin >> choose;
        } while (choose < 0 || choose > 14);

        switch(choose)
        {
            case 1:
            {
                OutPutFieldItem();
                List_Item.ShowList();
                system("pause");
                //system("cls");
                break;
            }
            case 2:
            {
                TryItemAgain:
                cout << "\n\t*Nhap thong tin 1 san pham:\n";
                Item x;
                cin >> x;
                // thiết lập mã sản phẩm gồm 5 chữ số
                x.Set_MaSp(10000 + x.Get_MaSp());
                if(List_Item.CheckListItem(x.Get_MaSp()) == true)
                {
                    cout << "\n\t*Ma san pham vua nhap da ton tai !!!\n";
                    cout << "\n\t*Hay nhap ma san pham khac !\n";
                    goto TryItemAgain;
                }
                else
                {
                    List_Item.AddTail(x);
                }
                system("pause");
                //system("cls");
                break;
            }
            case 3:
            {
                string s;
                cout << "\n\t*Nhap ten san pham can tim: ";
                fflush(stdin);
                getline(cin, s);
                OutPutFieldItem();
                List_Item.Search_TenSp(s);
                system("pause");
                //system("cls");
                break;
            }
            case 4:
            {
                List_Item.Sort_GiaBanItem();
                OutPutFieldItem();
                List_Item.ShowList();
                system("pause");
                //system("cls");
                break;
            }
            case 5:
            {
                List_Item.Sort_MaSpItem();
                OutPutFieldItem();
                List_Item.ShowList();
                system("pause");
                //system("cls");
                break;
            }
            case 6:
            {
                List_Item.DeleteHead();
                OutPutFieldItem();
                List_Item.ShowList();
                system("pause");
                //system("cls");
                break;
            }
            case 7:
            {
                List_Item.DeleteTail();
                OutPutFieldItem();
                List_Item.ShowList();
                system("pause");
                //system("cls");
                break;
            }
            case 8:
            {
                OutPutFieldClient();
                List_Client.ShowList();
                system("pause");
                //system("cls");
                break;
            }
            case 9:
            {
                TryClientAgain:
                cout << "\n\t*Nhap thong tin 1 khach hang:\n";
                Client x;
                cin >> x;
                // thiết lập mã khách hàng gồm 5 chữ số
                x.Set_MaKh(10000 + x.Get_MaKh());
                if(List_Client.CheckListClient(x.Get_MaKh()) == true)
                {
                    cout << "\n\t*Ma khach hang vua nhap da ton tai !!!\n";
                    cout << "\n\t*Hay nhap ma khach hang khac.\n";
                    goto TryClientAgain;
                }
                else
                {
                    List_Client.AddTail(x);
                }
                system("pause");
                //system("cls");
                break;
            }
            case 10:
            {
                List_Purchase.MuaSanPham(List_Client, List_Item);
                system("pause");
                //system("cls");
                break;
            }
            case 11:
            {
                OutPutFieldPurchased();
                List_Purchase.ShowList();
                system("pause");
                //system("cls");
                break;
            }
            case 12:
            {
                List_Invoice.LapHoaDon(List_Client, List_Purchase);
                system("pause");
                //system("cls");
                break;
            }
            case 13:
            {
                string temp = "\n\n*************************************************************************************************************************************************************\n\n";
                fileoutInvoice << temp;
                List_Invoice.XuatHoaDon(List_Client, List_Purchase, fileoutInvoice);
                system("pause");
                //system("cls");
                break;
            }
            case 14:
            {
                List_Item.WriteListItem(fileoutItem);
                List_Client.WriteListClient(fileoutClient);
                List_Purchase.WriteListPurchased(fileoutPurchase);
                system("pause");
                //system("cls");
                break;
            }
            case 0:
                exit(0);
        }
    }
    fileinItem.close();
    fileoutItem.close();
    fileinClient.close();
    fileoutClient.close();
    fileoutPurchase.close();
    fileoutInvoice.close();
    return 0;
}