#include<bits/stdc++.h>
#define maxn 405
#define ll long long
using namespace std;
int a[maxn][maxn],n,m;
ll res,f[maxn],h[maxn],Left[maxn];
deque<int > St;
ll cal(int x,int y,int z) {
    for (int j=1; j<=m; ++j)
        h[j]=0;
    ll res=0;
    for (int i=1; i<=n; ++i) {
        while(!St.empty())
            St.pop_back();
        St.push_back(0);
            for (int j=1; j<=m; ++j) {
            h[j]=(h[j]+1)*(a[i][j]==x||a[i][j]==y||a[i][j]==z);
            while(St.size()>1&&h[St.back()]>=h[j])
                St.pop_back();
            Left[j]=St.back()+1;
            St.push_back(j);
            if (h[j]!=0)
                f[j]=h[j]*(j-Left[j]+1)+f[Left[j]-1];
            else
                f[j]=0;
            res+=f[j];
        }
    }
    return res;
}
int main() {
    freopen("CRECT.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j) {
            char s;
            cin>>s;
            a[i][j]=s-'A'+1;
        }
    for (int i=1; i<=3; ++i)
        for (int j=i+1; j<=4; ++j)
            for (int k=j+1; k<=5; ++k)
                res+=cal(i,j,k)-cal(i,i,j)-cal(i,i,k)-cal(j,j,k)
                     +cal(i,i,i)+cal(j,j,j)+cal(k,k,k);
    cout<<res;
}
