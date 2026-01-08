#define MaxVertexNum 100        
tyoedef struct ArcNode{         //边表节点
    int adjvex;                 //该弧所指向的顶点位置
    struct ArcNode *nextarc;    //指向下一条弧的指针
}ArcNode;

typedef struct VNode{            //顶点表节点
    int data;                   //顶点信息
    ArcNode *firstarc;          //指向第一条依附该顶点的弧的指针
}VNode,AdjList[MaxVertexNum];

typedef struct{                 //图的邻接表表示
    AdjList vertices;
    int vexnum,arcnum;           //图的当前顶点数和弧数
}Graph;                         //图的邻接表表示

bool TopologicalSort(Graph G){
    InitStack(&S);              //初始化空栈,存储入度为零的顶点
    for(int i=0;i<G.vexnum;i++)
        if(indegree[i]==0)
            push(&S,i);          //入度为零的顶点入栈
    int count=0;               //用于统计输出顶点个数
    while(!IsEmpty(S)){
        Pop(&S,&i);          //栈顶元素出栈
        printf[count++]=G.vertices[i].data; //输出顶点i
        for(p=G.vertices[i].firstarc;p=p->nextarc){
            //将所有i指向的顶点的入度减1，并且将入度减为零的顶点压入栈s
            v=p->adjvex;
            if(!--indegree[v])
                push(&S,v);      //若v入度为零则入栈
        }
    }
    if(count<G.vexnun)
        return FALSE;           //图中有回路
    else
        return TRUE;            //无回路，输出拓扑序列
}