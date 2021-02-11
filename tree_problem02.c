//2) find minimun and maximum in binary search tree

#include<stdio.h>
#include<stdlib.h>
#include"lib.c"

//This function find maximum element in tree using loop  
int find_maximum(node root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    } 
    while (root ->right != NULL)
    {
        root = root->right;
    }
    return root->data;
    
}

//This function find minimum element in tree in recursive manner
int find_minimum(node root)
{
    if (root == NULL)
    {
        printf("tree is empty\n");
        return -1;
    }
    else if (root->left == NULL )
        return root->data;
    return find_minimum(root->left);
} 


int main()
{
    node root = NULL;
    create_tree(&root);
    printf("The tree is \t");
    print_tree(root);
    printf("\nThe minimum is %d \n", find_minimum(root));
    printf("The maximum is %d \n", find_maximum(root));
    return 0;
    
}
   