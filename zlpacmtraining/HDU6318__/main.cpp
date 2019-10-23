#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
#define int ll
#define lowbit(x) (x&(-x))
int c[N];
struct node
{
    int v,id;
    bool operator < (node b)
    {
        return (v<b.v)||(v==b.v&&id<b.id); //��С��������
    }
} node[N];
int n;
void add(int i)
{
    while(i<=n)
    {
        c[i]++;
        i+=lowbit(i);
    }
}
long long sum(int i)
{
    long long res=0;
    while(i>0)
    {
        res+=c[i];
        i-=lowbit(i);
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
            node[i].id=i;
            node[i].v=a;
        }
        sort(node+1,node+1+n);
        ll ans=0;
        for(int i=1; i<=n; i++)
        {
            add(node[i].id);  //��ɢ��������� �±��Ч����ֵ
            ans+=i-sum(node[i].id); //�õ�֮ǰ�ж��ٸ���������������ԣ�
        }
       printf("%lld\n",ans*min(x,y));
    }

    return 0;
}
