#ifndef NGAY_ // KHI TA đặt hằng số này thì trong các file khác khi gọi tới thư viện này, các biến trong thư viện này sẽ ko dc đặt trùng nữa
#define NGAY_
#include <iostream>
#include <string>
#include "link_list.h"
#include "quanly.h"
#include "congviec.h"
using namespace std;

class NGAY
{
private:
    int ten_ngay;
    node *list;

public:
    NGAY()
    {
        ten_ngay = 0;
        list = NULL;
    }
    ~NGAY()
    {
        ten_ngay = 0;
        delete list;
    }
    int getTenNgay()
    { // lay ra 1 ngày trong tháng để tính toán vs lịch công tác
        return ten_ngay;
    }

    node *getlist() // lấy gtri con trỏ nào thì trả về gtri của con trỏ đó(thêm kdl* )
    {
        return list;
    }

    void setTenNgay(int ngay)
    {
        ten_ngay = ngay; // nhap 1 gtri cho ngày vào biên ten_ngay
    }

    void setList(CongViec x) // them 1 cv vao danh sách theo giờ (ta lấy ra giờ và ktra)
    {
        if (list == NULL)
        {
            list = creatNode(x); // tạo ra 1 nút mới
        }
        else
        {
            node *temp = list; // tạo 1 con trỏ trỏ đến nút đầu ds, sau đó ta so sánh giờ của nút muốn thêm vs giờ
            while (temp != NULL)
            {
                if(l
            }
        }
    }
};

#endif