#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
#define ll long long
#define int ll
int c[maxn];
struct Node
{
    int v,index;
    bool operator < (const Node &b) const
    {
        return v<b.v; //从小到大排序
    }
} node[maxn];
int n;
void add(int i)
{
    while(i<=n)
    {
        c[i]++;
        i+=i&(-i);
    }
}
long long sum(int i)
{
    long long res=0;
    while(i>0)
    {
        res+=c[i];
        i-=i&(-i);
    }
    return res;
}

signed main()
{
    ll x,y;
    while(~scanf("%lld%lld%lld",&n,&x,&y))
    {
        memset(c,0,sizeof(c));
        int a;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a);
            node[i].index=i;
            node[i].v=a;
        }
        sort(node+1,node+1+n);
        long long ans=0;
        for(int i=1; i<=n; i++)
        {
            add(node[i].index);  //离散化结果—— 下标等效于数值
            ans+=i-sum(node[i].index); //得到之前有多少个比你大的数（逆序对）
        }
       printf("%lld\n",abs(ans)*min(x,y));
    }

    return 0;
}
