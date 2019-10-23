#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int s[1005];
struct tree
{
    int pos;
    int sub;
    int sum;
    tree(int p=0,int s=0,int ss=0)
    {
        pos=p;
        sub=s;
        sum=ss;
    }
}a[1005];
bool cmp(tree x,tree y)
{
    if(x.sub==y.sub)
        return x.pos<y.pos;
    else
        return x.sub>y.sub;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int temp;
    for(int i=1;i<=n;i++)//n棵树
    {
        for(int j=1;j<=m+1;j++)
        {
            scanf("%d",&temp);
            if(j!=1)
            {
                a[i].sub-=temp;
                s[i]+=temp;
            }

            else
                a[i].sum=temp;
        }
        a[i].pos=i;

    }
    ll sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i].sum;//原先的果子总量
    for(int i=1;i<=n;i++)
        sum+=s[i];
    cout<<sum<<" ";
    sort(a+1,a+n+1,cmp);
    cout<<a[1].pos<<" "<<a[1].sub<<endl;
    return 0;
}
