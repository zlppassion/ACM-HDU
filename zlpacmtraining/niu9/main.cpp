#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=2e5+5;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
#define mid (l+r)/2
double X;
int n, q, num = 0;
int a[N], T[N];
double sum[N<<5];
int L[N<<5], R[N<<5],sz[N<<5];

inline int build(int l, int r)
{
    int rt = ++ num;
    sz[rt] = sum[rt]=0;
    if (l < r)
    {
        L[rt] = build(l, mid);
        R[rt] = build(mid+1, r);
    }
    return rt;
}

inline int update(int pre, int l, int r, double x)
{
    int rt = ++ num;
    L[rt] = L[pre];
    R[rt] = R[pre];
    sz[rt] = sz[pre]+1;
    sum[rt] = sum[pre]+x;
    if (l < r)
    {
        if (x <= mid) L[rt] = update(L[pre], l, mid, x);
        else R[rt] = update(R[pre], mid+1, r, x);
    }
    return rt;
}

inline int querySZ(int u, int v, int l, int r, int k)
{
    if(r<=k)
        return sz[v]-sz[u];
    int ans=0;
    ans+=querySZ(L[u], L[v], l, mid, k);
    if(k>mid)
        ans+=querySZ(R[u], R[v], mid+1, r, k);
    return ans;
}
inline int querySUM(int u, int v, int l, int r, int k)
{
    if(r<=k)
        return sum[v]-sum[u];
    int ans=0;
    ans+=querySUM(L[u], L[v], l, mid, k);
    if(k>mid)
        ans+=querySUM(R[u], R[v], mid+1, r, k);
    return ans;
}
double p[N];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,m;
    cin>>n>>m;
    T[0]=build(0,1e5);
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
        T[i]=update(T[i-1],0,1e5,a[i]);
    }
    for(int i=1; i<=m; i++)
    {
        ll l,r;
        double x,y;
        cin>>l>>r>>x>>y;
        double avg=(p[r]-p[l-1])/y;
    //    cout<<querySZ(T[l-1], T[r], 0, 1e5, 2.6)<<endl;
        double l1=0,r1=1e5;
        for(int i=0; i<200; i++)
        {
            X=(l1+r1)/2;
            double SZ=querySZ(T[l-1], T[r], 0, 1e5, X);
            double res=querySUM(T[l-1],T[r],0,1e5,X);
            res=y-(res+X*(r-l+1-SZ))/avg;
            if(fabs(x-res)<eps)
            {
                cout<<fixed<<setprecision(9)<<fabs(X)<<endl;
                break;
            }
            else if(x>res)
                r1=X-1;
            else
                l1=X+1;
        }
    }
    return 0;
}
