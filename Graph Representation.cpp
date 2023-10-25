#include<bits/stdc++.h>
using namespace std;

vector<int>Node_Vec[11];
vector<int>Node_Cost[11];    //Graph input with weight

int main()
{
   int node_no,edge_no;
   cout<<"Number of nodes: ";
   cin>>node_no;
   cout<<"Number of edges: ";
   cin>>edge_no;

   int nodeA,nodeB,cost;
   for(int i=1;i<=edge_no;i++)
   {
       cin>>nodeA>>nodeB>>cost;
       Node_Vec[nodeA].push_back(nodeB);
       Node_Cost[nodeA].push_back(cost);
   }

   for(int i=1;i<=node_no;i++)
   {
       cout<<i<<" -> ";
       for(int j=0;j<Node_Vec[i].size();j++)
       {
           cout<<Node_Vec[i][j]<<" ";
       }
       cout<<endl;
   }

   for(int i=1;i<=node_no;i++)
   {
       cout<<i<<" -> ";
       for(int j=0;j<Node_Cost[i].size();j++)
       {
           cout<<Node_Cost[i][j]<<" ";
       }
       cout<<endl;
   }
}
