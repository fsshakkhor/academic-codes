#include<bits/stdc++.h>

using namespace std;
queue<string>Q[1024];
vector<string>v;
void rec(int at,int l,int r)
{
    if(l > r)return;
    if(l==r){
        Q[at].push(v[l]);
        return;
    }
    int mid = (l+r)/2;
    rec(2*at,l,mid);
    rec(2*at+1,mid+1,r);

    while(!Q[2*at].empty() or !Q[2*at+1].empty()){

        if(Q[2*at].empty()){

            Q[at].push(Q[2*at+1].front());
            Q[2*at+1].pop();

        }else if(Q[2*at+1].empty()){
            Q[at].push(Q[2*at].front());
            Q[2*at].pop();
        }else{
            if(Q[2*at].front() < Q[2*at+1].front()){
                Q[at].push(Q[2*at].front());
                Q[2*at].pop();
            }else{
                Q[at].push(Q[2*at+1].front());
                Q[2*at+1].pop();
            }
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0;i<n;i++)cin >> v[i];
    rec(1,0,n-1);

    for(int i = 0;i<n;i++){
        cout << Q[1].front() << endl;
        Q[1].pop();
    }

}
