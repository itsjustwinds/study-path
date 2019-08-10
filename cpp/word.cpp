#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
char a[maxn][maxn],s[maxn];
int p[maxn],len[maxn],n,m,nS,dd[100][100],dd2[100][100][100];
ll F[105][105][maxn][6];
ll f[maxn][maxn],g[maxn];
vector<int> e[100];
ll tinh1(int head,int tail)
{
        if (f[head][tail]!=-1) return f[head][tail];
        if (head>tail) return 0;
        ll res=-1e18;
        for (int i=head;i<=tail-1;++i)
        {
                for (int j=i+1;j<=tail;++j)
                {
                        ll x=dd[s[i]-'a'][s[j]-'a'];
                        if (dd[s[i]-'a'][s[j]-'a']!=0)
                        res=max(res,tinh1(head,i-1)+tinh1(i+1,j-1)+tinh1(j+1,tail)+x);
                }
        }
        f[head][tail]=res;
        return f[head][tail];
}
void sub1()
{
        memset(f,-1,sizeof f);
        for (int i=1;i<=n;++i)
        {
                dd[a[i][1]-'a'][a[i][2]-'a']=p[i];
        }
        for (int i=1;i<=nS;++i)
        {
                g[i]=g[i-1];
                for (int j=1;j<=i;++j)
                        g[i]=max(g[i],g[j-1]+tinh1(j,i));
        }
        cout<<g[nS];
}
ll tinh2(int i,int j)
{
        if (f[i][j]!=-1) return f[i][j];
        if (i>j) return 0;
        f[i][j]=-1e18;
        for (int k=i+1;k<j;++k)
        {
                int x=dd2[s[i]-'a'][s[k]-'a'][s[j]-'a'];
                if (x==0) continue;
                f[i][j]=max(f[i][j],tinh2(i+1,k-1)+tinh2(k+1,j-1)+x);
        }
        for (int k=i+1;k<j;++k)
                f[i][j]=max(f[i][j],tinh2(i,k)+tinh2(k+1,j));
        return f[i][j];
}
void sub2()
{
        memset(f,-1,sizeof f);
        for (int i=1;i<=n;++i)
                dd2[a[i][1]-'a'][a[i][2]-'a'][a[i][3]-'a']=p[i];
        for (int i=1;i<=nS;++i)
        {
                g[i]=g[i-1];
                for (int j=1;j<=i;++j)
                        g[i]=max(g[i],g[j-1]+tinh2(j,i));
        }
        cout<<g[nS];
}
ll tinh3(int head,int tail)
{
        if (f[head][tail]!=-1) return f[head][tail];
        if (head>tail) return 0;
        f[head][tail]=-1e18;
        for (int i=tail;i>=head;--i )
        {
        for (int k=1;k<=n;++k)
        {
                if (i==2&&head==2&&tail==6&&k==2)
                {
                        int ok=1;
                }
                for (int j=i;j<=tail;++j)
                        for (int h=0;h<len[k];++h)
                        if (s[j]==a[k][h+1]&&F[i][j-1][k][h]!=-1)
                        F[i][j][k][h+r1]=max(F[i][j][k][h+1],F[i][j-1][k][h]+tinh3(j+1,tail));
        }
        }
        for (int k=1;k<=n;++k)
        if (F[head][tail][k][len[k]]!=-1)f[head][tail]=max(f[head][tail],F[head][tail][k][len[k]]+p[k]);
        return f[head][tail];
}
void sub3()
{
        memset(F,-1,sizeof F);
        memset(f,-1,sizeof f);
        for (int i=0;i<=nS;++i)
                for (int j=0;j<=nS;++j)
                for (int k=1;k<=n;++k)
                F[i][j][k][0]=0;
        tinh3(2,6);
        for (int i=1;i<=nS;++i)
        {
                //g[i]=g[i-1];
                for (int j=1;j<=i;++j)
                        g[i]=max(g[i],g[j-1]+tinh3(j,i));
        }
        cout<<g[nS];
}
int main()
{
        freopen("WORD.inp","r",stdin);
        //freopen("WORD.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        cin>>n;
        int maxl=0;
        for (int i=1;i<=n;++i)
        {
                cin>>(a[i]+1);
                cin>>p[i];
                len[i]=strlen(a[i]+1);
                maxl=max(maxl,len[i]);
        }
        nS=strlen(s+1);
        if (maxl==2) sub1();
        if (maxl==3) sub2();
        if (maxl==5) sub3();
}
