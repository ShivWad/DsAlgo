#include <iostream>
using namespace std;

struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
    BinaryTreeNode()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
    BinaryTreeNode *root;

public:
    BinaryTree(int data)
    {
        root = new BinaryTreeNode(data);
    }
    BinaryTree() : root(){};

    bool isEmpty(BinaryTreeNode *root)
    {
        if (root == nullptr)
        {
            cout << "Empty Root" << endl;
            return true;
        }
        return false;
    }
    void insertElement()
    {
    }
    void deleteElement()
    {
    }
    void findElement()
    {
    }
    void preOrderTraversal()
    {
        preOrderTraversalInternal(root);
    }
    void preOrderTraversalInternal(BinaryTreeNode *root)
    {
        if (isEmpty(root))
            return;
        cout << root->data << endl;
        preOrderTraversalInternal(root->left);
        preOrderTraversalInternal(root->right);
    }
    void traverseTree()
    {
    }
    int Height()
    {
        return 0;
    }
    int Size()
    {
        return 0;
    }
};

int main()
{
    BinaryTree bTree = BinaryTree(10);

    bTree.preOrderTraversal();
}