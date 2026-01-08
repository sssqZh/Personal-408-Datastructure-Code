#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

// 定义顺序表结构体（静态分配）
struct SqList {
    int data[MAX_SIZE];  // 静态数组
    int length;          // 当前长度
};


//静态分配
void InitList(struct SqList *L){

    L->length = 0;
}
//插入操作
bool ListInsert(struct SqList *L, int index, int value){
    if(index < 0 || index > L->length)
        return false;
    if(L->length >=MAX_SIZE)
        return false;
    for(int j=L->length;j>=index;j--){
        L->data[j] = L->data[j-1];
        L->data[index-1] = value;
        L->length++;
        return true;
    }
}
//删除操作
bool ListDelete(struct SqList *L, int index, int *value) {
    // 检查删除位置是否合法
    if(index < 1 || index > L->length) {
        return false;
    }
    
    // 保存被删除的值
    *value = L->data[index-1];
    
    // 移动元素覆盖被删除的位置
    for(int j = index; j < L->length; j++) {
        L->data[j-1] = L->data[j];
    }
    // 表长减1
    L->length--;
    return true;
}
//按值查找
int LocationELem(struct SqList *L, int value){
    for(int i=0;i<L->length;i++){
        if(L->data[i]==value)
            return i+1; // 返回位置，位置从1开始
    }
    return 0; // 未找到
}



// 动态顺序表结构体
struct SqList {
    int *data;      // 指向动态数组的指针
    int length;     // 当前长度
    int capacity;   // 总容量
};

// 初始化动态顺序表
void InitList(struct SqList *L, int capacity) {
    L->data = (int*)malloc(capacity * sizeof(int));
    L->length = 0;
    L->capacity = capacity;
    
    // 初始化数组内容
    for(int i = 0; i < capacity; i++) {
        L->data[i] = 0;
    }
}

// 销毁顺序表
void DestroyList(struct SqList *L) {
    free(L->data);
    L->data = NULL;
    L->length = 0;
    L->capacity = 0;
}

int main() {
    // 这里可以添加测试代码
    return 0;
}




