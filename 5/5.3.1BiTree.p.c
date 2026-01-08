#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 50
// 二叉树结点结构
typedef struct TreeNode {
    char data;               // 结点数据
    struct TreeNode *left;   // 左子树指针
    struct TreeNode *right;  // 右子树指针
} TreeNode;

// 二叉树结构（可选，用于管理整棵树）
typedef struct {
    TreeNode *root;          // 根结点指针
    int count;               // 节点数量
} BinaryTree;

//构造队列及其基本操作，便于层次遍历
typedef struct{
    TreeNode* data[MaxSize]; // 直接存储TreeNode指针
    int front,rear;
}SqQueue;
    //队列初始化
void InitQueue(SqQueue *Q){
    Q->rear=Q->front=0; //初始化队首，队尾指针
}
    //判断队列是否为空
int IsEmpty(SqQueue *Q){
    return Q->front == Q->rear;
}
    //入队
int EnQueue(SqQueue *Q, TreeNode* node){
    if((Q->rear+1)%MaxSize == Q->front)
        return 0;
    Q->data[Q->rear] = node;
    Q->rear = (Q->rear+1)%MaxSize;
    return 1;
}
    //出队
int DeQueue(SqQueue *Q, TreeNode** node){
    if(IsEmpty(Q))
        return 0;
    *node = Q->data[Q->front];
    Q->front = (Q->front+1)%MaxSize;
    return 1;
}

//创建新结点
TreeNode *create_node(char data){
    TreeNode *new_node=(TreeNode *)malloc(sizeof(TreeNode));  //动态分配内存
    if (new_node==NULL)
    {
        printf("内存分配失败！\n");
        return NULL;
    }
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
//初始化二叉树
void InitTree(BinaryTree *tree){
    tree->root=NULL;       //初始化根结点为空
    tree->count=0;
}
//判断二叉树是否为空
bool is_tree_empty(BinaryTree *tree){
    return tree->root==NULL;
}
//获取根结点数据
char get_root_data(BinaryTree *tree){
    if (is_tree_empty(tree)){
        printf("树为空！\n");
        return 0;
    }
    return tree->root->data;
}
//先序遍历
void PreOrder(TreeNode *root){
    if (root!=NULL){          //若根结点存在
        visit(root->data);     //访问根结点
        PreOrder(root->left);  //递归遍历左子树
        PreOrder(root->right); //递归遍历右子树
    }
}
//中序遍历
void InOrder(TreeNode *root){
    if(root){
        InOrder(root->left);
        visit(root->data);
        InOrder(root->right);
    }
}
//后序遍历
void PostOrder(TreeNode *root){
    if(root){
        PostOrder(root->left);
        PostOrder(root->right);
        visit(root->data);
    }
}

//层次遍历
void LevelOrder(TreeNode *root){
    if(!root) return;
    // 创建队列
    SqQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, root);
    // 层次遍历
    while(!IsEmpty(&Q)){
        TreeNode *current;
        DeQueue(&Q,&current);
        visit(current->data);
        if(current->left) EnQueue(&Q, current->left);
        if(current->right) EnQueue(&Q, current->right);
    }
}
