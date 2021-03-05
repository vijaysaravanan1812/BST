// 4) level traversal of binary tree

#include<iostream>
#include<stdio.h>
#include<queue>
#include"lib.c"
using namespace std;

void level_order_traversal(node root)
{
    if (root == NULL)
    {
        printf("No list here to print\n");
        return;
    }
    queue <node> q;
    q.push(root);
    while (!q.empty())
    {
        node current = q.front();
        q.pop();
        printf("%d ",current->data);
        if (current->left != NULL)
            q.push(current->left);
        if (current ->right != NULL)
            q.push(current->right);
    }
}

int main()
{
    node root = NULL;
    create_tree(&root);
    printf("The level traversal of tree is\n");
    level_order_traversal(root);
    printf("\n");
}