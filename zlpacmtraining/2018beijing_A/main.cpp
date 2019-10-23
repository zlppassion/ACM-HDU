/*/*Input
There are no more than 25 test cases.

For each case, the first line includes two integers N and M(0 < N,M �� 100), meaning that the palace
is a N �� M matrix.

Then the N��M matrix follows.

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
/*��һ��100��100���Թ�����.����ʾ·�棬��S����ʾ��㣬��T����ʾ�յ㣻��#����ʾ�����������붾��������Ҫ����һ��������
��B����ʾ��������ÿ�ν����Զ����һ���������ɷ�������Ӷ���ö���������Я��5������P����ʾ����ҩ�����ԭ�������
һ����ʹ�ú�ʹ��һ���ƶ�����ʱ����������Я����һ���ƶ������ƶ������ڵ��ĸ����ӣ�����һ����λʱ�䣬����ƶ�����
�����������ڶ���������ͣ��һ����λʱ�䡣���S��T�����ʱ�䣬������ܵ�����-1��*/
/*��dp[x][y][t]��ʾ����(x,y)������ƿΪt��ʱ�����ʱ�䣬bfs����ÿ�������������ÿ��������ʱ��
�����ﲻ��vis����״̬����
�����dp[ex][ey][0~5]��ȡ��Сֵ��*/
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
