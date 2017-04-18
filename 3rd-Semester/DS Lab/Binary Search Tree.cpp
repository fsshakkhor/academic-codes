#include<bits/stdc++.h>

using namespace std;
class node
{
public:
    int val;
    node *l;
    node *r;
    node(){
        l = r = nullptr;
        val = -999;
    }
};

void traverse(node *ptr)
{
    if(ptr->l!=nullptr)traverse(ptr->l);
    cout << ptr->val << " ";
    if(ptr->r!=nullptr)traverse(ptr->r);
}

void insert(node *ptr,int value)
{
    if(ptr->val==-999){
        ptr->val = value;
        return;
    }
    if(ptr->val < value){
        if(ptr->r==nullptr){
            node *now = new node();
            now->val = value;
            ptr->r = now;
        }else{
            insert(ptr->r,value);
        }
    }else if(ptr->val >= value){
        if(ptr->l==nullptr){
            node *now = new node();
            now->val = value;
            ptr->l = now;
        }else{
            insert(ptr->l,value);
        }
    }
}

void remove(node *ptr,int value,node *pr)
{
    if(ptr->val < value){
        if(ptr->r==nullptr){
            cout << ":Value not found\n";
        }else{
            remove(ptr->r,value,ptr);
        }
    }else if(ptr->val > value){
        if(ptr->l==nullptr){
            cout << ":Value not found\n";
        }else{
            remove(ptr->l,value,ptr);
        }
    }else{
        if(ptr->l==nullptr && ptr->r==nullptr){
            if(pr==nullptr){
                pr->val = -999;
                return;
            }
            if(pr->l!=nullptr && (pr->l)->val==ptr->val)pr->l = nullptr;
            if(pr->r!=nullptr && (pr->r)->val==ptr->val)pr->r = nullptr;
            free(ptr);
        }else if(ptr->r==nullptr){
            while(ptr->l!=nullptr)
            {
                swap(ptr->val,(ptr->l)->val);
                pr = ptr;
                ptr = ptr->l;
            }
            if(pr!=nullptr)pr->l = nullptr;
            free(ptr);
        }else{
            node *now = ptr->r;
            pr = now;
            while(now->l!=nullptr){
                pr = now;
                now = now->l;
            }
            swap(now->val,ptr->val);
            if(pr!=nullptr)pr->l=nullptr;
            free(now);
        }
    }
}
int main()
{
    node *root = new node;
    cout << "1. Insert Value\n";
    cout << "2. Show Inorder Traversal\n";
    cout << "3. Delete Value\n";
    while(true){
        int value,choice;
        cout <<  "Enter Your Choice : ";
        cin >> choice;
        if(choice==1){
            cout << "How many values do you want to insert ?\n:";
            int timer;cin >> timer;
            while(timer--){cin >> value;insert(root,value);}
        }else if(choice==2){
            cout << "Values in BST : ";
            traverse(root);
            cout << endl;
        }else {
            cout << "Enter The Value : ";
            cin >> value;
            cout << endl;
            remove(root,value,nullptr);
        }
        cout << endl;
    }
}
