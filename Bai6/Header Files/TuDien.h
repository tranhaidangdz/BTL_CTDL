#ifndef TU_DIEN_H
#define TU_DIEN_H

#include <string>

#include "BSTree.h"

using namespace std;

class TuDien
{
private:
    BSTree<string, string> b;
public:
    void docFile();
    void ghiFile();
    void themTuMoi(string key, string elem);
    void xoaMotTu(string key);
    void capNhatNghia(string key);
    void timKiem(string key);
};

#endif