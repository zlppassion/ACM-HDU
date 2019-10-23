#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//0-670-82162-4
int main()
{
    int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
    scanf("%d-%d%d%d-%d%d%d%d%d-%d",&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9,&a10);
    long long ans=a1*1+a2*2+a3*3+a4*4+a5*5+6*6+a7*7+a8*8+a9*9;
    int temp=ans%11;
    return 0;
}
