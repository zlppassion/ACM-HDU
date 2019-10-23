#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
char s[maxn];
int n;
int siz[maxn*2];
int sum[maxn*2];
struct Suffix_Automation
{
    int next[maxn*2][26],fa[maxn*2],l[maxn*2],mmin[maxn*2];
    int last,cnt;
    int cntA[maxn*2],A[maxn*2];
    void init()
    {
        last=cnt=1;
        fa[1]=l[1]=0;
        memset(next[1],0,sizeof next[1]);
    }
    int inline newnode()
    {
        cnt++;
        memset(next[cnt],0,sizeof next[cnt]);
        fa[cnt]=l[cnt]=0;
        return cnt;
    }
    void add(int c)
    {
        int p=last;
        int np=newnode();
        mmin[np]=l[np]=l[p]+1;
        last=np;
        while(p&&!next[p][c])
        {
            mmin[np]=min(mmin[np],mmin[p]+1);
            next[p][c]=np,p=fa[p];
        }
        if(!p)
            fa[np]=1;
        else
        {
            int q=next[p][c];
            if(l[q]==l[p]+1)
                fa[np]=q;
            else
            {
                int nq=++cnt;
                l[nq]=l[p]+1;
                mmin[q]=l[p]+2;
                memcpy(next[nq],next[q],sizeof next[q]);
                fa[nq]=fa[q];
                fa[np]=fa[q]=nq;
                while(next[p][c]==q)
                    next[p][c]=nq,p=fa[p];
            }
        }
        siz[np]=1;
    }
    void work(int op)
    {
        memset(cntA,0,sizeof cntA);
        for(int i=1; i<=cnt; i++)
            cntA[l[i]]++;
        for(int i=1; i<=n; i++)
            cntA[i]+=cntA[i-1];
        for(int i=1; i<=cnt; i++)
            A[cntA[l[i]]--]=i;
        for(int i=cnt; i>=1; i--)
        {
            int p=A[i];
            if(op)
                siz[fa[p]]+=siz[p];
            else siz[p]=1;
        }
        siz[1]=0;
        for(int i=cnt; i>=1; i--)
        {
            int p=A[i];
            sum[p]=siz[p];
            for(int j=0; j<26; j++)
                sum[p]+=sum[next[p][j]];
        }
    }
} sam;
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    sam.init();
    for(int i=1; i<=n; i++)
        sam.add(s[i]-'a');
    int op=0;
    sam.work(op);
    int k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&k);
        if(k>sum[1])
            printf("-1\n");
        else
        {
            int p=1;
            while(k>siz[p])
            {
                k-=siz[p];
                for(int i=0; i<26; i++)
                {
                    if(sum[sam.next[p][i]]>=k)
                    {
                        printf("%c",'a'+i);
                        p=sam.next[p][i];
                        break;
                    }
                    else k-=sum[sam.next[p][i]];
                }
            }
            printf("\n");
        }
    }

    return 0;
}
