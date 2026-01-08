#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100  // 最大节点数
#define EMPTY -1      // 空节点标记

// 二叉树顺序存储结构
typedef struct {
    char data[MAX_SIZE];  // 存储节点数据
    int size;             // 当前节点数量
    int capacity;         // 最大容量
} SeqBinaryTree;

// 初始化顺序二叉树
void InitSeqTree(SeqBinaryTree *tree) {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree->data[i] = EMPTY;  // 初始化为空
    }
    tree->size = 0;
    tree->capacity = MAX_SIZE;
}

// 检查二叉树是否为空
bool IsTreeEmpty(SeqBinaryTree *tree) {
    return tree->size == 0;
}

// 获取根节点
char GetRoot(SeqBinaryTree *tree) {
    if (IsTreeEmpty(tree)) {
        printf("树为空\n");
        return EMPTY;
    }
    return tree->data[0];
}

// 获取左孩子
char GetLeftChild(SeqBinaryTree *tree, int parentIndex) {
    int leftIndex = 2 * parentIndex + 1;
    if (leftIndex >= tree->capacity || tree->data[leftIndex] == EMPTY) {
        return EMPTY;
    }
    return tree->data[leftIndex];
}

// 获取右孩子
char GetRightChild(SeqBinaryTree *tree, int parentIndex) {
    int rightIndex = 2 * parentIndex + 2;
    if (rightIndex >= tree->capacity || tree->data[rightIndex] == EMPTY) {
        return EMPTY;
    }
    return tree->data[rightIndex];
}

// 获取父节点
char GetParent(SeqBinaryTree *tree, int childIndex) {
    if (childIndex == 0) {
        return EMPTY;  // 根节点没有父节点
    }
    int parentIndex = (childIndex - 1) / 2;
    return tree->data[parentIndex];
}