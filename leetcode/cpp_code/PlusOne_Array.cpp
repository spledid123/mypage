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
 * 加一
 * 
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 你可以假设除了整数 0 之外，这个整数不会以零开头
 * 
 * 示例 1:
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
******************************************************************************/
std::ostream& operator <<(std::ostream& os, std::vector <int>& nums){
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
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector <int> ::iterator iter = digits.end() - 1;

        while(iter >= digits.begin()){
            if(*iter == 9){
                if(iter == digits.begin()){
                    *iter = 0;
                    digits.insert(digits.begin(), 1);
                    break;
                }
                *iter = 0;
                iter --;
                continue;
            }
            *iter = *iter + 1;
            break;
        }
        return digits;
    }
};
/*****************************************************************************/
int main(){
    int num[6] = {9, 9, 9, 9, 9, 9};
    std::vector <int> nums(num, num + 6);
    std::vector <int> nums1;
    Solution Solution;

    nums1 = Solution.plusOne(nums);
    std::cout << nums1;
}
