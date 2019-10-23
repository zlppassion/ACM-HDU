#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005];
ll dp[200005];
ll ans=-10005;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        dp[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(dp[i],dp[i-1]+dp[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
