/*
 * @lc app=leetcode.cn id=460 lang=c
 *
 * [460] LFU缓存
 *
 * https://leetcode-cn.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (34.39%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    3.1K
 * Total Submissions: 9K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * 设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。
 * 
 * get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
 * put(key, value) -
 * 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。
 * 
 * 进阶：
 * 你是否可以在 O(1) 时间复杂度内执行两项操作？
 * 
 * 示例：
 * 
 * 
 * LFUCache cache = new LFUCache( 2 /* capacity (缓存容量) */ );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回 1
 * cache.put(3, 3);    // 去除 key 2
 * cache.get(2);       // 返回 -1 (未找到key 2)
 * cache.get(3);       // 返回 3
 * cache.put(4, 4);    // 去除 key 1
 * cache.get(1);       // 返回 -1 (未找到 key 1)
 * cache.get(3);       // 返回 3
 * cache.get(4);       // 返回 4
 * 
 */

// @lc code=start

typedef struct LFUCache {
    int key;
    int value;
    int used;
    int time;
} LFUCache;

int cmp(const void *a, const void *b)
{
    LFUCache *p1 = (LFUCache *)a;
    LFUCache *p2 = (LFUCache *)b;
    if(p1->used != p2->used)
        return p1->used - p2->used;
    else
        return p2->time - p1->time;
}

LFUCache* lFUCacheCreate(int capacity)
{
    LFUCache *obj = (LFUCache *)calloc(capacity + 1, sizeof(LFUCache)); //空出obj[0]用来存缓冲区最大容量和当前容量
    obj->time = capacity;
    return obj;
}

int lFUCacheGet(LFUCache* obj, int key)
{
    int ans = -1;
    for(int i = 1;i <= obj[0].used; i++) {
        obj[i].time += 1;
        if(obj[i].key == key) {
            obj[i].used += 1;
            obj[i].time = 0;
            ans = obj[i].value;
        }
    }
    return ans;
}

void lFUCachePut(LFUCache* obj, int key, int value)
{
   int flag = 1;

    if(obj[0].time == 0)
        return;

    for (int i = 1; i <= obj[0].used; i++) {
        obj[i].time += 1;
        if(obj[i].key == key) {
            obj[i].value = value;
            obj[i].used += 1;
            obj[i].time = 0;
            flag = 0;
        }
    }

    if(flag) {
        if(obj[0].used >= obj[0].time) {
            qsort(obj + 1, obj[0].used, sizeof(LFUCache), cmp);
            obj[1].key = key;
            obj[1].value = value;
            obj[1].used = 1;
            obj[1].time = 0;
        } else {
            obj[0].used += 1; // 缓冲区大小加1
            obj[obj[0].used].key = key;
            obj[obj[0].used].value =value;
            obj[obj[0].used].used = 1;
            obj[obj[0].used].time = 0;
        }
    }
}

void lFUCacheFree(LFUCache* obj)
{
    free(obj);
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/
// @lc code=end

