/*Input
There are no more than 10 test cases.

In each case:

The first line is an integer n, meaning there are n (0 < n ≤ 10) arm rings.

Then n lines follow. Each line is a string on an arm ring consisting of only lowercase letters.
The length of the string is no more than 8.

Output
For each case, print the password. If there is no LCS, print 0 instead.

Sample Input
2
abcdefg
zaxcdkgb
5
abcdef
kedajceu
adbac
abcdef
abcdafc
2
abc
def
Sample Output
acdg
acd
0*/
/*因为数据量和字符串长度很小，可以用dfs枚举出每个字符串的所有子串，用set保存。至于字符串环的处理，
考虑每次枚举出的字符串可以从0到sz（此字符串的长度）枚举分成两半，再把后面的部分加到前面即可构造出所有的环形字符串。*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,len;
set<string> st[12];
string s,t;
void dfs(int x, int l)
{
    if(l==len)
    {
        if(t=="")
            return;
        int sz=t.length();
        for(int j=0;j<sz;j++)
        {
            st[x].insert(t.substr(j,sz-j)+t.substr(0,j));
        }
        return ;

    }
    t+=s[l];
    dfs(x,l+1);//要选l开头的
    t.erase(t.end()-1);
    dfs(x,l+1);//不选l开头的
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            st[i].clear();
        }
        for(int i=0;i<n;i++)
        {
            cin>>s;
            len=s.length();
            t="";
            dfs(i,0);
        }
        string ans;
        set<string>::iterator it=st[0].begin();
        for(;it!=st[0].end();it++)
        {
            int flag=0;
            for(int j=1;j<n;j++)
            {
                // if(!st[j].count(*it))
                if(st[j].find(*it)==st[j].end())
                {
                    flag=1;
                    break;
                }
            }
             if(!flag)
            {
                if((*it).length()>ans.length())   ans=*it;
                else if((*it).length()==ans.length()&&(*it)<ans)    ans=*it;
            }
        }

         if(ans=="")
            cout<<0<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
