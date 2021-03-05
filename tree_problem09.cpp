
// print inorder traversal without recursion

#include<iostream>
#include<stack>
#include"lib.c"

using namespace std;

node inorder(node root)
{
    stack <node> s;
    bool done = 0;

    while (!done)
    {
        if (root != NULL)
        {
            s.push(root);
            root = root ->left;
        }
        else
        {
            if(!s.empty())
            {
                root = s.top();
                s.pop();
                printf("%d ",root->data);

                root = root->right;
            }
            else
                done = 1;
        }
    }
    printf("\n");

    
    


}

int main()
{
    node root = NULL;
    create_tree(&root);
    inorder(root);
}
