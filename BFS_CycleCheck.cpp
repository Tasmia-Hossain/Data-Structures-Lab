#include <bits/stdc++.h>
using namespace std;

vector<int> Node_Vec[11];
int level[11];
int parent[11];

bool BFS(int source)
{
    for (int i = 0; i < 11; i++)
    {
        level[i] = INT_MAX;
        parent[i] = -1;
    }

    queue<int> Q;
    Q.push(source);
    level[source] = 0;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int j = 0; j < Node_Vec[u].size(); j++)
        {
            int v = Node_Vec[u][j];
            if (level[v] == INT_MAX)
            {
                Q.push(v);
                level[v] = level[u] + 1;
                parent[v] = u;
            }
            else if (parent[u] != v)
            {
                // If the node v is already visited and not the parent of u, then there is a cycle
                return true;
            }
        }
    }

    return false;
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

    BFS(10);

    // Check if there is a cycle in the graph
    bool hasCycle = false;
    for (int i = 1; i <= node_no; i++)
    {
        if (level[i] != INT_MAX && parent[i] != -1)
        {
            hasCycle = BFS(i);
            if (hasCycle)
                break;
        }
    }

    if (hasCycle)
        cout << "\nThe graph contains a cycle." << endl;
    else
        cout << "\nThe graph does not contain a cycle." << endl;

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

//Output: The graph contains a cycle.
