#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//#define ll long long
int p[100005];
int gcd(int a,int b)//�����Լ��
{
    int temp;
    while(a%b!=0)
    {
        temp=a;
        a=b;
        b=temp%b;
    }
    return b;
}
int lcm(int a,int b)
{
    int a1=a,b1=b,temp;
    while(a%b!=0)
    {
        temp=a;
        a=b;
        b=temp%b;
    }
    return a1*b1/b;
}
int x,y;
int main()
{
    cin>>x>>y;
    int s=x*y;//�˻�
    int ans=0;
    for(int i=x;i<=s;i++)
    {
        int t=s/i;//��һ����Ϊi,�ڶ�����Ϊt

        if(gcd(i,t)==x&&lcm(i,t)==y)
        {
            ans++;

        }

    }
    cout<<ans<<endl;
    return 0;
}
