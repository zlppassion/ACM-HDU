#include <iostream>
#include<bits/stdc++.h>
using namespace std;
set<int> a;
int main()
{
    int n;
    scanf("%d",&n);
    int m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        a.insert(m);
    }
    set<int>::iterator it=a.begin();
    cout<<a.size()<<endl;
    for(;it!=a.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}
