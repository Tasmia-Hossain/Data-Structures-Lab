#include <bits/stdc++.h>
using namespace std;

vector<int> Node_Vec[11];
int color[11];

bool BFS(int source)
{
    queue<int> Q;
    Q.push(source);
    color[source] = 1;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int j = 0; j < Node_Vec[u].size(); j++)
        {
            int v = Node_Vec[u][j];
            if (color[v] == -1)
            {
                Q.push(v);
                color[v] = 1 - color[u]; // Assign the opposite color of the parent node
            }
            else if (color[u] == color[v])
            {
                // If the adjacent nodes have the same color, the war will not end.
                return false;
            }
        }
    }

    return true;
}

bool isWarEnd(int node_no)
{
    for (int i = 1; i <= node_no; i++)
    {
        if (color[i] == -1)
        {
            if (!BFS(i))
                return false;
        }
    }

    return true;
}

int main()
{
    int node_no, edge_no;
    cout << "Number of nodes: ";
    cin >> node_no;
    cout << "Number of edges: ";
    cin >> edge_no;

    int nodeA, nodeB;
    for (int i = 1; i <= edge_no; i++)
    {
        cin >> nodeA >> nodeB;
        Node_Vec[nodeA].push_back(nodeB);
        Node_Vec[nodeB].push_back(nodeA);
    }

    // Initialize colors with -1 (uncolored)
    memset(color, -1, sizeof(color));

    if (isWarEnd(node_no))
        cout << "\nThe war will end at some point." << endl;
    else
        cout << "\nThe war will not end." << endl;

    return 0;
}

//input:
//Number of nodes: 10
//Number of edges: 13
/*
1 2
1 3
1 4
2 6
6 10
4 7
3 7
3 8
9 10
9 7
8 7
8 5
10 5
*/

//Output: The war will not end.
