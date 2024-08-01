class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        
        for (char c : S) {
            if (isdigit(c)) {
                st.push(c - '0');
            } else {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                
                if (c == '+') st.push(num2 + num1);
                else if (c == '-') st.push(num2 - num1);
                else if (c == '*') st.push(num2 * num1);
                else if (c == '/') st.push(num2 / num1);
            }
        }
        
        return st.top();
    }
};