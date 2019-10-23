#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//到这一位置为止的最长上升子序列和自这个位置向后的最长下降子序列
//相加减一取最大值
int n;
int a[105];
int dp1[105],dp2[105];
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1; i<=n; i++)
    {
        dp1[i]=1;
        for(int j=1; j<i; j++)
        {
            if(a[j]<a[i]&&dp1[i]<dp1[j]+1)//到这一位置为止的最长上升子序列
            {
                dp1[i]=dp1[j]+1;
            }
        }
    }
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        dp2[i]=1;
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]<a[i]&&dp2[i]<dp2[j]+1)
            {
                dp2[i]=dp2[j]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp1[i]+dp2[i]-1);
    }
    cout<<n-ans<<endl;
    return 0;
}
