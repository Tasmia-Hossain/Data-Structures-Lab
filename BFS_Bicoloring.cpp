#include <bits/stdc++.h>
using namespace std;

vector<int> Node_Vec[11];
int level[11];
int color[11];

bool BFS(int source)
{
    for (int i = 0; i < 11; i++)
    {
        level[i] = INT_MAX;
        color[i] = -1; // -1 indicates uncolored
    }

    queue<int> Q;
    Q.push(source);
    level[source] = 0;
    color[source] = 1; // Assign the initial color (1 or 0)

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
                color[v] = 1 - color[u]; // Assign the opposite color of the parent node
            }
            else if (color[u] == color[v])
            {
                // If the adjacent nodes have the same color, the graph cannot be colored with only 2 colors
                return false;
            }
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

    cout << "\nAdjacency List: " << endl;
    for (int i = 1; i <= node_no; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < Node_Vec[i].size(); j++)
        {
            cout << Node_Vec[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nLevel of the nodes :" << endl;
    BFS(1);

    for (int i = 1; i <= node_no; i++)
    {
        cout << "Node " << i << " -> Color: ";
        if (color[i] == 1)
            cout << "Red" << endl;
        else
            cout << "Green" << endl;
    }

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


//Output:
/*
Adjacency List:
1 -> 2 3 4
2 -> 1 6
3 -> 1 7 8
4 -> 1 7
5 -> 8 10
6 -> 2 10
7 -> 4 3 9 8
8 -> 3 7 5
9 -> 10 7
10 -> 6 9 5

Level of the nodes :
Node 1 -> Color: Red
Node 2 -> Color: Green
Node 3 -> Color: Green
Node 4 -> Color: Green
Node 5 -> Color: Green
Node 6 -> Color: Red
Node 7 -> Color: Red
Node 8 -> Color: Red
Node 9 -> Color: Green
Node 10 -> Color: Green
*/
