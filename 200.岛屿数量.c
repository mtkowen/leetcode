/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (47.62%)
 * Likes:    434
 * Dislikes: 0
 * Total Accepted:    71.2K
 * Total Submissions: 148.9K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给定一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */

// @lc code=start
typedef struct {
    int x;
    int y;
} queue;

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int count = 0;
    int head = 0, tail = 0;
    int movex[] = {0, 1, 0, -1};
    int movey[] = {1, 0, -1, 0};

    if (!grid || !gridSize || !(*gridColSize))
        return 0;

    queue *obj = (queue *)malloc(gridSize * (*gridColSize) * sizeof(queue));
    if (!obj)
        return 0;
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            head = 0;
            tail = 0;
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                count++;
                obj[tail].x = i;
                obj[tail++].y = j;

                while (head < tail) {
                    int x = obj[head].x;
                    int y = obj[head++].y;

                    for (int i = 0; i < 4; i++) {
                        int dx = x + movex[i];
                        int dy = y + movey[i];

                        if (dx < 0 || dx >= gridSize || dy < 0 || dy >= *gridColSize || grid[dx][dy] == '0')
                            continue;
                        
                        grid[dx][dy] = '0';
                        obj[tail].x = dx;
                        obj[tail++].y = dy;
                    }
                }
            }
        }
    }

    return count;
}


// @lc code=end

