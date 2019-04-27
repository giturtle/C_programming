

//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//示例 1:
//输入: [1,2,3,4,5,6,7] 和 k = 3
//输出: [5,6,7,1,2,3,4]
//解释:
//向右旋转 1 步: [7,1,2,3,4,5,6]
//向右旋转 2 步: [6,7,1,2,3,4,5]
//向右旋转 3 步: [5,6,7,1,2,3,4]

//示例 2:
//输入: [-1,-100,3,99] 和 k = 2
//输出: [3,99,-1,-100]
//解释: 
//向右旋转 1 步: [99,-1,-100,3]
//向右旋转 2 步: [3,99,-1,-100]
/********************************************************************/


//1. 双重循环法 [☆]
//时间复杂度：O(kn)   时间复杂度很高
//空间复杂度：O(1)

void rotate(int* nums, int numsSize, int k){
    if(numsSize < 2){
        return;
    }
    k %= numsSize;
    if(k == 0){
        return;
    }
    while(k--){
        int t = nums[numsSize-1];
        for(int i = numsSize - 2;i >= 0;i--){
            nums[i+1] = nums[i];
        }
        nums[0] = t;
    }
}

/********************************************************************/

//2. 翻转法 [★]
//时间复杂度：O(n)
//空间复杂度：O(1)

void reverse(int *nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = temp;
    }
}
void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);   //先整体逆转
    reverse(nums, 0, k - 1);          //前半段逆转  [0,k-1]
    reverse(nums, k, numsSize - 1);    //后半段逆转  [k,len-1]
}

/********************************************************************/

//3. 循环交换法：有问题，待修缮
//时间复杂度：O(n)
//空间复杂度：O(1)
    
void swap(int *nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = temp;
    }
}
void rotate(int* nums, int numsSize, int k){
    int n = numsSize;
    k %= numsSize;
    // 第一次交换完毕后，前 k 位数字位置正确，后 n-k 位数字中最后 k 位数字顺序错误，继续交换
    for (int start = 0; start < n && k != 0; n -= k, start += k, k %= n) {
        for (int i = 0; i < k; i++) {
            swap(nums, start + i, n - k + i);
        }
    }
}


/********************************************************************/

//4. 递归交换（Java版本）
//时间复杂度：O(n)
//空间复杂度：O(n/k)


void swap(int *nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = temp;
    }
}
void recursiveSwap(int[] nums, int k, int start, int length) {
    k %= length;
    if (k != 0) {
        for (int i = 0; i < k; i++) {
            swap(nums, start + i, nums.length - k + i);
        }
        recursiveSwap(nums, k, start + k, length - k);
    }
}
void rotate(int* nums, int numsSize, int k){
    recursiveSwap(nums, k, 0, nums.length);
}



