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
    int num=floor(m*1.0*1.5);//����Ϊ����Ϊnum���˵ķ���
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
    cout<<num<<endl;//���ĸ��ˣ�����Ϊnum-1
    */for(int i=num;i<n;i++)
    {
        if(a[i].s!=a[num-1].s)
            break;

        else
            temp++;
    }
    int ansf=a[num-1].s;
    cout<<ansf<<" "<<num+temp<<endl;//��������⣬temp=1,������Ϊ5��������ֹ��Ϊ4
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
