#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[30];//�洢���ַ���
int a[30][30];//���������ʾ��i����ŵ��ַ����͵�j����ŵ��ַ������ص�����
int mx(int x,int y)
{
    bool flag=true;
    int ky=0;
    for(int kx=s[x].size()-1;kx>=0;kx--)
    {
        for(int k=kx;k<s[x].size();k++)
        {
            if(s[x][k]!=s[y][ky++])
            {
                flag=false;
                break;
            }
        }
        if(flag==true)
        {
            return s[x].size()-kx;
        }
        ky=0;
        flag=true;
    }
    return 0;
}
int n;
char ch;
int vis[30];//�жϵ��ʵ�ʹ��Ƶ��
int ans=-1;//��
int an=0;//ÿ���ѵ��ĵ�ǰ���
void dfs(int pos)
{
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]>=2)//ʹ�������μ����Ͼ�����
            continue;
        if(a[pos][i]==0)
            continue;//������֮��û���غϲ��־�����
        if(a[pos][i]==s[pos].size()||a[pos][i]==s[i].size())
            continue;//���ǰ���ǰ�����ϵ�Ļ����Ͳ�����Ҫ��������
        an+=s[i].size()-a[pos][i];//�����ʺϲ��ټ�ȥ�غϲ���
        vis[i]++;
        flag=true;
        dfs(i);
        an-=s[i].size()-a[pos][i];//����
        vis[i]--;
        flag=false;
    }
    if(flag==false)//˵���������ҵ��κ�һ�����ʿ���������
       ans=max(ans,an);//����ans
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    cin>>ch;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=mx(i,j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i][0]==ch)//����У��Ϳ������������Ϊͷ��ʼ����
        {
            vis[i]++;
            an=s[i].size();//���µ�ǰ������
            dfs(i);
            vis[i]=0;//����Ӱ��
        }
    }
    cout<<ans<<endl;

}
