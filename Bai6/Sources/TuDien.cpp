#include <iostream>
#include <string>
#include <fstream>

#include "../Header Files/TuDien.h"
#include "../Header Files/BSTree.h"

using namespace std;

void TuDien::docFile()
{
    fstream file("../Datas/input.txt");
    if (file.fail())
        return;
    string key = "", elem = "";
    while (getline(file, key) && getline(file, elem))
    {

        b.insert(key, elem);
    }
    file.close();
}

void TuDien::ghiFile()
{
    b.inOrder();
}

void TuDien::themTuMoi(string key, string elem)
{
    b.insert(key, elem);
}

void TuDien::xoaMotTu(string key)
{
    b.remove(key);
}

void TuDien::capNhatNghia(string key)
{
    if (b.search(key))
    {
        string temp = "";
        cout << "Nhap nghia moi: ";
        getline(cin, temp);

        // Tim theo key -> Cap nhat nghia moi
        b.search(key, b.getRoot())->setElement(temp);
    }
    else
    {
        cout << "Khong tim thay tu " << key << " trong tu dien!\n";
    }
}
void TuDien::timKiem(string key)
{
    if (b.search(key))
    {
        cout << "Tim thay tu " << key << " trong tu dien:\n";
        cout << b.search(key, b.getRoot())->getKey() << ": " << b.search(key, b.getRoot())->getElement() << "\n";
    }
    else
    {
        cout << "Khong tim thay tu " << key << " trong tu dien!\n";
    }
}
