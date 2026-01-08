#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DNode { // 定义双链表结点结构
    int data;          // 数据域
    struct DNode *prev,*next; // 指向前驱结点的指针,指向后继结点的指针
} DNode, *DLinkList;

//插入片段O(1)
//...
//删除片段O(1)
//...