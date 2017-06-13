#include<bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));
    ofstream file("in.txt");

    int n = 100;
    file << n << endl;

    for(int i = 1;i<=n;i++){
        int len = 10;
        while(len--)
        {
            int d = rand()%26;
            char ch = d + 'A';
            file << ch;
        }
        file << endl;
    }



}
