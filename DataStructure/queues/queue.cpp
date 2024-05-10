#include <iostream>

using namespace std;
class Node
{
public:
    int data;

    Node *next;
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }
};
class Queue
{
private:
    Node *front;
    Node *rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr){};

    bool isEmpty()
    {
        return front == nullptr;
    }
    void enqueue(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty())
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1; // Indicate error or default value
        }
        int data = front->data;
        Node *temp = front;

        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        free(temp);
        size--;
        return data;
    }

    /**
     * @brief Traverse and print stack
     * @param head
     */
    void printQueue()
    {
        Node *cur = front;

        if (cur == nullptr)
            cout << "Empty List" << endl;
        while (cur != NULL)
        {
            cout << cur->data << endl;
            cur = cur->next;
        }
        free(cur);
        cout << "----------------------------------" << endl;
    }
};

int main()
{
    Queue q = Queue();
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(2);
    q.enqueue(1);
    q.printQueue();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.printQueue();

}