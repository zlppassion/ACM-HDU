#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
   int n,q;
   scanf("%d%d",&n,&q);
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   for(int j=1;j<=q;j++)
   {
       int k;
       scanf("%d",&k);
       int r=upper_bound(a,a+n,k)-a;//��һ������k��λ��
       int l=lower_bound(a,a+n,k)-a;//��һ�����ڵ���k��λ��
       if(r==l)
       {
           cout<<"-1 -1"<<endl;
       }
       else
       {
           cout<<l<<" "<<r-1<<endl;
       }
   }
    return 0;
}
