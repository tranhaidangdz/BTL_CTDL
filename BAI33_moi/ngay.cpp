#ifndef NGAY_CPP
#define NGAY_CPP
#include <iostream>
#include <string>
#include <iomanip>
#include "congviec.cpp"
#include "link_list.cpp"
using namespace std;

class ngay
{
private:
    int ten_ngay;
    list cv;

public:
    int getTenNgay()
    {
        return ten_ngay;
    }
    void setTenNgay(int ngay) // truyền vào gtri mới cho ngay
    {
        ten_ngay = ngay;
    }
    list getList() // lấy ra ds công việc
    {
        return cv;
    }
    void setList(list x) // gán gtri mới cho ds cv
    {
        cv = x;
    }
    void themCongViec(CongViec x) // hàm thêm 1 nút cv vào ds lk (ta đã xd hàm thêm 1 nút vào ds, và nút đó chnính là cv cần thêm)
    {

        cv.insert(x);
    }
    // nap chong TT nhap cho lop ngay(gồm nhập vào ten_ngay và list công việc):
    friend istream &operator>>(istream &in, ngay &a)
    {
        cout << "nhap ten ngay:";
        in >> a.ten_ngay;

        return in;
    }
};
#endif