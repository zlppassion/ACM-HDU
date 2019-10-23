#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1005][1005];
ll d[1005];
ll f[1005][1005];//i行加到j列的结果
ll cc[1005];//全部i列相加的值
ll rr[1005];//行的最大值
int main()
{
    int t;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        memset(f,0,sizeof(f));
        memset(cc,0,sizeof(cc));
        for(int i=0;i<1005;i++)
            rr[i]=1000000005;

        map<ll,int>qq;
        priority_queue<int,vector<int>,greater<int> > mm;
        int n,m;
        ll ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%lld",&a[i][j]);
                f[i][j]=a[i][j];
                cc[j]-=a[i][j];
            }
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%lld",&d[i]);
            cc[i]+=d[i];//如果执行了全部列操作的答案。
        }
        for(int i=1;i<=n;i++)
        {
            qq[i]=0;
            for(int j=1;j<=m;j++)
            {
                if(j>1)
                f[i][j]+=f[i][j-1];//f[i][j]直接就是累计惩罚的钱

                if(rr[i]>=f[i][j])
                {
                    rr[i]=f[i][j];
                    qq[i]=j;//i行的最小惩罚值在j列
                }
            }
          //cout<<endl;
            //cout<<qq[i]<<" ";
            mm.push(qq[i]);//找到最小值
        }
      //  cout<<endl;
        int pos=mm.top();
       // cout<<pos<<endl;
        ans+=cc[pos];
        //我打算竖着加

        for(int j=pos;j<=m;j++)
        {
            ll temp=ans;
            int tot=1;
            while(tot<=n)
            {
               ans=max(ans,ans-a[tot][j]);
               tot++;
            }
            ans=max(ans,temp+cc[j+1]);

        }
        printf("Case #%d: %lld\n",ii,ans);

    }
    return 0;
}
