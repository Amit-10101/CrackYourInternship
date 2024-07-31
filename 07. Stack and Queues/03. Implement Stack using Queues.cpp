class MyStack {
public:
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size();

        for (int i = 0; i < n-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if (!q.empty()) {
            int top = q.front();
            q.pop();
            return top;
        }
        return -1;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};