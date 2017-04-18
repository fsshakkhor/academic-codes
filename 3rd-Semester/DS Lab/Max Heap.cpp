#include<bits/stdc++.h>

using namespace std;

class Heap{
public:
    int ara[105];
    int sz;
    Heap(){
        sz = 0;
    }
    void push(int val){
        sz++;
        ara[sz] = val;
        int temp = sz;
        while(temp!=1 and ara[temp/2]<ara[temp]){
            swap(ara[temp],ara[temp/2]);
            temp = temp/2;
        }
    }
    bool empty(){
        return sz==0;
    }
    int top(){
        return ara[1];
    }
    void pop(){
        swap(ara[1],ara[sz]);
        sz--;
        int temp = 1;
        while(1){
            int in=-1,mx = ara[temp];
            if(2*temp<=sz and ara[2*temp]>mx){
                mx = ara[2*temp];
                in = 2*temp;
            }
            if(2*temp+1<=sz and ara[2*temp+1]>mx){
                mx = ara[2*temp+1];
                in = 2*temp + 1;
            }
            if(in==-1)break;
            swap(ara[temp],ara[in]);
            temp = in;
        }
    }
};
int main()
{
    Heap Q;
    cout << "1. Insert" << endl;
    cout << "2. Delete Top" << endl;
    cout << "3. Show Top" << endl;
    while(1){
        cout << "Have Your Choice: ";
        int ch,val;
        cin >> ch;
        if(ch==1){
            cout << "Enter The Value : ";
            cin >> val;
            Q.push(val);
        }else if(ch==2){
            if(Q.empty())cout << "Message : The Heap is already Empty.\n";
            else {
                Q.pop();
                cout << "Message : Successfully Deleted Top."<< endl;
            }
        }else{
            if(Q.empty())cout << "Message : The Heap is Empty.\n";
            else cout << "The Top Element is : " << Q.top() << endl;
        }
        cout << endl;
    }
}
