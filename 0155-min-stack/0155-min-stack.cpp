class MinStack {
private:
    stack<pair<int,int>> st;
    int min_;
    int size;
public:
    MinStack() {
        min_ = INT_MAX;
        size = 0;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push( {val, val} );
            return;
        }
        min_ = min(getMin(),val);
        st.push({val,min_});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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