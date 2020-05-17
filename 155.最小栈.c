/*
 * @lc app=leetcode.cn id=155 lang=c
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (52.13%)
 * Likes:    440
 * Dislikes: 0
 * Total Accepted:    91.1K
 * Total Submissions: 173.7K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) —— 将元素 x 推入栈中。
 * pop() —— 删除栈顶的元素。
 * top() —— 获取栈顶元素。
 * getMin() —— 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */

// @lc code=start

#define MAX_SIZE 5000

typedef struct {
    int *data;
    int top
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() 
{
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->data = (int *)malloc(MAX_SIZE * sizeof(int));
    obj->top = -1;

    return obj;
}

void minStackPush(MinStack* obj, int x)
{
    if (obj->top == MAX_SIZE - 1)
        return;

    obj->top++;
    obj->data[obj->top] = x;
}

void minStackPop(MinStack* obj)
{
    if (obj->top == -1)
        return;
    
    obj->top--;
}

int minStackTop(MinStack* obj)
{
    if (obj->top == -1)
        return 0;
    
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) 
{
    if(obj->top == -1)
        return 0;

    int min = obj->data[obj->top];
    for (int i = obj->top; i > -1; i--)
        if (min > obj->data[i])
            min = obj->data[i];

    return min;
}

void minStackFree(MinStack* obj)
{
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
// @lc code=end

