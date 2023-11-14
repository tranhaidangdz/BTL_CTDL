#ifndef BINARY_SEARCH_TREE_CPP
#define BINARY_SEARCH_TREE_CPP
#include <iostream>
#include <string>
#include <iomanip>
#include "congviec.cpp"
#include "link_list.cpp"
#include "ngay.cpp"
#include "bst_node.cpp"
using namespace std;

class BST_tree
{
private:
    BST_node *root; // nút gốc của cây(kdl là 1 nút của cây )
    int n;          // số ptu của cây
public:
    BST_tree(BST_node *root, int n)
    {
        this->root = root;
        this->n = n;
    }
    BST_tree()
    {
        root = NULL;
        n = 0;
    }
    ~BST_tree()
    {
        delete root;
        n = 0;
    }
    // 1.lấy ra nút gốc của cây
    BST_node *getRoot()
    {
        return this->root;
    }
    // 2.lấy ra số ptu trong cây:
    int getSize()
    {
        return this->n;
    }
    // 3. ktra cây có ptu ko: trả về nếu root!=NULL (cây có ptu thì trả về 1)
    int isEmpty()
    {
        return root != NULL;
    }

    // 4.hàm tìm kiếm 1 nút trên cây: xem lịch công tác theo ngay
    BST_node *search(BST_node *p, int k) // tham so truyền vào 1 nút của cây, gtri k cần tìm (kdl trả về là kdl của nút đó: tìm nút thì trả về nút )
    {
        if (p == NULL) // nếu cây chưa có ptu trả về null luôn
        {
            return NULL;
        }
        if (p->getNgay().getTenNgay() == k) // ta đang cần ss ngày của 1 nút trong cây vs ngày ta truyền vào, ss =,<,> để sắp xếp vào cây
        {
            return p;
        }
        else if (p->getNgay().getTenNgay() < k) // p là con trỏ 1 nút của cây, truy cập vào đối tg "ngày" trong 1 nút(1 nút gồm đối tg ngày,left,rigth...), đối tg ngày này chứa
        // " ten_ngay và 1 list công việc". ta cần lấy ra tên ngày để ss với p nên ta cho p trỏ 2 lần để truy cập hàm "getTen Ngay"
        {
            return search(p->getRight(), k); // nếu ngày cần tìm > ngày hiện tại => ta tìm bên phải cây (dùng đệ qui, cứ lặp lại đến khi tìm hết bên phải thì thôi )
        }
        else //(p->getNgay().getTenNgay() >k)
        {
            return search(p->getLeft(), k); // sau đó tìm hết bên trái xem có gtri ngay ko?
        }
    }
    bool search(int k) // ham này ktra xem nó tìm thấy nút ko, nếu ko thấy trả về 0, thấy thì về 1
    {
        return search(root, k) != NULL;
    }

    // 5. thêm 1 nút vào cây <=> thêm 1 ngày(trong ngày chứa list cv 1 ngày cần làm)
    BST_node *insertNgay(BST_node *p, BST_node *parent, ngay k) // truyền vào nút p hiện tại,nút cha trc nó, gtri ngày cần truyền
    {
        if (p == NULL) // nếu cây chưa có nút=> gọi hàm tạo 1 nút mới(ở trong file BST_node) :ta truyền gtri cho hàm tạo này là đc
        {
            p = new BST_node(k, parent, NULL, NULL); // truyền đối cho hàm tạo 1 nút: ngày, nút cha,left,right chưa có ta cho =NULL
        }
        else
        {
            if (k.getTenNgay() < p->getNgay().getTenNgay()) // nếu tên ngày truyền vào < ten ngay của nút =>thêm vào bên trái
            {
                p->setLeft(insertNgay(p->getLeft(), p, k)); // chèn 1 nút vào bên trái nút p  :p= p->getleft(): cho nút p trỏ sang bên trái của nó  ,parent = p: nút cha của nút p lúc này giữ chỗ nút p ,  k: gtri ngày muốn thêm
            }
            else if (k.getTenNgay() > p->getNgay().getTenNgay())
            {
                p->setRight(insertNgay(p->getRight(), p, k)); // chèn 1 nút vào bên trái nút p
            }
        }
        return p;
    }
    void insertNgay(ngay k)
    {
        root = insertNgay(root, NULL, k); // chèn 1 nút vào cây: p=nút gốc, nút cha của p=nULL, gtri ngày k
    }

    // 6. duyệt danh sách theo chiều left-node-right: <=< in_order(duyet giua )
    void LNR(BST_node *p, string TinhChat)
    {
        if (p != NULL) // bắt đầu từ nút gốc, nếu gốc khác rỗng thì ta xét tiếp
        {
            LNR(p->getLeft(), TinhChat);                              // gọi hàm đệ quy đi về bên trái nút gốc,cứ đi đến khi in hết nút bên trái
            p->getNgay().getList().inCongViec_theoTinhChat(TinhChat); // in ra gtri nút duyệt đến(đâu tiên duyệt nút trái => in nút trái trc, sau gặp nút phải nó in nút phải, cuối cùng in nút gốc) : do mỗi nút chứa 1 ds lk=> in ra gtri nút =gọi hàm in ra ds lk
            LNR(p->getRight(), TinhChat);                             // ktra nếu bên phải gốc có nút thì in ra
        }
    }

