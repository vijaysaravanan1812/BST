
//6) find the inorder successor of given node

#include<stdio.h>
#include<stdlib.h>
#include"lib.c"

//Function for getting node
node find_node(node root,int data)
{
    if (root == NULL)
        return NULL;
    else if (root ->data == data)
        return root;
    else if (data < root->data)
        return find_node(root->left, data);
    else
        return find_node(root->right,data);

}

//This function find in order successor of given node
node get_successor(node root, int data)
{
    node current_node = find_node(root,data);

    if (current_node == NULL)
        return NULL;
    
    //if node has right sub tree 
    if (current_node->right != NULL )
    {
        current_node->data = find_min(current_node->right);
        return current_node;
    }
    //if node has no right sub tree
    else 
    {
        node succesor = NULL;
        node ancestor = root;  
        while (ancestor != current_node)
        {
            if ( current_node->data < ancestor->data  )
            {
                succesor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
             //  succesor = ancestor;
                ancestor = ancestor ->right;
            }
            
        }
        return succesor;

    }
}


int main()
{
    node root = NULL,successor = NULL;int data;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,35);
    root = insert(root,5);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,18);
    root = insert(root,16);
    root = insert(root,4);
    root = insert(root,6);
    root = insert(root,3);
    printf("The tree is \n");
    print_tree(root);
    printf("\n");
    printf("Enter the element that in tree ot get it's  inoder successor\t");
    scanf("%d",&data);
    successor = get_successor(root,data);
    printf("in order successor is %d \n",successor->data);


    return 0;
}

