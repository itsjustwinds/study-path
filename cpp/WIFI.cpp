#include<bits/stdc++.h>
#define maxn 505
using namespace std;
int lf[maxn],rg[maxn],lfmin,rgmax,n,m;
char s[maxn][maxn];
int main()
{
        freopen("WIFI.inp","r",stdin);
        //freopen("WIFI.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1; i<=n; ++i)
        {
                lf[i]=1e9;
                rg[i]=-1;
        }
        lf[0]=1e9;
        rg[0]=-1;
        lfmin=0;
        rgmax=0;
        for (int i=1; i<=n; ++i)
                for (int j=1; j<=m; ++j)
                {
                        cin>>s[i][j];
                        if (s[i][j]=='*')
                        {
                                if (lf[i]==1e9) lf[i]=j;
                                rg[i]=j;
                                if (lf[i]<lf[lfmin])lfmin=i;
                                if (rg[i]>rg[rgmax])rgmax=i;
                        }
                }
        for (int i=2; i<lfmin; ++i)
        {
                //if (rg[i]<lf[i-1]||lf[i]>rg[i-1]) continue;
                if (lf[i]>lf[i-1]) lf[i]=lf[i-1];
        }
        for (int i=n-1; i>lfmin; --i)
        {
                //if (rg[i]<lf[i+1]||lf[i]>rg[i+1]) continue;
                if (lf[i]>lf[i+1]) lf[i]=lf[i+1];
        }
        for (int i=2; i<rgmax; ++i)
        {
                //if (rg[i]<lf[i-1]||lf[i]>rg[i-1]) continue;
                if (rg[i]<rg[i-1]) rg[i]=rg[i-1];
        }
        for (int i=n-1; i>rgmax; --i)
        {
                //if (rg[i]<lf[i+1]||lf[i]>rg[i+1]) continue;
                if (rg[i]<rg[i+1]) rg[i]=rg[i+1];
        }
        for (int i=1; i<=n; ++i)
        {
                if (lf[i]==1e9) continue;
                for (int j=lf[i]; j<=rg[i]; ++j)
                        s[i][j]='*';
        }
        int trc=-1;
        for (int i=1; i<=n; ++i)
        {
                if (lf[i]==1e9) continue;
                if (trc!=-1)
                {
                        int ok=0;
                        if (trc!=i-1&&lf[trc]>=lf[i]&&rg[trc]<=rg[i])
                        {
                                ok=1;
                                for (int j=lf[trc];j<=rg[trc];++j)
                                        for (int k=trc;k<=i;++k)
                                        s[k][j]='*';
                        }
                        if (trc!=i-1&&lf[trc]<=lf[i]&&rg[trc]>=rg[i])
                        {
                                ok=1;
                                for (int j=lf[i];j<=rg[i];++j)
                                        for (int k=trc;k<=i;++k)
                                        s[k][j]='*';
                        }
                        if (trc!=i-1&&lf[trc]<=rg[i]&&lf[trc]>=lf[i])
                        {
                                for (int j=lf[i]; j<=rg[trc]; ++j)
                                {
                                        ok=1;
                                        for (int k=trc; k<=i; ++k)
                                                s[k][j]='*';
                                }
                        }
                        if (trc!=i-1&&rg[trc]>=lf[i]&&rg[trc]<=rg[i])
                        {
                                for (int j=rg[i]; j>=lf[trc]; --j)
                                {
                                        ok=1;
                                        for (int k=trc; k<=i; ++k)
                                                s[k][j]='*';
                                }
                        }
                        if (!ok)
                        {
                                if (lf[i]>rg[trc])
                                {
                                        for (int j=trc; j<=i; ++j)
                                                s[j][rg[trc]]='*';
                                        for (int j=rg[trc]; j<=lf[i]; ++j)
                                                s[i][j]='*';
                                }
                                else
                                {
                                        for (int j=trc; j<=i; ++j)
                                                s[j][lf[trc]]='*';
                                        for (int j=rg[i]; j<=lf[trc]; ++j)
                                                s[i][j]='*';
                                }
                        }
                }
                trc=i;
        }
        for (int i=1; i<=n; ++i)
        {
                for (int j=1; j<=m; ++j)
                        cout<<s[i][j];
                cout<<"\n";
        }
}
