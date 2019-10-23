#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
int n,flag[maxn];
char s[4][maxn];
bool use[maxn];
int id(char ch)
{
    return ch-'A'+1;
}
void dfs(int x,int y,int jin)//x行n列，进位
{
    if(y==0)//从上到下，从右到左，y=0代表搜索到了最后一列
    {
        if(jin==0)//此时进位为0才满足要求
        {
            for(int i=1;i<n;i++)
            {
                printf("%d ",flag[i]);
            }
            printf("%d\n",flag[n]);
           exit(0);

        }
        return;
    }
    for(int i=y-1;i>=0;i--)//剪枝1
    {
        int w1=flag[id(s[1][i])];//1行i列
        int w2=flag[id(s[2][i])];//2行i列
        int w3=flag[id(s[3][i])];//3行i列
        if(w1==-1||w2==-1||w3==-1)//如果这个位置上还没有被赋值，就重新循环
        {
            continue;
        }
        if((w1+w2)%n!=w3&&(w1+w2+1)%n!=w3)//if((w1+w2+jin)%n!=w3),我想这样写，待会儿试试
        {
            return ;
        }
    }
    if(flag[id(s[x][y])]==-1)//如果这个位子上还没有被赋值，就进行赋值操作
    {
        for(int i=n-1;i>=0;i--)
        {
            if(!use[i])//如果这个数没有用过
            {
                if(x!=3)//且不是最后一行
                {
                    flag[id(s[x][y])]=i;
                    use[i]=1;
                    dfs(x+1,y,jin);//继续搜索下一行
                    flag[id(s[x][y])]=-1;
                    use[i]=0;//还原
                }
                else//是最后一行
                {
                    int w=flag[id(s[1][y])]+flag[id(s[2][y])]+jin;
                    if(w%n!=i)
                        continue;
                    use[i]=1;
                    flag[id(s[3][y])]=i;
                    dfs(1,y-1,w/n);//搜索下一列，进位需要改变
                    use[i]=0;
                    flag[id(s[3][y])]=-1;
                }
            }
            else//如果这个位子上已经被赋值了
            {
                if(x!=3)
                {
                    dfs(x+1,y,jin);
                }
                else
                {
                    int w=flag[id(s[1][y])]+flag[id(s[2][y])]+jin;
                    if(w%n!=flag[id(s[3][x])])
                    {
                        return;
                    }
                    dfs(1,y-1,w/n);
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&n);//代表n进制
    for(int i=1;i<=3;i++)
    {
        scanf("%s",s[i]+1);//读入三行字符串
    }
    memset(flag,-1,sizeof(flag));
    dfs(1,n,0);//从1行n列开始
    return 0;
}
