#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int n,nex[maxn],pre[maxn];
char s[maxn];
typedef vector<char > data;
data res,now;
bool go(data now)
{
        int dem=0;
        while(1)
        {
                int cnt=0;
                int beg=0;
                int ok=0;
                for (int i=nex[0]; i<=n; i=nex[i])
                        if (s[i]==now[cnt])
                        {
                                if (cnt==0) beg=i;
                                ++cnt;
                                if (cnt==now.size())
                                {
                                        nex[pre[beg]]=nex[i];
                                        pre[nex[i]]=pre[beg];
                                        ok=1;
                                        dem+=now.size();
                                        break;
                                }
                        }
                        else
                        {
                                cnt=0;
                                if (s[i]==now[cnt])
                                {
                                        if (cnt==0) beg=i;
                                        ++cnt;
                                }

                        }
                if (ok)
                {
                        if (dem==n) return 1;
                        continue;
                }
                return 0;
        }
}
bool operator >(const data &a,const data &b)
{
        for (int i=0; i<a.size(); ++i)
                if (a[i]!=b[i]) return a[i]>b[i];
        return 0;
}
int main()
{
        freopen("BGSTRING.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        n=strlen(s+1);
        for (int len=1; len<=n; ++len)
                if (n%len==0)
                {
                        int ok=0;
                        for (int j=1; j<=n-len+1; ++j)
                        {
                                now.clear();
                                for (int k=j; k<=j+len-1; ++k)now.push_back(s[k]);
                                for (int i=0; i<=n; ++i)nex[i]=i+1;
                                for (int i=n+1; i>=1; --i)pre[i]=i-1;
                                if (go(now))
                                {
                                        if (ok)
                                        {
                                                if (res>now) res=now;
                                        }
                                        else res=now;
                                        ok=1;
                                }
                        }
                        if (ok) break;
                }
        for (int i=0; i<res.size(); ++i)
                cout<<res[i];
        return 0;
}
