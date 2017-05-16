#include "TreeD.h"

template <class T>
int TreeD<T>::countNodes() {
    return countNodesHelper(this->root);
}

template <class T>
int TreeD<T>::countNodesHelper(PNode p) {
    if(p == NULL)
        return 0;
    return 1+countNodesHelper(p->left)+countNodesHelper(p->right);
}

template <class T>
int TreeD<T>::countInsideNodes() {
    return countInsideNodesHelper(this->root) - 1; // -1 excludes root
}

template <class T>
int TreeD<T>::countInsideNodesHelper(TreeD::PNode p) {
    int count=0;
    if(p == NULL) return 0;
    if(p->left != NULL || p->right !=NULL) {
        count=1;
        if(p->left != NULL)
            count+=countInsideNodesHelper(p->left);
        if(p->right != NULL)
            count+=countInsideNodesHelper(p->right);
    }
    return count;
}

template <class T>
int TreeD<T>::countLeafs() {
    return countLeafsHelper(this->root);
}

template <class T>
int TreeD<T>::countLeafsHelper(TreeD::PNode p) {
    if(p == NULL) return 0;
    if(p->left == NULL && p->right == NULL) return 1;
    return countLeafsHelper(p->left) + countLeafsHelper(p->right);
}

template <class T>
int TreeD<T>::countOneChildNodes() {
    return countOneChildNodesHelper(this->root);
}

template <class T>
int TreeD<T>::countOneChildNodesHelper(TreeD::PNode p) {
    if (p == NULL) return 0;
    int count=0;
    if((p->left != NULL && p->right == NULL) || (p->left == NULL && p->right != NULL))
        count = 1;
    if (p->left != NULL)
        count+=countOneChildNodesHelper(p->left);
    if(p->right != NULL)
        count+=countOneChildNodesHelper(p->right);

    return count;
}

template <class T>
void TreeD<T>::inOrderBack() const {
    return inOrderBackHelper(this->root);
}

template <class T>
void TreeD<T>::inOrderBackHelper(TreeD::PNode p) const {
    if (p != NULL) {
        inOrderBackHelper(p->right);
        std::cout<< p->data<<" ";
        inOrderBackHelper(p->left);
    }
}

template <class T>
void TreeD<T>::preOrderBack() const {
    return preOrderBackHelper(this->root);
}

template <class T>
void TreeD<T>::preOrderBackHelper(TreeD::PNode p) const {
    if (p != NULL) {
        std::cout << p->data << " ";
        preOrderBackHelper(p->right);
        preOrderBackHelper(p->left);
    }
}

template <class T>
void TreeD<T>::postOrderBack() const {
    return postOrderBackHelper(this->root);
}

template <class T>
void TreeD<T>::postOrderBackHelper(TreeD::PNode p) const {
    if (p != NULL) {
        postOrderBackHelper(p->right);
        postOrderBackHelper(p->left);
        std::cout<<p->data<<" ";
    }
}

template <class T>
int TreeD<T>::findHeight() {
    return findHeightHelper(this->root);
}

template <class T>
int TreeD<T>::findHeightHelper(TreeD::PNode p) {
    int heightLeft = 0;
    int heightRight = 0;
    if(p == NULL) return -1;
    heightLeft = findHeightHelper(p->left);
    heightRight = findHeightHelper(p->right);
    if(heightLeft > heightRight)
        return heightLeft+1;
    else
        return heightRight+1;


}





