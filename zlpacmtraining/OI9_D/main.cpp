
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+10;
//int A[1e6+5];
int n,k;
set<int> q;
ll ans=0;
//cur用于确定子集的大小
void print_subset(int *A,int n,int cur)
{
    q.clear();

    for(int i = 0;i<cur;i++)
    {


         q.insert(A[i]+1);

    }

    if(q.size()<=k)
    {
        ll t=1;
        set<int>::iterator it=q.begin();
        for(;it!=q.end();it++)
        {
            t=(t*(*it))%mod;
        }

        ans=(ans+t)%mod;
    }

    int s = cur? A[cur-1]+1 : 0;
    for(int i=s;i<n;i++)
    {
        A[cur]=i;
        print_subset(A,n,cur+1);
    }
}

int main()
{


    while(scanf("%d%d",&n,&k)!=EOF)
    {
        ans=0;
        int *A=new int[n + 1];
        for(int i = 1; i <= n; ++ i)
           scanf("%d",&A[i]);
        print_subset(A,n,0);
        printf("%lld\n",ans);

    }
    return 0;
}


