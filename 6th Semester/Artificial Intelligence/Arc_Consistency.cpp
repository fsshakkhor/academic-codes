#include<bits/stdc++.h>

using namespace std;

vector<int>st[15];
int n,m;
struct edge{
    int u,v,w;
};
vector<edge>E;

int compare(int a,int b,int w)
{
    if(w == 0)return a < b;
    if(w == 1)return a > b;
    if(w == 2)return a == b;
    if(w == 3)return a != b;
}
int val[10];
int checker()
{
    for(int i = 0;i < E.size();i++){
        int a = E[i].u;
        int b = E[i].v;
        if(compare(val[a],val[b],E[i].w) == 0)return 0;
    }
    return 1;
}
int fails = 0;
void rec(int pos)
{
    if(pos == n + 1){
        if(checker()){
            for(int i = 1;i <= n;i++)cout << val[i] << " ";
            cout << endl;
        }else{
            fails++;
        }
        return;
    }
    for(int i = 0;i < st[pos].size();i++){
        val[pos] = st[pos][i];
        rec(pos + 1);
    }
}
int main()
{

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int c,v;
        cin >> c;
        for(int j = 0;j < c;j++){
            cin >> v;
            st[i].push_back(v);
        }
    }
    ///0 means less than
    ///1 means greater than
    ///2 means equal
    ///3 means not equal
    for(int i = 1;i <= m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        E.push_back({a,b,c});
        if(c <= 1){
            E.push_back({b,a,1-c});
        }
    }

    while(1)
    {
        int toxic = 0;
        for(int i = 0;i < E.size();i++){
            int a = E[i].u;
            int b = E[i].v;
            for(int j = 0;j < st[a].size();j++){
                bool sat = 0;
                for(int k = 0;k < st[b].size();k++){
                    if(compare(st[a][j],st[b][k],E[i].w)){
                        sat = 1;
                    }
                }
                if(sat == 0){
                    toxic = 1;
                    st[a].erase(st[a].begin() + j);
                    break;
                }
            }
            if(toxic)break;
        }
        if(toxic == 0)break;
    }
    for(int i = 1;i <= n;i++){
        cout << char('A' + i - 1) << " -- > ";
        for(int j = 0;j < st[i].size();j++)cout << st[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << "Solution -> ";
    rec(1);
    cout << "\nNumber of Fails :" << fails << endl;
}
