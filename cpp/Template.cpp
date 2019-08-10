#include<bits/stdc++.h>
#define maxn 500005
#define fs first
#define sc second
using namespace std;
char s[maxn];
int z[maxn],st[4*maxn],n;
typedef pair<int,int> II;
II ac[maxn];
void Z_function()
{
        int l=0,r=0;
        z[0]=n;
        for (int i=1;i<n;++i)
        {
                if (i<=r) z[i]=min(r-i+1,z[i-l]);
                while(i+z[i]<=n&&s[z[i]]==s[i+z[i]]) ++z[i];
                if (i+z[i]-1>r)
                {
                        r=i+z[i]-1;
                        l=i;
                }
        }
}
void build(int id,int l,int r)
{
        if (l==r)
        {
                st[id]=l;
                return;
        }
        int m=(l+r)>>1;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id]=max(st[id*2],st[id*2+1]);
}
void update(int id,int l,int r,int i)
{
        if (l>i||r<i) return;
        if (l==r&&r==i)
        {
                st[id]=0;
                return;
        }
        int m=(l+r)>>1;
        update(id*2,l,m,i);
        update(id*2+1,m+1,r,i);
        st[id]=max(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return 0;
        if (l>=i&&r<=j)
        {
                return st[id];
        }
        int m=(l+r)>>1;
        int tmp1=get(id*2,l,m,i,j);
        int tmp2=get(id*2+1,m+1,r,i,j);
        return max(tmp1,tmp2);
}
bool check(int m)
{
        int l=1,r=m;
        while(r<n)
        {
                int tmp=get(1,1,n,l+1,r+1);
                if (!tmp) return 0;
                l=tmp;
                r=tmp+m-1;
        }
        return 1;
}
int main()
{
        freopen("Template.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>s;
        n=strlen(s);
        Z_function();
        for (int i=n;i>=1;--i)
                z[i]=z[i-1];
        for (int i=1;i<=n;i++)
        {
                ac[i].fs=z[i];
                ac[i].sc=i;
        }
        sort(ac+1,ac+n+1);
        int now=0;
        build(1,1,n);
        for (int i=n;i>=1;--i)
        {
                if (z[i]==n-i+1)
                {
                        while(now+1<=n&&ac[now+1].fs<z[i])
                        {
                                update(1,1,n,ac[now+1].sc);
                                ++now;
                        }
                        if (check(z[i]))
                        {
                                cout<<z[i];
                                return 0;
                        }
                }
        }
        cout<<n;
        return 0;
}
