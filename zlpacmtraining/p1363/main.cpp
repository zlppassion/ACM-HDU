#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn=1505;
char a[maxn][maxn];
bool map1[maxn*2],map2[maxn*2];
int n,m,dn,dm;
bool dfs(int x,int y)
{
    if(x==-1)
    {
        if(dfs(dn-1,y))
            return true;
        return false;
    }
    if(x == dn)
    {
        if(dfs(0, y))return true;
        return false;
    }
    if(y == -1)
    {
        if(dfs(x, dm - 1))return true;
        return false;
    }
    if(y == dm)
    {
        if(dfs(x, 0))return true;
        return false;
    }//�����ĸ�if��ʾ�Ƿ񵽱߽磬�Ǿʹ���
    if(map1[x][y] || board[x % n][y % m] == '#')
    {
        return false;
    }//�ж��ܲ�����
    if(map2[x % n][y % m])
    {
        return true;
    }//�ж�����û���ߵ�������ӳ��
    map1[x][y] = true;
    map2[x % n][y % m] = true;
    //��¼
    if(dfs(x + 1, y))return true;
    if(dfs(x - 1, y))return true;
    if(dfs(x, y + 1))return true;
    if(dfs(x, y - 1))return true;
    //����
    return false;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        dn=n*2;
        dm=m*2;
        int sx,sy;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
            }
        }
        memset(map1,0,sizeof(map1));
        memset(map2,0,sizeof(map2));
        if(dfs(sx,sy))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
