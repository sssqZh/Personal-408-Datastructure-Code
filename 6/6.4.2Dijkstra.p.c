/* 
   Dijkstra 算法 - 包含路径记录
   输入: graph (邻接矩阵), src (起点下标)
   输出: 填充好的 dist 和 path 数组
*/

#define INF 99999
#define V 6 // 假设顶点数

void Dijkstra_With_Path(int graph[V][V], int src) {
    // --- 1. 定义三个辅助数组 ---
    int final[V];  // 是否已找到最短路
    int dist[V];   // 最短距离
    int path[V];   // 前驱节点

    // --- 2. 初始化 ---
    for (int i = 0; i < V; i++) {
        final[i] = 0;          // 初始都不属于已求得集合
        dist[i] = graph[src][i]; // 初始距离为直达距离（不能直达就是INF）
        
        // 初始化 path 数组：
        if (graph[src][i] < INF && i != src) {
            path[i] = src;     // 如果能直达，前驱就是 src
        } else {
            path[i] = -1;      // 不能直达，或者就是自身，前驱设为 -1
        }
    }

    // 修正源点自身的状态
    final[src] = 1; // 源点不需要求，已知
    dist[src] = 0;  // 自己到自己距离为0

    // --- 3. 主循环 (处理剩下的 V-1 个点) ---
    for (int i = 1; i < V; i++) {
        
        // A. 寻找最小值的点 (Greedy)
        int min = INF;
        int k = -1; // k 用于记录找到的那个点的下标

        for (int w = 0; w < V; w++) {
            // 在还没确定的点中(final=0)，找距离(dist)最小的
            if (!final[w] && dist[w] < min) {
                min = dist[w];
                k = w;
            }
        }

        // 如果没找到连通的点，算法可以提前结束（针对非连通图）
        if (k == -1) break;

        // B. 将点 k 加入“已毕业”集合
        final[k] = 1;

        // C. 松弛操作 (Relaxation) - 关键步骤
        for (int w = 0; w < V; w++) {
            // 条件1: w 还没毕业 (!final[w])
            // 条件2: k 到 w 有路 (graph[k][w] < INF)
            // 条件3: 借道 k 会比原来的路更近 (min + graph < dist)
            if (!final[w] && (graph[k][w] < INF) && (min + graph[k][w] < dist[w])) {
                
                // 更新距离
                dist[w] = min + graph[k][w];
                
                // 【重点】更新前驱
                // 因为我是通过 k 走到 w 的，所以 w 的前驱变成了 k
                path[w] = k; 
            }
        }
    }
    
    // 此时，dist[] 存了最短长度，path[] 存了路径线索
}

// 打印从 src 到 v 的路径
void PrintPath(int path[], int v) {
    int stack[V]; // 用栈来反转顺序
    int top = -1;
    
    // 1. 倒推回溯
    while (path[v] != -1) { 
        stack[++top] = v; // 把终点压栈
        v = path[v];      // 这里的关键：把 v 变成它的前驱
    }
    stack[++top] = v; // 把最后的起点压入

    // 2. 正序打印
    printf("最短路径: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
        if (top >= 0) printf("-> ");
    }
}