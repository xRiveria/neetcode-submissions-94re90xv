class MinStack {
public:
    std::stack<long> m_Stack;
    long m_MinimumValue = 0;

    MinStack() {
        
    }
    
    void push(int val) {
        if (m_Stack.empty())
        {
            m_Stack.push(0);
            m_MinimumValue = val;
        }
        else
        {
            m_Stack.push(val - m_MinimumValue);
            if (val < m_MinimumValue) m_MinimumValue = val;
        }
    }
    
    void pop() {
        if (m_Stack.empty())
        {
            return;
        }

        long topValue = m_Stack.top();
        m_Stack.pop();

        if (topValue < 0) { m_MinimumValue = m_MinimumValue - topValue; }
    }
    
    int top() {
        long topValue = m_Stack.top();
        long returnValue = topValue > 0 ? m_Stack.top() + m_MinimumValue : m_MinimumValue;
        return (int)returnValue;
    }
    
    int getMin() {
        return (int)m_MinimumValue;
    }
};
