struct Node
{
    Node* next;
    int value;

    Node(int val) { value = val; next = nullptr; }
};

class MyCircularQueue {
public:
    Node* front = nullptr;
    Node* rear = nullptr;
    int maxCapacity = 0;
    int currentCapacity = 0;

    MyCircularQueue(int k) {
        maxCapacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
            rear->next = front; // Circular
        }
        else
        {
            // Insert to the left of the 
            newNode->next = front; // New node is to be the rear. Connect this to the front.
            rear->next = newNode; // Current rear's next node is the new node.
            rear = newNode; // New node is the rear now..
        }
        currentCapacity++;
        return true;
    }
    
    bool deQueue() {
       if (isEmpty()) return false;
       if (currentCapacity == 1)
       {
            delete front;
            front = rear = nullptr;
       }
       else
       {
        // It is a queue. We pop from the front.
        Node* temp = front;
        front = front->next; 
        rear->next = front;
        delete temp;
       }

       currentCapacity--;
       return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return front->value;
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return rear->value;
    }
    
    bool isEmpty() {
        return (currentCapacity == 0);
    }
    
    bool isFull() {
        return (currentCapacity == maxCapacity);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */