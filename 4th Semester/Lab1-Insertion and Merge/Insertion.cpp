#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    vector<string>v(n);
    for(int i = 0;i<n;i++)cin >> v[i];

    for(int i = 1;i<n;i++){
        int in = i;
        while(in>0){
            if(v[in] < v[in-1]){
                swap(v[in],v[in-1]);
            }else break;

            in--;
        }
    }
    for(int i = 0;i<n;i++)cout << v[i] << endl;


}
