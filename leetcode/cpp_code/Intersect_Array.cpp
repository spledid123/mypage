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
//using namespace std;
/******************************************************************************
 * 两个数组的交集 II
 * 
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1：
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2,2]
 * 
 * 说明：
 * 输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 进阶：
 * 如果给定的数组已经排好序呢？你将如何优化你的算法？
 * 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
 * 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
******************************************************************************/
std::ostream& operator << (std::ostream& os, std::vector <int> &nums){//重载操作符 
    std::vector <int> ::iterator iter;//迭代器
    iter = nums.begin();
    
    os << '[';
    while(iter != nums.end()){
        if(iter!=nums.begin())
            os << ",";
        os << *iter;

        iter ++;
    }
    os << ']';

    return os;
}
/*****************************************************************************/
/*****************************************************************************/
class Solution {
public:
    std::vector<int> intersect_1(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector <int> nums;

        if(nums1.size() == 0 || nums2.size() == 0){
            return nums;
        }

        sort(nums1.begin(), nums1.end());//排序，默认由小到大

        std::vector <int> ::iterator num2;
        std::vector <int> ::iterator num;
        num2 = nums2.begin();

        while(num2 != nums2.end()){
            if(nums1.size() == 0){
                break;
            }
            num = std::lower_bound(nums1.begin(), nums1.end(), *num2);//二分查找，第一个大于或等于num的数字，
                                                       //找到返回该数字的地址，不存在则返回end
            if(num != nums1.end() && *num == *num2){
                nums.push_back(*num2);
                nums1.erase(num);
            }
            num2 ++;
        }

        return nums;
    }

    std::vector<int> intersect_2(std::vector<int>& nums1, std::vector<int>& nums2) {//双指针
        if(nums1.size() < nums2.size()){//交换
            return intersect(nums2, nums1);
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        std::vector <int> ::iterator num1 = nums1.begin(), num2 = nums2.begin();
        std::vector <int> num;

        while(num1 != nums1.end() && num2 != nums2.end()){
            if(*num1 < *num2){
                num1 ++;
            }
            else if(*num1 > *num2){
                num2 ++;
            }
            else if(*num1 == *num2){
                num.push_back(*num1);
                num1 ++;
                num2 ++;
            }
        }
        return num;
};

    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {//建哈希表
        std::unordered_map <int,int> Hash;//建立一个key/value都是int的哈希表

        for(int num : nums1){//遍历
            Hash[num] ++;//num为值，记录出现次数
        }

        std::vector <int> nums;
        
        for(int num : nums2){
            if(Hash.count(num)){//判定是否出现num
                nums.push_back(num);
                Hash[num] --;
                if(Hash[num] == 0){
                    Hash.erase(num);//清除
                }
            }
        }

        return nums;
    }//在两个数组数据都较大时更适合用哈希表
};
/*****************************************************************************/

int main(){
    int num1[2] = {9, 1};
    int num2[9] = {7,8,3,9,0,0,9,1,5};

    std::vector <int> nums1(num1, num1 + 2);
    std::vector <int> nums2(num2, num2 + 9);
    Solution Solution;
    
    std::vector <int> nums;
    nums = Solution.intersect(nums1, nums2);
    std::cout << nums;
}

