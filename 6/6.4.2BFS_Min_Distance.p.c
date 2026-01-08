//求顶点u到其他顶点的最短路径
void BFS_Min_Distance(Graph G, int u){
    //d[i]表示从u到i结点的最短路径
    for(int i=0;i<G.verNum;++i){
        d[i]=∞;               //初始化距离数组
        path[i]=-1;           //最短路径从哪个顶点过来
    }
    d[u]=0;                  //源点到自身距离为0
    visited[u]=TRUE;         //源点已访问
    Enqueue(Q,u);            //源点入队列
    while(!IsEmpty(Q)){
        DeQueue(Q,&u);      //顶点u出列
      for(w=FirstNeighbor(G,u);w>=0;w=NexNeighbor(G,u,w))
        if(!visited[w]){
            d[w]=d[u]+1;        //更新源点到w的最短路径
            path[w]=u;           //最短路径应从u到w
            visited[w]=TRUE;     //w已访问
            Enqueue(Q,w);        //w入队列
        }
    }
}