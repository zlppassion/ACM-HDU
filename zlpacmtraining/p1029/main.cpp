#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//#define ll long long
int p[100005];
int gcd(int a,int b)//求最大公约数
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
    int s=x*y;//乘积
    int ans=0;
    for(int i=x;i<=s;i++)
    {
        int t=s/i;//第一个数为i,第二个数为t

        if(gcd(i,t)==x&&lcm(i,t)==y)
        {
            ans++;

        }

    }
    cout<<ans<<endl;
    return 0;
}
