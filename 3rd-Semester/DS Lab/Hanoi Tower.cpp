#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};

class Stack{
public:
    string name;
    node *p;
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
    void display(){
        cout << "Stack Name : " << name << "\t";
        node *now = p->next;
        while(now!=NULL){
                cout << now->data << " ";
                now=now->next;
        }
        cout << endl;
    }
};

void rec(int N,Stack *s1,Stack *s2,Stack *s3)
{
    if(N==0)return;

    rec(N-1,s1,s3,s2);

    int temp = s1->top();
    s1->pop();
    s3->push(temp);

    cout << "moving " << temp << " " << "from" << " "<<s1->name << " to " << s3->name << endl;
    s1->display();
    s2->display();
    s3->display();
    cout << endl;

    rec(N-1,s2,s1,s3);
}
int main()
{
    int n;
    cin >> n;
    Stack s1,s2,s3;
    s1.name="A";
    s2.name="B";
    s3.name="C";
    for(int i = n;i>=1;i--)s1.push(i);

//    cout << !s1.empty() << endl;
//    cout << !s2.empty() << endl;
//    cout << !s3.empty() << endl;

    rec(n,&s1,&s2,&s3);
//    cout << !s1.empty() << endl;
//    cout << !s2.empty() << endl;
//    cout << !s3.empty() << endl;
}
