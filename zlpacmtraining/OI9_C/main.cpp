#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll gpow(ll a,ll b,ll p)
{
    ll t=a%p,ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*t%p;
        }
        t=t*t%p;
        b>>=1;
    }
    return ans;
}
ll inv(ll a,ll p)
{
    return gpow(a,p-2,p);
}
ll C(ll n,ll m,ll p)
{
    if(m>n||n<0||m<0)
        return 0;
    if(m==0||n==m)
        return 1;
    if(m>n-m)
        m=n-m;
    ll ca=1,cb=1;
    for(ll i=0;i<m;i++)
    {
        ca=ca*(n-i)%p;
        cb=cb*(m-i)%p;
    }
    return ca*inv(cb,p)%p;
}
ll lucas(ll n,ll m,ll p)
{
    if(m==0)
        return 1;
    else
    {
        return (C(n%p,m%p,p)*lucas(n/p,m/p,p))%p;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
   if(n==1)
    {
        printf("%d\n",26);
    }
    else if(n==2)
    {
        printf("%d\n",26*26);
    }
    else if(n==3)
    {
        printf("17570\n");
    }
    else if(n==4)
    {
        ll ans=0;
        ans=pow(26,4)-(26*4)*6;
        printf("%d\n",ans%mod);
    }
    else if(n==5)
    {
        ll ans=0;
        ans=pow(26,5)-(pow(26,2)*5*4*3);
        printf("%d\n",ans%mod);
    }
    else
    {
        ll ans=gpow(26,n,mod);
        ans-=(gpow(26,n-3,mod)*lucas(n,3,mod)*6);
        printf("%lld\n",ans);
    }

    return 0;
}
