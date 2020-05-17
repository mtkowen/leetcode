/*
 * @lc app=leetcode.cn id=820 lang=c
 *
 * [820] 单词的压缩编码
 *
 * https://leetcode-cn.com/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (40.93%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    30.1K
 * Total Submissions: 62.3K
 * Testcase Example:  '["time", "me", "bell"]'
 *
 * 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
 * 
 * 例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes =
 * [0, 2, 5]。
 * 
 * 对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
 * 
 * 那么成功对给定单词列表进行编码的最小字符串长度是多少呢？
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: words = ["time", "me", "bell"]
 * 输出: 10
 * 说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 7
 * 每个单词都是小写字母 。
 * 
 * 
 */

// @lc code=start

#define WORD_MAX_NUM 2000

int cmp(const void *a, const void *b)
{
    return strlen(*(const char **)b) - strlen(*(const char **)a);
}

int minimumLengthEncoding(char ** words, int wordsSize)
{
    int flag[WORD_MAX_NUM] = {0};
    int total = 0;
    char *find = NULL;

    qsort(words, wordsSize, sizeof(char *), cmp);

    for(int i = 0; i < wordsSize; i++) {
        if (flag[i] == 1)
            continue;

        int ilen = strlen(words[i]);
        total +=  ilen + 1;
        for(int j = i + 1; j < wordsSize; j++) {
            int jlen = strlen(words[j]);
            find = strstr(words[i] + ilen - jlen, words[j]);
            if (find != 0)
                flag[j] = 1;
        }
    }

    return total;
}

// @lc code=end

