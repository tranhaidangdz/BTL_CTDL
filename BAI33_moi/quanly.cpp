#ifndef QUAN_LY_CPP
#define QUAN_LY_CPP
#include <iostream>
#include <string>
#include <iomanip>
#include "congviec.cpp"
#include "link_list.cpp"
#include "ngay.cpp"
#include "bst_node.cpp"
#include "binary_search_tree.cpp"
using namespace std;

class QuanLy
{
private:
    BST_tree Tree;

public:
    void Nhap_ND_CongViec_TheoNgay_TheoGio()
    {
        int m;
        cout << "nhap so ngay muon them: ";
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            ngay a;
            cout << "nhap ngay thu " << i + 1 << endl;
            cin >> a; // moi ngay nhạp vao 1 tên_ngay(đã nạp chồng)
            cout << "nhap so cong viec muon them trong ngay: " << endl;
            int n;
            cin >> n;                   // n cv trong ngay đó
            for (int j = 0; j < n; j++) // vòng lặp này nhập vào n cv, chèn cv vào ds lk
            {
                cout << "nhap cong viec thu " << j + 1 << endl;
                CongViec x; // nhập từng cv trong ngay
                cin >> x;
                a.themCongViec(x);
            }

            Tree.insertNgay(a); // thêm ngày vào cây
        }
    }

    void Xem_Lich_CongTac_TheoNgay() // nếu TH các hàm này có chung 1 đối(VD hàm nhập istream , hàm xuất ostream ): ta đã cấp phát mảng ở trên nên ở dưới ta chỉ cần for luôn mà ko cần cáp phát lại
    {                                // còn ở đây các hàm riêng biệt nhau , mỗi khi dùng mảng thì ta cần cấp phát lại
        int ten_ngay;
        cout << "nhap vao ten ngay muon xem:";
        cin >> ten_ngay;
        // gọi hàm tìm kiếm 1 ngày=1 nút trong cây ( đã xd ở file BST_search_tree)
        // BST_node *p; // thiếu đối số nào trong hàm thì ta khai báo thêm đối số đó để truyền cho đủ
        // p = Tree.getRoot(); // ban đầu nút bắt đầu từ nút gốc của cây

        if (Tree.search(Tree.getRoot(), ten_ngay) != NULL)
        {
            cout << "danh sach cong viec trong ngay " << ten_ngay << " :" << endl;
            BST_node *p = Tree.search(Tree.getRoot(), ten_ngay);
            p->getNgay().getList().in();
        }
        else
        {
            cout << "ko tim thay !\n";
        }
    }
    void Xem_CongViec_Theo_TinhChat()
    {
        string TinhChat;

        cout << "nhap vao tinh chat muon tim: ";
        cin.ignore();
        getline(cin, TinhChat);

        Tree.LNR(Tree.getRoot(), TinhChat);
    }

    void Xem_CongViec_Da_Hoan_Tat()
    {
        cout << "\ncac cong viec da hoan tat: \n";
        Tree.CV_HoanTat(Tree.getRoot());
    }

    void Xem_CongViec_Chua_Hoan_Tat()
    {
        cout << "\ncac cong viec chua hoan tat: \n";
        Tree.CV_Chua_HoanTat(Tree.getRoot());
    }

    void Xem_CongViec_Tu_NgayA_den_NgayB()
    {
        ngay fromDate, toDate;

        cout << "Nhap ngay bat dau: ";
        cin >> fromDate;
        cout << "Nhap ngay ket thuc: ";
        cin >> toDate;
        cout << "Danh sach cong viec tu ngay " << fromDate.getTenNgay() << " den ngay " << toDate.getTenNgay() << " la:\n";
        Tree.Xem_CongViec_Tu_NgayA_den_NgayB(Tree.getRoot(), fromDate, toDate);
    }

    void DIeu_Chinh_Lich_Cong_Tac()
    {
        int lc;
        BST_node *p;
        int ten_ngay;

        string tenCV;

        do
        {
            cout << "chon lua chon cua ban:\n ";
            cout << "1.Them 1 ngay vao lich cong tac" << endl;
            cout << "2.Xoa 1 cv khoi lich cong tac" << endl;
            cout << "3.Sua 1 ngay trong lich cong tac" << endl;
            switch (lc)
            {
            case 1:

                break;
            case 2:
                cout << "nhap ten cv muon xoa: " << endl;
                getline(cin, tenCV);
                cout << "nhap ten cv muon xoa: " << endl;
                getline(cin, tenCV);
                Tree.deleteNode(p, ten_ngay, tenCV);
                break;
            case 3:

                break;
            default:
                cout << "nhap lua chon ko hop le!\n";
                break;
            }
        } while (lc != 0);
    }
};
#endif