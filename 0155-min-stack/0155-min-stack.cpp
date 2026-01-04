// class MinStack {
// private:
//     stack<pair<int,int>> st;
//     int size;
// public:
//     MinStack() {
//         size = 0;
//     }
    
//     void push(int val) {
//         if(st.empty()) {
//             st.push( {val, val} );
//             return;
//         }
//         st.push({val,min(getMin(),val)});
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */



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
        min_ = min(min_,val);
        st.push({val,min_});
    }
    
    void pop() {
        st.pop();
        if(st.empty()) min_ = INT_MAX;
        else min_ = st.top().second;
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