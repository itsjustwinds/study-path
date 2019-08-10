#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],n,res,cnt;
struct trie
{
    int child[2];
};
trie node[10000007];
int getbit(int n,int k)
{
    return (n>>(k-1))&1;
}
void insert(int n)
{
    int now=1;
    for (int i=1;i<=32;++i)
    {
        int k=getbit(n,i);
        if (!node[now].child[k]) node[now].child[k]=++cnt;
        now=node[now].child[k];
    }
}
void check(int n)
{
    int now=1;
    int kq=0;
    for (int i=1;i<=32;++i){
        int k=getbit(n,i);
        if (node[now].child[1-k])
        {
            kq+=1<<(i-1);
            now=node[now].child[1-k];
            continue;
        }
        //if (node[now].child[k]==0) break;
        now=node[now].child[k];
    }
    res=max(res,kq);
}
int main()
{
    freopen("MAXXOR.inp","r",stdin);
    freopen("MAXXOR.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cnt=1;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        check(a[i]);
        insert(a[i]);
    }
    cout<<res;
    return 0;
}
