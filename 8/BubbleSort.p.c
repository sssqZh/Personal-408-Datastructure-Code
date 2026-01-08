void BubbleSort(int arr[], int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        bool falg=false; //用于优化
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                falg=true;
            }
        if(!falg)  //若一趟排序未发生交换，说明已排序完成
            break;
        }
    }