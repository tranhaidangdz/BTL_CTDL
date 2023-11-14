#ifndef BST_NODE_ // KHI TA đặt hằng số này thì trong các file khác khi gọi tới thư viện này, các biến trong thư viện này sẽ ko dc đặt trùng nữa
#define BST_NODE_
#include <iostream>
#include <string>
#include "link_list.h"
#include "quanly.h"
#include "ngay.h"
#include "congviec.h"
using namespace std;

class BST_node // 1 nút của cây nhị phân, chứa gtri = link_list , trong cái "congviectrongngay" lại chứa 1 ds lk đơn , trong ds lk đơn lại chứa gtri Congviec
{
private:
    NGAY cv_1ngay;
    BST_node *parent;
    BST_node *left;
    BST_node *right;

public:
    BST_node(NGAY cv_1ngay, BST_node *parent, BST_node *left, BST_node *right)
    {
        this->cv_1ngay = cv_1ngay;
        this->parent = parent;
        this->left = left;
        this->right = right;
    }

    BST_node *getParent()
    {
        return parent;
    }

    BST_node *getLeft()
    {
        return left;
    }

    BST_node *getRight()
    {
        return right;
    }

    void setLeft(BST_node *left)
    {
        this->left = left;
    }

    void setRight(BST_node *right)
    {
        this->right = right;
    }

    void setParent(BST_node *parent)
    {
        this->parent = parent;
    }
    // ktra bên phải nút đó có ptu nào ko
    int hasLeft()
    {
        return left != NULL; // nếu có con bên trái thì nó trả về khác rỗng, còn nếu ==null thì bên trái nó ko có con
    }
    // ktra bên trái nút đó có ptu nào ko
    int hasRight()
    {
        return right != NULL;
    }
    // ktra bên phải nút đó có ptu nào ko
    int hasLeft()
    {
        return left != NULL; // nếu có con bên trái thì nó trả về khác rỗng, còn nếu ==null thì bên trái nó ko có con
    }
    // ktra bên trái nút đó có ptu nào ko
    int hasRight()
    {
        return right != NULL;
    }
};

#endif
