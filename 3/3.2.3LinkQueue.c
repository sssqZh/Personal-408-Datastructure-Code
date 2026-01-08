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