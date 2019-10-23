#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const int maxn=2e5+5;
#define ll long long
struct node
{
    ll x,y;//x代表值，y代表索引
};
ll n,k,b[maxn],big;
ll f[maxn];
node a[maxn];
ll sum;
bool cmp(node a,node b)
{
    return (a.x<b.x || (a.x==b.x && a.y<b.y));
}
int lowb(int x)
{
    return x&(-x);
}
long long find(ll x)
{
    long long tmp = 0;
    ll y = x;
    while (y>0)
    {
        tmp += f[y];
        y -= lowb(y);
    }
    return tmp;
}
void insert(int x)
{
    ll y = x;
    while (y<=n)
    {
        f[y] ++;
        y += lowb(y);
    }
}
ll x,y;
void work()
{
    big=0;
    sort(a+1,a+1+n,cmp);
    a[0].x=-1;
    for (int i=1; i<=n; i++)
    {
        if (a[i].x!=a[i-1].x) big++;
        b[a[i].y]=big;
    }
    memset(f,0,sizeof(f));
    long long ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        ans +=  (find(n)-find(b[i]));
        insert(b[i]);
    }
    printf("%lld\n",ans*min(x,y));
}
int main()
{

    while(scanf("%lld%lld%lld",&n,&x,&y)!=EOF)
    {
        for (int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i].x);
            a[i].y=i;
        }
        work();
    }
    return 0;
}
