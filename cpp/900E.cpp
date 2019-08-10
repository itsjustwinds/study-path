#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int cost[maxn],n,oddA[maxn],evenA[maxn],oddB[maxn],evenB[maxn];
char s[maxn];
int f[maxn],cnt[maxn],m;
bool check(int pos)
{
    int start=pos-m+1;
    if (start%2)
    {
        if (oddB[pos]-oddB[pos-m]!=0||evenA[pos]-evenA[pos-m]!=0) return 0;
    }
    else if (oddA[pos]-oddA[pos-m]!=0||evenB[pos]-evenB[pos-m]!=0) return 0;
    return 1;
}
int main()
{
    freopen("900E.inp","r",stdin);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>(s+1);
    cin>>m;
    for (int i=1;i<=n;++i)
    {
        cost[i]=cost[i-1];
        if (s[i]=='?') ++cost[i];
        oddA[i]=oddA[i-1];
        oddB[i]=oddB[i-1];
        evenA[i]=evenA[i-1];
        evenB[i]=evenB[i-1];
        if (s[i]=='a')
        {
            if (i%2) oddA[i]++;
            else evenA[i]++;
        }
        else if (s[i]=='b')
        {
            if (i%2) oddB[i]++;
            else evenB[i]++;
        }
    }
    for (int i=m;i<=n;++i)
    if (check(i))
    {
        cnt[i]=cnt[i-m]+1;
        f[i]=f[i-m]+cost[i]-cost[i-m];
        if (cnt[i]==cnt[i-1]) f[i]=min(f[i],f[i-1]);
    }
    else
    {
        f[i]=f[i-1];
        cnt[i]=cnt[i-1];
    }
    cout<<f[n];
}
