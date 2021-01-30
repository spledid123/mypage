/*****************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*****************************************************************************/

/******************************************************************************
 * 买卖股票的最佳时机 II
 * 
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 示例 1:
 * 输入: [7,1,5,3,6,4]
 * 输出: 7
 * 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
 *      随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
 * 示例 3:
 * 输入: [7,6,4,3,1]
 * 输出: 0
 * 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0.
 * 
 * 1 <= prices.length <= 3 * 10 ^ 4
 * 0 <= prices[i] <= 10 ^ 4
 * 
******************************************************************************/
// int find_sta(int *prices, int pricesSize, int sta, int flag){//根据sta为起点的最大值,flag:0为小，1为大
//     int next_sta, maxprofile = 0, profile;//如名
//     if(flag){
//         if(pricesSize - sta < 2){
//             return 0;
//         }
//         next_sta = sta + 1;
//         while(next_sta < pricesSize){
//             profile = find_sta(prices, pricesSize, next_sta, 0);
//             if(profile > maxprofile)
//                 maxprofile = profile;
//             all++;
//             next_sta++;
//          }
//          return maxprofile;
//     }
//     else{
//         if(pricesSize - sta < 1)
//             return 0;
//         next_sta = sta + 1;
//         while(next_sta < pricesSize && prices[next_sta] > prices[sta]){
//             profile = find_sta(prices, pricesSize, next_sta, 1) + prices[next_sta] - prices[sta];
//             if(profile > maxprofile)
//                 maxprofile = profile;
//             all++;
//             next_sta++;
//         }
//         return maxprofile;
//     }
// }
// int maxProfit(int* prices, int pricesSize){//这个的限制是一天只能买卖一个操作
//     int profile, maxprofile = 0;
//     int sta;//开始读取的起点；
//     for (sta = 0; sta < pricesSize; sta++){
//         profile = find_sta(prices, pricesSize, sta, 0);
//         if(maxprofile < profile)
//             maxprofile = profile;
//        if(profile != 0)
//             break;
//     }
//     return maxprofile;
// }
//这个的限制是一天只能买卖一个操作
//递归，暴力搜索
//O(n^n)
/*****************************************************************************/
int maxProfit(int *prices, int pricesSize){//请注意，一天内可以卖出买入多次
    int i, profile = 0;
    if(pricesSize==0)
        return 0;
    for (i = 1; i < pricesSize;i++){
        if(prices[i]>prices[i-1]){
            profile = profile + prices[i] - prices[i - 1];
        }
    }
    return profile;
}
//贪心算法
//如果连续增加，那么这样无疑是最大值；
//如果中途有减少，比如2,1,3,那么（1，3）也是最佳选择
//连续下跌，不买
/*****************************************************************************/
int main(){
    int prices[100] = { 7, 1, 5, 3, 6, 4 };
    printf("%d", maxProfit(prices, 6));
}










