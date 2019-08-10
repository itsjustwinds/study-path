#include<bits/stdc++.h>
#define maxn 200005
#define mod 1000000007
using namespace std;
int n,it[maxn*4];
long long now,tmp,res;
char s[maxn];
void build(int id,int l,int r)
{
    if (l==r)
    {
        if (s[l]==')') it[id]=1;
        else it[id]=0;
        return;
    }
    build(id*2,l,(l+r)/2);
    build(id*2+1,(l+r)/2+1,r);
    it[id]=it[id*2]+it[id*2+1];
}
void get(int id,int l,int r,int i,int j)
{
    if (l>j||r<i)
        return;
    if (l>=i&&r<=j)
    {
        tmp+=it[id];
        return;
    }
    get(id*2,l,(l+r)/2,i,j);
    get(id*2+1,(l+r)/2+1,r,i,j);
}
int main()
{
    freopen("785D.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(s+1);
    n=strlen(s+1);
    build(1,1,n);
    for (int i=1;i<=n-1;i++)
        if (s[i]=='(')
    {
        now++;
        tmp=0;
        get(1,1,n,i+1,n);
        long long k=tmp;
        int l=min(now,tmp);
        for (int j=2;j<=l;j++)
            k=(k+(k-1)*(l-j+1))%mod;
        res=(res+k)%mod;
    }
    cout<<res;
    return 0;
}
