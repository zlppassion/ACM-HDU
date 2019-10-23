
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    scanf("%lld",&n);
    if(n==1||n==2)
        printf("55\n");
    else if(n%2)
        printf("1\n");
    else
        printf("-1\n");
    return 0;

}
