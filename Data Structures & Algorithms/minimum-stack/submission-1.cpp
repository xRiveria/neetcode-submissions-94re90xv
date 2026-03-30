class MinStack {
public:
    std::stack<int> m_Stack;
    std::stack<int> m_MinimumStack;

    MinStack() {
        
    }
    
    void push(int val) {
        m_Stack.push(val);
        if (!m_MinimumStack.empty())
        {
            int smallestValue = std::min(val, m_MinimumStack.top());
            m_MinimumStack.push(smallestValue); 
        }
        else
        {
            m_MinimumStack.push(val);
        }
    }
    
    void pop() {
        m_Stack.pop();
        m_MinimumStack.pop();
    }
    
    int top() {
        return m_Stack.top();
    }
    
    int getMin() {
       return m_MinimumStack.top();
    }
};
