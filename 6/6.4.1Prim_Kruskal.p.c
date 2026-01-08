//
GENERIC_MST(G){
    T=NUll;
    while T未生成一颗生成树；
        do 找到一条最小代价边(u,v)并加入T后不会产生回路；
            T=T+边(u,v);
}

// Prim算法求最小生成树
void Prim(Graph G,int s,MST T){
    T=NULL;
    U={w};
    while((V-U)!=NULL){
        找到一条边(u,v)，u∈U，v∈(V-U)，且边(u,v)代价最小；
        T=T+边(u,v);
        U=U∪{v};
    }
}

// Kruskal算法求最小生成树
void Kruskal(Graph G,MST T){
    T=NULL;
    nums=n;
    while(nums>1){
        找到一条边(u,v)，且边(u,v)代价最小；
        if(u和v不在同一棵树中){
            T=T+边(u,v);
            合并u和v所在的两棵树；
            nums=nums-1;
        }
    }