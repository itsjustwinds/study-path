#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,res[maxn],qU[maxn],qV[maxn],qneed[maxn],l[maxn],r[maxn],U[maxn],V[maxn];
vector<int > check[maxn];
int root[maxn],sum[maxn];
int getr(int u) {
    if (root[u]==u) return u;
    root[u]=getr(root[u]);
    return root[u];
}
void Union(int u,int v) {
    sum[v]+=sum[u];
    root[u]=v;
}
int main() {
    freopen("Stamp Rally.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=m; ++i)
        cin>>U[i]>>V[i];
    int q;
    cin>>q;
    for (int i=1; i<=q; ++i)
        cin>>qU[i]>>qV[i]>>qneed[i];
    for (int i=1; i<=q; ++i) {
        l[i]=1,r[i]=m;
    }
    int change=1;
    while(change) {
        change=0;
        for (int i=1; i<=m; ++i)
            check[i].clear();
        for (int i=1; i<=q; ++i) {
            if (l[i]<=r[i]) {
                check[(l[i]+r[i])>>1].push_back(i);
                change=1;
            }
        }
        for (int i=1; i<=n; ++i) {
            root[i]=i;
            sum[i]=1;
        }
        for (int i=1; i<=m; ++i) {
            int u=U[i];
            int v=V[i];
            int ru=getr(u);
            int rv=getr(v);
            if (ru!=rv) Union(ru,rv);
            for (int j=0; j<check[i].size(); ++j) {
                int id=check[i][j];
                int u=qU[id];
                int v=qV[id];
                int ru=getr(u);
                int rv=getr(v);
                if (ru!=rv) {
                    if (sum[ru]+sum[rv]>=qneed[id]) {
                        res[id]=i;
                        r[id]=i-1;
                    } else l[id]=i+1;
                } else {
                    if (sum[ru]>=qneed[id]) {
                        res[id]=i;
                        r[id]=i-1;
                    } else l[id]=i+1;
                }
            }
        }
    }
    for (int i=1; i<=q; ++i)
        cout<<res[i]<<"\n";
}
