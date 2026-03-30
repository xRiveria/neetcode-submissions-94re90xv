struct ListNode
{
    int key;
    int val;
    ListNode* next;
    ListNode* previous;
    ListNode(int k, int v) : key(k), val(v), next(nullptr), previous(nullptr) {}
};

class LRUCache {
public:
    std::unordered_map<int, ListNode*> m_HashMap;
    // Head and Tail surrounds our main list.
    ListNode* m_Head;
    ListNode* m_Tail;
    int m_TotalCapacity = 0;

    LRUCache(int capacity) {
        m_TotalCapacity = capacity;
        m_Head = new ListNode(0, 0);
        m_Tail = new ListNode(0, 0);
        m_Head->next = m_Tail;
        m_Tail->previous = m_Head;
    }

    void RemoveNode(ListNode* node)
    {
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }

    void PushBack(ListNode* node)
    {
        // Note that tail is always at the end.
        node->previous = m_Tail->previous;
        node->next = m_Tail;
        m_Tail->previous->next = node;
        m_Tail->previous = node;
    }
    
    int get(int key) {
        if (!m_HashMap.count(key))
        {
            return -1;
        }

        ListNode* node = m_HashMap[key];
        RemoveNode(node);
        PushBack(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (m_HashMap.count(key))
        {
            ListNode* node = m_HashMap[key];
            node->val = value;
            RemoveNode(node);
            PushBack(node);
        }
        else
        {
            if ((int)m_HashMap.size() == m_TotalCapacity)
            {
                // LRU is head->next;
                ListNode* lru = m_Head->next;
                RemoveNode(lru);
                m_HashMap.erase(lru->key);
                delete lru;
            }

            ListNode* node = new ListNode(key, value);
            PushBack(node);
            m_HashMap[key] = node;
        }
    }
};
