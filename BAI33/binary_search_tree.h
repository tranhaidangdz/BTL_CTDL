#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_
#include <iostream>

#include "link_list.h"
#include "congviec.h"
#include "bst_node.h"

using namespace std;

class binary_search_tree
{
private:
    BST_node *root; // node root: trong 1 nút của cây chứa tên ngày và ds cv cần làm trong ngày đó
    // chứa con trỏ trái,phải trỏ đến các nút bên trái và phải nút đó
    int n; // số nút có trong cây

public:
    BST_node *creatNode(BST_node *root)
    {
    }
    binary_search_tree()
    {
        root = NULL;
        n = 0;
    }

    ~binary_search_tree()
    {
        delete root; // 1. giai phong con tro sau khi sd
        n = 0;
    }

    int size() // 2. lấy ra số ptu trong cây
    {
        return n;
    }

    int isEmpty() // 3.ktra cây có rỗng ko :trả về nếu cây có ptu
    {
        return root != NULL;
    }
    // 4. hàm lấy ra nút gốc của cây:
    BST_node *getRoot() // root la con trỏ nên kdl trả về của nó có dấu * : (kdl*)
    {
        return root;
    }
    // tìm kiếm 1 nút trong cây theo ngay :
    BST_node *Search(BST_node *p, int ngay) // phải có đối số trong hàm mới dùng đệ quy đc (hàm này trả về 1 nút trong cây)
    {

        if (p == NULL)
        {
            return NULL;
        }
        if (p->getTenNgay() == ngay)
        {
            return p; // neu tim thay tra ve ten_ngay đó luôn
        }
        else if (p->getTenNgay() < ngay) // nếu ngày cần tìm > ngày hiện tại => ta tìm bên phải cây
        {
            return Search(p->getRight(), ngay); // nó cứ tìm hết bên phải cây xem có gtri ngay ko?
        }
        else // TH:  (p->getTenNgay() < ngay):nếu ngày cần tìm < ngày hiện tại => ta tìm bên trái cây
        {
            return Search(p->getLeft(), ngay); // sau đó tìm hết bên trái xem có gtri ngay ko?
        }
    }
    bool Seach(int ngay) // ham này ktra xem nó tìm thấy nút ko, nếu ko thấy trả về 0, thấy thì về 1
    {
        return Search(root, ngay) != NULL;
    }

    // thêm 1 nút vào cây nhị phân theo ngày :
    BST_node *insert(BST_node *p, BST_node *parent, int ngay) // truyền vào nút p hiện tại,nút cha trc nó, gtri ngày cần truyền
    {
        if (p == NULL) // nếu cây chưa có nút=> gọi hàm tạo 1 nút mới
        {
            p = new BST_node(ngay, list, parent, left, right);
        }
    }
};
#endif
