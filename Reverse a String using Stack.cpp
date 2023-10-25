#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input,ans="";
    stack<char>s;
    cout<<"Enter a string: ";
    getline(cin,input);
    for(int i=0;i<input.size();i++)
    {
        char ch=input[i];
        s.push(ch);
    }
    while(!s.empty())
    {
        ans=ans+s.top();
        s.pop();
    }
    cout<<"Reverse of the string: "<<ans<<endl;
    return 0;
}
