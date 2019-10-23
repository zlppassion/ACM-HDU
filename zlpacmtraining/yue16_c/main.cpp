#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int b[1005];
int main()
{
    scanf("%d%d",&n,&m);
    int hmax=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

    }
   while(m--)
   {
       int h;
       scanf("%d",&h);
       int ans=0;
       for(int i=1;i<=n+1;i++)
       {
           if(a[i]<=h&&a[i-1]>h)
            ans++;
       }
       cout<<ans<<endl;
   }
    return 0;
}
