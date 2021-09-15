
#include<iostream>
#include"bst.cpp"
using namespace std;

int main()
{
    bst<int>b;
    b.insert(35);
    b.display();

    printf("Height of tree is %d \n", b.height());
    
}


