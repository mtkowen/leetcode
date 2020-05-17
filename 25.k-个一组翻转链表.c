/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (57.08%)
 * Likes:    527
 * Dislikes: 0
 * Total Accepted:    62.8K
 * Total Submissions: 104.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverse(struct ListNode *curr)
{
    struct ListNode prev;
    prev.next = NULL;

    while (curr) {
        struct ListNode *tmp = curr->next;
        curr->next = prev.next;
        prev.next = curr;
        curr = tmp;
    }

    return prev.next;
}

struct ListNode* reverseKGroup(struct ListNode* link, int k)
{
    struct ListNode p;
    struct ListNode *prev = &p;
    struct ListNode *tail = &p;

    prev->next = link;

    while (tail) {
        for (int i = 0; i < k; i++) { // 分组
            tail = tail->next;
            if(!tail) return p.next;
        }

        struct ListNode *curr = prev->next;
        struct ListNode *next = tail->next;
        tail->next = NULL;
        prev->next = reverse(curr); //翻转
        // 链接每一组结果
        curr->next = next;
        // 计算下一组
        prev = curr;
        tail = prev;
    }

    return p.next;
}

// @lc code=end

