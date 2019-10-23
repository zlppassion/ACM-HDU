#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn=10000005;
int vis[maxn];
int prime[maxn];
int tot;
void shai()
{
    tot=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i])
            prime[tot++]=i;
        for(int j=0;j<tot&&prime[j]*i<maxn;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
int main()
{
    shai();
    int n,m;
    scanf("%d%d",&n,&m);
    int p;
    vis[1]=1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&p);
        if(!vis[p])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}
