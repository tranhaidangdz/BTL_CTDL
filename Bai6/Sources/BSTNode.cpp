#include "../Header Files/BSTNode.h"

template <class Keys, class T>
BSTNode<Keys, T>::BSTNode()
{
    this->parent = NULL;
    this->right = NULL;
    this->left = NULL;
}

template <class Keys, class T>
BSTNode<Keys, T>::BSTNode(Keys k, T e, BSTNode<Keys, T> *parent)
{
    this->key = k;
    this->element = e;
    this->parent = parent;
    this->right = NULL;
    this->left = NULL;
}



template <class Keys, class T>
BSTNode<Keys, T> *BSTNode<Keys, T>::getParent()
{
    return this->parent;
}

template <class Keys, class T>
BSTNode<Keys, T> *BSTNode<Keys, T>::getLeft()
{
    return this->left;
}

template <class Keys, class T>
BSTNode<Keys, T> *BSTNode<Keys, T>::getRight()
{
    return this->right;
}

template <class Keys, class T>
void BSTNode<Keys, T>::setLeft(BSTNode<Keys, T> *p)
{
    this->left = p;
}

template <class Keys, class T>
void BSTNode<Keys, T>::setRight(BSTNode<Keys, T> *p)
{
    this->right = p;
}

template <class Keys, class T>
void BSTNode<Keys, T>::setParent(BSTNode<Keys, T> *p)
{
    this->parent = p;
}

template <class Keys, class T>
int BSTNode<Keys, T>::hasLeft()
{
    return this->left != NULL;
}

template <class Keys, class T>
int BSTNode<Keys, T>::hasRight()
{
    return this->right != NULL;
}

template <class Keys, class T>
T BSTNode<Keys, T>::getElement()
{
    return this->element;
}

template <class Keys, class T>
Keys BSTNode<Keys, T>::getKey()
{
    return this->key;
}

template <class Keys, class T>
void BSTNode<Keys, T>::setElement(T e)
{
    this->element = e;
}

template <class Keys, class T>
void BSTNode<Keys, T>::setKey(Keys k)
{
    this->key = k;
}
