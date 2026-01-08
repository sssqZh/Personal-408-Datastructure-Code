#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxVerterxNum 100 //最大顶点数


//图的邻接矩阵存储结构定义
typedef char VertexType; //顶点类型
typedef int EdgeType;
typedef struct 
{
    VertexType ves[MaxVerterxNum]; //顶点数组
    EdgeType edge[MaxVerterxNum][MaxVerterxNum]; //邻接矩阵
    int verNum,edgeNum; //顶点数，边数
    bool isDirected;                  //标记是否为有向图
}MGraph;

// 通用度计算函数（自动判断图类型）
void GetVertexDegree(MGraph *G, int vertexIndex, int *degree, int *inDegree, int *outDegree) {
    if (vertexIndex < 0 || vertexIndex >= G->verNum) {
        *degree = *inDegree = *outDegree = -1;
        return;
    }
    
    if (G->isDirected) {
        // 有向图
        *outDegree = GetOutDegree_Directed(G, vertexIndex);
        *inDegree = GetInDegree_Directed(G, vertexIndex);
        *degree = *outDegree + *inDegree;
    } else {
        // 无向图
        *degree = GetDegree_Undirected(G, vertexIndex);
        *inDegree = *outDegree = *degree; // 无向图中入度=出度=度
    }
}