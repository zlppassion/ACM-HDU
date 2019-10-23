#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[55][55];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    return 0;
}
