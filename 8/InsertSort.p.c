void InsertSort(int arr[], int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            temp=arr[i];
            for(j=i-1;j>=0&&arr[j]>temp;j--)
                arr[j+1]=arr[j];
            arr[j+1]=temp;
        }
    }
}

//带哨兵
void InsertSortWithSentinel(int arr[], int n){
    int i,j,temp;
    for(i=2;i<=n;i++){
        if(arr[i]<arr[i-1]){
            arr[0]=arr[i]; //设置哨兵
            for(j=i-1;arr[j]>arr[0];j--)
                arr[j+1]=arr[j];
            arr[j+1]=arr[0];
        }
    }
}