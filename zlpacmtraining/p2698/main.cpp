#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int N,D;
struct node
{
    int x;
    int y;
}a[100005],f[100005];
bool cmp(node m,node n)
{
    if(m.x!=n.x)
        return m.x<n.x;
    else
        return m.y<n.y;
}
int main()
{
    scanf("%d%d",&N,&D);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(a+1,a+N+1,cmp);
    int head=1,tail=1,j=2,ans=0x3f3f3f3f;
    f[1]=a[1];
    while(j<=N)
    {
        while((f[tail].y>a[j].y)&&tail>=head)
            tail--;
        tail++;
        f[tail]=a[j];
        while((tail>=head)&&(f[tail].y-f[head].y>=D))
        {
            ans=min(ans,f[tail].x-f[head].x);
            head++;
        }
        j++;

    }
    if(ans!=0x3f3f3f3f)
    {
        cout<<ans<<endl;
    }
    else
        cout<<"-1"<<endl;
    return 0;
}
/*
4 5
2 10
4 4
6 8
12 3
*/
