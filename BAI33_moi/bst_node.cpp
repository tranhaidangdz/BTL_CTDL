#ifndef BST_NODE_CPP
#define BST_NODE_CPP
#include <iostream>
#include <string>
#include <iomanip>
#include "congviec.cpp"
#include "link_list.cpp"
#include "ngay.cpp"
using namespace std;

class BST_node
{
private:
    ngay a;
    BST_node *parent;
    BST_node *left;
    BST_node *right;

public:
    BST_node(ngay a, BST_node *parent, BST_node *left, BST_node *right)
    {
        this->a = a;
        this->parent = parent;
        this->left = left;
        this->right = right;
    }
    ngay getNgay()
    {
        return a;
    }
    void setNgay(ngay x)
    {
        a = x;
    }

    BST_node *getParent() // lấy ra con trỏ parent nên trả về kdl* tenham
    {
        return parent;
    }
    void setParent(BST_node *p)
    {
        parent = p;
    }

    BST_node *getLeft() // lấy ra con trỏ left nên trả về kdl* tenham
    {
        return left;
    }
    void setLeft(BST_node *p)
    {
        left = p;
    }

    BST_node *getRight() // lấy ra con trỏ right nên trả về kdl* tenham
    {
        return right;
    }
    void setRight(BST_node *p)
    {
        right = p;
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