#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[400],b[200];//aΪ���ӷ�����bΪ���п�Ƭ
int g[5];
//4�����п�Ƭ��ÿ�ֿ�Ƭ���������ᳬ��40
int f[43][43][43][43];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        g[b[i]]++;//��¼b[i]��Ƭ������Ŀ
    }
    f[0][0][0][0]=a[1];
    for(int i=0;i<=g[1];i++)
    {
        for(int j=0;j<=g[2];j++)
        {
            for(int k=0;k<=g[3];k++)
            {
                for(int t=0;t<=g[4];t++)
                {
                    int pos=1+i+j*2+k*3+t*4;
                    if(i)
                        f[i][j][k][t]=max(f[i][j][k][t],f[i-1][j][k][t]+a[pos]);
                    if(j)
                        f[i][j][k][t]=max(f[i][j][k][t],f[i][j-1][k][t]+a[pos]);
                    if(k)
                        f[i][j][k][t]=max(f[i][j][k][t],f[i][j][k-1][t]+a[pos]);
                    if(t)
                        f[i][j][k][t]=max(f[i][j][k][t],f[i][j][k][t-1]+a[pos]);
                }
            }
        }
    }
    cout<<f[g[1]][g[2]][g[3]][g[4]]<<endl;
    return 0;
}
