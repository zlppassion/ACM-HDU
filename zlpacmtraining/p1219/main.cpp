#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int r[20],c[20],zl[50],rl[50];
int n;
int sum=0;
void print()
{
    if(sum<3)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<r[i]<<" ";

        }
        cout<<endl;
    }
    sum++;
}
void dfs(int i)
{
    if(i>n)
    {
        print();
        return;
    }
    for(int j=1;j<=n;j++)//j代表列
    {
        if(!c[j]&&!zl[i+j]&&!rl[i-j+n])
        {
            r[i]=j;//i行 为j列占了
            c[j]=1;
            zl[i+j]=1;
            rl[i-j+n]=1;
            dfs(i+1);
            c[j]=0;
            zl[i+j]=0;
            rl[i-j+n]=0;
        }
    }
}
int main()
{

    scanf("%d",&n);
    dfs(1);
    cout<<sum<<endl;
    return 0;
}
