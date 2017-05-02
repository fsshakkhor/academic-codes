#include<bits/stdc++.h>

using namespace std;

int n;
int ara[123];

int partition(int lo,int hi)
{
    int pivot = ara[hi];
    int l = lo;
    for(int j = lo;j<hi;j++){
        if(ara[j]<=pivot){
            swap(ara[l],ara[j]);
            l++;
        }
    }
    swap(ara[l],ara[hi]);
    return l;
}
void quick(int lo,int hi)
{
    if(lo>=hi)return;
    int par = partition(lo,hi);
    quick(lo,par-1);
    quick(par+1,hi);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i<n;i++)cin >> ara[i];

    quick(0,n-1);
    for(int i = 0;i<n;i++)cout << ara[i] << " ";

}
