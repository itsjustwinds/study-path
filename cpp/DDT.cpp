#include<bits/stdc++.h>
#define maxn 2000005
using namespace std;
string s[maxn];
int n,d[maxn],cnt,res;
struct trie
{
        int child[26];
};
trie node[1000007];
vector<int> f[1000007];
vector<int> e[maxn];
void insert(string s,int t)
{
        vector<int > tmp1;
        vector<int > tmp2;
        tmp1.clear();
        tmp2.clear();
        int now=1;
        int n=s.length();
        for (int i=0;i<n;++i)
        {
                int k=s[i]-'A';
                if (node[now].child[k]==0) node[now].child[k]=++cnt;
                now=node[now].child[k];
                int trc=0;
                for (int j=0;j<f[now].size();++j)
                if (f[now][j]!=t&&f[now][j]!=trc)
                {
                        tmp1.push_back(f[now][j]);
                        trc=f[now][j];
                }
        }
        f[now].push_back(t);
        now=1;
        for (int i=n-1;i>=0;--i)
        {
                int k=s[i]-'A';
                if (node[now].child[k]==0) node[now].child[k]=++cnt;
                now=node[now].child[k];
                int trc=0;
                for (int j=0;j<f[now].size();++j)
                if (f[now][j]!=t&&f[now][j]!=trc)
                {
                        tmp2.push_back(f[now][j]);
                        trc=f[now][j];
                }
        }
        f[now].push_back(t);
        int i=0,j=0;
        int trc=0;
        int ok=1;
        while(i<tmp1.size()&&j<tmp2.size())
        {
                int s1=tmp1[i];
                while (s1==trc)
                {
                        if (i==tmp1.size()-1)
                        {
                                ok=0;
                                break;
                        }
                        s1=tmp1[++i];
                }
                int s2=tmp2[j];
                while(s2==trc)
                {
                        if (j==tmp2.size()-1)
                        {
                                ok=0;
                                break;
                        }
                        s2=tmp2[++j];
                }
                if (!ok) break;
                if (s1<s2)
                {
                        ++i;
                        continue;
                }
                if (s1>s2)
                {
                        ++j;
                        continue;
                }
                e[t].push_back(s1);
                trc=s1;
                ++i;
                ++j;
        }
}
int main()
{
        freopen("DDT.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        cnt=1;
        for (int i=1;i<=n;++i)
                cin>>s[i];
        for (int i=1;i<=n;++i)
                insert(s[i],i);
        for (int i=1;i<=n;++i)
        {
                d[i]=1;
                for (int j=0;j<e[i].size();++j)
                {
                        int v=e[i][j];
                        d[i]=max(d[i],d[v]+1);
                }
                res=max(res,d[i]);
        }
        cout<<res;
        return 0;
}
