#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int R;
int a[1005][1005];
//int dp[1005][1005];
int main()
{
    scanf("%d",&R);
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
   // memset(dp,0,sizeof(dp));
    //for(int i=1;i<=R;i++)
      //  dp[R][i]=a[R][i];
    for(int i=R-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
        }
    }
    cout<<a[1][1]<<endl;
    return 0;
}
