#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll gpow(ll a,ll b,ll p)//������ a^b%p
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
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    if(k==1)
        cout<<"0"<<endl;
    else
    {
        ll ans=((n-2,k-1,mod))%mod;
        cout<<ans<<endl;
    }
    //��1�������󾭹�k���ص�1�ķ���������
    return 0;
}
