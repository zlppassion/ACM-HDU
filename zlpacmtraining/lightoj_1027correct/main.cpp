#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
int GCD(int a, int b)
{
   return b == 0 ? a : GCD(b, a%b);
}
int a[110];
int main()
{
    int t;
    int N;
    int k = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &N);
        int sum1 = 0, sum2 = 0;
        int door1 = 0, door2 = 0;
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &a[i]);
            if(a[i] > 0)
            {
                sum1 += a[i];
                door1++;
            }
            else
            {
                sum2 += abs(a[i]);
                door2++;
            }
        }
        int up = sum1 + sum2;
        int down = N - door2;
        printf("Case %d: ", k++);
        if(door2 == N)
            printf("inf\n");
        else
            printf("%d/%d\n", up / GCD(up, down), down / GCD(up, down));
    }
    return 0;
}
