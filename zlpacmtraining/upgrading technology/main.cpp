#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1005][1005];
ll d[1005];
ll f[1005][1005];//i�мӵ�j�еĽ��
ll cc[1005];//ȫ��i����ӵ�ֵ
ll rr[1005];//�е����ֵ
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
            cc[i]+=d[i];//���ִ����ȫ���в����Ĵ𰸡�
        }
        for(int i=1;i<=n;i++)
        {
            qq[i]=0;
            for(int j=1;j<=m;j++)
            {
                if(j>1)
                f[i][j]+=f[i][j-1];//f[i][j]ֱ�Ӿ����ۼƳͷ���Ǯ

                if(rr[i]>=f[i][j])
                {
                    rr[i]=f[i][j];
                    qq[i]=j;//i�е���С�ͷ�ֵ��j��
                }
            }
          //cout<<endl;
            //cout<<qq[i]<<" ";
            mm.push(qq[i]);//�ҵ���Сֵ
        }
      //  cout<<endl;
        int pos=mm.top();
       // cout<<pos<<endl;
        ans+=cc[pos];
        //�Ҵ������ż�

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
