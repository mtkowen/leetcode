/*
 * @lc app=leetcode.cn id=739 lang=c
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (59.32%)
 * Likes:    283
 * Dislikes: 0
 * Total Accepted:    42.1K
 * Total Submissions: 70K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize)
{
    int top = 0;
    int *res = (int *)malloc(TSize * sizeof(int));
    int stack[TSize + 1];

    *returnSize = TSize;
    for (int i = TSize - 1; i >= 0; i--) {
        while (top && T[stack[top]] <= T[i])
            top--;
        
        res[i] = (top == 0) ? 0 : (stack[top] - i);
        stack[++top] = i;
    }

    return res;
}


// @lc code=end

