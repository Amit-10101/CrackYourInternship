class twoStacks {
private:
    vector<int> arr;
    int i;
    int j;

public:
    twoStacks() : arr(200, 0), i(-1), j(99) {}

    // Function to push an integer into the stack1.
    void push1(int x) {
        arr[++i] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        arr[++j] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if (i == -1) return -1; 
        return arr[i--];
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if (j == 99) return -1;
        return arr[j--];
    }
};