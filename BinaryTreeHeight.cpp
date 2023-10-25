#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *root=NULL;

int Find_height(node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        int left_height=Find_height(temp->left);
        int right_height=Find_height(temp->right);
        return max(left_height,right_height)+1;
    }
}

int main()
{
    node *A,*B,*C,*D,*E;
    A=new node();
    B=new node();
    C=new node();
    D=new node();
    E=new node();
    A->data=10;
    A->left=B;
    A->right=C;
    B->data=15;
    B->left=D;
    B->right=NULL;
    C->data=11;
    C->left=NULL;
    C->right=E;
    D->data=25;
    D->left=NULL;
    D->right=NULL;
    E->data=19;
    E->left=NULL;
    E->right=NULL;
    root=A;

    int height=Find_height(root);
    cout<<"Height of the binary tree: "<<height<<endl;

    return 0;
}
