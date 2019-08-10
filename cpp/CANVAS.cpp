#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int a[maxn],n;
ll res,sum[maxn];
void tinh(int l,int r)
{
            if (l>=r) return;
            int now;
            res+=sum[r]-sum[l-1];
            int m=(l+r)/2;
            now=(l+r)/2;
            tinh(l,now);
            tinh(now+1,r);
}
int main()
{
            //freopen("CANVAS.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int test;
            cin>>test;
            while(test--)
            {
                        cin>>n;
                        for (int i=1; i<=n; ++i) cin>>a[i];
                        for (int i=1;i<=n;++i)
                                    sum[i]=sum[i-1]+a[i];
                        res=0;
                        tinh(1,n);
                        cout<<res<<"\n";
            }
}
