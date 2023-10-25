#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *root=NULL;

void findCycle()
{
    int p=0;
    node *tortoise=root;
    node *hare=root;
    while(tortoise!=NULL && hare!=NULL && hare->next!=NULL)
    {
        tortoise=tortoise->next;
        hare=hare->next->next;
        if(tortoise==hare)
        {
            p=1;
            break;
        }
    }
    if(p==1)
        cout<<"Cycle found"<<endl;
    else
        cout<<"Cycle not found"<<endl;
}

void CycleFirstNode()
{
    node *tortoise=root;
    node *hare=root;
    while(tortoise!=NULL && hare!=NULL && hare->next->next!=NULL)
    {
        tortoise=tortoise->next;
        hare=hare->next->next;
        if(tortoise==hare)
            break;
    }
    node *tortoise2=root;
    while(tortoise!=NULL && tortoise2!=NULL)
    {
        tortoise=tortoise->next;
        tortoise2=tortoise2->next;
        if(tortoise==tortoise2)
            break;
    }
    cout<<"First node of the cycle: "<<tortoise->data<<endl;
}

void TwoHareMeet()
{
    node *tortoise=root;
    node *hare=root;
    while(tortoise!=NULL && hare!=NULL && hare->next->next!=NULL)
    {
        tortoise=tortoise->next;
        hare=hare->next->next;
        if(tortoise==hare)
            break;
    }
    node *hare2=root;
    while(hare!=NULL && hare!=NULL)
    {
        hare=hare->next->next;
        hare2=hare2->next->next;
        if(hare==hare2)
            break;
    }
    cout<<"Two hares meeting node: "<<hare->data<<endl;
}

void BreakCycle()
{
    node *tortoise=root;
    node *hare=root;
    while(tortoise!=NULL && hare!=NULL && hare->next->next!=NULL)
    {
        tortoise=tortoise->next;
        hare=hare->next->next;
        if(tortoise==hare)
        {
            tortoise=root;
            while(tortoise->next!=hare->next)
            {
                tortoise=tortoise->next;
                hare=hare->next;
            }
            hare->next=NULL;
            break;
        }
    }
}

int main()
{
    node *A,*B,*C,*D,*E,*F,*G,*H,*I,*J;
    A = new node();
    B = new node();
    C = new node();
    D = new node();
    E = new node();
    F = new node();
    G = new node();
    H = new node();
    I = new node();
    J = new node();

    A->data = 20;
    A->next = B;
    B->data = 45;
    B->next = C;
    C->data = 12;
    C->next = D;
    D->data = 42;
    D->next = E;
    E->data= 90;
    E->next= F;
    F->data = 67;
    F->next = G;
    G->data = 15;
    G->next = H;
    H->data = 28;
    H->next = I;
    I->data = 64;
    I->next = J;
    J->data= 85;
    J->next= D;

    root = A;
    findCycle();

    CycleFirstNode();
    TwoHareMeet();

    BreakCycle();
    findCycle();

    return 0;
}
