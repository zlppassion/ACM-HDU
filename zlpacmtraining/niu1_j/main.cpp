#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll x,y;
    int a,b;
    while(scanf("%lld%d%lld%d",&x,&a,&y,&b)==4)
    {
        __int128 l = (__int128)x * b;
        __int128 r = (__int128)y * a;
        if(l>r){
            printf(">");
        }
        else if(l<r){
            printf("<");
        }
        else{
            printf("=");
        }
        printf("\n");
    }
    return 0;
}
