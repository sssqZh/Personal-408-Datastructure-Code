#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxVerterxNum 100 //最大顶点数

//图的邻接表存储结构定义
typedef struct ArcNode{             //边表结点
    int adjvex;                     //该弧所指向的顶点的位置
    struct ArcNode *nextarc;        //指向下一条弧的指针
    //InfoType info; // 边信息（可选）
}ArcNode;
typedef struct VNode{               //顶点表结点
    char data;                      //顶点信息
    ArcNode *firstarc;              //指向第一条依附该顶点的弧的指针
}VNode,AdjList[MaxVerterxNum];
typedef struct{                     //图的邻接表存储结构
    AdjList vertices;               //邻接表
    int vernum,arnum;               //图的当前顶点数和弧数   
}ALGraph;                          //ALGraph即为图的邻接表存储结构