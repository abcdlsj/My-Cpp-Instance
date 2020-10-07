/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    map<int, list<pair<int, int>>::iterator> map;
public:
    LRUCache(int capacity) : cap(capacity) {
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        auto ele = *map[key];
        cache.erase(map[key]);
        cache.push_front(ele);
        map[key] = cache.begin();
        return map[key]->second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);

        if (it != map.end()) {
            cache.erase(map[key]);
        }

        if (cap == cache.size()) {
            auto bk = cache.back();
            map.erase(bk.first);
            cache.pop_back();
        }

        cache.push_front(make_pair(key, value));
        map[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

