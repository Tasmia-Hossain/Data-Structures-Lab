#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *reverseList(node *root)
{
    node *prev = NULL;
    node *nextNode = NULL;

    node *curr_node = root;
    while (curr_node != NULL)
    {
        nextNode = curr_node->next;
        curr_node->next = prev;
        prev = curr_node;
        curr_node = nextNode;
    }
    return prev;
}

node *addNumbers(node *root1, node *root2)
{
    root1 = reverseList(root1);
    root2 = reverseList(root2);

    node *result = NULL;
    node *curr_node = NULL;
    int carry = 0;

    while (root1 != NULL || root2 != NULL || carry != 0)
    {
        int sum = carry;

        if (root1 != NULL)
        {
            sum += root1->data;
            root1 = root1->next;
        }

        if (root2 != NULL)
        {
            sum += root2->data;
            root2 = root2->next;
        }

        carry = sum / 10;
        sum %= 10;

        node *temp = new node();
        temp->data = sum;
        temp->next = NULL;

        if (result == NULL)
        {
            result = temp;
            curr_node = temp;
        }
        else
        {
            curr_node->next = temp;
            curr_node = temp;
        }
    }
    return reverseList(result);
}

void printList(node *root)
{
    while (root != NULL)
    {
        cout << root->data;
        if (root->next != NULL)
            cout << " -> ";
        root = root->next;
    }
}

int main()
{
    node *A, *B, *C;
    A = new node();
    B = new node();
    C = new node();
    A->data = 3;
    A->next = B;
    B->data = 4;
    B->next = C;
    C->data = 2;
    C->next = NULL;

    node *D, *E, *F;
    D = new node();
    E = new node();
    F = new node();
    D->data = 4;
    D->next = E;
    E->data = 6;
    E->next = F;
    F->data = 5;
    F->next = NULL;

    node *res = addNumbers(A, D);
    printList(res);

    return 0;
}
