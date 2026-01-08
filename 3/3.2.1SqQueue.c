#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//队列的顺序存储类型定义

#define MaxSize 50     //定义队列中元素的最大个数
typedef struct{
    int data[MaxSize]; //用数组存放队列元素
    int front,rear;    //队首指针，队尾指针
}SqQueue;