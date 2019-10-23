#include <iostream>
#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > h1;
priority_queue<int,vector<int>,less<int> > h2;//大根堆，从大到小
int n,m;
int a[200005];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int last=1,j=1;
    for(int i=1;i<=m;i++)
    {
       int k;
       scanf("%d",&k);
       for(;last<=k;last++)
       {
           h1.push(a[last]);

       }
       while(h2.size()<j&&(!h1.empty()))
       {
           int top=h1.top();//最小值
           h1.pop();
           h2.push(top);
       }
      while(h2.size()==j&&(!h1.empty())&&h2.top()>h1.top())//因为我们理解的是插入h1.top()
       {
           int top2=h2.top();h2.pop();
            int top1=h1.top();h1.pop();
            h2.push(top1);
            h1.push(top2);
       }
       cout<<h2.top()<<endl;
       j++;
    }

    return 0;
}
