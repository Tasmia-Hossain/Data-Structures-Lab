#include<bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if(ch=='^')     return 5;
    else if(ch=='*' || ch=='/')     return 4;
    else if(ch=='+' || ch=='-')     return 3;
    else
        return -1;
}

int prefixEvaluate(string prefix)
{
    stack<int>st;
    for(int i=prefix.size()-1;i>=0;i--)
    {
        char ch=prefix[i];
        if(ch>='0'&&ch<='9')    st.push(ch-'0');
        else
        {
            int operand1=st.top();
            st.pop();
            int operand2=st.top();
            st.pop();
            int result;
            switch(ch)
            {
            case '+':
                result=operand1+operand2;
                break;
            case '-':
                result=operand1-operand2;
                break;
            case '*':
                result=operand1*operand2;
                break;
            case '/':
                result=operand1/operand2;
                break;
            case '^':
                int res=1;
                for(int j=1;j<=operand2;j++)
                {
                    res*=operand1;
                }
                result=res;
                break;
            }
            st.push(result);
        }
    }
    return st.top();
}

int main()
{
    string input,prefix="";
    stack<char>s;
    cout << "Enter an infix expression: ";
    cin>>input;
    reverse(input.begin(),input.end());

    for(int i=0;i<input.size();i++)
    {
        char symbol=input[i];
        if((symbol>='A' && symbol<='Z') || (symbol>='a' && symbol<='z') || (symbol>='0' && symbol<='9'))
            prefix=prefix+symbol;
        else if(symbol==')')
            s.push(symbol);
        else if(symbol=='(')
        {
            while(!s.empty() && s.top()!=')')
            {
                prefix=prefix+s.top();
                s.pop();
            }
            if(!s.empty())      s.pop();
        }
        else if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/' || symbol=='^')
        {
            while(!s.empty() && precedence(symbol)<=precedence(s.top()))
            {
                prefix=prefix+s.top();
                s.pop();
            }
            s.push(symbol);
        }
    }

    while(!s.empty())
    {
        prefix=prefix+s.top();
        s.pop();
    }
    reverse(prefix.begin(),prefix.end());
    cout<<"The prefix expression is: "<<prefix<<endl;
    int result=prefixEvaluate(prefix);
    cout<<"Evaluation result: "<<result<<endl;
}

