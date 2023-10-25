#include<bits/stdc++.h>
using namespace std;
vector<int>A;

int Partition(int low,int hi)
{
    int pivot=A[low];
    int i=low;
    int j=hi;
    while(i<j)
    {
        while(A[i]<=pivot)
        {
            i++;
        }
        while(A[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(A[i],A[j]);
        }
    }
    swap(A[low],A[j]);
    return j;
}

void quicksort(int low,int hi)
{
    if(low<hi)
    {
        int pos=Partition(low,hi);
        quicksort(low,pos-1);
        quicksort(pos+1,hi);
    }
}

int main()
{
    int n,x;
    cout<<"Enter size: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        A.push_back(x);
    }
    quicksort(0,A.size()-1);
    cout<<"After Quick Sort: ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
