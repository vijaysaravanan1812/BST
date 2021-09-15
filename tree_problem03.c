
// 3) find the heigth of tree
#include"lib.c"
#include<stdio.h>
#include<stdlib.h>

int left_height,right_height;

int height_of_tree(node root)
{
    if (root == NULL)
        return -1;
    return (height_of_tree(root->left ) > height_of_tree( root->right) ?  height_of_tree(root->left ) : height_of_tree( root->right)) + 1; 
    
}


int main()
{
    node root = NULL;
    create_tree(&root);
    printf("The tree is \t");
    print_tree(root);
    printf("\n");
    printf("Height of tree is \t %d \n",height_of_tree(root));
    return 0;
}
