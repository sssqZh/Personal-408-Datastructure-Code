typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
} BSTNode,*BSTree;

BSTNode *BST_Search(BSTree T, int key){
    while(T!=NUll&&T->key!=key){
        if(key<T->key)
            T=T->lchild;
        else
            T=T->rchild;
    }
    return T;
}
BSTNode *BST_Search2(BSTree T, int key){//递归实现
    if(T==NULL||T->key==key)
        return T;
    else if(key<T->key)
        return BST_Search2(T->lchild,key);
    else
        return BST_Search2(T->rchild,key);
}