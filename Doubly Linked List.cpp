#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

node *root=NULL;
node *tail=NULL;

void printing()
{
    node *curr_node=root;
    cout<<"Forward: ";
    while(curr_node!=NULL)
    {
        cout<<curr_node->data<<" ";
        curr_node=curr_node->next;
    }
    cout<<endl;
    node *curr_node2=tail;
    cout<<"             Reverse: ";
    while(curr_node2!=NULL)
    {
        cout<<curr_node2->data<<" ";
        curr_node2=curr_node2->prev;
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
    node *curr_node=root;
    int cnt=0;
    while(curr_node!=NULL)
    {
        cnt++;
        curr_node=curr_node->next;
    }
    return cnt;
}

void insert_first(int val)
{
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;

    if(root==NULL)
    {
        root=temp;
        tail=temp;
    }
    else
    {
        temp->next=root;
        root->prev=temp;
        root=temp;
    }
}
void insert_last(int val)
{
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;

    if(root==NULL)
    {
        root=temp;
        tail=temp;
    }
    else
    {
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}

void insert_anywhere(int pos,int val)
{
    int n=counting();
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;

    if(root==NULL)
    {
        root=temp;
        tail=temp;
    }
    else if(pos==1)
        insert_first(val);

    else if(pos>n)
        insert_last(val);

    else
    {
        node *curr_node=root;
        for(int i=1;i<pos-1;i++)
        {
            curr_node=curr_node->next;
        }
        temp->next=curr_node->next;
        curr_node->next->prev=temp;
        curr_node->next=temp;
        temp->prev=curr_node;
    }
}

void delete_first()
{
    root=root->next;
    root->prev=NULL;
}

void delete_last()
{
    tail=tail->prev;
    tail->next=NULL;
}

void delete_anywhere(int pos)
{
    node *curr_node=root;
    int count=1;
    node *temp;
    temp=new node();
    if(root==NULL)
    {
        root=temp;
        tail=temp;
    }
    else if(pos==1)
        delete_first();

    else if(pos==counting())
        delete_last();

    else
    {
        while(count!=pos)
        {
            curr_node=curr_node->next;
            count++;
        }
        curr_node->prev->next=curr_node->next;
        curr_node->next->prev=curr_node->prev;
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
        A->prev=NULL;
        B->data = 20;
        B->next = C;
        B->prev=A;
        C->data = 30;
        C->next = D;
        C->prev=B;
        D->data = 40;
        D->next = E;
        D->prev=C;
        E->data=50;
        E->next=NULL;
        E->prev=D;
        root=A;
        tail=E;
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
