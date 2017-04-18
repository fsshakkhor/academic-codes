#include<bits/stdc++.h>

using namespace std;

struct data
{
    int id;
    char ip[100];
    data *Next;
};
struct data *root;
int total = 0;
void add()
{
    total++;
    char s[100];
    int ID;
    cout << "Enter ID: ";cin >> ID;
    cout << "Enter IP: ";cin >> s;

    data *now = root;
    while(now->Next !=root)now = now->Next;

    data *newnode = (struct data *)malloc(sizeof(struct data));
    newnode->id = ID;
    strcpy(newnode->ip,s);
    newnode->Next = root;

    now->Next = newnode;
}

void print()
{
    cout << "->List of All Computers:\n";
    data *now = root;
    do
    {
        cout << "\t\t\tID : " << now->id << endl;
        cout << "\t\t\tIP : " << now->ip << endl;
        cout << endl;
        now = now->Next;
    }while(now!=root);
}

void removing()
{
    int ID;
    cout << "Enter The Computer ID: ";cin >> ID;
    data *now = root;
    int found = 0;
    do
    {
        if(now->id==ID){
            found = 1;break;
        }
        now = now->Next;
    }while(now!=root);

    if(!found)cout << "\t\t\tID Not Found\n";
    else{
        data *here = root;
        while(here->Next!=now){
            here = here->Next;
        }
        here->Next = now->Next;
        free(now);
        cout << "ID " << ID << " Removed\n";
    }
}

void visit()
{
    int id1,id2;
    cout << "Enter The Two IDs : ";
    cin >> id1 >> id2;
    data *now = root;
    data *start;
    int found = 0;
    do
    {
        if(now->id==id1){
            found++;
            start = now;
        }else if(now->id==id2){
            found++;
        }
        now = now->Next;
    }while(now!=root);
//    cout << found << endl;
    if(found<2)cout << "\t\t\tInvalid IDs\n";
    else{
        cout << "-> All Computers Between " << id1 << " and " << id2 << ":\n";
        int counter = 0;
        while(start->id!=id2){
            cout << endl;
            cout << "\t\t\t\tID: " << start->id << endl;
            cout << "\t\t\t\tIP: " << start->ip << endl;
            start = start->Next;counter++;
        }
        cout << endl;
        cout << "\t\t\t\tID: " << start->id << endl;
        cout << "\t\t\t\tIP: " << start->ip << endl;
        counter++;
        cout << "\t\t\t\tNumber of Computers Between Them : " << counter << endl;
    }

}

void change()
{
    data *now = root;
    int ID;
    cout << "Enter The ID of the new Master PC: ";cin >> ID;
    int found = 0;
    do
    {
        if(now->id==ID){
            found = 1;break;
        }
        now = now->Next;
    }while(now!=root);

    if(!found)cout << "\t\t\t\tID Not Found\n";
    else{
        root = now;
    }
}

void show()
{
    cout << endl;
    cout << "\t\t\tID of Master PC: " << root->id << endl;
    cout << "\t\t\tIP of Master PC: " << root->ip << endl;
    cout << endl;
}
void close()
{
    int id1,id2;
    cout << "Enter The Two IDs : ";
    cin >> id1 >> id2;
    data *now = root;

    int dis1 = 0;
    do
    {
        if(now->id==id1)break;
        dis1++;
        now = now->Next;
    }while(now!=root);

    now = root;

    int dis2 = 0;
    do
    {
        if(now->id==id2)break;
        dis2++;
        now = now->Next;
    }while(now!=root);

    cout << endl;
    if(dis1<dis2)cout << "\t\t\t\tCloser PC is " << id1 << endl;
    else cout << "\t\t\t\tCloser PC is " << id2 << endl;
    cout << endl;
}
int main()
{
    char s[100];
    int ID;
    total = 1;
    root = (struct data *)malloc(sizeof(struct data));

    cout << "Set The Master PC ->\n\nEnter ID: ";
    cin >> ID;
    cout << "Enter IP Address: ";
    cin >> s;

    root->id = ID;
    strcpy(root->ip,s);
    root->Next = root;

    cout << endl;
    cout << "1 -> Add Computer\n";
    cout << "2 -> Print\n";
    cout << "3 -> Remove Computer\n";
    cout << "4 -> Visit Computers\n";
    cout << "5 -> Change Master PC\n";
    cout << "6 -> Show The Master PC\n";
    cout << "7 -> Closer PC Check\n";
    cout << endl;

    while(1)
    {
        cout << "Enter Your Choice: ";
        int ch;
        cin >> ch;
        if(ch==1)add();
        else if(ch==2)print();
        else if(ch==3)removing();
        else if(ch==4)visit();
        else if(ch==5)change();
        else if(ch==6)show();
        else if(ch==7)close();
        getchar();
    }


}

/*
101 25
1 105 26
1 110 27
1 103 28
1 125 29
1 140 30
1 152 31
1 139 32
*/
