//树的先序遍历
void PreOrder(TreeNode *root){
    if (root!=NULL){          //若根结点存在
        visit(root->data);     //访问根结点
        PreOrder(root->left);  //递归遍历左子树
        PreOrder(root->right); //递归遍历右子树
    }
}

//DFS遍历
bool visited[MAX_VERTEX_NUM]; //访问标志数组

void DFSTraverse(Graph G){     //对图G进行深度优先遍历
    for(int i=0;G.vexnum;i++){
        visited[i] = FALSE;    //访问标记数组初始化
    }
    for(int i=0;i<G.vexnum;i++){  //本代码中从v0开始遍历
        if(!visited[i])             
        DFS(G,i);             // 对未访问的顶点调用DFS()
    }
}

void DFS(Graph G,int v){       //从顶点v出发，深度优先遍历图G
    visit(v);                  //访问顶点v
    visited[v]=TRUE;           //对v做已访问标记
    for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
        if(!visited[w]){        //w为v的尚未访问的邻接顶点
            DFS(G,w);
        }
    }
}