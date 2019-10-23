#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
//int a[100005];
ll mul(ll a,ll b,ll p) //快速乘取模，计算a*b%p
{
    ll res=0;
    while(b)
    {
        if(b&1) res =(res+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return res;
}
ll gpow(ll a,ll b,ll p)//快速幂 a^b%p
{
    ll t=a%p,ans=1;
    while(b)
    {
        if(b&1)  ans=ans*t%p;
        t=t*t%p;
        b>>=1;
    }
    return ans;
}
ll inv(ll a,ll p)//逆元
{
    return gpow(a,p-2,p);
}
ll C(ll n,ll m,ll p) //求组合数C(n,m)%p
{
    if(m>n||n<0||m<0) return 0;
    if(m==0||n==m) return 1;
    if(m>n-m) m=n-m;
    ll ca=1,cb=1;
    for(ll i = 0; i<m; i++)
    {
        ca=ca*(n-i)%p;
        cb=cb*(m-i)%p;
    }
    return ca*inv(cb,p)%p;
}
ll Lucas(ll n,ll m,ll p)//大组合数C(n,m)%p
{
    if(m ==0) return 1;
    else return (C(n%p,m%p,p)*Lucas(n/p,m/p,p))%p;
}
int main()
{
  ll n,k, p;
  scanf("%lld%lld%lld",&n,&k,&p);
  //p=(k/n)%mod;
  ll ans=0;
  for(int i=k;i<=n;i++)
  {
      ll  a=Lucas(n,i,mod),b=gpow(p,i,mod),c=gpow(1-p,n-i,mod);
      cout<<a<<","<<b<<","<<c<<endl;
      ll temp=(Lucas(n,i,mod)*gpow(p,i,mod)*gpow(1-p,n-i,mod))%mod;
      cout<<"temp"<<temp<<endl;
     ans=(ans+temp)%mod;
     cout<<"ans"<<ans<<endl;
  }
  printf("%lld\n",ans);
  return 0;
}
