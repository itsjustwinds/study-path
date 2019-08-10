#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int a[maxn],n,le[maxn],ri[maxn],res;
int main()
{
            freopen("KPLANK.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n;
            for (int i=1; i<=n; ++i)
            {
                        cin>>a[i];
            }
            a[0]=-1;
            a[n+1]=-1;
            for (int i=1; i<=n; ++i)
            {
                        le[i]=i;
                        while(a[i]<=a[le[i]-1]) le[i]=le[le[i]-1];
            }
            for (int i=n; i>=1; --i)
            {
                        ri[i]=i;
                        while(a[i]<=a[ri[i]+1]) ri[i]=ri[ri[i]+1];
            }
            for (int i=1; i<=n; ++i)
            {
                        int k=ri[i]-le[i]+1;
                        int ok=0;
                        int tmp=a[i];
                        if (a[i]>k)
                        {
                                    int tmp1=a[le[i]-1];
                                    int tmp2=a[ri[i]+1];
                                    if (le[i]==1) tmp1=1111111111;
                                    if (ri[i]==n) tmp2=1111111111;
                                    if (tmp1<tmp2) swap(tmp1,tmp2);
                                    if (tmp1<=a[i])
                                    {
                                                tmp=tmp1;
                                                ok=1;
                                    }
                                    else if (tmp2<a[i])
                                    {
                                                tmp=tmp2;
                                                ok=1;
                                    }
                        }
                        else ok=1;
                        if (ok) res=max(res,min(tmp,ri[i]-le[i]+1));
            }
            cout<<res;
            return 0;
}