    // 7. hàm xóa 1 nút khỏi cây:
    // Hàm tìm nút có giá trị nhỏ nhất trong cây con có gốc là p:
    BST_node *findMin(BST_node *p)
    {
        while (p->getLeft() != NULL)
        {
            p = p->getLeft(); // tìm nút con nhỏ nhất bên trái (hàm này để lát xóa nút có 2 con)
        }
        return p;
    }

    void deleteNode(BST_node *&p, int ngay, string tenCV)
    {
        p = search(p, ngay); // tìm 1 nút theo tên ngày và gán vào nút p

        if (p == NULL) // ktra nếu nút rỗng thì in ra TB
        {
            cout << "Khong co cong viec can xoa!\n";
            return;
        }

        if (p->getLeft() == NULL && p->getRight() == NULL)
        {
            // TH nút lá: nút đó ko có con trỏ bên trái &phải
            if (p->getParent() != NULL) // TH vẫn còn rút cha của p
            {
                if (p->getParent()->getLeft() == p)
                {
                    p->getParent()->setLeft(NULL); // cho con trỏ trái của p trỏ đến null
                }
                else
                {
                    p->getParent()->setRight(NULL); // con trỏ phải của p trỏ đến null
                }
            }
            else
            {
                // Xóa nút gốc
                delete p;
                p = NULL;
            }
        }
        else if (p->getLeft() == NULL && p->getRight() != NULL)
        {
            // TH nút có 1 nút con phải
            BST_node *temp = p;
            p = p->getRight();
            p->setParent(temp->getParent());
            delete temp;
        }
        else if (p->getRight() == NULL && p->getLeft() != NULL)
        {
            // TH nút có 1 nút con trái
            BST_node *temp = p;
            p = p->getLeft();
            p->setParent(temp->getParent());
            delete temp;
        }
        else
        {
            // TH nút có cả 2 nút con
            BST_node *successor = findMin(p->getRight());
            p->setNgay(successor->getNgay());
            deleteNode(successor, ngay, tenCV);
        }
    }

    // 8. Hàm in ra công việc đã hoàn tất trong cây  bắt đầu từ nút p:

    void CV_HoanTat(BST_node *p)
    {
        if (p != NULL)
        {
            CV_HoanTat(p->getLeft()); // duyệt hét bên trái của nút gốc, bắt đầu từ nút gốc, cứ duyệt bên trái của nút đến hết

            p->getNgay().getList().inCongViec_theoTinhChat("da hoan tat"); // in ra danh sach cv theo tinh chat "da hoan tat" (lưu ý khi nhập vào dữ liệu ta cũng phải nhập tính chất đã hoàn tất)
            cout << endl;
            CV_HoanTat(p->getRight()); // duyệt tiếp đến các nút nằm bên phải nút gốc của cây
        }
    }

    // 9.Hàm in ra công việc chưa hoàn tất trong cây bắt đầu từ nút p
    void CV_Chua_HoanTat(BST_node *p)
    {
        if (p != NULL)
        {
            CV_Chua_HoanTat(p->getLeft()); // duyệt hét bên trái của nút gốc, bắt đầu từ nút gốc, cứ duyệt bên trái của nút đến hết

            p->getNgay().getList().inCongViec_theoTinhChat("chua hoan tat"); // in ra danh sach cv theo tinh chat "da hoan tat" (lưu ý khi nhập vào dữ liệu ta cũng phải nhập tính chất đã hoàn tất)
            cout << endl;
            CV_Chua_HoanTat(p->getRight()); // duyệt tiếp đến các nút nằm bên phải nút gốc của cây
        }
    }

    // 10. Hàm in ra công việc trong khoảng ngày từ fromDate đến toDate trong cây con bắt đầu từ nút p
    void Xem_CongViec_Tu_NgayA_den_NgayB(BST_node *p, ngay fromDate, ngay toDate)
    {
        if (p != NULL)
        {
            Xem_CongViec_Tu_NgayA_den_NgayB(p->getLeft(), fromDate, toDate);

            if (p->getNgay().getTenNgay() >= fromDate.getTenNgay() && p->getNgay().getTenNgay() <= toDate.getTenNgay()) // ktra nếu ten ngày của nút đó nằm trong khoảng từ a-> b thì in ra ds cv trong các ngày đó
            {
                cout << "Cac cong viec trong ngay " << p->getNgay().getTenNgay() << ":\n";
                p->getNgay().getList().in();
                cout << "------------------------\n";
            }

            Xem_CongViec_Tu_NgayA_den_NgayB(p->getRight(), fromDate, toDate);
        }
    }
};

#endif