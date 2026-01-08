#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 100

bool visited[MAX_VERTEX_NUM]; //访问标志数组
void BFSTraverse(Graph G){     //对图G进行广度优先遍历
    for(int i=0;i<G.verNum;++i){
        visited[i] = FALSE;    //访问标记数组初始化
    }
    InitQueue(Q);               //初始化辅助队列Q
    for(int i=0;i<G.verNum;++i){//从0号节点开始遍历 
        if(!visited[i])         //对每个连通分量调用一次BFS 
            BFS(G,i);           //vi未访问过，从vi开始BFS
    }
}
//广度优先遍历
void BFS(Graph G, int v){  //从顶点v出发进行广度优先遍历
    visit(v);              //访问初始顶点v
    visited[v]=TRUE;       //对v做已访问标记 
    Enqueue(Q,v);           //将v入队列
    while(!IsEmpty(Q)){
        DeQueue(Q,&v);      //顶点v出列
        for(w=FirstAdjVex(G,v); w>=0; w=NextAdjVex(G,v,w)){
            if(!visited[w]){       //w为v的尚未访问的邻接顶点
                visit(w);          //访问顶点w
                visited[w]=TRUE;   //对w做已访问标记
                Enqueue(Q,w);      //将顶点w入队列
            }
        }
    }
}

//