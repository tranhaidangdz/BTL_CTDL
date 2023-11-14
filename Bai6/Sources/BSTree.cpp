#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "../Header Files/BSTree.h"

using namespace std;

template <class Keys, class T>
BSTree<Keys, T>::BSTree()
{
    root = NULL;
    n = 0;
}

template <class Keys, class T>
BSTree<Keys, T>::~BSTree()
{
    delete root;
}

template <class Keys, class T>
BSTNode<Keys, T> *BSTree<Keys, T>::getRoot()
{
    return this->root;
}

template <class Keys, class T>
int BSTree<Keys, T>::isEmpty()
{
    return this->root != NULL;
}

template <class Keys, class T>
int BSTree<Keys, T>::size()
{
    return this->n;
}

template <class Keys, class T>
int BSTree<Keys, T>::isInternal(BSTNode<Keys, T> *p)
{
    return (p->hasLeft() || p->hasRight());
}

template <class Keys, class T>
int BSTree<Keys, T>::isExternal(BSTNode<Keys, T> *p)
{
    return !(p->hasLeft() && p->hasRight());
}

template <class Keys, class T>
int BSTree<Keys, T>::isRoot(BSTNode<Keys, T> *p)
{
    return p->getParent() == NULL;
}

template <class Keys, class T>
BSTNode<Keys, T> *BSTree<Keys, T>::search(Keys k, BSTNode<Keys, T> *p)
{
    if (p == NULL)
    {
        return NULL;
    }

    if (p->getKey() == k)
    {
        return p;
    }
    else if (p->getKey() < k)
    {
        return search(k, p->getRight());
    }
    else
    {
        return search(k, p->getLeft());
    }
}

template <class Keys, class T>
bool BSTree<Keys, T>::search(Keys k)
{
    return search(k, root) != NULL;
}

template <class Keys, class T>
BSTNode<Keys, T> *BSTree<Keys, T>::insert(Keys k, T e, BSTNode<Keys, T> *temp, BSTNode<Keys, T> *parent)
{
    if (temp == NULL)
    {
        // Make root
        temp = new BSTNode<Keys, T>(k, e, parent);
    }
    else
    {
        if (k < temp->getKey())
        {
            temp->setLeft(insert(k, e, temp->getLeft(), temp));
        }
        else if (k > temp->getKey())
        {
            temp->setRight(insert(k, e, temp->getRight(), temp));
        }
    }

    return temp;
}

template <class Keys, class T>
void BSTree<Keys, T>::insert(Keys k, T e)
{
    root = insert(k, e, root, NULL);
    n++;
}

template <class Keys, class T>
BSTNode<Keys, T> *BSTree<Keys, T>::getMinRight(BSTNode<Keys, T> *p)
{
    BSTNode<Keys, T> *temp = p;
    while (temp->getLeft() != NULL)
    {
        temp = temp->getLeft();
    }

    return temp;
}

template <class Keys, class T>
void BSTree<Keys, T>::remove(BSTNode<Keys, T> *tmp)
{
    if (tmp == NULL)
        return;

    // Xoa nut la
    if (!tmp->hasLeft() && !tmp->hasRight())
    {
        // Lay ra nut cha
        BSTNode<Keys, T> *p = tmp->getParent();

        // Kiem ra nut can xoa dang o ben trai hay phai va tien hanh xoa
        if (p->getLeft() == tmp)
        {
            p->setLeft(NULL);
        }
        else
        {
            p->setRight(NULL);
        }
    }

    // Don cay ben trai len
    else if (tmp->hasLeft() && !tmp->hasRight())
    {
        // Lay ra nut cha
        BSTNode<Keys, T> *p = tmp->getParent();

        // Nut ben trai cap nhat nut cha
        tmp->getLeft()->setParent(p);

        // Kiem ra nut can xoa dang o ben trai hay phai va tien hanh don cay con
        if (p->getLeft() == tmp)
        {
            p->setLeft(tmp->getLeft());
        }
        else
        {
            p->setRight(tmp->getLeft());
        }
    }

    // Don cay ben phai len
    else if (!tmp->hasLeft() && tmp->hasRight())
    {
        // Lay ra nut cha
        BSTNode<Keys, T> *p = tmp->getParent();

        // Nut ben phai cap nhat nut cha
        tmp->getRight()->setParent(p);

        // Kiem ra nut can xoa dang o ben trai hay phai va tien hanh don cay con
        if (p->getLeft() == tmp)
        {
            p->setLeft(tmp->getRight());
        }
        else
        {
            p->setRight(tmp->getRight());
        }
    }
}

template <class Keys, class T>
void BSTree<Keys, T>::remove(Keys k)
{
    // Tim nut co khoa k
    BSTNode<Keys, T> *tmp = search(k, root);

    if (tmp == NULL)
        return;

    // Truong hop nut can xoa co ca 2 con
    if (tmp->hasLeft() && tmp->hasRight())
    {
        // Lay ra nut nho nhat trong cay con ben phai dua len nut can xoa
        BSTNode<Keys, T> *minRight = getMinRight(tmp->getRight());

        // Gan gia tri nut can xoa bang nut minRight
        tmp->setKey(minRight->getKey());
        tmp->setElement(minRight->getElement());

        // Xoa nut minRight (Truong hop nut ben trai nho nhat)
        remove(minRight);
    }

    // Xoa nut trong cac truong hop con lai
    else
    {
        remove(tmp);
    }

    n--;
}


template <class Keys, class T>
void BSTree<Keys, T>::preOrder(BSTNode<Keys, T> *p, ofstream &f)
{
    // Root -> Left -> Right
    if (p != NULL)
    {
        f << p->getKey() << "\t" << p->getElement() << "\n";
        preOrder(p->getLeft(), f);
        preOrder(p->getRight(), f);
    }
}

template <class Keys, class T>
void BSTree<Keys, T>::inOrder(BSTNode<Keys, T> *p, ofstream &f)
{
    // Left -> Root -> Right
    if (p != NULL)
    {
        inOrder(p->getLeft(), f);
        f  << p->getKey() << "\t" << p->getElement() << "\n";
        inOrder(p->getRight(), f);
    }
}

template <class Keys, class T>
void BSTree<Keys, T>::postOrder(BSTNode<Keys, T> *p, ofstream &f)
{
    // Left -> Right -> Root
    if (p != NULL)
    {
        postOrder(p->getLeft(), f);
        postOrder(p->getRight(), f);
        f << p->getKey() << "\t" << p->getElement() << "\n";
    }
}

template <class Keys, class T>
void BSTree<Keys, T>::preOrder()
{
    ofstream file("../Datas/output.txt");
    preOrder(root, file);
    file.close();
}


template <class Keys, class T>
void BSTree<Keys, T>::inOrder()
{
    
    ofstream file("../Datas/output.txt");
    inOrder(root, file);
    file.close();
}

template <class Keys, class T>
void BSTree<Keys, T>::postOrder()
{
    ofstream file("../Datas/output.txt");
    postOrder(root, file);
    file.close();
}
