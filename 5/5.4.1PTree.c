#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50 
//双亲表示法
typedef struct{              //树的结点定义
    int data;                //数据域
    int parent;              //双亲位置域
}PTNode;
typedef struct{
    PTNode nodes[MaxSize];   //双亲表示
    int n;                   //结点总数
}PTree;

//孩子表示法
struct CTNode{
    int child;            //孩子结点在数组中的位置
    struct CTNode *next;  //指向下一个孩子的指针
};                        //为什么在这个结构体中不需要 typedef？   因为：自引用结构体的特殊性    对于包含自引用的结构体（如链表节点），必须使用有标签的结构体定义：
typedef struct {
    int data;                    // 节点数据
    struct CTNode *firstChild;   // 指向第一个孩子节点
} CTBox;

typedef struct {
    CTBox nodes[MaxSize];        // 节点数组
    int n, r;                    // 节点数和根的位置
} CTree;                         //树结构定义

//孩子兄弟表示法
typedef struct{
    int data;
    struct CSNode *firstchild, *nextsibling;
}CSNode,*CSTree;