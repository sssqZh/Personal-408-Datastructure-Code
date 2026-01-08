/*
   Floyd-Warshall 算法
   输入: graph[V][V] (邻接矩阵)
   输出: 更新后的 A[V][V] 和 path[V][V]
   复杂度: O(V^3) - 非常慢，但代码极短，适合 V < 300 的情况
*/

#define INF 99999
#define V 4 // 假设有4个点

void Floyd(int graph[V][V]) {
    int A[V][V];    // 最短距离矩阵
    int path[V][V]; // 路径前驱矩阵

    // --- 1. 初始化 ---
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            A[i][j] = graph[i][j]; // 复制邻接矩阵的距离
            
            // 初始化 path
            // 如果 i 和 j 之间有边，且 i != j，则 j 的前驱是 i
            if (graph[i][j] != INF && i != j) {
                path[i][j] = i;
            } else {
                path[i][j] = -1; // 代表不通
            }
        }
    }

    // --- 2. 三层循环核心 (动态规划) ---
    
    // 第一层 k: 允许经过的中转点 (必须在最外层！)
    // k = 0 表示只允许经过 0 号点中转
    // k = 1 表示允许经过 0, 1 号点中转...
    for (int k = 0; k < V; k++) {
        
        // 第二层 i: 起点
        for (int i = 0; i < V; i++) {
            
            // 第三层 j: 终点
            for (int j = 0; j < V; j++) {
                
                // 核心状态转移方程：
                // 如果从 i 经过 k 到 j 的距离，比直接 i 到 j 更短
                if (A[i][k] != INF && A[k][j] != INF && 
                    A[i][k] + A[k][j] < A[i][j]) {
                    
                    // 1. 更新最短距离
                    A[i][j] = A[i][k] + A[k][j];
                    
                    // 2. 更新路径前驱
                    // "从 i 到 j 的最后一步"，等同于 "从 k 到 j 的最后一步"
                    // 因为路变成了 i -> ... -> k -> ... -> j
                    path[i][j] = path[k][j];//与书上不同，path[i][j] = k（记录中转点）的写法需要递归
                }
            }
        }
    }
    
    // 循环结束后，A[i][j] 就是最终的最短路径长度
}


// 打印从 u 到 v 的完整路径
void PrintPath_Floyd(int path[V][V], int u, int v) {
    if (path[u][v] == -1) {
        printf("不存在路径\n");
        return;
    }

    int stack[V];
    int top = -1;
    int curr = v;

    // 1. 倒推入栈
    // 只要 curr 不等于起点 u，就一直找前驱
    while (curr != u) {
        stack[++top] = curr;
        curr = path[u][curr]; // 注意这里是 path[u][curr]
        // 意思是：在以 u 为起点的路径体系里，curr 的前驱是谁
    }
    stack[++top] = u; // 最后把起点压入

    // 2. 打印
    printf("路径 %d 到 %d: ", u, v);
    while (top >= 0) {
        printf("%d ", stack[top--]);
        if (top >= 0) printf("-> ");
    }
    printf("\n");
}