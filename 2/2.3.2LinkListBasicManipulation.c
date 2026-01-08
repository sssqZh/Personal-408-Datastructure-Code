#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 定义链表结点结构
typedef struct LNode { 
    int data;          // 数据域
    struct LNode *next;// 指针域
} LNode, *LinkList;

//带头节点单链表的初始化
bool InitList(LinkList *L)
{
    *L=(LNode*)malloc(sizeof(LNode));//创建头节点
    (*L)->next=NULL;//头节点之后暂时还没有元素节点
    return true;
}
//不带头节点单链表的初始化
bool ZeroInitList(LinkList *L){
    *L=NULL;
    return true;
}

//求表长操作O(n)
int Length(LinkList L){
    int Len=0;//计数变量，初始为0
    LNode *p=L;
    while (p->next!=NULL)
    {
        p=p->next;
        Len++;//每访问一个节点，计数加1
    }
    return Len;
    }

//按序号查找节点O(n)
LNode *GetValue(LinkList L, int index){
    LNode *p=L;                       //指针p指向当前扫描到的节点
    int j=0;                          //记录当前节点的位序，头节点是第零个节点
    while (p->next!=NULL &&j<index){  //循环找到第index个节点
        p=p->next;
        j++;
    }
    return p;                         //返回第index个节点的指针
}

//按值查找表节点O(n)
LNode *LocationValue(LinkList L, int value){
    LNode *p=L->next;                    //指针p指向第一个节点
    while (p!=NULL &&p->data!=value)     //从第一个节点开始查找value
    {
        p=p->next;
    }
    return p;                            //返回value所在的节点的指针
}

//单链表的插入操作O(n)   
//首先查找第i-1个节点,假设第i-1个节点为*p,然后令新节点*s指向*p的后继节点，再令节点*p的指针域指向新插入的节点*s
bool Insert(LinkList *L, int index, int value){
    LNode *p=*L;                    //指针p指向头节点
    int j=0;                       //记录当前节点的位序，头节点是第零个节点
    while (p!=NULL&&j<index-1)
    {
        p=p->next;
        j++;
    }
    if (p==NULL)            //如果i大于表长，或者i小于1，则插入失败
    {
        return false;
    }
    LNode *s=(LNode*)malloc(sizeof(LNode));//创建新节点
    s->data=value;
    s->next=p->next;              //p32操作1  新节点指向原第i个节点
    p->next=s;                    //p32操作2  原第i-1个节点指向新节点
    return true;
}
    
//单链表的删除操作O(n)
bool Delete(LinkList *L, int index,int *value){
    LNode *p=*L;                    //指针p指向头节点
    int j=0;                        //记录当前节点的位序，头节点是第零个节点
    while (p->next!=NULL&&j<index-1)  //循环找到第i-1个节点
    {
        p=p->next;
        j++;
    }
    if(p->next=NULL||j>index-1)     //如果i大于表长，或者i小于1，则删除失败
      return false;
    LNode*q=p->next;                //指针q指向待删除节点
    *value=q->data;                //保存待删除节点的值
    p->next=q->next;               //将*q节点从链中断开
    free(q);                       //释放待删除节点的空间
    return true;
}

//头插法建立单链表O(n)
LinkList List_HeadInsert(LinkList L){ //逆向建立单链表
    LNode *s;                          //设元素类型为整型
    int x;
    L=(LNode*)malloc(sizeof(LNode));    //创建头节点
    L->next=NULL;                       //初始为空链表
    scanf("%d",&x);                     //输入第一个元素
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));//创建新节点
        s->data;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);                 //输入下一个元素
    }
    return L;                          //返回头节点
}

//尾插法建立单链表O(n)
LinkList List_TailInsert(LinkList *L){//正向建立单链表
    int x;
    L=(LNode*)malloc(sizeof(LNode));    //创建头节点
    LNode *s,*r=*L;                   //r为指向尾节点的指针，初始时指向头节点
    scanf("%d",&x);                     //输入第一个元素
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));//创建新节点
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);                 //输入下一个元素
    }
    r->next=NULL;                       //最后一个元素的指针域置空
    return *L;                         //返回头节点
}