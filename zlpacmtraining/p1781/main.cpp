#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=1e6+5;
const int mod=1e9+7;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
#define int ll
ll sumc[N<<2],sumw[N<<2];
ll pushUp(int rt)
{
    sumw[rt]=sumw[rt<<1]+sumw[rt<<1|1];
    sumc[rt]=sumc[rt<<1]+sumc[rt<<1|1];
}
void update(int c,int w,int l,int r,int rt)
{
    if(l==r)
    {
        if(!sumc[rt])
        {
            sumw[rt]=w,sumc[rt]=c;
        }
        return ;
    }
    ll m=(l+r)>>1;
    if(c<=m)
        update(c,w,l,m,rt<<1);
    else
        update(c,w,m+1,r,rt<<1|1);
    pushUp(rt);
}
void del(int o,int l,int r,int rt)
{
    if(l==r)
    {
        if(sumc[rt])
        {
            sumc[rt]=sumw[rt]=0;
        }
        return ;
    }
    ll m=(l+r)>>1;
    if((o==2&&sumc[rt<<1|1])||!sumc[rt<<1])
        del(o,m+1,r,rt<<1|1);
    else if((o==3&&sumc[rt<<1])||!sumc[rt<<1|1])
        del(o,l,m,rt<<1);
    pushUp(rt);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    int o,w,c;
    while(cin>>o&&o!=-1)
    {
        if(o==1)
        {
            cin>>w>>c;
            update(c,w,1,N-1,1);
        }
        else
        {
            del(o,1,N-1,1);
        }
    }
    cout<<sumw[1]<<" "<<sumc[1]<<endl;
    return 0;
}
