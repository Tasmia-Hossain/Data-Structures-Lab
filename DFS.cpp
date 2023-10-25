#include <bits/stdc++.h>
using namespace std;

vector<int> Node_Vec[6]; // Adjacency list representation
string color[6]; // Node color

void DFS(int source)
{
    int u=source;
    color[u] = "gray"; // Mark current node as visited (gray)

    for (int i = 0; i < Node_Vec[u].size(); i++)
    {
        int v = Node_Vec[u][i]; // Adjacent node of u
        if (color[v] == "white")
        {
            DFS(v); // Recursive call to visit adjacent nodes
        }
    }

    cout << u << "  "; // Print the visited node
    color[u] = "black"; // Mark current node as fully explored (black)
}

int main() {
    // Initialize node and edge counts
    int node_no, edge_no;
    cout << "Number of nodes: ";
    cin >> node_no;
    cout << "Number of edges: ";
    cin >> edge_no;

    int nodeA, nodeB;
    // Input edges and build adjacency list
    for (int i = 1; i <= edge_no; i++)
    {
        cin >> nodeA >> nodeB;
        Node_Vec[nodeA].push_back(nodeB);
        Node_Vec[nodeB].push_back(nodeA);
    }

     cout<<"\nAdjacency List: "<<endl;
     for(int i=1;i<=node_no;i++)
    {
        cout<<i<<" -> ";
        for(int j=0;j<Node_Vec[i].size();j++)
        {
        cout<<Node_Vec[i][j]<<" ";
        }
        cout<<endl;
    }

    // Reset node colors to "white"
    for (int i = 1; i <= node_no; i++)
    {
        color[i] = "white";
    }

    // Perform DFS traversal starting from node 1
    cout << "\nDFS Traversal: ";
    DFS(3);
    cout << endl;

    return 0;
}

//Input:
//Number of nodes: 5
//Number of edges: 5
/*
1 2
1 5
2 3
2 4
4 5
*/

/* Output:
Adjacency List:
1 -> 2 5
2 -> 1 3 4
3 -> 2
4 -> 2 5
5 -> 1 4

DFS Traversal: 4  5  1  2  3
*/
