class MinStack {
public:
    int mini;
    stack<int> st;
    stack<int> minStack;

    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(val<=mini){
        mini = val;
        minStack.push(mini);
        }

        st.push(val);
    }
    
    void pop() {
        if(!st.empty()){

        if(!minStack.empty() and minStack.top()==st.top()){
            minStack.pop();
            if(!minStack.empty()){
            mini = minStack.top();
            }
            else
            mini = INT_MAX;
        }

        st.pop();
        }

        return;
    }
    
    int top() {
        
        return st.top();
        
    }
    
    int getMin() {
        return mini;
    }
};
