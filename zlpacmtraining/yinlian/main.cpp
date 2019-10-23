#include <iostream>
#include<bits/stdc++.h>
using namespace std;
char a[302][302];
int rr[302][302];
int cc[302][302];//
int main()
{
    int T;
    scanf("%d",&T);
    int n,m;
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(rr,0,sizeof(rr));
        memset(cc,0,sizeof(cc));
        scanf("%d%d",&n,&m);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
           rr[i][0]=0;

            for(int j=1;j<=m;j++)//Ã¿Ò»ÐÐ
            {
               cin>>a[i][j];
                if(a[i][j]=='.')
                {
                    rr[i][j]=rr[i][j-1]+1;
                    cc[i][j]=cc[i-1][j]+1;
                }
                else
                {
                    rr[i][j]=0;
                    cc[i][j]=0;
                }
            }
        }
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<rr[i][j]<<" ";
            }
            cout<<endl<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<cc[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {

               if(rr[i][j]!=0)
               {
                   ans=max(ans,1);
                   int t=j;
                   for(int k=i+1;k<=n;k++)
                   {
                       if(rr[k][t+1]>=k-i+1&&cc[k][t+1]>=k-i+1)
                       {
                           ans=max(ans,(k-i+1)*(k-i+1));
                           t++;
                       }
                       else
                        break;
                   }

               }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
/*
4 3
.*.
..*
..*
...
*/

