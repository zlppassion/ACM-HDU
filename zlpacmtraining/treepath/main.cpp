#include<bits/stdc++.h>
using namespace std;
vector<int> s[100100];
long long sum1,sum2;
int vis[100100];
/*找一个根节点建树,记录深度,将所有偶数深度的结点拿出来放在一起,个数为a,
奇数同理，个数为b,这样就保证了两个图当中任意两个结点之间的路径都为偶数,然后所有路径数为 ，
类似一个二分图， 偶数的就只能走偶数步走到偶数*/
void dfs(int root,int cnt){
    if(cnt%2==0) sum1++;
    else sum2++;
    vis[root]=1;
    int a=s[root].size();
    for(int i=0;i<a;i++){
        int v=s[root][i];
        if(vis[v]==1) continue;
        else
        dfs(v,cnt+1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        s[a].push_back(b);
        s[b].push_back(a);
    }
    dfs(1,1);
    long long sum=sum1*(sum1-1)/2+sum2*(sum2-1)/2;
    printf("%lld",sum);
    return 0;
}
