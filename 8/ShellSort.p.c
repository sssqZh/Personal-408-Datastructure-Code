void Shellsort(int A[],int n){
    //A[0]只是暂存单元，不是哨兵
    int d ,i ,j;
    for(d=n/2;d>=1;d=d/2){    //增量变化
        for(i=d+1;i<=n;i++){
            if(A[i]<A[i-d]){
                A[0]=A[i]; //暂存单元
                for(j=i-d;j>0&&A[0]<A[j];j=j-d)
                    A[j+d]=A[j];
                A[j+d]=A[0];    //插入排序
            }
        }
    }
} 