/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (49.47%)
 * Likes:    1049
 * Dislikes: 0
 * Total Accepted:    76K
 * Total Submissions: 151.8K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start
int max(int a, int b)
{
    return a >= b ? a : b;
}

int min(int a, int b)
{
    return a <= b ? a : b;
}

int trap(int* height, int heightSize)
{
    int *left = (int *)malloc(heightSize * sizeof(int));
    int *right = (int *)malloc(heightSize * sizeof(int));

    for (int i = 1; i < heightSize; i++)
        left[i] = max(left[i - 1], height[i - 1]);
    
    for (int i = heightSize - 2; i >= 0; i--)
        right[i] = max(right[i + 1], height[i + 1]);

    int water = 0;
    for (int i = 0; i < heightSize; i++) {
        int level = min(left[i], right[i]);
        water += max(0, level - height[i]);
    }

    return water;
}


// @lc code=end

