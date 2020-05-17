/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.46%)
 * Likes:    655
 * Dislikes: 0
 * Total Accepted:    115.3K
 * Total Submissions: 152.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dfs(int *nums, int numsSize, int *returnSize, int pos, int **res)
{
    if (pos == numsSize) {
        for (int i = 0; i < numsSize; i++)
            res[*returnSize][i] = nums[i];
        (*returnSize)++;
        return;
    }

    for (int i = pos; i < numsSize; i++) {
        swap(nums + pos, nums + i);
        dfs(nums, numsSize, returnSize, pos + 1, res);
        swap(nums + pos, nums + i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int n = 1;
    int **res;

    for (int i = 1; i <= numsSize; i++)
        n *= i;
    
    res = (int **)malloc(n * sizeof(int *));
    *returnColumnSizes = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        res[i] = (int *)malloc(numsSize * sizeof(int));
        (*returnColumnSizes)[i] = numsSize;
    }

    *returnSize = 0;
    dfs(nums, numsSize, returnSize, 0, res);

    return res;
}


// @lc code=end

