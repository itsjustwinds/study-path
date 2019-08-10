#include<bits/stdc++.h>
#define mod 1337377
using namespace std;
char s[300005];
int n,f[300005],m,cnt,maxx;
struct trie
{
    int child[26];
    int dem,high;
};
trie node[10000007];
void check(int l)
{
    int now=1;
    for (int i=1;i<=maxx;i++)
    {
        int k=s[l+i-1]-'a';
        if (!node[now].child[k]) return;
        now=node[now].child[k];
        if (node[now].dem) f[l-1+node[now].high]=(f[l-1+node[now].high]+f[l-1])%mod;
    }
}
int main()
{
    freopen("NKSEV.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(s+1);
    m=strlen(s+1);
    cin>>n;
    cnt=1;
    for (int i=1;i<=n;i++)
    {
        char c[105];
        int now=1;
        cin>>(c+1);
        int len=strlen(c+1);
        maxx=max(maxx,len);
        for (int i=1;i<=len;i++)
        {
            int k=c[i]-'a';
            if (!node[now].child[k])
            {
                node[now].child[k]=++cnt;
                node[cnt].high=node[now].high+1;
            }
            now=node[now].child[k];
        }
        node[now].dem++;
    }
    f[0]=1;
    for (int i=0;i<=m-1;i++)
    {
        check(i+1);
    }
    cout<<f[m];
    return 0;
}
