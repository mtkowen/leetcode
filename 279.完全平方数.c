/*
 * @lc app=leetcode.cn id=279 lang=c
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (54.89%)
 * Likes:    364
 * Dislikes: 0
 * Total Accepted:    47.9K
 * Total Submissions: 86.6K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */

// @lc code=start

typedef struct {
    int a;
} queue;


int numSquares(int n)
{
    int steps = 0;
    int head = 0, tail = 0;
    int *visited = (int *)malloc(n * sizeof(int));
    queue *obj = (queue *)malloc(n * sizeof(queue));

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    obj[tail++].a = 0;
    visited[0] = 1;

    while (head < tail) {
        steps++;
        int size = tail - head;
        for (int i = 0; i < size; i ++) {
            for (int j = 1; j * j <= n; j++) {
                int next = obj[head].a + j * j;

                if (next == n) return steps;
                if (next > n) break;
                if (visited[next]) continue;

                visited[next] = 1;
                obj[tail++].a = next;
            }
            head++;
        }
    }
    return steps;
}


// @lc code=end

