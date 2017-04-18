#include<bits/stdc++.h>

using namespace std;

const int total = 100;
int link[total];
int ex[total];
int cof[total];

int find_avail()
{
    for(int i = 2;i<=total;i++)
    {
        if(link[i]==-1)return i;
    }
}

int find_last()
{
    int id = 1;
    while(link[id]!=0)
    {
        id = link[id];
    }
    return id;
}

void print()
{
    int id = link[1];
    cout << "\nP(x) = ";
    while(id!=0)
    {
        if(cof[id]!=0){
            if(id!=link[1] and cof[id]>0)cout << " +";

            if(cof[id]!=1)cout << cof[id];

            if(ex[id]>0)cout << "x";
            if(ex[id]>1)cout << "^" << ex[id] << " ";
        }
        id = link[id];
    }
    cout << endl;
}

int exist(int expo)
{
    int id = link[1];
    while(id!=0)
    {
        if(ex[id]==expo)return id;
        id = link[id];
    }
    return -1;
}

void add()
{
    int c,e;
    cout << "Enter The Co-efficient and Expo: ";
    cin >> c >> e;
    int avail = exist(e);
    if(avail==-1)
    {
        avail = find_avail();
        cof[avail]=c;
        ex[avail]=e;
        link[avail]=0;
        int last = find_last();
        link[last]=avail;
    }
    else
    {
        cof[avail]+=c;
    }
}
void final_sort()
{
    int timer = total;
    while(timer--)
    {
        int id = link[1];
        while(link[id]!=0)
        {
//            cout << id << " " << link[id] << " " << ex[id] << " " << ex[link[id]] << endl;
            if(ex[link[id]]>ex[id]){
                swap(ex[link[id]],ex[id]);
                swap(cof[link[id]],cof[id]);
            }
            id = link[id];
        }
    }
}
int main()
{
    memset(link,-1,sizeof(link));link[1]=0;
    cout << "\n1.Add\n2.Print\n3.Sort\n";
    while(1)
    {
        int input;
        cout << "Enter Your Choice : ";
        cin >> input;
        if(input==1)add();
        else if(input==2)print();
        else if(input ==3 )final_sort();
    }
}
/*
1
2 3
1
3 4
1
1 2
2
*/
