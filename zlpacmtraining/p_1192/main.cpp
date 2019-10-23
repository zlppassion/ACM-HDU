#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod=100003;
int s[100005];
int n,k;//最高n层，最多一次k步，求方案数
//可以自己模拟一下，可以发现每一个点的递推关系为s[n]=求和（s[n-k]~s[n-1])
//就可以想象为最后一步：越1~k个台阶的情况，相加起来
int main()
{
    scanf("%d%d",&n,&k);
    s[0]=1;//初始化，一种情况
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k&&(i-j)>=0;j++)
        {
            s[i]=(s[i]+s[i-j])%mod;
        }
    }
    cout<<s[n]<<endl;
    return 0;
}
