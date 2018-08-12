#include "TreeBST.h"


template <class T>
TreeBST<T>::TreeBST() {
    root = NULL;
}

template <class T>
bool TreeBST<T>::insert(const T &data) {
    return insertHelper(root, data);
}

template <class T>
bool TreeBST<T>::insertHelper(TreeBST::PNode &p, const T &data) {
    if (p == NULL) {
        PNode helper;
        try {
            helper = new Node(data);
            p = helper;
            return true;
        } catch (...) {
            return false;
        }
    } else {
        if (data < p->data)
            return insertHelper(p->left, data);
        else if (p->data < data)
            return insertHelper(p->right, data);
        else
            return false;
    }
}

template <class T>
void TreeBST<T>::deleteTree(TreeBST::PNode &p) {
    if (p != NULL) {
        deleteTree(p->left);
        deleteTree(p->right);
        delete p;
        p = NULL;
    }
}

template <class T>
TreeBST<T>::~TreeBST() {
    deleteTree(root);
}

template <class T>
void TreeBST<T>::preOrder() const {
    preOrderHelper(root);
}

template <class T>
void TreeBST<T>::preOrderHelper(TreeBST::PNode p) const {
    if (p != NULL) {
        std::cout << p->data << " ";
        preOrderHelper(p->left);
        preOrderHelper(p->right);
    }
}

template <class T>
void TreeBST<T>::inOrder() const {
    inOrderHelper(root);
}

template <class T>
void TreeBST<T>::inOrderHelper(TreeBST::PNode p) const {
    if (p != NULL) {
        inOrderHelper(p->left);
        std::cout<< p->data<<" ";
        inOrderHelper(p->right);
    }
}

template <class T>
void TreeBST<T>::postOrder() const {
    postOrderHelper(root);
}

template <class T>
void TreeBST<T>::postOrderHelper(TreeBST::PNode p) const {
    if (p != NULL) {
        postOrderHelper(p->left);
        postOrderHelper(p->right);
        std::cout<<p->data<<" ";
    }
}

template <class T>
typename TreeBST<T>::PNode TreeBST<T>::search(T data, PNode p) {
    if (p != NULL) {
        if (data == p->data)
            return p;
        if (data < p->data)
            return search(data, p->left);
        else
            return search(data, p->right);
    } else
        return NULL;

}