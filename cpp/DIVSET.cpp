#include<bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
int n,c,k,cnt[70],ok,res;
ll a[maxn],maxx,x;
int main()
{
            freopen("DIVSET.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int test;
            cin>>test;
            while(test--)
            {
                        cin>>n>>k>>c;
                        for (int i=1; i<=n; ++i)
                        {
                                    cin>>a[i];
                        }
                        x=1;
                        ok=1;
                        for (int i=1; i<=k; ++i)
                                    cnt[i]=0;
                        cnt[1]=n;
                        for (int i=2; i<=k; ++i)
                        {
                                    if (x>1e18/c)
                                    {
                                                cout<<0;
                                                ok=0;
                                                break;
                                    }
                                    x*=c;
                                    for (int j=1; j<=n; ++j)
                                                if (a[j]>=x) cnt[i]++;
                        }
                        if (!ok) continue;
                        res=0;
                        while(1)
                        {
                                    int now=0;
                                    for (int i=k; i>=1; --i)
                                    {
                                                cnt[i]-=++now;
                                                if (cnt[i]<0)
                                                {
                                                            ok=0;
                                                            break;
                                                }
                                    }
                                    if (ok) res++;
                                    if (!ok) break;
                        }
                        cout<<res<<"\n";
            }
            return 0;
}
