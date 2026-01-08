#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 50
typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;//左右孩子指针
    int ltag,rtag;                     //左右线索标志(每个结点独立存储)
}ThreadNode;
//通过中序遍历对二叉树线索化的递归算法
void InitThreadTree(ThreadNode *p,ThreadNode **pre){
if(p){
    InitThreadTree(p->lchild,pre);         //递归，线索化左子树
    if (p->lchild==NULL)                   //当前结点的左子树为空
    {  
        p->lchild=*pre;                     //建立当前结点的前驱线索
         p->ltag=1;
    }
    if (*pre!=NULL&&(*pre)->rchild==NULL)      //前驱结点的右子树为空
    {  
        (*pre)->rchild=p;                     //建立当前结点的后继线索
         (*pre)->rtag=1;                         
    }
    *pre=p;                                 //标记当前结点成为刚刚访问过的结点
    InitThreadTree(p->rchild,pre);         //递归，线索化右子树
}
}
//通过中序遍历建立中序线索二叉树
void CreateInitThreadTree(ThreadNode *T,ThreadNode **pre){
    ThreadNode *pre=NULL;
    if (T!=NULL)
    {
        InitThreadTree(T,pre);
        (*pre)->rchild=NULL;
        (*pre)->rtag=0;
    }
}
//中序线索二叉树的遍历
//求中序线索二叉树的中序序列下的第一个结点
ThreadNode* FirstNode(ThreadNode *p){
    while(p->ltag==0)
        p=p->lchild;
    return p;
}
//求中序线索二叉树的中序序列下的下一个结点
ThreadNode* NextNode(ThreadNode *p){
    if(p->rtag==1){
       return FirstNode(p->rchild);  //右子树中最左下结点
    }
    else
        return p->rchild;            //若rtag==1，则直接返回后继线索
}

//利用上述两个算法，可以写出不含头节点的中序线索二叉树的中序遍历的算法
void Inorder(ThreadNode *T){
    for (ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
    {
        visit(p->data);
    }
}
    