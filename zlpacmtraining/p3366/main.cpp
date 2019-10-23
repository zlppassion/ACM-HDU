#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int maxv=5005;
const int maxe=200005;
struct edge
{
    int u,v;
    int cost;
}e[maxe];
bool cmp(edge a,edge b)
{
    return a.cost<b.cost;
}
int father[maxv];
int findfather(int v)
{
    if(v==father[v])
        return v;
    else
    {
        int F=findfather(father[v]);
        father[v]=F;
        return F;
    }
}
ll kruskal(int n,int m)
{
    ll ans=0;
    int num_edge=0;
    for(int i=0;i<n;i++)
    {
        father[i]=i;
    }
    sort(e,e+m,cmp);
    for(int i=0;i<m;i++)
    {
        int fau=findfather(e[i].u);
        int fav=findfather(e[i].v);
        if(fau!=fav)
        {
            father[fau]=fav;
            ans+=e[i].cost;
            num_edge++;
            if(num_edge==n-1)
                break;
        }
    }
    if(num_edge!=n-1)
        return -1;
    else
        return ans;
}
signed main()
{
    int n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].cost);
    }
    ll aa=kruskal(n,m);
    if(aa==-1)
    {
        cout<<"orz"<<endl;
    }
    else
        cout<<aa<<endl;
    return 0;
}
