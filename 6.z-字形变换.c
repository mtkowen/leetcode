/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (46.12%)
 * Likes:    537
 * Dislikes: 0
 * Total Accepted:    89.3K
 * Total Submissions: 192.7K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 *
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 *
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 *
 *
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 *
 * 请你实现这个将字符串进行指定行数变换的函数：
 *
 * string convert(string s, int numRows);
 *
 * 示例 1:
 *
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 *
 *
 * 示例 2:
 *
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 *
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 *
 */

// @lc code=start


char *convert(char *s, int numRows)
{
    if (strlen(s) == 0 || numRows <= 0) {
        return "";
    }

    int i, k, dis;
    int j = 0;
    int step = 2 * (numRows - 1);
    int len = strlen(s);
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    /* numRows为1时, step=1 */
    step = (numRows == 1) ? 1 : step;

    /* 按照每层进行遍历 */
    for (i = 0; i < numRows; i++) {
        k = i;
        dis = 2 * i;
        /* 不同步进代码进行归一处理 */
        while (k < len) {
            res[j++] = s[k];
            dis = step - dis;
            k += (i == 0 || i == numRows - 1) ? step : dis;
        }
    }
    res[j] = '\0';
    return res;
}


// @lc code=end

