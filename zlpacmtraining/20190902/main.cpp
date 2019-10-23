#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1005][1005];
int b[2010];
struct tree
{
    int sub;
    int ff;//ff为0代表没有掉落

    int sheng;
    tree()
    {
        sub=0;
        ff=0;

        sheng=0;
    }
}tr[1005];
int main()
{
    int n;
    scanf("%d",&n);
   // ll sum=0;
    int ans=0;//ans为发生苹果掉落的苹果树的棵数
    int E=0;
    for(int i=1;i<=n;i++)
    {
      //  int flag=0;
        int m;
        scanf("%d",&m);
        scanf("%d",&a[i][1]);
        int te=a[i][1];
        for(int j=2;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]<=0)
                tr[i].sub-=a[i][j];
            else//当前在统计数量
            {
                if(a[i][j]<te-tr[i].sub)
                {
                   // ans++;
                    tr[i].ff=1;
                    tr[i].sub+=(te-tr[i].sub-a[i][j]);
                }

            }
        }
        tr[i].sheng=a[i][1]-tr[i].sub;
    }
    ll smax=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=b[i+n]=tr[i].ff;
        smax+=tr[i].sheng;
        if(tr[i].ff==1)
            ans++;

    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]+b[i+1]+b[i+2]==3)
            E++;
    }
    cout<<smax<<" "<<ans<<" "<<E<<endl;
    return 0;
}
/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0
*/
/*
5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
*/
