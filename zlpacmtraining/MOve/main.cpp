#include <bits/stdc++.h>
using namespace std;
int a[1005];
int num,k;
bool check(int maxv)
{
    multiset<int>s;
    s.clear();
    for(int i=1; i<=num; i++)
    {
        s.insert(a[i]);
    }
    multiset<int>::iterator it;
    for(int i=1; i<=k; i++)
    {
        int now=maxv;
        while(now>=0&&s.size()>0)
        {
            it=s.upper_bound(now);//返回第一个>now的位置
            if(it==s.begin())//当now为0时，第一个大于now的位置在第一个，不break的话，会无限循环下去
                break;
            it--;//刚才找到了第一大于的位置，那么减一个就可以在当前容量进行装了
            now-=*it;
            if(now>=0)
            {
                s.erase(it);
            }
            else
            {
                break;
            }
        }
    }
    if(s.size()==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int tnum;
    cin>>tnum;
    int cnt=1;
    while(tnum--)
    {

        cin>>num>>k;
        int sum=0;
        for(int i=1; i<=num; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        cout<<"Case #"<<cnt<<": ";
        cnt++;
        for(int i=(sum/k);; i++)
        {
            if(check(i))
            {
                cout<<i<<endl;
                break;
            }
        }

    }
}
