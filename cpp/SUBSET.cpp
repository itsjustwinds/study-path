#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
vector<ll > T;
map<ll,int > trc1,trc2,DD;
int n,ok,a[maxn];
ll l,r;
void sub2()
{
        ll sum=0;
        for (int i=1;i<=n;++i)
        {
                sum+=a[i];
                if (sum>=l)
                {
                        cout<<i<<"\n";
                        for (int j=1;j<=i;++j)
                                cout<<j<<" ";
                        return;
                }
        }
}
int dd[maxn];
void sub3()
{
        ll sum=0;
        for (int i=1;i<=n;++i)
        {
                sum+=a[i];
        }
        ll now=n;
        int d=0;
        while(sum>r)
        {
                ll t=min(now,sum-r);
                sum-=t;
                now=t-1;
                dd[t]=1;
                ++d;
        }
        cout<<n-d<<"\n";
        for (int i=1;i<=n;++i)
        if (!dd[i])
        cout<<i<<" ";
}
void dfs1(int i,ll sum)
{
        if (i==(n/2)+1)
        {
                if (DD[sum]) return;
                DD[sum]=1;
                T.push_back(sum);
                return;
        }
        dfs1(i+1,sum);
        trc1[sum+a[i]]=i;
        dfs1(i+1,sum+a[i]);
}
int findd(int le,int ri,ll x)
{
        int res=-1;
        while(le<=ri)
        {
                int m=(le+ri)>>1;
                ll k=T[m];
                if (x+T[m]>=l)
                {
                        res=m;
                        ri=m-1;
                }
                else le=m+1;
        }
        return res;
}
void dfs2(int i,ll sum)
{
        if (ok) return;
        if (i==n+1)
        {
                int x=findd(0,T.size()-1,sum);
                if (x==-1) return;
                //int k=T[x];
                if (sum+T[x]>r) return;
                ok=1;
                vector<int >res;
                ll S=T[x];
                while(S)
                {
                        int x=trc1[S];
                        res.push_back(x);
                        S-=a[x];
                }
                S=sum;
                while(S)
                {
                        int x=trc2[S];
                        res.push_back(x);
                        S-=a[x];
                }
                cout<<res.size()<<"\n";
                sort(res.begin(),res.end());
                for (int i=0;i<res.size();++i)
                        cout<<res[i]<<" ";
                return;
        }
        if (ok) return;
        dfs2(i+1,sum);
        trc2[sum+a[i]]=i;
        dfs2(i+1,sum+a[i]);
}
void sub1()
{
        dfs1(1,0);
        sort(T.begin(),T.end());
        dfs2(n/2+1,0);
}
int main()
{
        freopen("SUBSET.inp","r",stdin);
        freopen("SUBSET.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>l>>r;
        int ok=1;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                if (a[i]!=i) ok=0;
        }
        if (n<=40) sub1();
        else
              if (!ok) sub2();
        else
                sub3();
}
