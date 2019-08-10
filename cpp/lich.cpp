#include<bits/stdc++.h>
#define oo 1000000007
#define maxn 1005
#define fs first
#define sc second
using namespace std;
int n,a[maxn],m,c,s[maxn];
typedef pair<int,int> II;
II f[maxn];
int main()
{
    freopen("lich.inp","r",stdin);
    //freopen("lich.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>m>>c;
    for (int i=1; i<=n; i++) f[i]=II(oo,oo);
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for (int i=1; i<=n; i++)
        for (int j=i; j>=1; j--)
            if (s[i]-s[j-1]<=m)
            {
                if (f[j-1].sc+1>f[i].sc) continue;
                int t=m-s[i]+s[j-1];
                if (t==0&&f[i].fs>=f[j-1].fs)               // f[i]=min(f[i],f[j-1]);
                {
                    f[i].fs=f[j-1].fs;
                    f[i].sc=f[j-1].sc+1;
                }
                if (t>0&&t<=10&&f[i].fs>=f[j-1].fs-c)                            // f[i]=min(f[i],f[j-1]-c);
                {
                    f[i].fs=f[j-1].fs-c;
                    f[i].sc=f[j-1].sc+1;
                }
                if (t>10&&f[i].fs>=f[j-1].fs+(t-10)*(t-10))               // f[i]=min(f[i],f[j-1]+(t-10)*(t-10));
                {
                    f[i].fs=f[j-1].fs+(t-10)*(t-10);
                    f[i].sc=f[j-1].sc+1;
                }
            }
            else break;
    cout<<f[n].sc<<"\n";
    cout<<f[n].fs;
    return 0;
}
