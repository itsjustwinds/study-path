#include<bits/stdc++.h>
#define maxn 6006
using namespace std;
struct data
{
    int child[26];
    int dem;
};
data node[10000005];
char s[maxn];
int n,cnt,res;
void add(int l,int r)
{
    int now=1;
    for (int i=1;i<=r-l+1;i++)
    {
        int k=s[l+i-1]-'a';
        if (!node[now].child[k]) node[now].child[k]=++cnt;
        now=node[now].child[k];
    }
    node[now].dem++;
}
int get(int l,int r)
{
    int now=1;
    for (int i=1;i<=r-l+1;i++)
    {
        int k=s[l+i-1]-'a';
        if (!node[now].child[k]) return 0;
        now=node[now].child[k];
    }
    return node[now].dem;
}
int main()
{
    freopen("101c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cnt=1;
    cin>>(s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
    {
        add(i,j);
    }
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
    {
        res+=get(i,j);
    }
    cout<<res;
    return 0;
}
