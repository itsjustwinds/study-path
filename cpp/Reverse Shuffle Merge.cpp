#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int n,now;
char s[maxn];
struct data {
    int d[26];
};
data f[maxn],need,NW;
vector<int > e[26];
data operator -(data a,data b) {
    data c;
    for (int i=0; i<=25; ++i)
        c.d[i]=a.d[i]-b.d[i];
    return c;
}
bool operator >=(data a,data b) {
    for (int i=0; i<=25; ++i)
        if (a.d[i]<b.d[i]) return 0;
    return 1;
}
int main() {
    freopen("Reverse Shuffle Merge.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(s+1);
    n=strlen(s+1);
    reverse(s+1,s+n+1);
    for (int i=1; i<=n; ++i) {
        f[i]=f[i-1];
        f[i].d[s[i]-'a']++;
        e[s[i]-'a'].push_back(i);
        if (f[i].d[s[i]-'a']%2==0) need.d[s[i]-'a']++;
    }
    now=0;
    for (int XXX=1; XXX<=n/2; ++XXX)
        for (int i=0; i<=25; ++i)
            if (need.d[i]!=0) {
                int x=upper_bound(e[i].begin(),e[i].end(),now)-e[i].begin();
                x=e[i][x];
                data tmp=need;
                tmp.d[i]--;
                if ((f[n]-f[x-1])>=tmp) {
                    now=x;
                    need=tmp;
                    cout<<char(i+'a');
                    break;
                }
            }

}
