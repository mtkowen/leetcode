/*
 * @lc app=leetcode.cn id=152 lang=c
 *
 * [152] 乘积最大子序列
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (37.61%)
 * Likes:    496
 * Dislikes: 0
 * Total Accepted:    51.6K
 * Total Submissions: 134.7K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

// @lc code=start

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
} 

int maxProduct(int* nums, int numsSize)
{
    int res = nums[0];
    int maxs = 1, mins = 1;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            int tmp = maxs;
            maxs = mins;
            mins = tmp;
        }
        
        maxs = max(maxs * nums[i], nums[i]);
        mins = min(mins * nums[i], nums[i]);
        
        res = max(maxs, res); 
    }

    return res;
}

// @lc code=end

