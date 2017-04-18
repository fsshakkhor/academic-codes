#include<bits/stdc++.h>

using namespace std;
bool w[102][102];
bool adj[102][102];
int deg[102];
bool vis[102];
int main()
{
    int n,m;
    cout << "Enter The Number of Nodes: ";
    cin >> n;
    cout << "Enter The Number of Edges: ";
    cin >> m;

    while(m--){
        cout <<"Enter A Connection: ";
        int a,b;
        cin >> a >> b;
        adj[a][b]=1;
        deg[b]++;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            w[i][j] = adj[i][j];
        }
    }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                w[i][j] = w[i][j] || (w[i][k]&&w[k][j]);
            }
        }
    }
    int valid = 1;
    for(int i = 1;i<=n;i++)if(w[i][i])valid=0;

    queue<int>Q;
    for(int i =1;i<=n;i++){
        if(deg[i]==0){
            vis[i]=1;
            Q.push(i);
        }
    }
    cout << "Topological Order : ";
    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        cout << temp << " - ";
        for(int i = 1;i<=n;i++){
            if(adj[temp][i]==1){
                deg[i]--;
            }
            if(vis[i]==0 and deg[i]==0){
                vis[i]=1;
                Q.push(i);
            }
        }
    }

}
/*
5 4
1 2
2 3
2 4
3 5
*/
