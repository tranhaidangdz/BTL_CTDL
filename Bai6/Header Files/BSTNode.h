#ifndef BST_NODE_H
#define BST_NODE_H

template <class Keys, class T>
class BSTNode
{
private:
    Keys key;
    T element;
    BSTNode<Keys, T> *parent, *left, *right;

public:
    BSTNode();
    BSTNode(Keys k, T e, BSTNode<Keys, T> *parent);
    BSTNode<Keys, T> *getParent();
    BSTNode<Keys, T> *getLeft();
    BSTNode<Keys, T> *getRight();
    void setLeft(BSTNode<Keys, T> *p);
    void setRight(BSTNode<Keys, T> *p);
    void setParent(BSTNode<Keys, T> *p);
    int hasLeft();
    int hasRight();
    T getElement();
    Keys getKey();
    void setElement(T e);
    void setKey(Keys k);
};

#endif