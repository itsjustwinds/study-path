#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n,m,res,dx[4],dy[4],Dx[4],Dy[4],len,Sx,Sy,dd[4];
char s[maxn][maxn],T[maxn];
bool check(int i,int j) {
    return i>=1&&i<=n&&j>=1&&j<=m&&s[i][j]!='#';
}
bool check() {
    int nowX=Sx;
    int nowY=Sy;
    for (int i=0; i<=len; ++i) {
        nowX+=dx[T[i]-'0'];
        nowY+=dy[T[i]-'0'];
        if (!check(nowX,nowY)) return 0;
        if (s[nowX][nowY]=='E') return 1;
    }
    return s[nowX][nowY]=='E';
}
void dfs(int i) {
    if (i==4) {
        if (check()) ++res;
        return;
    }
    for (int j=0; j<=3; ++j) {
        if (dd[j]) continue;
        dx[i]=Dx[j];
        dy[i]=Dy[j];
        dd[j]=1;
        dfs(i+1);
        dd[j]=0;
    }
}
int main() {
    //freopen("908B.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    Dx[0]=-1;
    Dy[0]=0;
    Dx[1]=0;
    Dy[1]=1;
    Dx[2]=1;
    Dy[2]=0;
    Dx[3]=0;
    Dy[3]=-1;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j) {
            cin>>s[i][j];
            if (s[i][j]=='S') {
                Sx=i;
                Sy=j;
            }
        }
    cin>>(T+1);
    len=strlen(T+1);
    dfs(0);
    cout<<res;
}
