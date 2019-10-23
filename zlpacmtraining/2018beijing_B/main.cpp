/*Input
There are no more than 10 test cases.

In each case:

The first line is an integer n, meaning there are n (0 < n �� 10) arm rings.

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
/*��Ϊ���������ַ������Ⱥ�С��������dfsö�ٳ�ÿ���ַ����������Ӵ�����set���档�����ַ������Ĵ���
����ÿ��ö�ٳ����ַ������Դ�0��sz�����ַ����ĳ��ȣ�ö�ٷֳ����룬�ٰѺ���Ĳ��ּӵ�ǰ�漴�ɹ�������еĻ����ַ�����*/

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
    dfs(x,l+1);//Ҫѡl��ͷ��
    t.erase(t.end()-1);
    dfs(x,l+1);//��ѡl��ͷ��
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
