#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//队列的顺序存储类型定义

#define MaxSize 50     //定义队列中元素的最大个数
typedef struct{
    int data[MaxSize]; //用数组存放队列元素
    int front,rear;    //队首指针，队尾指针
}SqQueue;

//初始化
void InitQueue(SqQueue *Q){
    Q->rear=Q->front=0; //初始化队首，队尾指针
}
//循环队列的操作：
//判断空
bool IsEmpty(SqQueue Q){
    if (Q.front==Q.rear)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

//入队
bool EnQueue(SqQueue *Q,int x){
    if ((Q->rear+1)%MaxSize==Q->front)
    {
        return false;
    }
    Q->data[Q->rear]=x;         //data为数值.rear指向队尾元素的下一位置，因此rear位置为空，将x赋值到rear指针处
    Q->rear=(Q->rear+1)%MaxSize;//rear+1
    return true;
}

//出队
bool DeQueue(SqQueue *Q,int *x){
    if (Q->front==Q->rear)
    {
        return false;
    }
    *x=Q->data[Q->front];        //先进先出，队首指针front指向的元素为x，出队的元素值被赋值给了*x
    Q->front=(Q->front+1)%MaxSize;//队首指针加1取模
    return true;
}