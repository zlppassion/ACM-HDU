
/*首先如果全是负数肯定是inf;

然后我们假设我们走出去的期望时间是d;

那么拿第三个样例举例子; d = 1/3 * 3  + 1/3( 6 + d) + 1/3 (9 + d);
思路：设花费时间 出迷宫的期望为E。

每一个选择仅仅有两种情况——设当前门花费时间的绝对值为 T

一：选择的门能够直接把你传送出去。期望为1 / N * T。
二：选择的门把你传送到原来的位置，期望为1 / N * T。又回到初始状态，则出去的期望为1 / N * (T + E)。


设全部能够将你传送出去的门的时间值 总和为sum1，全部能够将你传送回去的门的时间值 总和为sum2。
设全部能够将你传送出去的门的数目为door1，全部能够将你传送回去的门的数目为door2。
得到等式

E = 1 / N * (sum1)  + 1 / N * (sum2 + door2 * E)。

化简得 E = (sum1 + sum2) / (N-door2); 当然若door2等于N。说明不可能出迷宫。
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
