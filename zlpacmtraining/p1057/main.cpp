#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int  a[35][35];
//a[i][k]代表经过k次传到了i的方案数
int main()
{
    scanf("%d%d",&n,&m);
    a[1][0]=1;//没有传 到本身的方案数当然是1咯
    //我们需要的答案是a[1][m]
    //不要把问题想复杂，这就是递推呀
    //传到i号同学的球只能来自于i的左边和右边
    //所以a[i][k]=a[i-1][k-1]+a[i+1][k-1]
    //然后对于1，n的情况要单独处理,a[1][k]=a[2][k-1]+a[n][k-1]
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
