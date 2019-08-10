#include<bits/stdc++.h>
#define maxn 18005
#define fs first
#define sc second
#define ll long long
#define base1 247
#define base2 397
#define mod 1000000007
using namespace std;
int n,m;
struct data
{
        int v;
        string s;
};
vector<data >e[maxn];
typedef pair<int,int> II;
vector<II >power;
ll res;
II HT;
vector<II >temp;
string T;
II get(vector<II > HS,int i,int j)
{
        II c;
        c.fs=(HS[j].fs-((ll)HS[i-1].fs*power[j-i+1].fs)%mod+mod)%mod;
        c.sc=(HS[j].sc-((ll)HS[i-1].sc*power[j-i+1].sc)%mod+mod)%mod;
        return c;
}
void dfs(int u,int ad,int now,vector<II > HS)
{
        int ok=0;
        for (int i=0; i<e[u].size(); ++i)
        {
                ok=1;
                int v=e[u][i].v;
                string s=e[u][i].s;
                int d=0;
                int dem=0;
                for (int j=0; j<s.length(); ++j)
                {
                        int x=int(s[j]);
                        ++d;
                        II tmp;
                        tmp.fs=(((ll)HS[now+j].fs*base1)%mod+x)%mod;
                        tmp.sc=(((ll)HS[now+j].sc*base2)%mod+x)%mod;
                        HS.push_back(tmp);
                }
                if (now+d>=m)
                {
                        for (int j=now+d; j>now; --j)
                        {
                                if (j<m) break;
                                II tmp=get(HS,j-m+1,j);
                                if (tmp==HT)++dem;
                        }
                }
                dfs(v,ad+dem,now+d,HS);
                for (int i=1; i<=d; ++i) HS.pop_back();
        }
        if (!ok)res+=ad;
}
int main()
{
        freopen("HWAYADS.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=2; i<=n; ++i)
        {
                int u,v;
                string s;
                cin>>u>>v>>s;
                e[u].push_back({v,s});
        }
        cin>>T;
        m=T.length();
        for (int i=0; i<T.size(); ++i)
        {
                HT.fs=(((ll)HT.fs*base1)%mod+T[i])%mod;
                HT.sc=(((ll)HT.sc*base2)%mod+T[i])%mod;
        }
        power.resize(100);
        power[0].fs=1;
        power[0].sc=1;
        for (int i=1; i<100; ++i)
        {
                power[i].fs=((ll)power[i-1].fs*base1)%mod;
                power[i].sc=((ll)power[i-1].sc*base2)%mod;
        }
        temp.push_back({0,0});
        dfs(0,0,0,temp);
        cout<<res;
        return 0;
}
