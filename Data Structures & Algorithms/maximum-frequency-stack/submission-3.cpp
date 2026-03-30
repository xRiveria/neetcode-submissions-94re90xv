class FreqStack {
public:
    std::unordered_map<int, int> frequency;
    std::priority_queue<std::vector<int>> vals; // Max heap by default.
    int index = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        frequency[val]++;
        // Use the 
        vals.push({ frequency[val], index++, val }); // If frequency[val] ties, we rely on index to determine sorting order.
    }
    
    int pop() {
        auto top = vals.top(); // Most frequent.
        vals.pop();
        int val = top[2];
        frequency[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */