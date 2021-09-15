// 7) check out that tree is symmetric(mirror image itself) or not

#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};
typedef struct tree* node;


node new_node(int data)
{
    node temp = (struct tree *)malloc(sizeof(struct tree));
    temp ->data = data;
    temp ->left = NULL;
    temp ->right = NULL;
    return temp;
}

    //Funtion to check wether image of tree is itself
int ismirror(node root1, node root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    else if (root1 && root2 && root1->data == root2->data)
    {
        return ismirror(root1->left,root2->right) && ismirror(root1 ->right,root2 ->left );
    }
    else
        return 0;
    
    
    
}

int issymmetric(node root)
{

    return ismirror(root,root);
}

int main()
{
    //now we create tree
    node root = new_node(1);
    root->left = new_node(3);
    root->right = new_node(3);
    root->left->left = new_node(2);
    root->left->right = new_node(4);
    root->right->left = new_node(4);
    root->right->right = new_node(2);
    if (issymmetric(root))
        printf("The tree is symmetric\n");
    else
        printf("The tree is not symmetric\n");
    
    

}