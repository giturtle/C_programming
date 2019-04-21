
//给定一个整数数组，判断是否存在重复元素。

//如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

//输入: [1,2,3,1]
//输出: true


bool containsDuplicate(int* nums, int numsSize) {
    //插入排序思想，来判断是否存在相同的元素
    int i = 1 ,j,tmp;
    for(;i < numsSize;i++){
       tmp = nums[i]; 
        for(j = i - 1;j >= 0;j--){
            if(nums[j] == tmp){
                return true;
            }
            else if(nums[j] < tmp){
                nums[j+1] = tmp;
                break;
            }
            else{
              nums[j+1] = nums[j];
            }
        }
    }
    return false;
}
