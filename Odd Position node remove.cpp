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

void delete_odd()
{
    node *curr_node=root;
    node *prev_node=NULL;
    int pos=1;

    while(curr_node!=NULL)
    {
        if(pos%2!=0)
        {
            if(prev_node!=NULL)
                prev_node->next=curr_node->next;
            else
                root=curr_node->next;

            node *temp=curr_node;
            curr_node=curr_node->next;
            delete temp;
        }
        else
        {
            prev_node=curr_node;
            curr_node=curr_node->next;
        }
        pos++;
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

    cout<<"After deleting odd position value: ";
    delete_odd();
    printing();
    return 0;
}
