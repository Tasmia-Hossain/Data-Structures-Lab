#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

node *root=NULL;

void printing()
{
        node *curr_node=root;
        do{
                cout<<curr_node->data<<" ";
                curr_node=curr_node->next;
        }while(curr_node!=root);
        cout<<endl;
}

void searching(int val)
{
    node *curr_node=root;

    do{
        if(curr_node->data==val)
        {
            cout<<"Found"<<endl;
            return;
        }
        curr_node=curr_node->next;
    } while(curr_node!=root);
    cout<<"Not Found"<<endl;
}

int counting()
{
    node *curr_node=root;
    int cnt=0;
    do{
        cnt++;
        curr_node=curr_node->next;
    }while(curr_node!=root);
    return cnt;
}

void insert_first(int val)
{
    node *temp;
    temp=new node();
    temp->data=val;

    if(root==NULL)
    {
        temp->next=temp;
        root=temp;
    }
    else
    {
         node *curr_node=root;
        while(curr_node->next!=root)
        {
            curr_node=curr_node->next;
        }
        temp->next=root;
        root=temp;
        curr_node->next=temp;
    }
}
void insert_last(int val)
{
    node *temp;
    temp=new node();
    temp->data=val;

    if(root==NULL)
    {
        temp->next=temp;
        root=temp;
    }
    else
    {
        node *curr_node=root;
        while(curr_node->next!=root)
        {
            curr_node=curr_node->next;
        }
        temp->next=root;
        curr_node->next=temp;
    }
}

void insert_anywhere(int pos,int val)
{
    int n=counting();
    node *temp;
    temp=new node();
    temp->data=val;

    if(root==NULL)
    {
        temp->next=temp;
        root=temp;
    }
    else if(pos==1)
    {
        insert_first(val);
    }
    else if(pos==n+1)
    {
        insert_last(val);
    }
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
    node *temp=root;
    node *curr_node=root;
    while(curr_node->next!=root)
    {
        curr_node=curr_node->next;
    }
    root=root->next;
    curr_node->next=root;
    delete temp;
}

void delete_last()
{
    node *curr_node=root;
    node *prev_node=NULL;
    while(curr_node->next!=root)
    {
        prev_node=curr_node;
        curr_node=curr_node->next;
    }
    prev_node->next=root;
    delete curr_node;
}

void delete_anywhere(int pos)
{
    node *prev_node=NULL;
    node *curr_node=root;
    int n=counting();
    node *temp;
    temp=new node();
    if(root==NULL)
    {
        root=temp;
    }
    else if(pos==1)
    {
        delete_first();
    }
    else if(pos==n)
    {
        delete_last();
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            prev_node=curr_node;
            curr_node=curr_node->next;
        }
        prev_node->next=curr_node->next;
        delete curr_node;
    }
}

int main()
{
        node *A, *B, *C, *D,*E;
        A=new node();
        B=new node();
        C=new node();
        D=new node();
        E=new node();

        A->data = 10;
        A->next = B;
        B->data = 20;
        B->next = C;
        C->data = 30;
        C->next = D;
        D->data = 40;
        D->next = E;
        E->data=50;
        E->next=A;
        root=A;
        cout<<"Printing: ";
        printing();

         cout<<"Searching a value: ";
        searching(40);

        int size=counting();
        cout<<"Size of the list: "<<size<<endl;
        cout<<endl;

        cout<<"Insert last: ";
        insert_last(60);
        printing();

        cout<<"Insert first: ";
        insert_first(5);
        printing();
        cout<<"Insert anywhere: ";
        insert_anywhere(4,100);
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
        cout<<endl;

        return 0;
}

