#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
int main()
{
    ll b,p,k;
    cin>>b>>p>>k;
    cout<<b<<"^"<<p<<" mod "<<k<<"="<<gpow(b,p,k)%k<<endl;
    return 0;
}
