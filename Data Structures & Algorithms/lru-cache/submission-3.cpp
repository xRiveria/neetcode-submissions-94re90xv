struct Node
{
    int m_Key;
    int m_Value;
    Node* m_Next;
    Node* m_Previous;
    
    Node(int k, int v) : m_Key(k), m_Value(v), m_Next(nullptr), m_Previous(nullptr) { }
};

class LRUCache {
public:
    std::unordered_map<int, Node*> hashMap;
    Node* m_Head; // LRU at head. Sentinel.
    Node* m_Tail; // MRU at tail. Sentinel.
    int m_MaxCapacity = 0;
    
    LRUCache(int capacity) {
        m_MaxCapacity = capacity;
        m_Head = new Node(0, 0);
        m_Tail = new Node(0, 0);
        m_Head->m_Next = m_Tail;
        m_Tail->m_Previous = m_Head;
    }
    
    int get(int key) {
        if (hashMap.count(key))
        {
            // Node* points into the gentleman in the Linked List.
            Node* node = hashMap[key];
            RemoveNode(node);
            PushBack(node);
            return node->m_Value;

        }
        else
        {
            return -1;
        }
    }

    // Sentinels are “Fake nodes that guarantee neighbors always exist.”
    // For these two functions, real nodes always exist between our sentinel nodes.
    // Even when m_Head->next = m_Tail, and m_Tail->prev = m_Head, we are safe unless we try deleting a Sentinel node.
    void RemoveNode(Node* node)
    {
        node->m_Previous->m_Next = node->m_Next;
        node->m_Next->m_Previous = node->m_Previous;
    }

    void PushBack(Node* node)
    {
        node->m_Previous = m_Tail->m_Previous;
        node->m_Next = m_Tail;
        m_Tail->m_Previous->m_Next = node;
        m_Tail->m_Previous = node;
    }
    
    void put(int key, int value) {
        if (hashMap.count(key))
        {
            Node* node = hashMap[key];
            node->m_Value = value;
            RemoveNode(node);
            PushBack(node);
        }
        else
        {
            if (hashMap.size() == m_MaxCapacity)
            {
                // LRU is head->next.
                Node* lru = m_Head->m_Next;
                RemoveNode(lru);
                hashMap.erase(lru->m_Key);
                delete lru;
            }
            
            Node* node = new Node(key, value);
            PushBack(node);
            hashMap[key] = node;
        }
    }
};
