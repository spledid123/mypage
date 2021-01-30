/*****************************************************************************/
#include <iostream>
#include <string>
#include <vector>
//#include <list>
#include <cmath>
#include <cstdlib>
#include <algorithm>
//#include <iterator> 
#include <unordered_map>//哈希表 
/*****************************************************************************/
//using namespace std
/******************************************************************************
 * 两数之和
 * 
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍
 * 
 * 示例:
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
******************************************************************************/
std::ostream& operator << (std::ostream& os, std::vector<int>& nums){
    std::vector<int>::iterator iter = nums.begin();
    
    std::cout << '[';
    while(iter != nums.end()){
        if(iter != nums.begin()){
            std::cout  << ", ";
        }
        std::cout << *iter;
        iter ++;
    }
    std::cout << ']';

    return os;
}
/*****************************************************************************/
class Solution {
public:
    std::vector<int> twoSum_1(std::vector<int>& nums, int target) {
        std::vector<int> nums1, nums2 = nums;
        int start = 0, end = nums.size() - 1;
        int i = 0, one, two;
        
        sort(nums2.begin(), nums2.end());
        while(nums2[start] + nums2[end] != target){
            if(nums2[start] + nums2[end] < target){
                start ++;
            }
            else if(nums2[start] + nums2[end] > target){
                end --;
            }
        }
        start = nums2[start];end = nums2[end];
        
        for(i = 0, one = -1, two = -1; i < nums.size(); i ++){
            if(nums[i] == start && one == -1){
                one = i;
            }
            if(nums[i] == end && i != one){
                two = i;
            }
            if(one > -1 && two > -1){
                break;
            } 
        }
        if(one < two){
            nums1.push_back(one);
            nums1.push_back(two);
        }
        else{
            nums1.push_back(two);
            nums1.push_back(one);  
        }

        return nums1;
    }

    std::vector<int> twoSum(std::vector<int>& nums, int target){//哈希表
        std::unordered_map <int, int> Hash;
        std::vector<int> outs;
        int i;

        for(i = 0; i < nums.size(); i ++){
            Hash[nums[i]] = i;
        }
        for(i = 0; i < nums.size(); i ++){
            if(Hash[target - nums[i]] && Hash[target - nums[i]] != i){//存在且不同
                outs.push_back(i);//假如是相同的两个数，Hash中的记录的是后面的下标
                outs.push_back(Hash[target - nums[i]]);
                break;
            }
        }
        
        return outs;
    }
};
/*****************************************************************************/
int main(){
    int num[2] = {3, 3};
    std::vector<int> nums(num, num + 2), nums1;
    int target = 6;
    Solution Solution;

    nums1 = Solution.twoSum(nums, target);
    std::cout << nums1;
}