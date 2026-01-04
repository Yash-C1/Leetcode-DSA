class MyStack {
private:
    queue<int> q;
    int size;

public:
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<size;i++){
            int temp = q.front();
            q.push(temp);
            q.pop();
        }
        size++;
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        size--;
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return size==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */