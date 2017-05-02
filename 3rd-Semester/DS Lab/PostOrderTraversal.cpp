#include<bits/stdc++.h>

using namespace std;
struct data{
    int left,right;
    int val;
    data(){
        left = right = 0;
    }
}nodes[1001];

class Stack
{
public:
    data ara[1001];
    int sz;
    Stack(){
        sz = 0;
    }
    data top(){
        return ara[sz];
    }
    bool empty(){
        return sz==0;
    }
    void push(data val){
        ara[++sz]=val;
    }
    void pop(){
        sz--;
    }
    int size(){
        return sz;
    }
};

int vis[1001];
int main()
{
    int n,root;
    cout << "Enter The Number of Nodes: ";
    cin >> n;

    int x;
    for(int i = 1;i<=n;i++){
        cout << "Enter the Left and Right Child of " << i << " : ";
        cin >> nodes[i].left;
        cin >> nodes[i].right;
        nodes[i].val = i;
    }
    Stack st;
    st.push(nodes[1]);

    cout << "\nTraverse : ";
    while(!st.empty()){
        data temp = st.top();
        vis[temp.val]++;

        if(vis[temp.val]==1 and temp.left!=0){
            st.push(nodes[temp.left]);
            continue;
        }
        if(vis[temp.val]==2 and temp.right!=0){
            st.push(nodes[temp.right]);
            continue;
        }
        cout << temp.val << " ";
        st.pop();
    }

}
