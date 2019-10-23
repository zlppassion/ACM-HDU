#include<bits/stdc++.h>
using namespace std;
int const ma = 1e5 + 7;
int mp[507][507], maxn[ma], minn[ma], quema[ma], quemi[ma];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        int ans = 1;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &mp[i][j]);
        for (int i = 1; i <= n; i++)
        {
            for (int p = 1; p <= n; p++)//在每一行都要计算
            {
                maxn[p] = 0, minn[p] = ma;
            }
            for (int k = i; k <= n; k++)
            {
                for (int p = 1; p <= n; p++)
                {
                    maxn[p] = max(maxn[p], mp[k][p]);   //找列的最大
                    minn[p] = min(minn[p], mp[k][p]);
                }
                int f1 = 1, f2 = 1, t1 = 0, t2 = 0, l = 1;//f1,f2就相当于对头，t1,t2就相当于队尾，
                for (int r = 1; r <= n; r++)//l 和 r模拟列，k与 i的差才是行
                {
                    while (f1 <= t1 && maxn[quema[t1]] < maxn[r]) t1--;            //每进入一个值后对单调队列进行排序，f1为队头，不能超过
                    while (f2 <= t2 && minn[quemi[t2]] > minn[r]) t2--;
                    quema[++t1] = r;        //进入队列
                    quemi[++t2] = r;
                    while (l <= r &&((maxn[quema[f1]] - minn[quemi[f2]]) > m))   //f2,f1的位置就是对应队列的最大和最小值
                    {
                        l++;
                        if (f1 <= t1 && quema[f1] < l)f1++;             //这里就是把对应的值弹出去,判断位置来弹数据
                        if (f2 <= t2 && quemi[f2] < l)f2++;
                    }
                    ans = max((r - l + 1) * (k - i + 1), ans);  //行*列，去找最大的矩阵
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
