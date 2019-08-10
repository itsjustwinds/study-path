#include<bits/stdc++.h>
using namespace std;
struct trie
{
    int child[2];
    int cnt;
};
trie a[5000005];
int cnt,trace[5000005],dd[100];
void insert(int x)
{
    int now=0;
    for (int i=32;i>=1;i--)
    {
        int k=(x>>(i-1))&1;
        if (!a[now].child[k]) a[now].child[k]=++cnt;
        now=a[now].child[k];
        a[now].cnt++;
    }
}
void del(int x)
{
    int now=0;
    for (int i=32;i>=1;i--)
    {
        int k=(x>>(i-1))&1;
        dd[i]=k;
        if (!a[now].child[k]) return;
        trace[a[now].child[k]]=now;
        now=a[now].child[k];
    }
    int i=2;
    while(now)
    {
        int ok=0;
        a[now].cnt--;
        if (a[now].cnt==0) ok=1;
        now=trace[now];
        if (ok) a[now].child[dd[i-1]]=0;
        i++;
    }
}
int ans(int x)
{
    int res=0;
    int now=0;
    for (int i=32;i>=1;i--)
    {
        int k=(x>>(i-1))&1;
        if (a[now].child[!k])
        {
            res=(res<<1)|1;
            now=a[now].child[!k];
            continue;
        }
        else if (a[now].child[k])
        {
            res=res<<1;
            now=a[now].child[k];
        }
    }
    return max(x,res);
}
int main()
{
    freopen("706d.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i_love_u;
    cin>>i_love_u;
    while(i_love_u--)
    {
        char s;
        int x;
        cin>>s>>x;
        if (s=='+')
        {
            insert(x);
        }
        else if (s=='-')
        {
            del(x);
        }
        else
        {
            int k=ans(x);
            cout<<k<<"\n";
        }
    }
    return 0;
}
