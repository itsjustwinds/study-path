#include<bits/stdc++.h>
#define maxn 2000005
using namespace std;
int dd[maxn],n,a[maxn],k,cnt,st[4*maxn];
vector<int > p;
void add(int x)
{
        vector<int > tmp;
        tmp.clear();
        while(x)
        {
                tmp.push_back(x%10);
                x/=10;
        }
        for (int i=tmp.size()-1;i>=0;--i)
                a[++cnt]=tmp[i];
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
        int x=st[id*2];
        int y=st[id*2+1];
        if (a[x]>=a[y]) st[id]=x;
        else st[id]=y;
}
int get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return 0;
        if (l>=i&&r<=j)
        {
                return st[id];
        }
        int m=(l+r)>>1;
        int x=get(id*2,l,m,i,j);
        int y=get(id*2+1,m+1,r,i,j);
        if (a[x]>=a[y]) return x;
        else return y;
}
int main()
{
        freopen("KDEL.inp","r",stdin);
        //freopen("KDEL.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=2;i*i<maxn;++i)
        if (!dd[i])
        {
                for (int j=i*i;j<maxn;j+=i)
                        dd[j]=1;
        }
        for (int i=2;i<maxn;++i)
        if (!dd[i])
        {
                p.push_back(i);
                if (p.size()==n) break;
        }
        a[0]=-1;
        for (int i=0;i<n;++i)
                add(p[i]);
        n=cnt;
        int now=1;
        int dem=0;
        int ktmp=k;
        build(1,1,n);
        if (k==n) return 0;
        while(1)
        {
                ++dem;
                int MAX=get(1,1,n,now,min(n,now+k));
                cout<<a[MAX];
                k-=(MAX-now);
                now=MAX+1;
                if (dem>=n-ktmp) break;
        }
        return 0;
}
