int BST_Insert(BSTree &T,KeyType k){
    if(T==NULL){
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=k;
        T->lchild=T->rchild=NULL;
        return 1; // 插入成功
    }
    else if (k==T->data)
        return 0; // 已经存在
    else if (k<T->data)
        return BST_Insert(T->lchild,k);
    else
        return BST_Insert(T->rchild,k);
}