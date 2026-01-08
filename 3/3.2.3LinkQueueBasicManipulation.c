#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//队列的链式存储类型定义

typedef struct LinkNode{  //链式队列结点
    int data;                  //数据域
    struct LinkNode *next;     //指针域
}LinkNode; 
typedef struct{                //链式队列
    LinkNode *front,*rear;     //队头指针和队尾指针
}LinkQueue;            
//初始化
void InitQueue(LinkQueue *Q){  //初始化带头结点的链式队列
    Q->front=Q->rear=(LinkNode *)malloc(sizeof(LinkNode)); //创建头结点，队头队尾指针均指向头结点
    Q->front->next=NULL;
}
//判队空
bool Isempty(LinkQueue Q){
    if(Q.front==Q.rear)
        return true;
    else
        return false;
}
//入队
void EnQueue(LinkQueue *Q,int x){
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));//创建新结点
    p->data=x;                    //将x赋值给新结点
    p->next=NULL;                 //新结点的指针域置空
    Q->rear->next=p;              //插入链尾
    Q->rear=p;                    //队尾指针指向新结点
}
//出队
bool DeQueue(LinkQueue *Q,int *x){
    if(Q->front==Q->rear)
        return false;            //空队
    LinkNode *p=Q->front->next;  //p指向实际的队首元素
    *x=p->data;                  //将队首元素值赋给*x
    Q->front->next=p->next;      // 头节点指向新的队首元素（第二个结点）,先进先出，指向第一个元素
    if (Q->rear==p)
        Q->rear=Q->front;        //队尾指针指向头结点，队列为空
    free(p);             
    return true;       //释放p指向的结点
}
    