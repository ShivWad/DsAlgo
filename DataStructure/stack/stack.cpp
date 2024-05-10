#include <iostream>

using namespace std;

class EmptyStackException : public exception
{
private:
    string message;

public:
    // Constructor accepts a const char* that is used to set
    // the exception message
    EmptyStackException(const char *msg)
        : message(msg)
    {
    }

    const char *what() const throw()
    {
        return message.c_str();
    }
};

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
class stack
{
private:
    Node *top;
    int size;

public:
    stack() : top(nullptr), size(0){};

    /**
     * @brief Traverse and print stack
     * @param head
     */
    void printStack()
    {
        Node *cur = top;

        if (cur == NULL)
            cout << "Empty List" << endl;
        while (cur != NULL)
        {
            cout << cur->data << endl;
            cur = cur->next;
        }

        cout << "----------------------------------" << endl;
    }

    /**
     * @brief Checks if stack is empty
     *
     * @return true
     * @return false
     */
    bool isEmpty()
    {
        if (top == nullptr)
            return true;
        return false;
    }

    /**
     * @brief Peek the last inserted element without removing
     *
     * @return int
     */
    int peek()
    {
        try
        {
            if (isEmpty())
            {
                throw EmptyStackException("This is a custom exception");
            }

            return top->data;
        }
        catch (EmptyStackException e)
        {
            cout << e.what() << endl;
        }
    }

    /**
     * @brief Removes and returns the last inserted element in the stack.
     *
     * @return int
     */
    int pop()
    {
        try
        {
            if (isEmpty())
            {
                throw EmptyStackException("This is a custom exception");
            }

            int data = top->data;
            Node *temp = top;
            top = top->next;
            free(temp);
            size--;
            return data;
        }
        catch (EmptyStackException e)
        {
            cout << e.what() << endl;
        }
    }

    /**
     * @brief Push new element in stack
     *
     * @param data
     */
    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        if (isEmpty())
        {
            newNode->next = nullptr;
        }
        else
            newNode->next = top;

        size++;
        top = newNode;
    }

    int getSize()
    {
        cout << size;
        return size;
    }
};

int main()
{
    stack s = stack();
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(2);

    s.printStack();
    s.pop();

    s.printStack();

    s.getSize();
}