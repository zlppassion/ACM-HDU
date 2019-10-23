#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e3+10;
const ll mod = 998244353;
ll dp[N][N],ans,C[N][N];
char s[N],t[N];
int n,m;
//dp[i][j]:��s����ǰi��Ϊ����ѡ��jλ��(����Ϊj��������)
//��t��ǰjλ����ȵ���������
int main(void)
{
    int T;
    scanf("%d",&T);
    C[0][0]=1;
    for(int i=1;i<=N-10;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    while(T--)
    {
        scanf("%d%d%s%s",&n,&m,s+1,t+1);
        ans=0;

        //ѡ�������г��ȵ���t�ĳ��ȣ�Ҫ��֤ǰ��ĳ��λ��ͬ
        //�м�����һλ����t

        //��ʼ����ѡ��0λ�������������϶�Ϊ1
        //��һ��Ҳ��ѡ
        for(int i=0;i<=n;i++)
            dp[i][0]=1;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=min(i,m);j++)
            {
                //���Ȳ���s[i]��t[j]�������Ĵ�С��ϵ���ܻ���dp[i-1][j]����������������
                //Ҳ���ǲ�ѡs���еĵ�iλ��
                dp[i][j]=dp[i-1][j];
                //ֻ��s[i]==t[j]ʱ������ѡs[i]����Ҫ��֤��s����ǰi-1Ϊ��
                //ѡ������j-1λ��Ҫ���
                if(s[i]==t[j]) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                //��Ȼ��s����ѡ������������ɵ�����jλ�Ѿ�����t�ĵ�jλ�ˣ�
                //��ô����������ôѡ������t��ʾ����
                if(s[i]>t[j])
                    ans=(ans+dp[i-1][j-1]*C[n-i][m-j]%mod)%mod;
            }
        //ѡ�������еĳ��ȴ���t�ĳ��ȵ����
        //ֱ���������ѧ��ʽ��
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0') continue;
            for(int j=m;j<=n-i;j++)//iλ�䵱��һ�����֣������ں�n-iλ����ѡjλ
                ans=(ans+C[n-i][j])%mod;
        }
        printf("%lld\n",ans);

    }

    return 0;
}
