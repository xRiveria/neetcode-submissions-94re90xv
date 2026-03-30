class MedianFinder {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_MinHeap; // Smallest elements at the top.
    std::priority_queue<int> m_MaxHeap; // Biggest elements at the top.
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (!m_MinHeap.empty() && num > m_MinHeap.top()) // If the value is greater than the smallest element in the min heap, we put it in the min heap.
        {
            m_MinHeap.push(num);
        }
        else if (!m_MinHeap.empty() && num <= m_MinHeap.top())
        {
            m_MaxHeap.push(num);
        }
        else
        {
            m_MinHeap.push(num);
            return;
        }

        while (std::abs((int)m_MaxHeap.size() - (int)m_MinHeap.size()) >= 2)
        {
            int maxHeapSize = m_MaxHeap.size();
            int minHeapSize = m_MinHeap.size();
            if (minHeapSize > maxHeapSize)
            {
                int val = m_MinHeap.top();
                m_MinHeap.pop();
                m_MaxHeap.push(val);
            }
            else
            {
                int val = m_MaxHeap.top();
                m_MaxHeap.pop();
                m_MinHeap.push(val);
            }
        }
    }
    
    double findMedian() {
        if (m_MaxHeap.size() != m_MinHeap.size())
        {
            if (m_MaxHeap.size() > m_MinHeap.size())
            {
                return m_MaxHeap.top();
            }
            else
            {
                return m_MinHeap.top();
            }
        }
        else
        {
            return (((double)m_MaxHeap.top() + m_MinHeap.top()) / 2.0);
        }
    }
};
