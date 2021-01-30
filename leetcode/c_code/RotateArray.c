/*****************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*****************************************************************************/

/******************************************************************************
 * 旋转数组
 * 
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 输入: [1,2,3,4,5,6,7] 和 k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
******************************************************************************/
void rotate_1(int* nums, int numsSize, int k){
    k = k % numsSize;
    int flag = 0;
    int i, j;
    for(i = 0; i < k; i++){
        flag = nums[numsSize - 1];
        for(j = numsSize - 2; j >= 0; j--){
                nums[j + 1] = nums[j];
        }
        nums[0] = flag;
    }
}
//O(n*k);O(1)
/*****************************************************************************/
void rotate_2(int* nums, int numsSize, int k){
    k = k % numsSize;
    if(k==0)return;
    int array[k];
    int i;
    for(i = 0; i < k; i++){
        array[i] = nums[numsSize + i - k];
    }
    for(i = 0; i < numsSize - k; i++){
        nums[numsSize - 1 - i]=nums[numsSize - 1 - i - k];
    }
    for(i = 0; i < k; i++){
        nums[i]=array[i];
    }
}
//O(n);O(k)
/*****************************************************************************/
void rotate_3(int* nums, int numsSize, int k)
{ //环状替代,第一轮：0,k-1,2k-1...;第二轮：1,k...;
//一组k和numsSize的一轮与numsSize与k的最大公因数效果相当
    k = k % numsSize;
    if(k == 0)return;//相当于不替换
    int start = 0, current; //start表示一轮替换的开始元素，记录下来防止重复;current表示现在需替换的元素位置
    int temp, now;//储存数据
    int count = 0; //记录替换次数
    for (; count < numsSize; start++)//到替换完成结束
    {
        temp = nums[start];
        current = start;
        //一轮替换的初始化
        do {
            current = (current + k) % numsSize;
            now = nums[current];
            nums[current] = temp;
            temp = now;
            count++;
        } while (current != start); //一轮替换，满足条件所有下标i同余;所以不会重复
    }
}
//O(n);O(1)
/*****************************************************************************/
void rotate(int *nums, int numsSize, int k){//反转
//可以看作讲后k个元素移到数组前面
    k = k % numsSize;
    int i;//序号
    int temp;
    for (i = 0; i < numsSize / 2; i++)
    {
        temp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = temp;
    } //倒转数组
    for (i = 0; i < k / 2; i++)
    {
        temp = nums[i];
        nums[i] = nums[k - 1 - i];
        nums[k - 1 - i] = temp;
    } //正转前k个元素，相当于k个元素移到前面
    for (i = k; i < (numsSize + k) / 2; i++)
    {
        temp = nums[i];
        nums[i] = nums[(numsSize + k) - 1 - i];
        nums[(numsSize + k) - 1 - i] = temp;
    }//正转剩下的元素
}
//O(n);O(1)
/*****************************************************************************/
int main()
{
    int array[7] = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(array, 7, k);
    int i = 0;
    for(i = 0; i < 7; i++){
        printf("%d ",array[i]);
    }
}
