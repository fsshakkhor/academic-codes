#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cmath>

using namespace std;

class stack
{
    string str;
public:
    void push(char ch)
    {
        str += ch;
    }
    void pop()
    {
        str.erase(str.end()-1);
    }
    char top()
    {
        char ch = str[str.size()-1];
        return ch;
    }
    int size()
    {
        return str.size();
    }
    void print()
    {
        for(int i = 0 ;i<str.size();i++)
        {
            if(i)cout <<  " ";
            cout << str[i];
        }
        cout << endl;
    }
};

class stackint
{
public:
    int ara[102];
    int sz;

    stackint()
    {
        sz = 0;
    }
    void push(int ch)
    {
        ara[sz]=ch;
        sz++;
    }
    void pop()
    {
        sz--;
    }
    char top()
    {
        return ara[sz-1];
    }
    int size()
    {
        return sz;
    }
};

int match(char a,char b)
{
    if(a=='(' and b==')')return 1;
    if(a=='{' and b=='}')return 1;
    if(a=='[' and b==']')return 1;
    return 0;
}
int check_balance(string str)
{
    stack st;
    for(int i= 0;i<str.size();i++)
    {
        if(str[i]==' ')continue;
        if(str[i]=='(' or str[i]=='{' or str[i]=='[')
           {
                st.push(str[i]);
                //cout << st.top() << " " << i << endl;
           }
           else if(str[i]==')' or str[i]=='}' or str[i]==']')
           {
                if(st.size()==0){
                    return 0;
                }
               //cout << "poping " << i << " "<< st.top() << " " << str[i]  << endl;
                if(!match(st.top(),str[i])){
                    return 0;
                }
                st.pop();
           }
    }
    return 1;
}

int isbracket(char ch)
{
    if(ch=='(' or ch==')' or ch=='{' or ch=='}' or ch=='[' or ch==']')return 1;
    else return 0;
}
int isopen(char ch)
{
    if(ch=='(' or ch=='{' or ch=='[' )return 1;
    else return 0;
}
int isclose(char ch)
{
    if(ch==')' or ch=='}' or ch==']' )return 1;
    else return 0;
}

int precedence(char ch)
{
    if(isbracket(ch))return 0;
    if(ch=='-' or ch=='+')return 1;
    if(ch=='*')return 2;
    if(ch=='/')return 3;
    if(ch=='^')return 4;
}
void output(string str)
{
    stack st,exp;
    for(int i = 0;i<str.size();i++)
    {
        if(str[i]==' ')continue;
        if(isdigit(str[i]))
        {
            exp.push(str[i]);
            continue;
        }
        if(isbracket(str[i]))
        {
            if(isopen(str[i]))st.push(str[i]);
            else{
                int val = str[i] - 1;

                while(st.top()!=val)
                {
                    exp.push(st.top());
                    st.pop();
                }
                st.pop();
            }
            continue;
        }
        char ch = st.top();
        if(precedence(str[i])<=precedence(ch))
        {
            exp.push(st.top());
            st.pop();
            st.push(str[i]);
            ch = st.top();
        }
        else
        {
            st.push(str[i]);
        }
    }
    cout << endl;
    cout << "Postfix : ";
    exp.print();

    string s;
    while(exp.size()!=0){
        s+= exp.top();
        exp.pop();
    }
    reverse(s.begin(),s.end());

    stackint now;
    for(int i = 0;i<s.size();i++)
    {
        if(isdigit(s[i])){
            now.push(s[i]-'0');
            continue;
        }
        int c1 = now.top();
        now.pop();
        int c2 = now.top();
        now.pop();
        if(s[i]=='+')now.push(c1+c2);
        else if(s[i]=='-')now.push(c2-c1);
        else if(s[i]=='*')now.push(c1*c2);
        else if(s[i]=='/')now.push(c2/c1);
        else if(s[i]=='^')now.push(pow(c2,c1));
    }
    cout << "Answer : ";
    cout << (int)now.top() << endl;
}

int main()
{
    cout << "Task 1 : Check Balanced" << endl;
    cout << "Task 2 : Conversion" << endl;
    cout << endl;
    while(1)
    {
        int choice;
        cout << "Enter your Choice : ";
        cin >> choice;
        getchar();
        cout << "Enter The String : ";
        string str;
        getline(cin,str);
        if(choice==1)
        {
            int out = check_balance(str);
            if(out)cout << "\t\t--->Valid\n\n";
            else cout << "\t\t--->Invalid\n\n";
        }
        else if(choice==2)
        {
            output(str);
        }

    }

}
//(5*(6+2)-6/2)
