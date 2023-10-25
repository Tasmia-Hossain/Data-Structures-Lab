//Binary_search (Implement with an array)
//Id: 20210204038

#include<bits/stdc++.h>
using namespace std;

int Bin_search(int A[],int n,int k)
{
    int low=0;
    int hi=n-1;
    while(low<=hi)
    {
        int mid=(low+hi)/2;
        if(A[mid]==k)
            return 1;
        else if(A[mid]<k)
            low=mid+1;
        else
            hi=mid-1;
    }
    return -1;
}
int main()
{
    int ans,n;
    cout<<"Enter array size: ";
    cin>>n;
    int v[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        ans=Bin_search(v,n,10);
    }
    if(ans==1)
        cout<<"Found"<<endl;
    else
        cout<<"Not found"<<endl;

}
