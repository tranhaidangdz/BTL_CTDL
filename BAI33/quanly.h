#ifndef QUAN_LY_
#define QUAN_LY_

#include <iostream>
#include <string>
#include "congviec.h"
#include "link_list.h"
#include "bst_node.h"
#include "binary_search_tree.h"

class QuanLy
{
private:
public:
    // in ra danh sách công việc trong ngày:
    void in()
    {
        cout << " cong viec trong ngay " < < < < ":\n";
        output(head);
    }
    void inDS_Theo_TinhChat_CongViec(string TinhChat)
    {
        cout << " cong viec trong ngay " << ten_ngay << ":\n";
        in_Theo_TinhChat_CongViec(head, TinhChat);
    }
    void inDS_Theo_TinhChat_CongViec(string TinhChat)
    {
        cout << " cong viec trong ngay " << ten_ngay << ":\n";
        in_Theo_TinhChat_CongViec(head, TinhChat);
    }

    void inDS_Theo_CongViec_DaHoanThanh(string TinhChat)
    {
        cout << " cong viec trong ngay " << ten_ngay << ":\n";
        in_Theo_CongViec_DaHoanThanh(head, TinhChat);
    }

    void inDS_Theo_CongViec_ChuaHoanThanh(string TinhChat)
    {
        cout << " cong viec trong ngay " << ten_ngay << ":\n";
        in_Theo_CongViec_ChuaHoanThanh(head, TinhChat);
    }
};

#endif