#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=1e5+5;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
int mi[N<<2],add[N<<2];
int a[N],n;
void pushUp(int rt)
{
    mi[rt]=min(mi[rt<<1],mi[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        mi[rt]=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushUp(rt);
}
int query(int L,int R,int l,int r,int rt,int x)
{
    if(mi[rt]>=x) return inf;
    if(l<L||r>R) return inf;
    if(l==r) return l;
    int m=(l+r)>>1;
    int ans=inf;
    ans=query(L,R,l,m,rt<<1,x);
    if(ans==inf)
        ans=query(L,R,m+1,r,rt<<1|1,x);
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        build(1,n,1);
        int q;
        cin>>q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int ans=a[l];
            while(l<=r)
            {
                int pos=query(l,r,1,n,1,ans);
                if(pos==inf)
                {
                    break;
                }
                ans%=a[pos];
                l=pos+1;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
