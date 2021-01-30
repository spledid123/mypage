/*****************************************************************************/
#include <iostream>
#include <string>
#include <vector>
//#include <list>
#include <cmath>
#include <cstdlib>
#include <algorithm>
//#include <iterator> 
//#include <unordered_map>//哈希表 
/*****************************************************************************/
//using namespace std;
/******************************************************************************
 * 移动零
 * 
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
******************************************************************************/
std::ostream& operator << (std::ostream& os, std::vector<int>& nums){
    std::vector <int> ::iterator iter = nums.begin();

    std::cout << '[';
    while(iter != nums.end()){
        if(iter != nums.begin())
            std::cout << ',';
        std::cout << *iter;
        iter ++;
    }
    std::cout << ']';

    return os;
}
/*****************************************************************************/
class Solution {
public:
    void moveZeroes_1(std::vector<int>& nums) {
        int i = 0;//记录0的个数
        std::vector<int> :: iterator iter = nums.begin(), iter_new;
        while(iter != nums.end() - 1){
            iter_new = iter + 1;
            if(*iter == 0){
                i ++;
                nums.erase(iter);
                iter_new --;
            }
            iter = iter_new;
        }
        while(i != 0){
            i --;
            nums.push_back(0);
        }
    }

    void moveZeroes(std::vector<int>& nums){//双指针
        int normal, choose;//normal正常遍历，choose仅表示非0元
        for(normal = 0, choose = 0; normal < nums.size(); normal ++){
            if(nums[normal] != 0){
                std::swap(nums[choose], nums[normal]);
                choose ++;
            }
        }
    }
};
/*****************************************************************************/
int main(){
    int num[6] = {1, 0, 3, 5, 0, 6};
    std::vector<int> nums(num, num + 6);
    Solution Solution;

    Solution.moveZeroes(nums);
    std::cout << nums;
}