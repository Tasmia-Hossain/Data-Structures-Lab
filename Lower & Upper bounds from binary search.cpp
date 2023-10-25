#include <bits/stdc++.h>
using namespace std;

int Bin_search(vector<int>A,int k)
{
    int low=0;
    int hi=A.size()-1;
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
    vector<int>v;
    int n,x,ans,lb,ub;
    cout<<"Enter size: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        ans=Bin_search(v,10);
        lb=lower_bound(v.begin(),v.end(),10)-v.begin();
        ub=upper_bound(v.begin(),v.end(),10)-v.begin();
    }
    if(ans==1)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    cout<<"Lower bound: "<<lb<<endl;
    cout<<"Upper bound: "<<ub<<endl;
}
