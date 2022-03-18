class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>>mn;
    priority_queue<int>mx;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.empty() || num <= mx.top())
            mx.push(num);
        else
            mn.push(num);
        if(mx.size() != mn.size() && (mx.size()-1 != mn.size())){
            if(mx.size() > mn.size()){
                mn.push(mx.top()); mx.pop();
            }else{
                mx.push(mn.top()); mn.pop();
            }
        }
    }
    
    double findMedian() {
        if(mx.size() == mn.size())
            return (double)(mx.top()+mn.top())/2;
        return (double)(mx.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */