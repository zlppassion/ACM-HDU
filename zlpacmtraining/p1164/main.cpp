#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
int f[101][10001];//����f[i][j]Ϊ��ǰi�����ù�jԪǮ�İ취����
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
            //if(j==��i���˵ļ۸�)f[i][j]=f[i-1][j]+1;
            //��������ΪǮi-1���˻�����jԪǮ���ϵ�i���˻�����jԪǮ
            if(j==a[i])
                f[i][j]=f[i-1][j]+1;
            //if(j>��i���˵ļ۸�) f[i][j]=f[i-1][j]+f[i-1][j-��i���˵ļ۸�];
            //��˵�����Ǯ�������ǵ�i����ȫ���ģ��п���ǰi-1���˻�����jԪ��Ҳ�п���ǰi-1���˻���(j-��i���˵ļ۸�
            if(j>a[i])
                f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
            //if(j<��i���˵ļ۸�) f[i][j]=f[i-1][j];
            //˵����jԪһ��û�л��ڵ�i��������
            if(j<a[i])
                f[i][j]=f[i-1][j];
        }
    cout<<f[n][m]<<endl;
    return 0;
}
