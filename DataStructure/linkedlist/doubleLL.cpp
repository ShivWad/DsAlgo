#include <iostream>
using namespace std;
/**
 * @brief Doubly Linked list node
 *
 */
class DllNode
{
public:
    DllNode *prev;
    DllNode *next;
    int data;
    /**
     * @brief Construct a new Dll Node object
     *
     * @param data
     */
    DllNode(int data)
    {
        prev = nullptr;
        next = nullptr;
        this->data = data;
    }
    /**
     * @brief Construct a new Dll Node object
     *
     */
    DllNode()
    {
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    DllNode *head;

public:
    /**
     * @brief Construct a new Doubly Linked List object
     *
     */
    DoublyLinkedList() : head(nullptr){};

    /**
     * @brief Get the Head of the DLL
     *
     * @return DllNode*
     */
    DllNode *getHead()
    {
        return head;
    }

    /**
     * @brief Checks if the list is empty
     *
     * @return true
     * @return false
     */
    bool isEmpty()
    {
        if (head == nullptr)
            return true;
        else
            return false;
    }

    /**
     * @brief Insert at the beginning of the DLL
     *
     * @param data
     */
    void insertAtBegin(int data)
    {
        DllNode *temp = new DllNode(data);
        if (isEmpty())
        {
            head = temp;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    /**
     * @brief Prints list
     *
     */
    void traverseDll()
    {
        if (isEmpty())
        {
            cout << "EMPTY LIST" << endl;
            return;
        }
        DllNode *curr = head;
        int counter = 1;
        while (curr != nullptr)
        {
            cout << counter << ". " << curr->data << endl;
            curr = curr->next;
            counter++;
        }

        cout << "----------------------------------" << endl;
    }

    /**
     * @brief Insert at the end of the list
     *
     * @param data
     */
    void insertAtEnd(int data)
    {
        DllNode *temp = new DllNode(data);
        if (isEmpty())
        {
            cout << "EMPTY LIST, inserted though" << endl;
            head = temp;
            return;
        }
        auto curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }

    /**
     * @brief Insert at the given position
     *
     * @param data
     * @param position
     */
    void insertAtPoistion(int data, int position)
    {
        DllNode *temp = new DllNode(data);
        if (isEmpty())
        {
            cout << "EMPTY LIST" << endl;
            return;
        }

        if (position <= 1)
        {
            free(temp);
            insertAtBegin(data);
            return;
        }
        position--; // if not this, then position 3 will put data at 4th. ik 0 based indexed is a thing. but this is asthetics.

        auto curr = head;
        while (--position && curr != nullptr)
        {
            curr = curr->next;
        }
        if (curr == nullptr)
        {
            cout << "Invalid position" << endl;
            return;
        }
        temp->next = curr->next;
        temp->prev = curr;
        curr->next = temp;
    }

    /**
     * @brief Deletes the first node
     *
     */
    void deleteFirst()
    {
        if (isEmpty())
        {
            cout << "EMPTY LIST" << endl;
            return;
        }
        // Handle single node list (list becomes empty)
        if (head->next == nullptr)
        {
            free(head);
            head = nullptr;
            return;
        }
        DllNode *temp = head->next;
        temp->prev = nullptr;
        head = temp;
        free(temp);
    }

    /**
     * @brief Deletes the last node
     *
     */
    void deleteAtEnd()
    {
        if (isEmpty())
        {
            cout << "EMPTY LIST" << endl;
            return;
        }
        // Handle single node list (list becomes empty)
        if (head->next == nullptr)
        {
            free(head);
            head = nullptr;
            return;
        }

        DllNode *curr = head;
        while (curr->next != nullptr)
            curr = curr->next;

        curr->prev->next = nullptr;
        free(curr);
    }

    /**
     * @brief Delete at a specific position
     *
     * @param position
     */
    void deleteAtPosition(int position)
    {
        if (isEmpty())
        {
            cout << "EMPTY LIST" << endl;
            return;
        }
        // Handle single node list deletion (position 1)
        if (position <= 1)
        {
            deleteFirst();
            return;
        }
        DllNode *curr = head;
        DllNode *prev = nullptr;
        while (--position && curr != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Invalid position" << endl;
            return;
        }
        prev->next = curr->next;
        curr->next->prev = prev;
        free(prev);
        free(curr);
    }
};

/// @brief main function
/// @return int
int main()
{
    DoublyLinkedList dll = DoublyLinkedList();
    dll.insertAtBegin(30);
    dll.insertAtBegin(40);
    dll.insertAtEnd(10);
    dll.insertAtEnd(110);
    dll.insertAtPoistion(123, 2);
    dll.traverseDll();
    dll.deleteAtPosition(0);
    dll.traverseDll();
}

// 1. 40
// 2. 123
// 3. 30
// 4. 10
// 5. 110