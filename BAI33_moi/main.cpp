#include <iostream>
#include <string>
#include <iomanip>
#include "congviec.cpp"
#include "link_list.cpp"
#include "ngay.cpp"
#include "bst_node.cpp"
#include "binary_search_tree.cpp"
#include "quanly.cpp"
using namespace std;

int main()
{
    QuanLy a; // luu ý khi khai báo biến có kdl class bị lỗi ta phải xem lại trong class đó có hàm tạo ko đối chưa?
    a.Nhap_ND_CongViec_TheoNgay_TheoGio();
    // a.Xem_Lich_CongTac_TheoNgay();
    // a.Xem_CongViec_Theo_TinhChat();
    // a.Xem_CongViec_Da_Hoan_Tat();
    // a.Xem_CongViec_Chua_Hoan_Tat();
    // a.Xem_CongViec_Tu_NgayA_den_NgayB();
    a.DIeu_Chinh_Lich_Cong_Tac();
    return 0;
}
