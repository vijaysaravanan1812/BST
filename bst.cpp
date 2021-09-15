// implememtation of functions that declare in class 

#include<iostream>


using namespace std;
#include"bst.h"

//Function in public section
template <typename T>
void bst<T>::insert(const T &element)
{
    insert(element, root);
}

//Function in private section
template <typename T>
void bst<T>::insert(const T &element, node *&temp)
{
    if (temp == NULL)
    {
        temp = new node(element, NULL, NULL);
    }
    else if (element <= temp->data)
    {
        insert(element,temp->left);
    }
    else if (element > temp->data)
    {
        insert(element, temp->right);
    }
}

//Function in public section 
template <typename T>
void bst<T>::remove(const T &element)
{
    remove(element, root);
}

//Function in private section
template <typename T>
void bst<T>::remove(const T &element, node *& temp )
{
    if (temp == NULL)
    {
        printf("No Element Found \n");
        getchar();
        return;
    }
    else if (element < temp->data)
    {
        remove(element, temp->left);
    }
    else if (element > temp->data)
    {
        remove(element, temp->right );
    }
    else
    {
        if (temp->left != NULL && temp->right != NULL )
        {
            temp->data = (find_min(temp->right))->data;
            remove(temp->data,temp->right);
        }
        else
        {
            node *tmp = temp;
            temp = ( temp->left != NULL ) ? temp->left : temp->right;
            delete tmp;
        }
        
    }
}

//Function in public section
template <typename T>
void bst<T>::display()
{
    print(root);
    printf("\n");
}

//Function in private section
template <typename T>
void bst<T>::print(node *& temp)
{
    if (temp != NULL)
    {
        cout<<" "<<temp->data;
        print(temp->left);
        print(temp->right);
    }
    
    
}

template <typename T>
int bst<T>::height(node *&temp) const
{
    if (temp == NULL)
        return -1;    
    else
    {
        return (height(temp->left) > height(temp->right))? height(temp->left) : height(temp->right) + 1;
    }
}

//Function in public section
template <typename T>
int bst<T>::height() 
{
    return height(root);
}

