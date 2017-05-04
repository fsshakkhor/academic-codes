#include<bits/stdc++.h>
#include <direct.h>
#include <sstream>

using namespace std;

void makeit(int n,char *str)
{
    string s;

    while(n>0){
        int r = n%10;
        char ch = char('0' + r);
        s+=ch;
        n/=10;
    }
    reverse(s.begin(),s.end());
    int in = s.size();

    for(int i = 0;i<s.size();i++)str[i]=s[i];

    str[in++] = '/';
    for(int i = 0;i<s.size();i++)str[in++]=s[i];
    str[in++]='.';
    str[in++]='p';
    str[in++]='d';
    str[in++]='f';

    str[in++] = '\0';

}

int main()
{

    char buf[1004];
    char str[1002];
    for(int i = 154401;i<=154445;i++)
    {
        ifstream in("154435.pdf", ios::binary);

        makeit(i,str);

        ofstream out(str, ios::binary);

        while(!in.eof())
        {
            in.read(buf, sizeof(buf));
            out.write(buf,sizeof(buf));
        }
        in.close();
        out.close();
    }

}
