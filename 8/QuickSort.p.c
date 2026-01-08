int partition(int* nums, int low, int high) {
    int pivot = nums[low]; // 选左边第一个为基准
    while (low < high) {
        // 1. 先从右往左，找一个比 pivot 小的数
        while (low < high && nums[high] >= pivot) {
            high--; // 注意这里是 high--
        }
        nums[low] = nums[high]; // 把找到的小数填到左边的坑
        
        // 2. 再从左往右，找一个比 pivot 大的数
        while (low < high && nums[low] <= pivot) {
            low++; // 注意这里是 low++
        }
        nums[high] = nums[low]; // 把找到的大数填到右边的坑
    }
    nums[low] = pivot; // 基准归位
    return low;
}
void QuickSort(int* nums,int low, int high){
    if(low<high){
        int pivotpos=partition(nums,low,high);
        QuickSort(nums,low ,pivotpos-1);
        QuickSort(nums,pivotpos+1,high);
    }
}