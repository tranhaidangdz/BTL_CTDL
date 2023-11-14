#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "BSTNode.cpp"
#include "BSTree.cpp"
#include "TuDien.cpp"

int main()
{
    TuDien a;
    int choose;
    string key = "key", elem = "element";
    do
    {
        cout << "\n-------------------------------------------------------------------\n";
        cout << "1. doc tu dien tu file de xay dung cay\n";
        cout << "2. ghi tu dien trong cay vao file\n";
        cout << "3. them mot tu moi vao tu dien dang luu trong cay\n";
        cout << "4. xoa bo mot tu cua tu dien dang luu trong cay\n";
        cout << "5. cap nhat lai nghia mot tu dang luu trong cay\n";
        cout << "6. tim kiem mot tu trong cay\n";
        cout << "0. thoat chuong trinh\n";
        cout << "Lua chon cua ban la: ";
        cin >> choose;
        cin.ignore();
        switch (choose)
        {
        case 0:
            cout << "Thoat thanh cong!\n";
            break;
        case 1:
            a.docFile();
            break;
        case 2:
            a.ghiFile();
            break;
        case 3:
            cout << "Nhap tu muon them: ";
            getline(cin, key);
            cout << "Nhap nghia cua tu " << key << ": ";
            getline(cin, elem);
            a.themTuMoi(key, elem);
            break;
        case 4:
            cout << "Nhap tu muon xoa: ";
            getline(cin, key);
            a.xoaMotTu(key);
            break;
        case 5:
            cout << "Nhap tu muon cap nhat nghia: ";
            getline(cin, key);
            a.capNhatNghia(key);
            break;
        case 6:
            cout << "Nhap tu muon tim kiem: ";
            getline(cin, key);
            a.timKiem(key);
            break;
        default:
            cout << "Vui long chon dung menu!\n";
            break;
        }
    } while (choose != 0);

    return 0;
}