
//08) find the sum of all nodes in binary tree

#include<stdlib.h>
#include<stdlib.h>
#include"lib.c"


//return sum of all nodes
int find_summation(node root)
{
    if (root == NULL)
        return 0;
    return (root->data + find_summation(root->left) + find_summation(root->right));
    
    
}

int main()
{
    node root =  NULL;
    create_tree(&root);
    printf("The tree is \n");
    print_tree(root);
    printf("\n");

    printf("The sum of tree is %d \n",find_summation(root));
}
