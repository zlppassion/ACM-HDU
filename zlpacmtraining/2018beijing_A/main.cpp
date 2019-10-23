/*/*Input
There are no more than 25 test cases.

For each case, the first line includes two integers N and M(0 < N,M ≤ 100), meaning that the palace
is a N × M matrix.

Then the N×M matrix follows.

The input ends with N = 0 and M = 0.

Output
For each test case, print the minimum time (in minute) Sun Wukong needed to save Tang Monk.
If it's impossible for Sun Wukong to complete the mission, print -1

Sample Input
2 2
S#
#T
2 5
SB###
##P#T
4 7
SP.....
P#.....
......#
B...##T
0 0
Sample Output
-1
8
11*/
/*给一个100×100的迷宫，’.’表示路面，’S’表示起点，’T’表示终点；’#’表示毒气区，进入毒气区必须要消耗一个氧气；
’B’表示氧气区，每次进入自动获得一个氧气，可反复进入从而获得多个，但最多携带5个；’P’表示加速药，获得原理和氧气
一样，使用后使下一次移动不耗时，可以无限携带。一次移动可以移动到相邻的四个格子，花费一个单位时间，如果移动到了
毒气区，将在毒气区额外停留一个单位时间。求从S到T的最短时间，如果不能到达，输出-1。*/
/*用dp[x][y][t]表示到达(x,y)且氧气瓶为t个时的最短时间，bfs根据每个点的特征处理每个点的最短时间
（这里不用vis保存状态），
最后在dp[ex][ey][0~5]里取最小值。*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
char a[105][105];
int sx,sy,ex,ey;
struct node
{
    int x,y,num;
    node(int i,int j,int k):x(i),y(j),num(k) {}
};
int dp[105][105][6];
int dir[][2]= {{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
int bfs()
{
    queue<node> q;
    node aa=node(sx,sy,0);

    memset(dp,inf,sizeof(dp));
    dp[sx][sy][0]=0;
    q.push(aa);
    while(!q.empty())
    {
        node t=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int newx=t.x+dir[i][0];
            int newy=t.y+dir[i][1];
            if(newx>=0&&newx<n&&newy>=0&&newy<m)
            {
                if((a[newx][newy]=='S'||a[newx][newy]=='.')&&dp[newx][newy][t.num]>dp[t.x][t.y][t.num]+1)
                {
                    dp[newx][newy][t.num]=dp[t.x][t.y][t.num]+1;
                    q.push(node(newx,newy,t.num));
                }
                else  if((a[newx][newy]=='#')&&t.num>0&&dp[newx][newy][t.num-1]>dp[t.x][t.y][t.num]+2)
                {
                    dp[newx][newy][t.num-1]=dp[t.x][t.y][t.num]+2;
                    q.push(node(newx,newy,t.num-1));
                }
                else  if(a[newx][newy]=='P'&&dp[newx][newy][t.num]>dp[t.x][t.y][t.num])
                {
                    dp[newx][newy][t.num]=dp[t.x][t.y][t.num];
                    q.push(node(newx,newy,t.num));
                }
            else if (a[newx][newy]=='B'&&t.num<5&&dp[newx][newy][t.num+1]>dp[t.x][t.y][t.num]+1)
            {
                dp[newx][newy][t.num+1]=dp[t.x][t.y][t.num]+1;
                     q.push(node(newx,newy,t.num+1));

                }
            else if (a[newx][newy]=='B'&&t.num==5&&dp[newx][newy][t.num]>dp[t.x][t.y][t.num]+1)
            {
                dp[newx][newy][t.num]=dp[t.x][t.y][t.num]+1;
                     q.push(node(newx,newy,t.num));

                }
                else if(a[newx][newy]=='T'&&dp[newx][newy][t.num]>dp[t.x][t.y][t.num]+1)
                {
                    dp[newx][newy][t.num]=dp[t.x][t.y][t.num]+1;
                    q.push(node(newx,newy,t.num));
                }
            }
        }
    }
    int ans=inf;
    for(int i=0;i<6;i++)
    {
        ans=min(ans,dp[ex][ey][i]);
    }
    if(ans!=inf)
        return ans;
    return -1;
}
int main()
{
    //int n,m;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++)
        {
            scanf("%s",a[i]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
                else if(a[i][j]=='T')
                {
                    ex=i;
                    ey=j;
                }
            }
        }
        cout<<bfs()<<endl;
    }
    return 0;
}
