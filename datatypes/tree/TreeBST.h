#ifndef ASD_TREEBST_H
#define ASD_TREEBST_H

#include <iostream>

template <class T>
class TreeBST {
protected:
    class Node {
    public:
        T data;
        Node *left;
        Node *right;

        Node(const T& data) : data(data), left(NULL), right(NULL) {};
    };

public:
    TreeBST();

    TreeBST(const TreeBST&) = delete;
    bool insert(const T&);
    bool remove(const T&);
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    ~TreeBST();

protected:
    typedef Node* PNode;
    PNode root;
private:
    bool insertHelper(PNode&, const T&);
    void preOrderHelper(PNode) const;
    void inOrderHelper(PNode) const;
    void postOrderHelper(PNode) const;
    void deleteTree(PNode&);
    PNode search(T data, PNode p);
};


#endif //ASD_TREEBST_H
