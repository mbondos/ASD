#ifndef ASD_TREED_H
#define ASD_TREED_H


#include "TreeBST.cpp"

template <class T>
class TreeD : public TreeBST<T> {
public:
    typedef typename TreeBST<T>::Node* PNode;

private:
    void preOrderBackHelper(PNode) const;
    void inOrderBackHelper(PNode) const;
    void postOrderBackHelper(PNode) const;

    int findHeightHelper(PNode p);
    int countNodesHelper(PNode p);
    int countInsideNodesHelper(PNode p);
    int countLeafsHelper(PNode p);
    int countOneChildNodesHelper(PNode p);
public:
    void preOrderBack() const;
    void inOrderBack() const;
    void postOrderBack() const;
    int findHeight();
    int countNodes();
    int countInsideNodes();

    int countLeafs();

    int countOneChildNodes();
};


#endif //ASD_TREED_H
