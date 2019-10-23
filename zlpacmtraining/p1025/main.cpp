#include<cstdio>
using namespace std;
int sum;
void dfs(int x,int s,int t)
{
    if(s==1)
    {
        sum++;
        return;
    }
    for(int i=x; i<=t/s; i++)
        dfs(i,s-1,t-i);
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    dfs(1,k,n);
    printf("%d",sum);
    return 0;
}
