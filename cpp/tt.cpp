#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
int t,f[105],s,n;
typedef pair<int,int> II;
II a[105];
int main()
{
    freopen("tt.inp","r",stdin);
    freopen("tt.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    t=test;
    while (test)
    {
        test--;
        cin>>n>>s;
        for (int i=1;i<=s;i++)
            f[i]=0;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            a[i]=II(min(x,y),max(x,y));
        }
        sort(a+1,a+n+1);
        int i=1;
        while (i<=n)
        {
            f[a[i].fs]++;
            if (a[i].fs!=a[i].sc) f[a[i].sc]++;
            if (a[i]==a[i+1]) i=i+2;
            else i++;
        }
        int res=0;
        for (int i=1;i<=s;i++)
            res=max(res,f[i]);
        cout<<"Case #"<<t-test<<": "<<res<<"\n";
    }
    return 0;
}
