typedef struct LNode { // 定义链表结点结构
    int data;          // 数据域
    struct LNode *next;// 指针域
} LNode, *LinkList;