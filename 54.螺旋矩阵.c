/*
 * @lc app=leetcode.cn id=54 lang=c
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (39.14%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    55.5K
 * Total Submissions: 139.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    if (matrix == NULL || matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = matrixSize * (*matrixColSize);
    int *res = (int *)malloc((*returnSize) * sizeof(int));
    int row = 0, col = -1, num = 0, level = 0;

    while (num < *returnSize) {
        while (col < ((*matrixColSize) - 1 - level)) res[num++] = matrix[row][++col];
        while (row < (matrixSize - 1 - level)) res[num++] = matrix[++row][col];
        if (num == *returnSize) break;
        while (col > level) res[num++] = matrix[row][--col];
        level++;
        while (row > level) res[num++] = matrix[--row][col];
    }
    return res;
}


// @lc code=end

