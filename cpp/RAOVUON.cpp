#include<bits/stdc++.h>
#define maxn 205
#define db double
#define ll long long
using namespace std;
int n,m;
db res,d[maxn][maxn][5],val[maxn][maxn];
struct point {
    int x,y;
};
point Tree[maxn],a[maxn];
struct data {
    int v;
    db c;
    int mask;
};
vector<data > e[maxn];
db dist(point a,point b) {
    db X=a.x-b.x;
    db Y=a.y-b.y;
    return sqrt(X*X+Y*Y);
}
ll ccw(point a,point b,point c) {
    return 1ll*a.x*(b.y-c.y)+1ll*b.x*(c.y-a.y)+1ll*c.x*(a.y-b.y);
}
bool check(point a,point b) {
    if (ccw(a,Tree[1],b)==0)
        return 0;
    if (ccw(a,Tree[1],b)>0) {
        for (int j=2; j<=n; ++j)
            if (ccw(a,Tree[j],b)<=0) {
                return 0;
            }
        return 1;
    }
    for (int j=2; j<=n; ++j)
        if (ccw(a,Tree[j],b)>=0)
            return 0;
    return 1;
}
struct cmp {
    bool operator ()(data a,data b) {
        return a.c>b.c;
    }
};
int type[maxn];
void dijks(int x) {
    for (int i=1; i<=m; ++i)
        for (int mask=0; mask<=3; ++mask)
            d[x][i][mask]=1e18;
    for (int i=1; i<=m; ++i) {
        if (ccw(a[x],Tree[1],a[i])>0)
            type[i]=1;
        else if (ccw(a[x],Tree[1],a[i])<0)
            type[i]=2;
        else
            type[i]=0;
    }
    d[x][x][0]=0;
    priority_queue<data,vector<data>,cmp > q;
    q.push({x,0,0});
    while(!q.empty()) {
        int u=q.top().v;
        db du=q.top().c;
        int mask=q.top().mask;
        q.pop();
        if (du!=d[x][u][mask])
            continue;
        for (int i=0; i<e[u].size(); ++i) {
            int v=e[u][i].v;
            db cost=e[u][i].c;
            int Newmask=mask;
            if (type[v]!=0) {
                int zZ=1<<(type[v]-1);
                Newmask|=zZ;
            }
            if (d[x][u][mask]+cost<d[x][v][Newmask]) {
                d[x][v][Newmask]=d[x][u][mask]+cost;
                q.push({v,d[x][v][Newmask],Newmask});
            }
        }
    }
}
int main() {
    freopen("RAOVUON.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>Tree[i].x>>Tree[i].y;
    cin>>m;
    for (int i=1; i<=m; ++i)
        cin>>a[i].x>>a[i].y;
    if (n==0) {
        cout<<"0.00";
        return 0;
    }
    memset(val,-1,sizeof val);
    db res=1e18;
    for (int i=1; i<=m; ++i)
        for (int j=i+1; j<=m; ++j) {
            if (!check(a[i],a[j]))
                continue;
            db c=dist(a[i],a[j]);
            e[i].push_back({j,c});
            e[j].push_back({i,c});
            val[i][j]=c;
            val[j][i]=c;
        }
    for (int k=1; k<=m; ++k) {
        dijks(k);
        db tmp=1e18;
        for (int u=1; u<=m; ++u) {
            if (u==k) continue;
            for (int v=u+1; v<=m; ++v) {
                if (v==k) continue;
                if (val[u][v]==-1) continue;
                for (int mask1=1; mask1<=3; ++mask1)
                    for (int mask2=1; mask2<=3; ++mask2) {
                        if ((mask1|mask2)!=3) continue;
                        tmp=min(tmp,d[k][u][mask1]+d[k][v][mask2]+val[u][v]);
                    }
            }
        }
        res=min(res,tmp);
    }
    cout<<setprecision(2)<<fixed<<res;
}
