#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[100005];
void qsort(int l,int r)
{
    if(l==r)
        return;
    int mid=a[(l+r)/2];
    int i=l,j=r;
    do
    {
        while(a[i]<mid)
            i++;
        while(a[j]>mid)
            j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(l<j)
        qsort(l,j);
    if(i<r)
        qsort(i,r);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    qsort(1,n);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
