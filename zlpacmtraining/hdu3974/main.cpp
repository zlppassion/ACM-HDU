#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
#define ll long long
#define ld long double
#define Accepted 0
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
const int maxn = 1e5 + 10;
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1);
const int mod = 1e9 + 7;
inline ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

#define ls rt << 1
#define rs rt << 1 | 1
//vector<int> E[maxn];
int tag[maxn];
int pre[maxn];
int Get[maxn];
/*void pushdown(int rt)
{
    if (tag[rt])
    {
        int len = E[rt].size();
        for (int i = 0; i < len; i++)
        {
            tag[E[rt][i]] = tag[rt];
        }
        tag[rt] = 0;
    }
}*/
signed main()
{
    IO int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        cout << "Case #" << cs << ":" << endl;
        unordered_map<int, int> mp;
        int tol = 0;
        memset(tag, -1, sizeof(tag));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            pre[i] = i;
        }
        for (int i = 1, u, v; i <= n - 1; i++)
        {
            cin >> u >> v;
            //E[v].push_back(u);
            pre[u] = v;
        }
        int m;
        cin >> m;
        while (m--)
        {
            char opt;
            cin >> opt;
            if (opt == 'C')
            {
                int x;
                cin >> x;
                int ans = tag[x];
                while (pre[x] != x)
                {
                    x = pre[x];
                    ans = max(ans, tag[x]);
                }
                if (ans == -1)
                    cout << ans << endl;
                else
                    cout << Get[ans] << endl;
            }
            if (opt == 'T')
            {
                int x, y;
                cin >> x >> y;
                if (!mp[y])
                {
                    mp[y] = ++tol;
                    Get[tol] = y;
                }
                tag[x] = mp[y];
            }
        }
    }
    return Accepted;
}
