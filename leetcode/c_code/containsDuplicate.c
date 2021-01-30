/*****************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
/*****************************************************************************/

/******************************************************************************
 * 给定一个整数数组，判断是否存在重复元素
 * 如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 
 * 
 * 示例 1:
 * 输入: [1,2,3,1]
 * 输出: true
 * ***************************************************************************/
int comp(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}
bool containsDuplicate_1(int* nums, int numsSize){//bool定义在<stdbool.h>中
    qsort(nums, numsSize, sizeof(int), comp);//排序
    int i;
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}
//O(n log n)
/*****************************************************************************/
#define numofarray 5
int main(){
    int array [numofarray] = {1, 2, 3, 4, 1};
    if (containsDuplicate(array, numofarray))
    {
        printf("存在重复项");
    }
    else{
        printf("不存在重复项");
    }
}