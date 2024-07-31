class Stack {
private:
    deque<int> deque;

public:
    void push(int value) {
        deque.push_back(value);
    }

    void pop() {
        if (!deque.empty()) {
            deque.pop_back();
        } else {
            cerr << "Stack is empty, cannot pop." << endl;
        }
    }

    int top() {
        if (!deque.empty()) {
            return deque.back();
        } else {
            cerr << "Stack is empty, no top element." << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return deque.empty();
    }
};

class Queue {
private:
    deque<int> deque;

public:
    void push(int value) {
        deque.push_back(value);
    }

    void pop() {
        if (!deque.empty()) {
            deque.pop_front();
        } else {
            cerr << "Queue is empty, cannot dequeue." << endl;
        }
    }

    int front() {
        if (!deque.empty()) {
            return deque.front();
        } else {
            cerr << "Queue is empty, no front element." << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return deque.empty();
    }
};