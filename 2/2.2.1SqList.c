#define MAXSIZE 50
typedef struct 
{
    int data[MAXSIZE];
    int length;
}Sqlist;
//静态分配
#define InitSize 100
typedef struct{
    int *data;
    int length;
    int MaxSize;
}SeqList;
//动态分配
//L.data = (int*)malloc(sizeof(int)*L.MaxSize); 初始动态分配语句
