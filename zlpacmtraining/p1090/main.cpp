#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[10005];
#define ll long long
//priority_queue<int> q;//Ĭ�ϴӴ�С
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        q.push(a[i]);
    }

    ll s=0;


   while(q.size()>=2)
   {
       int a=q.top();q.pop();//��Ϊ�Ǵ�С������������ÿ�����������Сֵ
       //cout<<a<<endl;
       int b=q.top();q.pop();
       //cout<<b<<endl;
       s+=(a+b);
       q.push(a+b);

   }
    cout<<s<<endl;
    return 0;
}
