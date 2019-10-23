#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[1000005],dp[1000005];
//set<int> mp;
int main()
{
    int n;
    cin>>n;
    scanf("%d",&a[0]);
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>a[i-1])
        {
            dp[i]=dp[i-1]+1;

        }
        else
            dp[i]=1;
       // mp.insert(dp[i]);
    }
    sort(dp,dp+n);
    cout<<dp[n-1]<<endl;
    return 0;
}
