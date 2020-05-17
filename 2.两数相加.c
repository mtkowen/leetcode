/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.31%)
 * Likes:    3683
 * Dislikes: 0
 * Total Accepted:    293.5K
 * Total Submissions: 808.2K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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

struct ListNode *node(void)
{
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));

    if (p != NULL) {
        p->val = 0;
        p->next = NULL;
    }

    return p;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry = 0;
    int sum;
    struct ListNode* head = node();
    struct ListNode* tail;
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;

    tail = head;
    
    while ((p1 != NULL) || (p2 != NULL)) {
        int x = (p1 == NULL) ? 0 : (p1->val);
        int y = (p2 == NULL) ? 0 : (p2->val);
        sum = x + y + carry;
        carry = sum / 10;
        tail->val = sum % 10;
        
        if (p1 != NULL)
            p1 = p1->next;
        if (p2 != NULL)
            p2 = p2->next;
        if (p1 == NULL && p2 == NULL)
            break;
        
        tail->next = node();
        tail = tail->next;
    };
    
    if (carry == 1) {
        tail->next = node();
        tail = tail->next;
        tail->val = 1;
    }
    
    return head;
}


// @lc code=end

