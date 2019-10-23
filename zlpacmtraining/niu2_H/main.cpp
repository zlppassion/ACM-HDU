#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%1d",&dp[i][j]);
            dp[i][j]+=dp[i][j]*dp[i-1][j];
            //预处理dp[i][j]为该点上方路连续1的最大值
        }


    }
    /*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    int firstArea=-1,secArea=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int h=dp[i][j];
            int w=1;
            //当前矩阵的高和宽
            while(h)
            {
                int nowArea=h*w;
                if(nowArea>firstArea)
                {
                    secArea=firstArea;
                    firstArea=nowArea;
                }
                else if(nowArea>secArea)
                {
                    secArea=nowArea;
                }
                h=min(h,dp[i][j-w]);
                w++;
            }
        }
    }
    cout<<(secArea==-1?0:secArea)<<endl;
    return 0;
}
