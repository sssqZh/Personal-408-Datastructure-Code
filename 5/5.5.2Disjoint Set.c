#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int UFSets[SIZE];       //集合元素数组
//并查集的表示
void Initial(int S[]){
    for (int i = 0; i < SIZE; i++)   //S即并查集
    {
        S[i] = -1;                   //每个自成单元素集合
    }
}

//Find，在并查集中查找并返回包含元素x的根 O(n)
int Find(int S[],int x){         //x为要查询的元素
    while (S[x]>=0)              //一路向北查找
    { 
        x=S[x];
    }
    return x;
}
//Union，O(1)合并两个集合,需要找到两个元素的根，再令一个子集树的根指向另一颗子集树的根
void Union(int S[],int Root1, int Root2){
    if(Root1==Root2) return;
    S[Root2]=Root1;               //令Root2的根指向Root1的根
}

//优化Union，Find优化为O(log2n),目标：构建树的时候尽量不让树长高，负值表示根节点，绝对值表示集合大小
void Union(int S[], int Root1, int Root2) {
    // Root1 和 Root2 必须是不同集合的根节点
    
    if (S[Root1] > S[Root2]) { 
        // Root2 的集合更大（因为更负，绝对值更大）
        S[Root2] += S[Root1];  // 合并后的大小
        S[Root1] = Root2;      // Root1 指向 Root2
    } else {
        // Root1 的集合更大或相等
        S[Root1] += S[Root2];  // 合并后的大小
        S[Root2] = Root1;      // Root2 指向 Root1
    }
}

//Find操作的优化(压缩路径)
int Find2(int S[],int x){
    int root=x;
    while (S[root]>=0) {
        root=S[root];
    }
    //路径压缩
    while (x != root) {   
        int parent = S[x];     //parent为x的父节点
        S[x] = root;           //将x的父节点指向root
        x = parent;
    }
    return root;               //返回根节点
}