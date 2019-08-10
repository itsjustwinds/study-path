#include<bits/stdc++.h>
#define maxn 250005
using namespace std;
int n,cnt,res;
string s[maxn];
bool cmp(const string &a,const string &b)
{
    return a.length()<b.length();
}
struct trie
{
    int child[256];
    int fi;
};
trie a[1000007];
int add()
{
    cnt++;
    for (int i=0;i<=255;i++)
        a[cnt].child[i]=0;
    a[cnt].fi=0;
    return cnt;
}
void insert(string s)
{
    int dem=0;
    int now=0;
    for (int i=0;i<(int)s.length();i++)
    {
        if (a[now].child[s[i]-' ']==0)
        {
            a[now].child[s[i]-' ']=add();
        }
        now=a[now].child[s[i]-' '];
        dem+=a[now].fi;
    }
    a[now].fi++;
    res=max(res,dem+1);
}
int main()
{
    freopen("chain2.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>s[i];
    sort(s+1,s+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        insert(s[i]);
    }
    cout<<res;
    return 0;
}
