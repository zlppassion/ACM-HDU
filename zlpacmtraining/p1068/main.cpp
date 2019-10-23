#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int k;
    int s;

}a[5005];
bool cmp(node x,node y)
{
   if(x.s!=y.s)
   return  x.s>y.s;
   else
    return x.k<y.k;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int num=floor(m*1.0*1.5);//分数为排名为num的人的分数
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].k,&a[i].s);
    }
    sort(a,a+n,cmp);
    int temp=0;
   /* for(int i=0;i<n;i++)
    {
        cout<<a[i].k<<" "<<a[i].s<<endl;
    }
    cout<<num<<endl;//第四个人，索引为num-1
    */for(int i=num;i<n;i++)
    {
        if(a[i].s!=a[num-1].s)
            break;

        else
            temp++;
    }
    int ansf=a[num-1].s;
    cout<<ansf<<" "<<num+temp<<endl;//比如这个题，temp=1,总数量为5，索引截止就为4
    for(int i=0;i<num+temp;i++)
    {
        cout<<a[i].k<<" "<<a[i].s<<endl;
    }
    /*int ansf=a[num-1].s;
    int temp=0;
    for(int i=num-1;i<n;i++)
    {
        if(a[i].s!=a[num-1].s)
            break;

        else
            temp++;
    }
    cout<<ansf<<" "<<num+temp-1<<endl;
    for(int i=0;i<num+temp-1;i++)
    {
        cout<<a[i].k<<" "<<a[i].s<<endl;
    }*/
    return 0;
}
