#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000005;

int next[maxn];

void get(char *s)
{
    int mp = strlen(s);
    int j = 0, k = -1;
    next[0] = -1;
    while(j < mp)
    {
        if(k == -1 || s[j] == s[k])
        {
            next[++j] = ++k;
        }
        else
        {
            k = next[k];
        }
    }
}
char s[maxn];

int main()
{
    while(gets(s) )
    {
        if(strcmp(s,".") == 0)
        {
            break;
        }
        get(s);
        int ans = 1;
        int mp = strlen(s);
        if(mp% (mp - next[mp]) == 0)
        {
            ans = mp / (mp - next[mp]);
        }
        printf("%d\n", ans);
    }
}
