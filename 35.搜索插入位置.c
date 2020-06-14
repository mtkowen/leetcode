/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (45.35%)
 * Likes:    537
 * Dislikes: 0
 * Total Accepted:    167.1K
 * Total Submissions: 365.9K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */

// @lc code=start
int searchInsert(int* nums, int numsSize, int target)
{
    if(!nums || !numsSize)
        return 0;

    int l = 0, r = numsSize - 1;
    int mid = 0;
    
    while (l <= r) {  
        mid = l + (r - l) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    
    return l;
}


// @lc code=end

