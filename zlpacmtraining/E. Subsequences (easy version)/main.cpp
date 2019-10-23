#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=500010;
const ll INF=2147483647;
ll n,k,ans;
string a,cur,icur;
queue<string> q;
set<string> s;
int main()
{
    cin>>n>>k;
    cin>>a;
    s.insert(a);
    q.push(a);
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        for(int i=0;i<cur.size();i++)
        {
            icur=cur;
            icur.erase(i,1);//erase(pos,n); 删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符
            if(s.size()<k&&!s.count(icur))//如果有k个点或者这个子序列出现过就不用再入队了。
            {
                s.insert(icur);
                q.push(icur);
                ans+=n-icur.size();//统计代价。
            }
            if(s.size()==k)
            {
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    if(s.size()<k)//没有k个子序列，无解。
    {
        cout<<"-1";
    }

    return 0;
}
