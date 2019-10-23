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
        return v<b.v; //��С��������
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
            add(node[i].index);  //��ɢ��������� �±��Ч����ֵ
            ans+=i-sum(node[i].index); //�õ�֮ǰ�ж��ٸ���������������ԣ�
        }
       printf("%lld\n",abs(ans)*min(x,y));
    }

    return 0;
}
