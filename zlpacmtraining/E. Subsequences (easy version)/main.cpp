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
            icur.erase(i,1);//erase(pos,n); ɾ����pos��ʼ��n���ַ�������erase(0,1)����ɾ����һ���ַ�
            if(s.size()<k&&!s.count(icur))//�����k���������������г��ֹ��Ͳ���������ˡ�
            {
                s.insert(icur);
                q.push(icur);
                ans+=n-icur.size();//ͳ�ƴ��ۡ�
            }
            if(s.size()==k)
            {
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    if(s.size()<k)//û��k�������У��޽⡣
    {
        cout<<"-1";
    }

    return 0;
}
