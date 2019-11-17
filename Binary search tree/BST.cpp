#include <iostream>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int value;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
private:
    Node* root;

    Node* find(Node* curNode, int value)
    {
        if(curNode == NULL)
            return NULL;
        if(curNode->value == value)
            return curNode;
        if(curNode->value < value)
            return find(curNode->right, value);
         return find(curNode->left, value);
    }

    Node* insert(Node *curNode, int value)
    {
        if(this->root == NULL)
        {
            this->root = new Node(value);
            return this->root;
        }
        if(curNode == NULL)
        {
            return new Node(value);
        }
        if(curNode->value < value)
        {
            curNode->right = insert(curNode->right, value);
        }
        else
        {
            curNode->left = insert(curNode->left, value);
        }
        return curNode;
    }

    Node* remove(Node* curNode, int value)
    {
        if(curNode == NULL)
        {
            return NULL;
        }
        if(curNode->value < value)
        {
            curNode->right = remove(curNode->right, value);
        }
        else if(curNode->value > value)
        {
            curNode->left = remove(curNode->left, value);
        }
        else
        {
            if(curNode->left == NULL)
            {
                Node* tmp = curNode->right;
                delete curNode;
                return tmp;
            }
            Node* maxInLeftSubTree = curNode->left;
            while(maxInLeftSubTree->right != NULL)
            {
                maxInLeftSubTree = maxInLeftSubTree->right;
            }
            curNode->value = maxInLeftSubTree->value;
            curNode->left = remove(curNode->left, curNode->value);
        }
        return curNode;
    }

    void printSorted(Node *root)
    {
        if(root == NULL)
        {
            return;
        }
        printSorted(root->left);
        cout<<root->value<<" ";
        printSorted(root->right);
    }

    Node* findMax(Node *root)
    {
        if(root->right != NULL)
        {
            return findMax(root->right);
        }
        return root;
    }

    Node* findMin(Node *root)
    {
        if(root->left != NULL)
        {
            return findMin(root->left);
        }
        return root;
    }

    Node* lowerBound(Node* root, int value)
    {
        if(root == NULL)
        {
            return NULL;
        }
        else if(root->value == value)
        {
            return root;
        }
        else if(root->value > value)
        {
            return lowerBound(root->left, value);
        }
        else
        {
            Node* tmp = lowerBound(root->right, value);
            if(tmp != NULL)
                return tmp;
            else
                return root;
        }
    }

public:
    BST()
    {
        root = NULL;
    }
    void insert(int value)
    {
        if(root == NULL)
        {
            root = new Node(value);
        }
        else
        {
            insert(root, value);
        }
    }
    void remove(int value)
    {
        remove(root, value);
    }
    bool exists(int value)
    {
        return find(root, value) != NULL;
    }
    int findMin()
    {
        if(root == NULL)
            return -1;
        return findMin(root)->value;
    }
    int findMax()
    {
        if(root == NULL)
            return -1;
        return findMax(root)->value;
    }
    int lowerBound(int value)
    {
        Node* lb = lowerBound(root, value);
        if(lb == NULL)
            return -1;
        else return lb->value;
    }
    void printSorted()
    {
        printSorted(root);
    }

};

int main()
{

}

