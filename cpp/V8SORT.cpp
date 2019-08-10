#include<bits/stdc++.h>
#define maxn 100005
#define oo 112345678901234567LL
#define ll long long
using namespace std;
int c[10][10],n,ac[10],a[10];
map<string,ll> f;
map<string,ll> :: iterator it;
string s,t;
struct data
{
            string s;
            ll val;
};
struct cmp
{
            bool operator()(const data &a,const data &b)
            {
                        return a.val>b.val;
            }
};
void dijkstra()
{
            do
            {
                        string k="";
                        for (int i=1;i<=n;++i)
                                    k=k+char(a[i]+'0');
                        f[k]=oo;
            }while(next_permutation(a+1,a+n+1));
            priority_queue<data,vector<data>,cmp > q;
            data tmp;
            tmp.s=s;
            tmp.val=0;
            f[s]=0;
            q.push(tmp);
            while(!q.empty())
            {
                        data u=q.top();
                        data v;
                        q.pop();
                        if (u.val!=f[u.s]) continue;
                        if (u.s==t) return;
                        for (int i=0;i<n;++i)
                                    for (int j=0;j<n;++j)
                        {
                                    if (i==j) continue;
                                    v=u;
                                    swap(v.s[i],v.s[j]);
                                    it=f.find(v.s);
                                    ll k=it->second;
                                    ll tmps=f[u.s]+c[i+1][j+1];
                                    if (k>tmps)
                                    {
                                                f[v.s]=tmps;
                                                tmp.s=v.s;
                                                tmp.val=tmps;
                                                q.push(tmp);
                                    }
                        }
            }
}
int main()
{
            freopen("V8SORT.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            getline(cin,s);
            int tmp=0;
            for (int i=0;i<s.length();++i)
            {
                        if (s[i]==' ')
                        {
                                    if (tmp)a[++n]=tmp;
                                    tmp=0;
                                    continue;
                        }
                        tmp=tmp*10+(s[i]-'0');
            }
            a[++n]=tmp;
            for (int i=1;i<=n;++i)
                        for (int j=1;j<=n;++j)
                        cin>>c[i][j];
            for (int i=1;i<=n;++i) ac[i]=a[i];
            sort(ac+1,ac+n+1);
            s.clear();
            for (int i=1;i<=n;++i)
            {
                        a[i]=lower_bound(ac+1,ac+n+1,a[i])-ac;
                        s=s+char(a[i]+'0');
            }
            for (int i=1;i<=n;++i)
            {
                        a[i]=lower_bound(ac+1,ac+n+1,ac[i])-ac;
                        t=t+char(a[i]+'0');
            }
            dijkstra();
            cout<<f[t];
            return 0;
}
