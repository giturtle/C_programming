//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

//示例:

//输入: [0,1,0,3,12]
//输出: [1,3,12,0,0]


void moveZeroes(int* nums, int numsSize) {
    if(nums == NULL){
        return NULL;
    }
    int count = 0;
    int i = 0,j = 0;
    for( ;i < numsSize;i++){
        if(nums[i] != 0){
            nums[j++] = nums[i];
        }
    }
    while(j < numsSize){
        nums[j++] = 0;
    }
}
