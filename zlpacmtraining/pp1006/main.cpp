#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[55][55][55][55];
int a[55][55];
int m,n;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=n;k++)
            {
                for(int t=1;t<=m;t++)
                {
                    dp[i][j][k][t]=max(max(dp[i][j-1][k][t-1],dp[i][j-1][k-1][t]),max(dp[i-1][j][k-1][t],dp[i-1][j][k][t-1]))+a[i][j]+a[k][t];
                    if(i==k&&j==t)
                    {
                        dp[i][j][k][t]-=a[i][j];
                    }
                }
            }
        }
    }
    cout<<dp[n][m][n][m]<<endl;
    return 0;
}
