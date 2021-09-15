

#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};

typedef struct tree* node;

//This function find maximum element in tree using loop  
int find_max(node root)
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
//return sum of all nodes
int find_sum(node root)
{
    if (root == NULL)
        return 0;
    return (root->data + find_sum(root->left) + find_sum(root->right));
    
    
}


void print_tree(node root)
{
    if (root == NULL)
        return;
    print_tree(root->left);
    printf("%d \t",root->data);
    print_tree(root->right);
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

//This function use double pointer
void create_tree(node* root)
{
    int x,i = 0;
    printf("Enter the element to form binary tree\n");
    while (1)
    {
        if (i == 10)
            break;
        printf("Enter the data to insert\t");
        scanf("%d",&x);
        *root = insert(*root, x);

        system("clear");
        i++;
    }
}
