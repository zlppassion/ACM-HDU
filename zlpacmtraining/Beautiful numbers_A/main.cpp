#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define ll long long
ll a[30];
ll dp[50][20];
ll dfs(int index,bool flag,bool limit)//limit代表数位上界变量
{
    if(index==0)
        return 1;
    if(!limit&&dp[index][flag]!=-1)
        return dp[index][flag];
    int up=limit?a[index]:1;
    ll ans=0;
    for(int i=0;i<=up;i++)
    {


    }
    if(!limit)
        dp[index][flag]=ans;
    return ans;
}
ll solve(ll x)
{
   ll pos=0;
   while(x)
   {
       a[++pos]=x%10;
       x/=10;
   }
   return dfs(pos,0,1);

}
int main()
{
    ll n,m;
    scanf("%lld%lld",&n,&m);
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",solve(m)-solve(n-1));
    return 0;
}
