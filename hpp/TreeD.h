#ifndef ASD_TREED_H
#define ASD_TREED_H


#include "TreeBST.cpp"

template <class T>
class TreeD : public TreeBST<T> {
public:
    typedef typename TreeBST<T>::Node* PNode;

private:
    int countNodesHelper(PNode p);
    int countInsideNodesHelper(PNode p);
    int countLeafsHelper(PNode p);
    int countOneChildNodesHelper(PNode p);
public:
    int countNodes();
    int countInsideNodes();

    int countLeafs();

    int countOneChildNodes();
};


#endif //ASD_TREED_H
