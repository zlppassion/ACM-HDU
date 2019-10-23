#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a,b,n;
int g[1005][1005];
int Q[1005],q[1005];//用来存最大值最小值的下标的
int X[1005][1005],x[1005][1005];
int Y[1005][1005],y[1005][1005];
int HEAD,TAIL,head,tail;
int main()
{
    scanf("%d%d%d",&a,&b,&n);
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    for(int i=1;i<=a;i++)
    {
        HEAD=TAIL=head=tail=Q[1]=q[1]=1;//先初始化为第一列
        for(int j=2;j<=b;j++)
        {
            //入队操作
            while(HEAD<=TAIL&&g[i][Q[TAIL]]<=g[i][j])
               TAIL--;
            while(head<=tail&&g[i][q[tail]]>=g[i][j])
                tail--;
            TAIL++;
            tail++;
            Q[TAIL]=j;
            q[tail]=j;
            //出队操作
            //如果超过了n,则队首出队
            while(j-Q[HEAD]>=n)
                HEAD++;
            while(j-q[head]>=n)
                head++;
            if(j>=n)
            {
                X[i][j-n+1]=g[i][Q[HEAD]];//以i,j-n+1开头的最大值
                x[i][j-n+1]=g[i][q[head]];//以i,j-n+1开头的最小值
            }
        }
    }
    for(int j=1;j<=b-n+1;j++)
    {
        HEAD=TAIL=head=tail=Q[1]=q[1]=1;//先初始化为第一行
        for(int i=2;i<=a;i++)
        {
             while(HEAD<=TAIL&&X[Q[TAIL]][j]<=X[i][j])
               TAIL--;
            while(head<=tail&&x[q[tail]][j]>=x[i][j])
                tail--;
            TAIL++;
            tail++;
            Q[TAIL]=i;
            q[tail]=i;
            //出队操作
            //如果超过了n,则队首出队
            while(i-Q[HEAD]>=n)
                HEAD++;
            while(i-q[head]>=n)
                head++;
            if(i>=n)
            {
                Y[i-n+1][j]=X[Q[HEAD]][j];//以i-n+1,j开头的最大值
                y[i-n+1][j]=x[q[head]][j];//以i-n+1,j开头的最小值
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=a-n+1;i++)
    {
        for(int j=1;j<=b-n+1;j++)
        {
            ans=min(ans,Y[i][j]-y[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
