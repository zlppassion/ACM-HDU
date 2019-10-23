#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005][1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%1d", &a[i][j]);
            a[i][j] += a[i][j] * a[i-1][j];
        }
    }
    int maxarea = 0, secarea = 0;
    for(int i = n; i >= 1; i--)
    {
        for(int j = m; j >= 1; j--)
        {
            int height = a[i][j];
            for(int k = j; k >= 0; k--)
            {
                if(a[i][k] == 0)
                {
                    break;
                }
                if(height * j <= secarea)
                {
                    break;
                }
                height = min(height, a[i][k]);
                int area = height * (j-k+1);
                if(area >= maxarea)
                {
                    secarea = maxarea;
                    maxarea = area;
                }
                else if(area >= secarea)
                {
                    secarea = area;
                }
            }
        }
    }
    printf("%d\n", secarea);
    //cin >> secarea;
    return 0;
}
