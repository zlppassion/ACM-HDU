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
            it=s.upper_bound(now);//���ص�һ��>now��λ��
            if(it==s.begin())//��nowΪ0ʱ����һ������now��λ���ڵ�һ������break�Ļ���������ѭ����ȥ
                break;
            it--;//�ղ��ҵ��˵�һ���ڵ�λ�ã���ô��һ���Ϳ����ڵ�ǰ��������װ��
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
