#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[30],w[30];
int f[26][30000];
int main()
{
    scanf("%d%d",&n,&m);//�ܼ�ǮΪn,������n
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&v[i],&w[i]);//Ǯ���ȼ�
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            {
                f[i][j]=f[i-1][j];
                if(j>=v[j])
                {
                    f[i][j]=max(f[i][j],f[i-1][j-v[j]]*w[i]);
                }
            }
    }
    cout<<f[m][n];
    return 0;
}
/*#include<iostream>
#include<algorithm>
using namespace std;
int w[30],v[30],f[50000];//w����Ϊ��Ҫ�ȣ�v����Ϊmoney��f������dp������
int n,m;//n������Ʒ������m����Ǯ��
int main()
{
    cin>>m>>n;//����
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];//v�ǵ��ۣ�w��Ȩֵ
        w[i]*=v[i];//w���������������Ϊ���ջ���Ҫ��*money��
    }
       //01���������յڶ���ģ�塰һά�����Ż�����
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=v[i];j--)//ע���m��ʼ
        {
            if(j>=v[i])//ֻҪǮ�����Ϳ�����
            {
                f[j]=max(f[j],f[j-v[i]]+w[i]);//dp
            }
        }
    }
    cout<<f[m]<<endl;//������СΪmʱ���ֵ
    return 0;
} */
