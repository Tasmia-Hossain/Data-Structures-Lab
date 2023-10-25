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

int postfixEvaluate(string postfix)
{
    stack<int>st;
    for(int i=0;i<postfix.size();i++)
    {
        char ch=postfix[i];
        if(ch>='0'&&ch<='9')    st.push(ch-'0');
        else
        {
            int operand2=st.top();
            st.pop();
            int operand1=st.top();
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
    string input,postfix="";
    stack<char>s;
    cout << "Enter an infix expression: ";
    cin>>input;
    for(int i=0;i<input.size();i++)
    {
        char symbol=input[i];
        if((symbol>='A' && symbol<='Z') || (symbol>='a' && symbol<='z') || (symbol>='0' && symbol<='9'))
            postfix=postfix+symbol;
        else if(symbol=='(')
            s.push(symbol);
        else if(symbol==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                postfix=postfix+s.top();
                s.pop();
            }
            if(!s.empty())      s.pop();
        }
        else if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/' || symbol=='^')
        {
            while(!s.empty() && precedence(symbol)<=precedence(s.top()))
            {
                postfix=postfix+s.top();
                s.pop();
            }
            s.push(symbol);
        }
    }

    while(!s.empty())
    {
        postfix=postfix+s.top();
        s.pop();
    }
    cout<<"The postfix expression is: "<<postfix<<endl;
    int result=postfixEvaluate(postfix);
    cout<<"Evaluation result: "<<result<<endl;
}
