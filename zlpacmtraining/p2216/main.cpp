#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a,b,n;
int g[1005][1005];
int Q[1005],q[1005];//���������ֵ��Сֵ���±��
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
        HEAD=TAIL=head=tail=Q[1]=q[1]=1;//�ȳ�ʼ��Ϊ��һ��
        for(int j=2;j<=b;j++)
        {
            //��Ӳ���
            while(HEAD<=TAIL&&g[i][Q[TAIL]]<=g[i][j])
               TAIL--;
            while(head<=tail&&g[i][q[tail]]>=g[i][j])
                tail--;
            TAIL++;
            tail++;
            Q[TAIL]=j;
            q[tail]=j;
            //���Ӳ���
            //���������n,����׳���
            while(j-Q[HEAD]>=n)
                HEAD++;
            while(j-q[head]>=n)
                head++;
            if(j>=n)
            {
                X[i][j-n+1]=g[i][Q[HEAD]];//��i,j-n+1��ͷ�����ֵ
                x[i][j-n+1]=g[i][q[head]];//��i,j-n+1��ͷ����Сֵ
            }
        }
    }
    for(int j=1;j<=b-n+1;j++)
    {
        HEAD=TAIL=head=tail=Q[1]=q[1]=1;//�ȳ�ʼ��Ϊ��һ��
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
            //���Ӳ���
            //���������n,����׳���
            while(i-Q[HEAD]>=n)
                HEAD++;
            while(i-q[head]>=n)
                head++;
            if(i>=n)
            {
                Y[i-n+1][j]=X[Q[HEAD]][j];//��i-n+1,j��ͷ�����ֵ
                y[i-n+1][j]=x[q[head]][j];//��i-n+1,j��ͷ����Сֵ
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
