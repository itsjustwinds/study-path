#include<bits/stdc++.h>
#define maxn 50
using namespace std;
int c[maxn][maxn],n,k,dd[maxn],d,t;
int res;
int get(int n,int k)
{
            return ((n>>(k-1))&1);
}
int main()
{
            freopen("BINARY.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            for (int i=0; i<=34; ++i)
                        c[0][i]=1;
            for (int i=1; i<=34; ++i)
                        for (int j=i; j<=34; ++j)
                                    c[i][j]=c[i-1][j-1]+c[i][j-1];
            while(cin>>n>>k)
            {
                        t=0;
                        d=0;
                        res=0;
                        if (k==1) ++res;
                        memset(dd,0,sizeof(dd));
                        for (int i=32; i>=1; --i)
                        {
                                    if (!get(n,i))
                                    {
                                                if (t) d++;
                                                continue;
                                    }
                                    dd[i]=1;
                                    if (t==0)
                                    {
                                                t=i;
                                    }
                        }
                        int dem=0;
                        for (int i=t-1;i>=1;--i)
                        {
                                    if (dd[i]==0)
                                        {
                                                    ++dem;
                                                    continue;
                                        }
                                    int tmp=k-dem-1;
                                    if (tmp>i-1||tmp<0) continue;
                                    res+=c[tmp][i-1];
                        }
                        if (k==d) ++res;
                        for (int i=t-1; i>=k+1; --i)
                        {
                                    if (k>i-1) continue;
                                    res+=c[k][i-1];
                        }
                        cout<<res<<"\n";
            }
            return 0;
}
