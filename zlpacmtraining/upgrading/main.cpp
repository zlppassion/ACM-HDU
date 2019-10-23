#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll sum[1005][1005];
int d[1005];
int a[1005][1005];
int main()
{
    cout<<0ll<<endl;
    int cnt=1,t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)scanf("%d",&a[i][j]),a[i][j]=-a[i][j];
        for(int i=1; i<=m; i++)scanf("%d",&d[i]);
        /*题意：有i个技能，每次升级都有花费cij，然后所有技能都达到j级送dj块钱，问你最多能赚多少

         解：先将花费乘-1转换为收益，对 a[i][j] 维护后缀和，表示 j+1~m 最大收益。

        然后  j 从1 到 m 遍历，j 表示当前某个技能的最低等级，找到 第 i 个技能 最小的后缀和，
        减去这个后缀和并加上其他技能的后缀和，再加上所以技能都达到 j 的收益取最大值。 */

        for(int i=1; i<=n; i++)
        {
            sum[i][m] = 0;
            for(int j=m-1; j>=0; j--)//越大成本越低
            {
                sum[i][j] = max(0ll,sum[i][j+1]+a[i][j+1]);
            }
        }
        ll now = 0,ans = 0;
        for(int j=0; j<=m; j++)
        {
            for(int i=1; i<=n; i++)now+=a[i][j];//对列求和
            now+=d[j];
            ll tp = 0,mi = 1e18;
            for(int i=1; i<=n; i++)
            {
                tp+=sum[i][j];
                mi = min(mi,sum[i][j]);//最小后缀和说明出的钱越多
            }

            ans = max(ans,tp-mi+now);
        }
        printf("Case #%d: %lld\n",cnt++,ans);
    }
    return 0;
}
