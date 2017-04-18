#include<bits/stdc++.h>

using namespace std;
int A[123],B[123];

struct node{
    int data;
    node *next;
};

class Stack{
    node *p;
public:
    Stack(){
        p = (struct node *)(malloc(sizeof(node)));
    }
    void push(int value){
        node *newnode = (struct node *)(malloc(sizeof(node)));
        newnode->data = value;
        newnode->next = p->next;
        p->next = newnode;
    }
    int top(){
        return (p->next)->data;
    }
    void pop(){
        p = p->next;
    }
    bool empty(){
        if(p->next==NULL)return 1;
        else return 0;
    }
};

int main()
{
    int n;
    cin >> n;
    Stack st;
    for(int i = 0;i<n;i++){
        cin >> A[i];
    }
    for(int i = n-1;i>=0;i--){
        while(not st.empty() and A[i]>st.top()){
            st.pop();
        }
        if(st.empty())B[i]=-1;
        else B[i]=st.top();
        st.push(A[i]);
    }
    for(int i = 0;i<n;i++)cout << B[i] << " ";

}
