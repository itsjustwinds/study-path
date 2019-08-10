#include<bits/stdc++.h>
#define maxn 2000006
using namespace std;
char s[maxn],t[maxn];
int n,m,Z[maxn];
vector<int >res;
void Z_func()
{
        int l=1,r=1;
        for (int i=2;i<=n;++i)
        {
                if (i<=r) Z[i]=min(Z[i-l+1],r-i+1);
                while(i+Z[i]<=n&&s[1+Z[i]]==s[i+Z[i]])
                        ++Z[i];
                if (i+Z[i]-1>r)
                {
                        r=i+Z[i]-1;
                        l=i;
                }
        }
}
int main()
{
        freopen("SM.inp","r",stdin);
        freopen("SM.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        cin>>(t+1);
        n=strlen(s+1);
        int tmp=n+1;
        m=strlen(t+1);
        s[++n]='#';
        for (int i=1;i<=m;++i)
                s[++n]=t[i];
        Z_func();
        for (int i=1;i<=n;++i)
        if (Z[i]==tmp-1) res.push_back(i-tmp-1);
        cout<<res.size()<<"\n";
        for (int i=0;i<res.size();++i)
                cout<<res[i]<<" ";
}
