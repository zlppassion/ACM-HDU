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
void dfs(int x,int y,int jin)//x��n�У���λ
{
    if(y==0)//���ϵ��£����ҵ���y=0���������������һ��
    {
        if(jin==0)//��ʱ��λΪ0������Ҫ��
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
    for(int i=y-1;i>=0;i--)//��֦1
    {
        int w1=flag[id(s[1][i])];//1��i��
        int w2=flag[id(s[2][i])];//2��i��
        int w3=flag[id(s[3][i])];//3��i��
        if(w1==-1||w2==-1||w3==-1)//������λ���ϻ�û�б���ֵ��������ѭ��
        {
            continue;
        }
        if((w1+w2)%n!=w3&&(w1+w2+1)%n!=w3)//if((w1+w2+jin)%n!=w3),��������д�����������
        {
            return ;
        }
    }
    if(flag[id(s[x][y])]==-1)//������λ���ϻ�û�б���ֵ���ͽ��и�ֵ����
    {
        for(int i=n-1;i>=0;i--)
        {
            if(!use[i])//��������û���ù�
            {
                if(x!=3)//�Ҳ������һ��
                {
                    flag[id(s[x][y])]=i;
                    use[i]=1;
                    dfs(x+1,y,jin);//����������һ��
                    flag[id(s[x][y])]=-1;
                    use[i]=0;//��ԭ
                }
                else//�����һ��
                {
                    int w=flag[id(s[1][y])]+flag[id(s[2][y])]+jin;
                    if(w%n!=i)
                        continue;
                    use[i]=1;
                    flag[id(s[3][y])]=i;
                    dfs(1,y-1,w/n);//������һ�У���λ��Ҫ�ı�
                    use[i]=0;
                    flag[id(s[3][y])]=-1;
                }
            }
            else//������λ�����Ѿ�����ֵ��
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
    scanf("%d",&n);//����n����
    for(int i=1;i<=3;i++)
    {
        scanf("%s",s[i]+1);//���������ַ���
    }
    memset(flag,-1,sizeof(flag));
    dfs(1,n,0);//��1��n�п�ʼ
    return 0;
}
