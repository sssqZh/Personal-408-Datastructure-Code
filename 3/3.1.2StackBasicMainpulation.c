#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50//定义栈中元素最大个数
typedef struct{
    int data[MAX_SIZE];//存放栈中元素
    int top;//栈顶指针
} SqStack;

//初始化栈
void InitStack(SqStack *S){
    S->top=-1;      //初始化栈顶指针
}

//判断栈是否为空
bool StackEmpty(SqStack S){
    if (S.top==-1)
    {
        return true;
    }
    else
        return false;
}

//入栈
bool Push(SqStack *S,int x){
    if(S->top==MAX_SIZE-1)
        return false;       //栈满，无法入栈
    S->top++;               //栈顶指针加1
    S->data[S->top]=x;     //将新元素放入栈顶
}

//出栈
bool Pop(SqStack *S,int *x){
    if(S->top==-1)         //栈空，无法出栈
        return false;
    *x=S->data[S->top--];  //先出栈，指针再减1
    return true;
}

//读栈顶元素
bool GetTop(SqStack S,int *x){
    if (S.top==-1)
    {
        return false;
    }
    *x=S.data[S.top];      //x记录栈顶元素
    return true;         
}