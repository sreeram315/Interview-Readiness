// https://leetcode.com/problems/lfu-cache/submissions/
class LFUCache {
    struct Node{
        int key, val, freq;
        Node(int key, int val, int freq): key(key), val(val), freq(freq){}
    };
public:
    int m = 0, capacity, size = 0;
    unordered_map<int, list<Node*>>ll;
    unordered_map<int, list<Node*>::iterator>mp;
    LFUCache(int capacity): capacity(capacity) {}
    
    void increaseFreq(list<Node*>::iterator listItem){
        Node *node = *listItem;
        int key = node->key, val = node->val, freq = node->freq;
        int nextFreq = freq+1, prevFreq = freq;
        ll[prevFreq].erase(listItem);
        if(m==prevFreq && ll[m].size()==0) m++;
        ll[nextFreq].push_front(node);
        node->freq = nextFreq;
        mp[key] = ll[nextFreq].begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        list<Node*>::iterator listItem = mp[key];
        Node *node = *listItem;
        increaseFreq(listItem);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity==0) return;
        if(mp.find(key) != mp.end()){
            increaseFreq(mp[key]);
            (*mp[key])->val = value;
            return;
        }
        if(size+1 > capacity){
            list<Node*>::iterator toBeDeleted = --(ll[m].end());
            Node *node = *toBeDeleted;
            int key = node->key, val = node->val, freq = node->freq;
            mp.erase(key);
            ll[m].pop_back();
            if(ll[m].size()==0) m++;
            size--;
        }
        Node *newNode = new Node(key, value, 0);
        ll[0].push_front(newNode);
        mp[key] = ll[0].begin();
        m = 0;
        size++;
    }
};
