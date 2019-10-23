#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[10005];
/*500 3
150 300
100 200
470 471
*/
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    int ll,rr;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&ll,&rr);
        a[ll]++;
        a[rr+1]--;
    }
    int ans=0,num=0;
    for(int i=0;i<=n;i++)//题目说的是0~L种树，，，请细心点。
    {
        num+=a[i];
        if(num<=0)
            ans++;

    }
    cout<<ans<<endl;
    return 0;
}
