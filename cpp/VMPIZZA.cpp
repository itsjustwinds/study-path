#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
#define oo 1000000000
#define fs first
#define sc second
using namespace std;
struct data
{
        ll t,a,b;
};
struct line
{
        ll a,b;
};
line operator + (line a,line b)
{
        line c;
        c.a=a.a+b.a;
        c.b=a.b+b.b;
        return c;
}
line st[5*maxn];
data a[maxn];
ll maxx;
ll n,ac[maxn],b[maxn],k,val[maxn],f[maxn];
line dm[maxn];
ll top,c[maxn],le[maxn],ri[maxn];
ll get(line d,int x)
{
        return d.a*x+d.b;
}
ll getmax(int id,int l,int r,int pos)
{
        if (l>pos||r<pos) return -1e18;
        ll ans=get(st[id],pos);
        if (l==r) return ans;
        int m=(l+r)>>1;
        ans=max(ans,getmax(id*2,l,m,pos));
        ans=max(ans,getmax(id*2+1,m+1,r,pos));
        return ans;
}
void update(int id,int l,int r,int i,int j,line val)
{
        if (l>j||r<i) return;
        int m=(l+r)>>1;
        if (l>=i&&r<=j)
        {
                if (get(st[id],l)>=get(val,l)&&get(st[id],r)>=get(val,r))
                {
                        return;
                }
                if (get(st[id],l)<get(val,l)&&get(st[id],r)<get(val,r))
                {
                        st[id]=val;
                        return;
                }
        }
        update(id*2,l,m,i,j,val);
        update(id*2+1,m+1,r,i,j,val);
}
int main()
{
        freopen("D:\\C++\\debug\\VMPIZZA.inp","r",stdin);
        freopen("D:\\C++\\debug\\VMPIZZA.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for (int i=1; i<=n; i++)
        {
                cin>>a[i].t>>a[i].a>>a[i].b;
                ac[i]=a[i].t;
                maxx=max(maxx,a[i].t);
        }
        sort(ac+1,ac+n+1);
        for (int i=0;i<=4*maxn;i++)
        {
                st[i].a=-1e13;
                st[i].b=-1e17;
        }
        for (int i=1; i<=n; i++)
        {
                ll x=a[i].t;
                b[i]=lower_bound(ac+1,ac+n+1,x)-ac;
                val[b[i]]=a[i].t;
                c[i]=b[i];
        }
        top=*max_element(b+1,b+n+1);
        sort(c+1,c+n+1);
        for (int i=1; i<n; i++)
                if (c[i]!=c[i+1])
                {
                        le[c[i+1]]=c[i];
                        ri[c[i]]=c[i+1];
                }
        for (int i=1; i<=n; i++)
        {
                int x=b[i];
                dm[x].a+=-a[i].b;
                dm[x].b+=a[i].a+a[i].b*val[x];
        }
        ri[top]=top+1;
        int now=top;
        le[0]=-1;
        ri[0]=1;
        while(now!=-1)
        {
                dm[now]=dm[now]+dm[ri[now]];
                now=le[now];
        }
        line tmp;
        tmp.a=dm[0].a;
        tmp.b=dm[0].b;
        update(1,0,maxx,0,maxx,tmp);
        for (int i=1; i<top+1;)
        {
                f[i]=getmax(1,0,maxx,val[i])-k;
                if (ri[i]!=top+1)
                {
                        f[i]-=get(dm[ri[i]],val[i]);
                        tmp.a=dm[ri[i]].a;
                        tmp.b=f[i]+dm[ri[i]].b;
                        update(1,0,maxx,val[i],maxx,tmp);
                }
                //cout<<f[i]<<"\n";
                i=ri[i];
        }
        cout<<f[top];
        return 0;
}
