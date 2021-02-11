//5) deleting the node in  binary search tree 

#include<stdio.h>
#include<stdlib.h>
#include"lib.c"

int find_min(node root)
{
    if (root == NULL)
    {
        printf("tree is empty\n");
        return -1;
    }
    else if (root->left == NULL )
        return root->data;
    return find_min(root->left);
} 


node delete_node(node root,int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root ->data)
    {
        root->left = delete_node(root->left,data);
        return root;
    }
    else if (data > root ->data)
    {
        root->right = delete_node(root->right,data);
        return root;
    }
    
    //Now we get that element 
    else
    {
        //case 1: root (node) has no children
        if (root ->left == NULL && root->right == NULL )
        {    
            free(root);
            root = NULL;
            return root;
        }
        //case 2: root (node) has one children
        else if (root ->left == NULL)
        {
            node temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root ->right == NULL)
        {
            node temp = root;
            root = root ->left;
            free(temp);
            return root;
        }
        //case 3: root (node) has two children
        else
        {
            root->data = find_min(root->right);
            root ->right = delete_node(root->right, root->data);   
            return root; 
        }
    }
    
    
    
}


int main()
{
    int element;
    node root = NULL;
    create_tree(&root);
    printf("\n");
    while (root != NULL)
    {
        printf("The tree is \n");
        print_tree(root);
        printf("\nEnter the element to delete\n");
        scanf("%d",&element);
        root = delete_node(root,element);
        print_tree(root);
        printf("\n");
        getchar();
        system("clear");
    }
    

}