#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int  a[35][35];
//a[i][k]������k�δ�����i�ķ�����
int main()
{
    scanf("%d%d",&n,&m);
    a[1][0]=1;//û�д� ������ķ�������Ȼ��1��
    //������Ҫ�Ĵ���a[1][m]
    //��Ҫ�������븴�ӣ�����ǵ���ѽ
    //����i��ͬѧ����ֻ��������i����ߺ��ұ�
    //����a[i][k]=a[i-1][k-1]+a[i+1][k-1]
    //Ȼ�����1��n�����Ҫ��������,a[1][k]=a[2][k-1]+a[n][k-1]
    //a[n][k]=a[n-1][k-1]+a[1][k-1]
    for(int k=1;k<=m;k++)
    {

        for(int j=2;j<n;j++)
        {
            a[j][k]=a[j-1][k-1]+a[j+1][k-1];
        }
        a[1][k]=a[2][k-1]+a[n][k-1];
        a[n][k]=a[n-1][k-1]+a[1][k-1];

    }
    cout<<a[1][m]<<endl;
    return 0;
}
