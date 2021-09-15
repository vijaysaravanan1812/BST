// program to implement the Binary search

#include<iostream>
using namespace std;

template <typename T>
class bst
{
private:
    struct node
    {
        T data;
        node *left;
        node *right;
        node(T element,node *left_node, node *right_node)
        {
            this->data = element;
            this->left = left_node;
            this->right = right_node;
        }
    };
    node *root;
    void insert(const T &element, node *&temp);
    void remove(const T &element, node *&temp);
    void print(node *&temp);
    int height(node *&temp) const;
    node *find_min(node *temp) const
    {
        if (temp == NULL)
            return NULL;
        else if (temp -> left == NULL)
        {
            return temp;
        }
        else
        {
            return find_min(temp->left);
        }
    }
  
public:
    bst()
    {
        root = NULL;
    }
    void insert(const T &element);
    void remove(const T &element);
    void display();
    int height();

};


