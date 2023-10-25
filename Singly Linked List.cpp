#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *root=NULL;

void printing()
{
    node *curr_node=root;
    while(curr_node!=NULL)
    {
        cout<<curr_node->data<<" ";
        curr_node=curr_node->next;
    }
    cout<<endl;
}

void searching(int val)
{
    node *curr_node=root;
    while(curr_node!=NULL)
    {
        if(curr_node->data==val)
        {
            cout<<"Found"<<endl;
            return;
        }
        curr_node=curr_node->next;
    }
    cout<<"Not Found"<<endl;
}

int counting()
{
    int cnt = 0;
    node *curr_node = root;
    while (curr_node != NULL)
    {
        cnt++;
        curr_node = curr_node->next;
    }
    return cnt;
}

void insert_first(int val)
{
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;
    if(root==NULL)
        root=temp;

    else
    {
        temp->next=root;
        root=temp;
    }
}

void insert_last(int val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    if (root == NULL)
        root = temp;

    else
    {
        node *curr_node = root;
        while (curr_node->next != NULL)
        {
            curr_node = curr_node->next;
        }
        curr_node->next = temp;
    }
}

void insert_anywhere(int val, int pos)
{
    int n=counting();
    node *temp=new node();
    temp->data = val;
    temp->next = NULL;

    if (pos == 1)
        insert_first(val);

    else if(pos==n+1)
        insert_last(val);

    else
    {
         node *curr_node=root;
        for(int i=1;i<pos-1;i++)
        {
            curr_node=curr_node->next;
        }
        temp->next=curr_node->next;
        curr_node->next=temp;
    }
}

void delete_first()
{
    node *temp = root;
    root = root->next;
    delete temp;
}

void delete_last()
{
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
    int n=counting();

    if (pos == 1)
        delete_first();

    else if (pos == n+1)
        delete_last();

    else
    {
        node *curr_node = root;
        node *prev_node = NULL;

        for(int i=1;i<pos;i++)
        {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }

        prev_node->next = curr_node->next;
        delete curr_node;
    }
}

int main()
{
    node *A, *B, *C, *D, *E;
    A = new node();
    B = new node();
    C = new node();
    D = new node();
    E = new node();

    A->data = 10;
    A->next = B;
    B->data = 20;
    B->next = C;
    C->data = 30;
    C->next = D;
    D->data = 40;
    D->next = E;
    E->data=50;
    E->next=NULL;
    root = A;

    cout<<"Printing: ";
    printing();

    cout<<"Searching a value: ";
    searching(100);

    int size = counting();
    cout << "Size of the linked list: " << size << endl;
    cout<<endl;

    cout<<"Insert first: ";
    insert_first(5);
    printing();

    cout<<"Insert last: ";
    insert_last(60);
    printing();

    cout<<"Insert anywhere: ";
    insert_anywhere(100, 3);
    printing();
    cout<<endl;

    cout<<"Delete first: ";
    delete_first();
    printing();

    cout<<"Delete last: ";
    delete_last();
    printing();

    cout<<"Delete anywhere: ";
    delete_anywhere(3);
    printing();

    return 0;
}
