#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int father[10005];
int n,m,z;
void init()
{
    for(int i=0;i<=n;i++)
    {
        father[i]=i;
    }
}
int findfather(int x)
{
    if(x!=father[x])
        father[x]=findfather(father[x]);
    return father[x];
}
void UN(int x,int y)
{
    x=findfather(x);
    y=findfather(y);
    if(x!=y)
        father[x]=y;
}
bool same(int x,int y)
{
    return findfather(x)==findfather(y);
}
int main()
{
    cin>>n>>m;
    init();
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&z,&x,&y);
        if(z==1)
            UN(x,y);
        else
        {
            if(same(x,y))
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;
        }
    }
    return 0;
}
