/*
 * @lc app=leetcode.cn id=1162 lang=c
 *
 * [1162] 地图分析
 *
 * https://leetcode-cn.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (38.49%)
 * Likes:    55
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 29.9K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * 你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1
 * 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
 * 
 * 我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 -
 * x1| + |y0 - y1| 。
 * 
 * 如果我们的地图上只有陆地或者海洋，请返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[[1,0,1],[0,0,0],[1,0,1]]
 * 输出：2
 * 解释： 
 * 海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[[1,0,0],[0,0,0],[0,0,0]]
 * 输出：4
 * 解释： 
 * 海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] 不是 0 就是 1
 * 
 * 
 */

// @lc code=start

typedef struct 
{
    int x;
    int y;
    int level;
} land;

int maxDistance(int** grid, int gridSize, int* gridColSize)
{
    int movex[] = {-1, 0, 1, 0};
    int movey[] = {0, 1, 0, -1};
    int head = 0, tail = 0;
    int tx = 0, ty = 0, tl = 0;
    int dx = 0, dy = 0, flag = 0;
    land *queue = (land *)malloc(gridSize * (*gridColSize) * sizeof(land));

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                queue[tail].x = i;
                queue[tail].y = j;
                queue[tail++].level = 0;
            }
        }
    }

    while (head < tail) {
        tx = queue[head].x;
        ty = queue[head].y;
        tl = queue[head++].level;

        for (int i = 0; i < 4; i++) {
            dx = tx + movex[i];
            dy = ty + movey[i];

            if (dx < 0 || dx >= gridSize || dy < 0 || dy >= *gridColSize)
                continue;

            if (grid[dx][dy] == 0) {
                flag = 1;
                grid[dx][dy] = -1;
                queue[tail].x = dx;
                queue[tail].y = dy;
                queue[tail++].level = tl + 1; 
            }
        }
    }

    return flag == 1 ? tl : -1;
}


// @lc code=end

