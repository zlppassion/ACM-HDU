#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int dp1[100005];
int dp2[100005];
int main()
{
    int tot=1;
    while(scanf("%d",&a[tot])!=EOF)
    {
        tot++;
    }
    int ans1=0,ans2=0;
    tot--;//一共tot个元素
    for(int i=1;i<=tot;i++)
    {
        dp1[i]=1;
        dp2[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]>=a[i]&&dp1[i]<dp1[j]+1)
            {
                dp1[i]=dp1[j]+1;
            }
            else if(a[j]<a[i]&&dp2[i]<dp2[j]+1)
            {
                dp2[i]=dp2[j]+1;
            }
        }
        ans1=max(ans1,dp1[i]);
        ans2=max(ans2,dp2[i]);
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
