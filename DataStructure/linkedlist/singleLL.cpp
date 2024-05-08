#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(Node *node)
    {
        this->data = node->data;
        this->next = node->next;
    }
};

class LinkedList
{

private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    Node *getHead()
    {
        return head;
    }

    /**
     * @brief checks if the LL is empty
     *s
     * @param head
     * @return true
     * @return false
     */
    bool isEmpty()
    {
        return this->head == NULL;
    }

    /**
     * @brief Traverse and print Linked list
     * @param head
     */
    void traverseLinkedList()
    {
        Node *cur = this->head;
        if (cur == NULL)
            cout << "Empty List";
        while (cur != NULL)
        {
            cout << cur->data << endl;
            cur = cur->next;
        }
    }

    /**
     * @brief Insert at the beginning of the Linked list
     *
     * @param data data
     * @param head head node
     * @return Node* head
     */
    Node *insertAtBeginning(int data)
    {
        Node *temp = new Node(data);

        if (this->head == NULL)
        {
            this->head = temp;
        }
        else
        {
            temp->next = this->head;
            this->head = temp;
        }

        return this->head;
    }

    /**
     * @brief Insert at the end of the Linked list
     * @param data data
     * @param head head node
     * @return Node*
     */
    Node *insertAtTheEnd(int data)
    {
        Node *curr = this->head;
        Node *newNode = new Node(data);
        if (curr == NULL)
        {
            this->head = newNode;
            return this->head;
        }
        while (curr->next != NULL)
            curr = curr->next;

        curr->next = newNode;

        return this->head;
    }

    /**
     * @brief Insert new node at the given position
     * @param data
     * @param head
     * @param position
     * @return Node*
     */
    Node *insertAtPosition(int data, int position)
    {
        Node *pred = this->head;
        Node *newNode = new Node(data);
        if (position <= 1)
        {
            newNode->next = this->head;
            return newNode;
        }
        while (--position && pred != NULL)
        {
            pred = pred->next;
        }
        if (pred == NULL)
        {
            cout << "Invalid position";
            return NULL;
        }
        newNode->next = pred->next;
        pred->next = newNode;
        return this->head;
    }

    /**
     * @brief Delete the first item of the node.
     *
     * @param head
     * @return Node*
     */
    Node *deleteFirst()
    {
        if (this->head == NULL)
        {
            cout << "LIST EMPTY";
            return NULL;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        free(temp);
        return this->head;
    }

    Node *deleteLast()
    {
        if (this->head == NULL)
        {
            cout << "LIST EMPTY";
            return NULL;
        }
        Node *temp = NULL;
        Node *curr = this->head;
        while (curr->next != NULL)
        {
            temp = curr;
            curr = curr->next;
        }
        temp->next = NULL;
        free(curr);
        return this->head;
    }
    /**
     * @brief Delete at given position
     *
     * @param head
     * @param position
     * @return Node*
     */
    Node *deleteAtPosition(int position)
    {
        if (this->head == NULL)
        {
            cout << "LIST EMPTY";
            return NULL;
        }
        // Handle deletion of the head node (position 1)
        if (position == 1)
        {
            Node *temp = this->head;
            this->head = this->head->next;
            delete temp;
            return this->head;
        }

        Node *pred = this->head;
        Node *temp = pred;
        while (--position && pred != NULL)
        {
            temp = pred;
            pred = pred->next;
        }

        if (pred == NULL)
        {
            cout << "Wrong Position error" << endl;
            return NULL;
        }
        temp->next = pred->next;
        free(pred);
        return this->head;
    }
};

/// @brief main function
/// @return int
int main()
{
    LinkedList linkedList = LinkedList();
    linkedList.insertAtBeginning(1);
    linkedList.insertAtBeginning(5);
    linkedList.insertAtTheEnd(3);
    linkedList.deleteAtPosition(2);
    linkedList.traverseLinkedList();
    Node *head = linkedList.getHead();
}