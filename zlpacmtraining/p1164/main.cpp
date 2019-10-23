#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
int f[101][10001];//定义f[i][j]为用前i道菜用光j元钱的办法总数
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            //if(j==第i道菜的价格)f[i][j]=f[i-1][j]+1;
            //方案数就为钱i-1道菜花光了j元钱加上第i道菜花的这j元钱
            if(j==a[i])
                f[i][j]=f[i-1][j]+1;
            //if(j>第i道菜的价格) f[i][j]=f[i-1][j]+f[i-1][j-第i道菜的价格];
            //就说明这个钱不可能是第i道菜全花的，有可能前i-1道菜花光了j元，也有可能前i-1道菜花了(j-第i道菜的价格）
            if(j>a[i])
                f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
            //if(j<第i道菜的价格) f[i][j]=f[i-1][j];
            //说明这j元一定没有花在第i道菜身上
            if(j<a[i])
                f[i][j]=f[i-1][j];
        }
    cout<<f[n][m]<<endl;
    return 0;
}
