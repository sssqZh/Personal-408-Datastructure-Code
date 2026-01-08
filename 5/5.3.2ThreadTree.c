typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchiild,*rchild;//左右孩子指针
    int ltag,rtag;                     //左右线索标志
}ThreadNode,*ThreadNode;