#include<bits/stdc++.h>
#define maxn 3005
#define fs first
#define sc second
using namespace std;
int a[maxn],b[maxn],n,k,m,p1[maxn][30],p2[maxn][30],best;
int dd[maxn];
typedef pair<int,int > II;
vector<II > now,nw;
int geta(int l,int r)
{
        if (l>r) return -1;
        int log=log2(r-l+1);
        int t1=p1[l][log];
        int t2=p1[r-(1<<log)+1][log];
        if (a[t1]<=a[t2]) return t1;
        return t2;
}
int getb(int l,int r)
{
        if (l>r) return -1;
        int log=log2(r-l+1);
        int t1=p2[l][log];
        int t2=p2[r-(1<<log)+1][log];
        if (b[t1]<=b[t2]) return t1;
        return t2;
}
vector<int > res;
int main()
{
        freopen("ARRAY.inp","r",stdin);
        freopen("ARRAY.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        cin>>m;
        for (int i=1;i<=m;++i)
                cin>>b[i];
        cin>>k;
        now.push_back({0,0});
        for (int i=1;i<=n;++i)
        {
                p1[i][0]=i;
        }
        for (int i=1;i<=m;++i)
        {
                p2[i][0]=i;
        }
        for (int j=1;1<<j<=n;++j)
        {
                for (int i=1;i+(1<<j)-1<=n;++i)
                {
                        int t1=p1[i][j-1];
                        int t2=p1[i+(1<<(j-1))][j-1];
                        if (a[t1]<=a[t2])
                        {
                                p1[i][j]=t1;
                        }
                        else p1[i][j]=t2;
                }
        }
        for (int j=1;1<<j<=m;++j)
        {
                for (int i=1;i+(1<<j)-1<=m;++i)
                {
                        int t1=p2[i][j-1];
                        int t2=p2[i+(1<<(j-1))][j-1];
                        if (b[t1]<=b[t2])
                        {
                                p2[i][j]=t1;
                        }
                        else p2[i][j]=t2;
                }
        }
        for (int h=1;h<=k;++h)
        {
                nw.clear();
                best=1e9;
                for (int i=0;i<now.size();++i)
                {
                        int x1=now[i].fs;
                        int x2=now[i].sc;
                        if (x1==0&&x2==4)
                        {
                                int ok=1;
                        }
                        int s=m-x2;
                        s=max(0,k-h-s);
                        int t=geta(x1+1,n-s);
                        if (t!=-1)
                        {
                                if (a[t]<best)
                                {
                                        best=a[t];
                                        if (best==0)
                                        {
                                                int ok=1;
                                        }
                                        nw.clear();
                                        nw.push_back(II(t,x2));
                                }
                                else if (a[t]==best) nw.push_back(II(t,x2));
                        }
                        s=n-x1;
                        s=max(0,k-h-s);
                        t=getb(x2+1,m-s);
                        if (t==-1)
                        {
                                int ok=1;
                        }
                        if (t!=-1)
                        {
                                if (b[t]<best)
                                {
                                        best=b[t];
                                        nw.clear();
                                        nw.push_back(II(x1,t));
                                }
                                else if (b[t]==best) nw.push_back(II(x1,t));
                        }
                }
                res.push_back(best);
                dd[best]++;
                now=nw;
        }
        if (a[geta(1,n)]==b[getb(1,m)])
        {
                int t=geta(1,n);
                if (dd[a[t]]<2)
                {
                        res.pop_back();
                        res.push_back(a[t]);
                }
        }
        int t=geta(1,n);
        if (!dd[a[t]])
        {
                res.pop_back();
                res.push_back(a[t]);
        }
        t=getb(1,m);
        if (!dd[b[t]])
        {
                res.pop_back();
                res.push_back(b[t]);
        }
        for (int i=0;i<res.size();++i)
                cout<<res[i]<<" ";
        return 0;
}
