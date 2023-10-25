#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *A,*B,*C,*D;

void printing()
{
    node *curr_node=A;
    while(curr_node!=NULL)
    {
        cout<<curr_node->data<<" ";
        curr_node=curr_node->next;
    }
}

void searching(int val)
{
    node *curr_node=A;
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

int list_size()
{
    int count = 0;
    node *curr_node = A;
    while (curr_node != NULL)
    {
        count++;
        curr_node = curr_node->next;
    }
    return count;
}

int main()
{
    A=new node();
    B=new node();
    C=new node();
    D=new node();

    A->data=10;
    A->next=C;
    B->data=40;
    B->next=NULL;
    C->data=20;
    C->next=D;
    D->data=30;
    D->next=B;

    printing();
    cout<<endl;
    searching(100);
    int size = list_size();
    cout << "Size of the linked list: " << size << endl;
    return 0;
}
