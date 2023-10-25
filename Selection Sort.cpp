#include<bits/stdc++.h>
using namespace std;

void selection_sort(int A[], int n)
{
    for(int i=0;i<n-1;i++)  // should be n-1 instead of n
    {
        int min=A[i], pos=i;  // need to declare pos and initialize with i
        for(int j=i+1;j<n;j++)  // should be n instead of n-1
        {
            if(A[j]<min)
            {
                min=A[j];
                pos=j;
            }
        }
        swap(A[i],A[pos]);
    }
    for(int i=0;i<n;i++)  // need to print each element of A
    {
        cout<<A[i]<<" ";
    }
}

int main()
{
    int A[]={20,12,10,15,2};
    int n=sizeof(A)/sizeof(A[0]);  // need to calculate the size of A
    selection_sort(A, n);  // need to pass the size of A as an argument
    return 0;  // need to return a value from main function
}
