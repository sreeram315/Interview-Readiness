class MinStack {
public:
    /** initialize your data structure here. */
    long m;
    stack<long>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            m = val;
            st.push(val);
            return;
        }
        if(val > m){
            st.push(val);
        }else{
            st.push(2*(long)val - m);
            m = val;
        }
    }
    
    void pop() {
        if(st.top() <= m)
            m = 2*m - st.top();
        st.pop();
    }
    
    int top() {
        return (st.top() > m) ? st.top() : m;
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */