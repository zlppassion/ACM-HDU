
/*�������ȫ�Ǹ����϶���inf;

Ȼ�����Ǽ��������߳�ȥ������ʱ����d;

��ô�õ���������������; d = 1/3 * 3  + 1/3( 6 + d) + 1/3 (9 + d);
˼·���軨��ʱ�� ���Թ�������ΪE��

ÿһ��ѡ�������������������赱ǰ�Ż���ʱ��ľ���ֵΪ T

һ��ѡ������ܹ�ֱ�Ӱ��㴫�ͳ�ȥ������Ϊ1 / N * T��
����ѡ����Ű��㴫�͵�ԭ����λ�ã�����Ϊ1 / N * T���ֻص���ʼ״̬�����ȥ������Ϊ1 / N * (T + E)��


��ȫ���ܹ����㴫�ͳ�ȥ���ŵ�ʱ��ֵ �ܺ�Ϊsum1��ȫ���ܹ����㴫�ͻ�ȥ���ŵ�ʱ��ֵ �ܺ�Ϊsum2��
��ȫ���ܹ����㴫�ͳ�ȥ���ŵ���ĿΪdoor1��ȫ���ܹ����㴫�ͻ�ȥ���ŵ���ĿΪdoor2��
�õ���ʽ

E = 1 / N * (sum1)  + 1 / N * (sum2 + door2 * E)��

����� E = (sum1 + sum2) / (N-door2); ��Ȼ��door2����N��˵�������ܳ��Թ���
Sample Input
3

1
1

2
-10 -3

3
3 -6 -9
Sample Output
Case 1: 1/1
Case 2: inf
Case 3: 18/1*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
int a[105];
int main()
{
    ll n,door2,sum;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        door2=0;
        sum=0;
        memset(a,0,sizeof(a));
        //cout<<endl;
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i]);

            if(a[i]<0)
            {
                door2++;
                sum=sum-a[i];
            }
            else
                sum+=a[i];

        }
        if(door2==m)
            cout<<"Case "<<i+1<<": inf"<<endl;
        else
        {
            int temp=m-door2;
            int ans=gcd(sum,temp);
            cout<<"Case "<<i+1<<": "<<sum/ans<<"/"<<temp/ans<<endl;
        }
    }
    return 0;
}
