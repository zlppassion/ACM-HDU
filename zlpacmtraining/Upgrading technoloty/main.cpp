#include<bits/stdc++.h>
#define MAXN 45689
#define INF 0x3f3f3f3f//将近ll类型最大数的一半，而且乘2不会爆ll
const ll mod = 1000000007;

ll a[1005][1005];
ll zui[1005][1005];
int main()
{
    int t, n, m, ccc=1;
    cin >> t;
    while(t--)
    {
        memset(a, 0, sizeof(a));
        memset(zui, 0, sizeof(zui));
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                scanf("%lld", &a[i][j]);
                a[i][j] += a[i][j-1];
            }
            zui[i][m] = a[i][m];
            for(int j=m-1; j>=0; --j)    //求每一行后缀和（后遍历）
                zui[i][j] = min(zui[i][j+1], a[i][j]);
        }

        ll sum=0, ans=0;
        for(int j=0, c; j<=m; ++j)//从0开始循环是因为第一列不一定全部选择完
        {
            ll mn=0, mx=0;
            for(int i=1; i<=n; ++i)
            {
                mn+=a[i][j];        //列求和
                mx+=zui[i][j];
            }
            for(int i=1; i<=n; ++i)//判断是全部选择呢，还是只选择部分
                mn = min(mn, mx - zui[i][j] + a[i][j]);//因为mx是zui[i][j]累加的，后面这个相当于判断不把这个点往后升级

            sum = max(sum, ans - mn);   //维护损失的值
            if(j < m)
            {
                scanf("%d", &c);        //得到dj
                ans+=c;
            }
        }
        printf("Case #%d: %lld\n", ccc++, sum);
    }
    return 0;
}
