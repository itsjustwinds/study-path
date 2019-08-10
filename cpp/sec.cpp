#include<bits/stdc++.h>
#define maxn 50007
using namespace std;
struct trie
{
    int child[2];
    int fi,cn;
};
trie a[1000007];
int n,cnt,res;
int add()
{
    cnt++;
    a[cnt].fi=0;
    a[cnt].cn=0;
    for (int i=0;i<=1;i++)
        a[cnt].child[i]=0;
    return cnt;
}
void insert(string s)
{
    int now=0;
    for (int i=0;i<(int)s.length();i++)
    {
        int k=s[i]-'0';
        if (a[now].child[k]==0) a[now].child[k]=add();
        now=a[now].child[k];
        a[now].cn++;
    }
    a[now].cn--;
    a[now].fi++;
}
void check(string s)
{
    int now=0;
    for (int i=0;i<(int)s.length();i++)
    {
        int k=s[i]-'0';
        if (!a[now].child[k]) return;
        now=a[now].child[k];
        res+=a[now].fi;
    }
    res+=a[now].cn;
}
int main()
{
    freopen("sec.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i_still_love_u_A;
    cin>>n>>i_still_love_u_A;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        string s="";
        for (int i=1;i<=x;i++)
        {
            int k;
            cin>>k;
            s=s+char(k+'0');
        }
        insert(s);
    }
    while(i_still_love_u_A--)
    {
        int x;
        cin>>x;
        string s="";
        for (int i=1;i<=x;i++)
        {
            int k;
            cin>>k;
            s=s+char(k+'0');
        }
        res=0;
        check(s);
        cout<<res<<"\n";
    }
    return 0;
}
