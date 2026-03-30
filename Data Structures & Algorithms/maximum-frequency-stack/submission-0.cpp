class FreqStack {
public:
    std::unordered_map<int, int> frequency;
    std::vector<int> freStack;
    FreqStack() {
        
    }
    
    void push(int val) {
        frequency[val]++;
        freStack.push_back(val);
    }
    
    int pop() {
        // Find most frequent element.
        int maxCount = -1;
        for (auto& p : frequency)
        {
            maxCount = std::max(maxCount, p.second);
        }

        int i = freStack.size() - 1;
        while (frequency[freStack[i]] != maxCount)
        {
            i--;
        }
        int val = freStack[i];
        freStack.erase(freStack.begin() + i); // Delete this element.
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