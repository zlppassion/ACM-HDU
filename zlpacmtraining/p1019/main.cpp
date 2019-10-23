#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[30];//存储的字符串
int a[30][30];//用这个来表示第i个编号的字符串和第j个编号的字符串的重叠部分
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
int vis[30];//判断单词的使用频率
int ans=-1;//答案
int an=0;//每次搜到的当前最长串
void dfs(int pos)
{
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]>=2)//使用了两次及以上就跳过
            continue;
        if(a[pos][i]==0)
            continue;//两单词之间没有重合部分就跳过
        if(a[pos][i]==s[pos].size()||a[pos][i]==s[i].size())
            continue;//如果前后是包含关系的话，就不符合要求，则跳过
        an+=s[i].size()-a[pos][i];//两单词合并再减去重合部分
        vis[i]++;
        flag=true;
        dfs(i);
        an-=s[i].size()-a[pos][i];//回溯
        vis[i]--;
        flag=false;
    }
    if(flag==false)//说明不能再找到任何一个单词可以相连了
       ans=max(ans,an);//更新ans
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
        if(s[i][0]==ch)//如果有，就可以以这个单词为头开始搜索
        {
            vis[i]++;
            an=s[i].size();//更新当前串长度
            dfs(i);
            vis[i]=0;//消除影响
        }
    }
    cout<<ans<<endl;

}
