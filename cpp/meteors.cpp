#include<bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
int n,m,need[maxn],qL[maxn],res[maxn],qR[maxn],qA[maxn],l[maxn],r[maxn];
vector<int > check[maxn],site[maxn];
ll bit[maxn];
void update(int u,int val) {
    while(u<maxn) {
        bit[u]+=val;
        u+=u&(-u);
    }
}
ll get(int u) {
    ll res=0;
    while(u) {
        res+=bit[u];
        u-=u&(-u);
    }
    return res;
}
void apply(int i) {
    if (qL[i]<=qR[i]) {
        update(qL[i],qA[i]);
        update(qR[i]+1,-qA[i]);
    } else {
        update(1,qA[i]);
        update(qR[i]+1,-qA[i]);
        update(qL[i],qA[i]);
    }
}
int main() {
    freopen("meteors.inp","r",stdin);
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; ++i) {
        int x;
        scanf("%d",&x);
        site[x].push_back(i);
    }
    for (int i=1; i<=n; ++i)
        scanf("%d",&need[i]);
    int test;
    scanf("%d",&test);
    for (int i=1; i<=test; ++i)
        scanf("%d%d%d",&qL[i],&qR[i],&qA[i]);
    for (int i=1; i<=n; ++i) {
        l[i]=1,r[i]=test;
    }
    for (int i=1; i<=n; ++i) res[i]=-1;
    int change=1;
    while(change) {
        change=0;
        for (int i=1; i<=test; ++i)
            check[i].clear();
        for (int i=1; i<=n; ++i)
            if (l[i]<=r[i]) {
                change=1;
                check[(l[i]+r[i])>>1].push_back(i);
            }
        memset(bit,0,sizeof bit);
        for (int i=1; i<=test; ++i) {
            apply(i);
            for (int j=0; j<check[i].size(); ++j) {
                int id=check[i][j];
                ll sum=0;
                for (int k=0; k<site[id].size(); ++k) {
                    int x=site[id][k];
                    sum+=get(x);
                    if (sum>=need[id]) break;
                }
                if (sum>=need[id]) {
                    res[id]=i;
                    r[id]=i-1;
                } else l[id]=i+1;
            }
        }
    }
    for (int i=1; i<=n; ++i)
        if (res[i]!=-1)printf("%d\n",res[i]);
        else printf("NIE\n");
}
