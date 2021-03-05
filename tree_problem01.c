//1)implement of Binary search tree and traverse the tree

#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
};
typedef struct tree* node;

void post_order(node root)
{
    if (root == NULL)
        return;
 
    post_order(root->left);
    post_order(root->right);
   printf("%d \t",root->data);    
}
void pre_order(node root)
{
    if (root == NULL)
        return;
    printf("%d \t",root->data);
    pre_order(root->left);
    pre_order(root->right);
    
}

void in_order(node root)
{
    if (root == NULL)
        return;
    in_order(root->left);
    printf("%d \t",root->data);
    in_order(root->right);
}

node get_node(int x)
{
    node new_node = (struct tree *)malloc(sizeof(struct tree));
    new_node->data = x;
    new_node->left = new_node->right = NULL;
    return new_node; 
}

node insert(node root,int data)
{
	if(root == NULL) 
    { // empty tree
		root = get_node(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data)
    {
		root->left = insert(root->left,data);
	}
	// else, insert in right subtree. 
	else 
    {
		root->right = insert(root->right,data);
	}
    return root;
}


int main()
{
    node root = NULL;
    
    root = insert(root, 14);
    root = insert(root,23);
    root = insert(root , 12);
    root = insert(root, 43);
    root = insert(root , 92);
    root = insert (root , 13);
    
    printf("pre order \t");
    pre_order(root);
    printf("\n");
    printf("in order \t");
    in_order(root);
    printf("\n");
    printf("post order \t");
    post_order(root);
    printf("\n");
    return 0;
}






