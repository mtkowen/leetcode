/*
 * @lc app=leetcode.cn id=95 lang=c
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (60.58%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    20.7K
 * Total Submissions: 33.6K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int GetTreesNum(int n)
{
    int i, j;   
    int *p = NULL;
    
    if (n <= 0) {
        return 1;
    }
    
    p = (int *)malloc((n + 1) * sizeof(int));  
    if (p == NULL)
        return 0;

    memset(p, 0, (n + 1) * sizeof(int));
    
    p[0] = 1;
    p[1] = 1;
    
    for (i = 2; i <= n; i++) {
        for (j = 0; j < i; j++) {
            p[i] += p[j] * p[i - j - 1];
        }
    }
    
    return p[n];
}

struct TreeNode** generate_Trees(int start, int end, int size, int *num)
{
    *num = 0;
    
    if (start > end) {
        struct TreeNode** all_trees = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        all_trees[0] = NULL;
        *num = 1;
        return all_trees;
    }
    
    struct TreeNode** all_trees = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * size);
    for (int i = start; i <= end; i++) {
        int left_num;
        struct TreeNode** left_trees = generate_Trees(start, i - 1, size, &left_num);
        
        int right_num;
        struct TreeNode** right_trees = generate_Trees(i + 1, end, size, &right_num);
        
        for (int j = 0; j < left_num; j++) {
            int base = *num + j * right_num;
            for (int k = 0; k < right_num; k++) {
                int idx = base + k;
                all_trees[idx] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                all_trees[idx]->val = i;
                all_trees[idx]->left = left_trees[j];
                all_trees[idx]->right = right_trees[k];
            }
        }
        *num += left_num * right_num;
        free(left_trees);
        free(right_trees);
    }
    return all_trees;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** generateTrees(int n, int* returnSize)
{
    struct TreeNode** res = NULL;
    int size;
    
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    size = GetTreesNum(n);
    res = generate_Trees(1, n, size, returnSize);
    
    return res;
}

// @lc code=end

