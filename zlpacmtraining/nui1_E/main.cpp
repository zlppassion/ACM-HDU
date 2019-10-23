#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//假设有一个合法串，因为子序列n个AB和m个BA，那么显然有前n个A必为AB的A，前m个B必为BA的B。
//因为如果我前n个A中有一个是BA的A，那我是不是可以从更后面随便找一个A给这个B用，那么显然前n个A必为AB的A
#define ll long long
const ll mod=1e9+7;
ll dp[2005][2005];//dp[i][j]代表前缀有i个A，j个B
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<=n+m;i++)
        {
            for(int j=0;j<=n+m;j++)
                dp[i][j]=0;
        }
        dp[0][0]=1;
        for(int i=0;i<=n+m;i++)
        {
            for(int j=0;j<=n+m;j++)
            {
                if(i-j<n)//因为前n个为A ,所以如果A的个数还没有大于B n个，则应该加A
                    dp[i+1][j]+=dp[i][j];
                if(j-i<m)//同理
                    dp[i][j+1]+=dp[i][j];
                dp[i+1][j]%=mod;
                dp[i][j+1]%=mod;
            }
        }
        printf("%lld\n",dp[n+m][n+m]);
    }
    return 0;
}
