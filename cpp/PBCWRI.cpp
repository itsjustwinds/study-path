#include<bits/stdc++.h>
#define maxn 3000005
using namespace std;
int m,n,dd[105],cnt[105];
char a[maxn],b[maxn];
int d,res;
void del(int s)
{
        if (dd[s]==cnt[s])
        {
                d--;
                cnt[s]--;
                return;
        }
        cnt[s]--;
        if (dd[s]==cnt[s]) d++;
}
void add(int s)
{
        if (dd[s]==cnt[s])
        {
                d--;
                cnt[s]++;
                return;
        }
        cnt[s]++;
        if (dd[s]==cnt[s]) d++;
}
int main()
{
        freopen("PBCWRI.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        cin>>(a+1);
        cin>>(b+1);
        for (int i=1;i<=n;++i)
                dd[a[i]-'A']++;
        for (int i=1;i<=n;++i)
                cnt[b[i]-'A']++;
        for (int i=0;i<=100;++i)
        if (dd[i]==cnt[i]) d++;
        if (d==101) ++res;
        for (int j=n+1;j<=m;++j)
        {
                del(b[j-n]-'A');
                add(b[j]-'A');
                if (d==101) ++res;
        }
        cout<<res;
        return 0;
}
