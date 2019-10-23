#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tree[10010];
    int leight=0,moved=0,result=0;
    cin>>leight>>moved;
    for(int i=0;i<10010;i++)
        tree[i]=0;
    while(moved--)
    {
        int start=0,end=0;
        cin>>start>>end;
        tree[start]++;
        tree[end+1]--;
    }
    for(int i=0,cut=0;i<=leight;i++)
    {
        cut+=tree[i];
        if(cut<=0)
            result++;
    }
    cout<<result<<endl;
    return 0;
}
