#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,ap,bp,as,bs,ans=0,w;
int f[2002][2002],l,r,q[2001];
//f[i][j]表示第i天后拥有j张股票赚的最多钱数
//l,r,q[x]用于单调队列
int main()
{
    scanf("%d%d%d",&n,&m,&w);//n天，m最多手头的量，w隔的天数
    memset(f,128,sizeof(f));//128实际上给f数组赋的是-inf,即-2139062144
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&ap,&bp,&as,&bs);
        for(int j=0;j<=as;j++)
            f[i][j]=-1*j*ap;//第一种情况，直接赋值，
        for(int j=0;j<=m;j++)
            f[i][j]=max(f[i][j],f[i-1][j]);//转移，如果改天不买股票
        if(i<=w)//因为第3，4种情况都有i-w-1,如果i<=w,会出现负下标
            continue;
        //第3种情况，在之前的基础上买股票，f[i,j]=max(f[i,j],f[i-w-1,k]-(j-k)*api];
        //可以进一步转化为f[i,j]=max(f[i,j],f[i-w-1,k]+k*api]-j*api;
        l=1,r=0;//单调队列准备,从小转移到大，因为是买股票，j应该是越来越大
        for(int j=0;j<=m;j++)
        {
            while(l<=r&&q[l]<j-as)
                l++;//把过期的元素扔掉
            while(l<=r&&f[i-w-1][q[r]]+q[r]*ap<=f[i-w-1][j]+j*ap)//最大值在开头，递增序列
                r--;
            q[++r]=j;//更新单调队列元素
            if(l<=r)//如果单调队列里面有元素，即可以转移,因为我们要的是最大值，所以是l
                f[i][j]=max(f[i][j],f[i-w-1][q[l]]+q[l]*ap-j*ap);


        }
        //第4种情况，在之前的基础上卖股票，f[i,j]=max(f[i,j],f[i-w-1,k]+(k-j)*bpi];
        //可以进一步转化为f[i][j]=max(f[i][j],f[i-w-1,k]+k*bp)-j*bp;
        l=1,r=0;//单调队列准备，从大转移到小，因为是卖股票，j应该是越来越小
        for(int j=m;j>=0;j--)
        {
            while(l<=r&&q[l]>j+bs)
                l++;//把过期的元素扔掉
            while(l<=r&&f[i-w-1][q[r]]+q[r]*bp<=f[i-w-1][j]+j*bp)//最大值在开头，递增序列
                r--;
            q[++r]=j;
            if(l<=r)//如果单调队列里有元素，即可转移
                f[i][j]=max(f[i][j],f[i-w-1][q[l]]+q[l]*bp-j*bp);
        }
    }
    for(int i=0;i<=m;i++)
    {
        ans=max(ans,f[n][i]);
    }
    cout<<ans<<endl;
    return 0;
}
