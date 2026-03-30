/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    std::unordered_map<Node*, Node*> m_Values; // Old to New
    //Node m_MasterHead; // Return m_MasterHead.next as the start.
    //Node* m_Head = &m_MasterHead;

    Node* copyRandomList(Node* head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        if (m_Values.count(head))
        {
            return m_Values[head];
        }

        Node* newNode = new Node(head->val);
        m_Values[head] = newNode;
        newNode->next = copyRandomList(head->next);
        if (head->random != nullptr)
        {
            newNode->random = m_Values[head->random];
        }

        return newNode;

        /*
        Node m_MasterHead(0);
        Node* m_Head = &m_MasterHead;

        while (head != nullptr)
        {
            m_Head->next = new Node(head->val);
            m_Head = m_Head->next;
            m_Values[head] = m_Head;
            head = head->next;
        }

        for (auto& value : m_Values)
        {
            if (value.first->random != nullptr)
            {
                value.second->random = m_Values[value.first->random]; 
            }
        }

        return m_MasterHead.next;
        */
    }
};
