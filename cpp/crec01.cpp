#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
char s[maxn][maxn];
int n,m,h[maxn],l[maxn];
long long res,sum[maxn];
deque<int >q;
int main()
{
        freopen("CREC01.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
                cin>>s[i][j];
        for (int i=1;i<=n;++i)
        {
                for (int j=1;j<=m;++j)
                h[j]=(s[i][j]-'0')*(h[j]+1);
                q.clear();
                q.push_back(0);
                for (int j=1;j<=m;++j)
                {
                        while(q.size()>1&&h[q.back()]>=h[j]) q.pop_back();
                        l[j]=q.back()+1;
                        q.push_back(j);
                }
                for (int j=1;j<=m;++j)
                {
                        sum[j]=1ll*h[j]*(j-l[j]+1)+sum[l[j]-1];
                        res+=sum[j];
                }
        }
        cout<<res;
}
