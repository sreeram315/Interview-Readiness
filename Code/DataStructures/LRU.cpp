// https://leetcode.com/problems/lru-cache/submissions/
class LRUCache {
public:
    int capacity, size;
    list<int>ls;
    unordered_map<int, pair<int, list<int>::iterator>>mp;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            if(*ls.begin() != key){
                list<int>::iterator itr = mp[key].second;
                ls.erase(itr);
                ls.push_front(key);
                mp[key] = {mp[key].first, ls.begin()};
            }
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
            ls.erase(mp[key].second);
        else
            size++;
        ls.push_front(key);
        mp[key] = {value, ls.begin()};
        if(size > capacity){
            list<int>::iterator itr = --(ls.end());
            mp.erase(*itr);
            ls.pop_back();
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */