#include<bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    stack<char>s;
    cin>>input;
    for(int i=0;i<input.size();i++)
    {
        char symbol=input[i];
        if(symbol=='(' || symbol=='{' || symbol=='[')
            s.push(symbol);
        else if(symbol==')' || symbol=='}' || symbol==']')
        {
            if(s.empty())
            {
                cout<<"Expression is not balanced"<<endl;
                return 0;
            }
            char top=s.top();
            s.pop();
            if((symbol==')' && top!='(') || (symbol=='}' && top!='{') || (symbol==']' && top!='['))
            {
                cout<<"Expression is not balanced"<<endl;
                return 0;
            }
        }
    }
    if(!s.empty())
        cout<<"Expression is not balanced"<<endl;
    else
        cout<<"Expression is balanced"<<endl;
    return 0;
}

//{2+3}/(4*3+(1-5))
//a+{b+c(x-y}
