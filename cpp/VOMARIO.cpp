#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
#define fs first
#define sc second
using namespace std;
int n,b[maxn],fck[maxn];
ll val[maxn],x[maxn],res,f[maxn],w[maxn],e[maxn];
struct line
{
        ll a,b;
};
line st[5*maxn];
typedef pair<int,int> II;
II dm[maxn];
ll Get(line d,int pos)
{
        return d.a*val[pos]+d.b;
}
ll get(int id,int l,int r,int pos)
{
        if (l>pos||r<pos) return 0;
        ll ans=Get(st[id],pos);
        if (l==r) return ans;
        int m=(l+r)>>1;
        ans=max(ans,get(id*2,l,m,pos));
        ans=max(ans,get(id*2+1,m+1,r,pos));
        return ans;
}
void update(int id,int l,int r,int i,int j,line val)
{
        if (l>j||r<i) return;
        int m=(l+r)>>1;
        if (l>=i&&r<=j)
        {
                if (Get(st[id],l)>=Get(val,l)&&Get(st[id],r)>=Get(val,r))
                {
                        return;
                }
                if (Get(st[id],l)<=Get(val,l)&&Get(st[id],r)<=Get(val,r))
                {

                        st[id]=val;
                        return;
                }
                if (Get(st[id],l)>=Get(val,l)&&Get(st[id],m)>=Get(val,m))
                {
                        update(id*2+1,m+1,r,i,j,val);
                        return;
                }
                if (Get(st[id],l)<=Get(val,l)&&Get(st[id],m)<=Get(val,m))
                {
                        update(id*2+1,m+1,r,i,j,st[id]);
                        st[id]=val;
                        return;
                }
                if (Get(st[id],m+1)>=Get(val,m+1)&&Get(st[id],r)>=Get(val,r))
                {
                        update(id*2,l,m,i,j,val);
                        return;
                }
                if (Get(st[id],m+1)<=Get(val,m+1)&&Get(st[id],r)<=Get(val,r))
                {
                        update(id*2,l,m,i,j,st[id]);
                        st[id]=val;
                        return;
                }
        }
        update(id*2,l,m,i,j,val);
        update(id*2+1,m+1,r,i,j,val);
}
int main()
{
        freopen("D:\\C++\\debug\\VOMARIO.inp","r",stdin);
        //freopen("D:\\C++\\debug\\VOMARIO.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1; i<=n; i++)
        {
                cin>>x[i]>>w[i]>>e[i];
                dm[i].fs=x[i];
                dm[i].sc=i;
        }
        sort(dm+1,dm+n+1);
        int trc=dm[1].fs;
        int dem=1;
        val[1]=x[dm[1].sc];
        b[dm[1].sc]=1;
        fck[1]=dm[1].fs;
        for (int i=2; i<=n; i++)
        {
                if (dm[i].fs==trc) b[dm[i].sc]=dem;
                else
                {
                        trc=dm[i].fs;
                        b[dm[i].sc]=++dem;
                        fck[dem]=dm[i].fs;
                }
                val[dem]=dm[i].fs;
        }
        int top=dem;
        sort(fck+1,fck+dem+1);
        for (int i=1; i<=n; i++)
        {
                f[i]=get(1,1,top,b[i])+e[i];
                res=max(res,f[i]);
                int l=1,r=top;
                if (w[i])
                {
                        l=lower_bound(fck+1,fck+dem+1,x[i]-f[i]/w[i])-fck;
                        r=upper_bound(fck+1,fck+dem+1,x[i]+f[i]/w[i])-fck-1;
                        r=lower_bound(fck+1,fck+dem+1,fck[r])-fck;
                }
                line tmp;
                tmp.a=w[i];
                tmp.b=f[i]-w[i]*x[i];
                update(1,1,top,l,b[i],tmp);
                tmp.a=-w[i];
                tmp.b=f[i]+w[i]*x[i];
                update(1,1,top,b[i],r,tmp);
        }
        cout<<res;
        return 0;
}
