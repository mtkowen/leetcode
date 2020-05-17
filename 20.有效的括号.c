/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (41.18%)
 * Likes:    1507
 * Dislikes: 0
 * Total Accepted:    251K
 * Total Submissions: 606.9K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start

bool isValid(char * s)
{
    //空字符串显然符合
    if (*s == 0)
        return true;

    int len = strlen(s);

    //奇数长度的字符串显然不符合
    if(len & 1) return false;

    char stack[len];
    int top = -1;
    for (int i = 0; i < len; ++i) {
        //如果是左括号们，欢迎入栈
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[++top] = s[i];
        //不是左括号们，如果栈空则无法配对，不符合
        else if (top == -1)
            return false;
        //不是左括号们，栈非空，当前和栈顶配对，符合
        else if(s[i] == stack[top] + 1 || s[i] == stack[top] + 2)
            stack[top--] = 0;
        //不是左括号们，栈非空，当前和栈顶不配对，不符合
        else 
            return false;
    }

    //最后栈为空则符合，不为空则不符合
    return top == -1;
}

// @lc code=end

