#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *root=NULL;

void insert(int val)
{
    node *temp=new node();      // Create a new node and set its data and pointers.
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;

    if(root==NULL)      // If the tree is empty, set the new node as the root.
    {
        root=temp;
    }
    else        // Traverse the tree to find the appropriate position for insertion.
    {
        node *curr_node=root;
        node *prev_node=root;
        while(curr_node!=NULL)
        {
            if(curr_node->data > temp->data)
            {
                prev_node=curr_node;
                curr_node=curr_node->left;
            }
            else
            {
                prev_node=curr_node;
                curr_node=curr_node->right;
            }
        }
        if(prev_node->data > temp->data)        // Insert the new node as the left or right child of the appropriate parent.
            prev_node->left=temp;
        else
            prev_node->right=temp;
    }
}

void delete_node(int val)
{
    node *curr_node=root;
    node *prev_node=root;

    while(curr_node!=NULL)      // Traverse the tree to find the node with the specified value.
    {
        if(curr_node->data == val)
            break;        // Found the node to delete

        prev_node=curr_node;

        if(curr_node->data<val)
                curr_node=curr_node->right;     // Move to the right child
        else
                curr_node=curr_node->left;      // Move to the left child
    }

    if(curr_node->left == NULL && curr_node->right == NULL)     // Check if the current node is a leaf node (no children).
    {
        if(prev_node->right == curr_node)       // Determine whether the current node is the left or right child of the parent.
            prev_node->right=NULL;      // Set the parent's right child to NULL
        else
            prev_node->left=NULL;       // Set the parent's left child to NULL
    }

    else if(curr_node->left == NULL || curr_node->right == NULL)        // Determine which child (left or right) the current node has.
    {
        node *child;
        if(curr_node->right == NULL)
            child=curr_node->left;      // If the right child is NULL, choose the left child.
        else
            child=curr_node->right;     // If the left child is NULL, choose the right child.

        if(prev_node->right==curr_node)     // Determine whether the current node is the left or right child of the parent.
            prev_node->right=child;     // Set the parent's right child to the chosen child.
        else
            prev_node->left=child;      // Set the parent's left child to the chosen child.
    }

    else
    {
        node *temp=curr_node;
        prev_node=curr_node;

        while(curr_node->left!=NULL)        // Find the in-order successor of the node to be deleted.
        {
            prev_node=curr_node;        // Update prev_node before moving down the tree.
            curr_node=curr_node->left;      // Move to the left child.
        }

        temp->data=curr_node->data;     // Replace the data of the node to be deleted with the in-order successor's data.

        if(prev_node->left == curr_node)        // Update the parent's child pointer to bypass the in-order successor node.
            prev_node->left=curr_node->right;
        else
            prev_node->right=curr_node->right;
    }
}

void in_order(node *temp)
{
    if(temp!=NULL)
    {
        in_order(temp->left);
        cout<<temp->data<<" ";
        in_order(temp->right);
    }
}

int main()
{
    insert(61);
    insert(28);
    insert(35);
    insert(40);
    insert(85);
    insert(54);
    insert(59);
    insert(78);
    insert(63);
    insert(82);

    in_order(root);     // Perform in-order traversal and print the values.
    cout<<endl;

    delete_node(40);
    in_order(root);
    cout<<endl;

    delete_node(82);
    in_order(root);
    cout<<endl;

    delete_node(54);
    in_order(root);
    cout<<endl;

    return 0;
}

//Output:
/*
28 35 40 54 59 61 63 78 82 85
28 35 54 59 61 63 78 82 85
28 35 54 59 61 63 78 85
28 35 59 61 63 78 85
*/
