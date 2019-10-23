#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int k,n,a,b,ans;
bool check(ll x)
{
    if(x>n)
        return 0;//因为我们要算的是在游戏次数刚好大于n时，玩的最大次数
    ll te=k-x*a-(n-x)*b;
    return te>0;//并且在游戏次数结束时，还剩有能量
}
int main()
{
    int q;
    scanf("%d",&q);

    while(q--)
    {
        scanf("%d%d%d%d",&k,&n,&a,&b);
        ans=-1;
        ll l=0,r=1e9;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid))
            {
                ans=mid;
                l=mid+1;//如果符合要求，每个题不一样，在这里，则代表答案还可以更大，因为我们找最大值
            }
            else
                r=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
