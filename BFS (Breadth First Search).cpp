#include<bits/stdc++.h>
using namespace std;

vector<int>Node_Vec[11];
int level[11];

void BFS(int source)
{
    for(int i=0;i<11;i++)
    {
        level[i]=INT_MAX;
    }
    queue<int>Q;
    Q.push(source);
    level[source]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int j=0;j<Node_Vec[u].size();j++)
        {
            int v=Node_Vec[u][j];
            if(level[v]==INT_MAX)
            {
                Q.push(v);
                level[v]=level[u]+1;
            }
        }
    }
}

int main()
{
    int node_no,edge_no;
   cout<<"Number of nodes: ";
   cin>>node_no;
   cout<<"Number of edges: ";
   cin>>edge_no;

   int nodeA,nodeB;
   for(int i=1;i<=edge_no;i++)
   {
       cin>>nodeA>>nodeB;
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

    cout<<"\nLevel of the nodes :"<<endl;
    BFS(10);
    for(int i=1;i<11;i++)
    {
        cout<<i<<" -> "<<level[i]<<endl;
    }
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
1 -> 3
2 -> 2
3 -> 3
4 -> 3
5 -> 1
6 -> 1
7 -> 2
8 -> 2
9 -> 1
10 -> 0
*/
