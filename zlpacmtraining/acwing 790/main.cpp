#include <iostream>
#include<bits/stdc++.h>
using namespace std;
double n;
bool check(double x)
{
    if(x*x*x>=fabs(n))
        return true;
    return false;
}
int main()
{
    cin>>n;
    int flag=0;
    if(n<0)
    {
        flag=1;
    }
    const double eps = 1e-7;   // eps 表示精度，取决于题目对精度的要求
    double l=0.0;
    double r=fabs(n);
    while (r - l >= eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else l = mid;
    }
    if(!flag)
        printf("%.6f\n",l);
    else
        printf("%.6f\n",-l);
    return 0;
}
