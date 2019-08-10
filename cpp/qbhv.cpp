#include<bits/stdc++.h>
#define maxn 26
using namespace std;
int dd[maxn],n,res,c[10001][10001];
vector<char> e;
char s[100],ans[100];
void tryy(int i)
{
            if (i==n+1)
            {
                       for (int i=1;i<=n;++i)
                       {
                                   cout<<ans[i];
                       }
                       cout<<"\n";
            }
            for (int j=0;j<(int)e.size();++j)
            {
                        char k=e[j];
                        if  (dd[k-'A']==0) continue;
                        ans[i]=k;
                        --dd[k-'A'];
                        tryy(i+1);
                        ++dd[k-'A'];
            }
}
int main()
{
            freopen("QBHV.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>(s+1);
            n=strlen(s+1);
            for (int i=1;i<=n;++i)
            {
                        if (dd[s[i]-'A']==0) e.push_back(s[i]);
                        ++dd[s[i]-'A'];
            }
            sort(e.begin(),e.end());
            for (int i=0;i<=10000;++i)
                        c[0][i]=1;
            for (int i=1;i<=10000;++i)
                        for (int j=i;j<=10000;++j)
            {
                        c[i][j]=c[i-1][j-1]+c[i][j-1];
            }
            res=1;
            int sum=n;
            for (int i=0;i<(int)e.size();++i)
            {
                        int k=dd[e[i]-'A'];
                        res*=c[k][sum];
                        sum-=k;
            }
            cout<<res<<"\n";
            tryy(1);
}
