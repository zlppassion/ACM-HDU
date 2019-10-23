#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5005;
struct node
{
    int danp;//单价
    int sum;//总量
}a[maxn];
bool cmp(node x,node y)
{
    return x.danp<y.danp;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a[i].danp,&a[i].sum);
    }
    sort(a,a+m,cmp);
    ll costq=0,costnum=0;
    int temp=0;
    for(int i=0;i<m;i++)
    {
        ll te=a[i].danp*a[i].sum;
        if((costnum+a[i].sum)<n)
        {
            costq+=te;
            costnum+=a[i].sum;
        }

        else
        {
            temp=i;
            break;
        }
    }
    int shengnum=n-costnum;
    costq+=shengnum*a[temp].danp;
    cout<<costq<<endl;
    return 0;
}
