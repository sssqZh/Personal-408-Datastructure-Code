#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//栈的链式储存类型可描述为
typedef struct Linknode{
    int data;             //数据域  
    struct Linknode *next;//指针域
}LiStack;                 //栈类型定义