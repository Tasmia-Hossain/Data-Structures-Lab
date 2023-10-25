#include<bits/stdc++.h>
using namespace std;

void Insertion_sort(vector<int>&A,int n)
{
    n=A.size();
    for(int i=1;i<=n-1;i++)
    {
        int key=A[i];
        int j=i-1;
        while(A[j]>key && j>=0)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

void printArray(vector<int>&v)
{
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

int main()
{
    vector<int>v;
    int n,x;
    cout<<"Enter size: ";
    cin>>n;

    cout<<"Enter array element: ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    Insertion_sort(v,n);
    cout<<"Array after insertion sort: ";
    printArray(v);
    return 0;
}
