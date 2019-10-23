#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll  long long
const ll inf=0x3f3f3f3f;
ll a[205][205];
ll dp[205][205];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(i==n)
                dp[n][j]=-inf;
        }
    }
    dp[n][m/2]=a[n][m/2],dp[n][m/2+1]=a[n][m/2+1],dp[n][m/2+2]=a[n][m/2+2];
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
        {
            ll x=dp[i+1][j],y=dp[i+1][j-1],z=dp[i+1][j+1];
            if(j-1==0)
                y=-inf;
            if(j+1==m+1)
                z=-inf;
             x=max(x,y);
             x=max(x,z);
             if(x==-inf)
                dp[i][j]=-inf;
             else
                dp[i][j]=a[i][j]+x;

        }
    }
    ll ans=0;
    for(int j=1;j<=m;j++)
    {
        ans=max(ans,dp[1][j]);
    }
    cout<<ans<<endl;
    return 0;
}
