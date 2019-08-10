#include<bits/stdc++.h>
#define db double
#define fs first
#define sc second
#define maxn 1005
#define ll  long long
using namespace std;
template<typename T> inline void read(T &x) {
    char c;
    bool neg = false;
    while (!isdigit(c = getchar()) && c != '-');
    x = 0;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    do {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
    if (neg) x = -x;
}
template<typename T> inline void write(T x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if (x < 10) {
        putchar(char(x + 48));
    } else {
        write(x/10);
        putchar(char(48 + x%10));
    }
}
template<typename T> inline void writeln(T x) {
    write(x);
    putchar('\n');
}
int n,k,d[maxn],sum[maxn];
struct data {
    ll s;
    int c;
};
data a[maxn];
ll res;
typedef pair<int,int> II;
II c[maxn][maxn];
void tinh(int k) {
    d[k]++;
    c[k][d[k]].fs=c[k][1].fs;
    c[k][d[k]].sc=c[k][1].sc;
    for (int i=2; i<=d[k]; ++i) {
        a[k].s+=((ll)(c[k][i].fs-c[k][i-1].fs)*((ll)c[k][i].sc+c[k][i-1].sc));
    }
    if (a[k].s<0) a[k].s=-a[k].s;
}
bool cmp(const data &a,const data &b) {
    return a.s<b.s;
}
int main() {
    freopen("TFIELD.inp","r",stdin);
    freopen("TFIELD.out","w",stdout);
    //ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(k);
    for (int i=1; i<=n; ++i) {
        cin>>d[i]>>a[i].c;
        for (int j=1; j<=d[i]; ++j) {
            read(c[i][j].fs);
            read(c[i][j].sc);
        }
    }
    for (int i=1; i<=n; ++i) tinh(i);
    sort(a+1,a+n+1,cmp);
    sum[n+1]=1000000000;
    for (int i=1; i<=n; ++i) {
        sum[0]=0;
        for (int j=1; j<=n; ++j)
            if (a[j].c!=i) sum[j]=sum[j-1]+1;
            else sum[j]=sum[j-1];
        int r=1;
        for (int l=1; l<=n; ++l) {
            while(sum[r+1]-sum[l-1]<=k)
                ++r;
            res=max(res,a[r].s-a[l-1].s);
        }
    }
    cout<<res/2;
    if (res%2) cout<<".5";
    else cout<<".0";
    return 0;
}
