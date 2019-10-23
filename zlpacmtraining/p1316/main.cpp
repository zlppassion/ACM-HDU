#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int A,B;
ll ans;
ll a[100005];
bool check(ll dd)
{
    ll tot=1;
    ll num=1;
    for(int i=2;i<=A;i++)
    {
        if(a[i]-a[num]>=dd)
        {
            tot++;//我们当前想的是最大距离为dd，当大于等于了，就应该选一个点了
            num=i;
        }
    }
    if(tot<B)//如果选的数还不足B，说明距离偏大，不符合要求
    {
        return false;
    }
     else//否则正确
        return true;
}
int main()
{
    scanf("%d%d",&A,&B);
    for(int i=1; i<=A; i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+A);
    ll l=0,r=a[A]-a[1],mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
             ans=mid;
             l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
