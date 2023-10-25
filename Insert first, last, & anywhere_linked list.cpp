#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *root=NULL;

void insert_first(int val)
{
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->next=root;
        root=temp;
    }
}

void insert_last(int val)
{
    node *temp, *curr_node;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        curr_node = root;
        while (curr_node->next != NULL)
        {
            curr_node = curr_node->next;
        }
        curr_node->next = temp;
    }
}

void insert_anywhere(int val, int pos)
{
    node *temp, *new_node;
    temp = new node();
    temp->data = val;
    temp->next = NULL;

    if (pos == 1)
    {
        temp->next = root;
        root = temp;
        return;
    }

    node *prev_node = root;
    for (int i = 1; i < pos - 1 && prev_node != NULL; i++)
    {
        prev_node = prev_node->next;
    }

    if (prev_node == NULL)
    {
        cout << "Invalid position. Insertion failed." << endl;
        return;
    }

    new_node = prev_node->next;
    prev_node->next = temp;
    temp->next = new_node;
}

void printing()
{
    node *curr_node=root;
    while(curr_node!=NULL)
    {
        cout<<curr_node->data<<" ";
        curr_node=curr_node->next;
    }
}

int main()
{
    node *A, *B, *C, *D;
    A = new node();
    B = new node();
    C = new node();
    D = new node();

    A->data = 10;
    A->next = C;
    B->data = 40;
    B->next = NULL;
    C->data = 20;
    C->next = D;
    D->data = 30;
    D->next = B;

    root = A;
    insert_first(5);
    insert_last(50);
    insert_anywhere(25, 4);
    printing();
    return 0;
}

