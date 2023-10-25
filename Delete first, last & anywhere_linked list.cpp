#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *root=NULL;

void delete_first()
{
    if (root == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    node *temp = root;
    root = root->next;
    delete temp;
}

void delete_last()
{
    if (root == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (root->next == NULL)
    {
        delete root;
        root = NULL;
        return;
    }

    node *curr_node = root;
    node *prev_node = NULL;
    while (curr_node->next != NULL)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    prev_node->next = NULL;
    delete curr_node;
}

void delete_anywhere(int pos)
{
    if (root == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (pos == 1)
    {
        node *temp = root;
        root = root->next;
        delete temp;
        return;
    }

    node *curr_node = root;
    node *prev_node = NULL;
    int count = 1;
    while (curr_node != NULL && count < pos)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
        count++;
    }

    if (curr_node == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    prev_node->next = curr_node->next;
    delete curr_node;
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
    node *A, *B, *C, *D, *E, *F;
    A = new node();
    B = new node();
    C = new node();
    D = new node();
    E = new node();
    F= new node();

    A->data = 10;
    A->next = B;
    B->data = 20;
    B->next = C;
    C->data = 30;
    C->next = D;
    D->data = 40;
    D->next = E;
    E->data=50;
    E->next=F;
    F->data=60;
    F->next=NULL;

    root = A;
    delete_first();
    delete_last();
    delete_anywhere(2);
    printing();
    return 0;
}

