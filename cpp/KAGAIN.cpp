#include<bits/stdc++.h>
#define maxn 30005
using namespace std;
int a[maxn],le[maxn],ri[maxn],n,res,l,r;
int main()
{
        freopen("KAGAIN.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>n;
                res=0;
                for (int i=1; i<=n; ++i)
                        cin>>a[i];
                le[1]=1;
                for (int i=2; i<=n; ++i)
                {
                        le[i]=i;
                        while(a[le[i]-1]>=a[i]) le[i]=le[le[i]-1];
                }
                ri[n]=n;
                for (int i=n-1; i>=1; --i)
                {
                        ri[i]=i;
                        while(a[ri[i]+1]>=a[i]) ri[i]=ri[ri[i]+1];
                }
                for (int i=1; i<=n; ++i)
                {
                        int tmp=a[i]*(ri[i]-le[i]+1);
                        if (tmp>res)
                        {
                                res=tmp;
                                l=le[i];
                                r=ri[i];
                        }
                        if (tmp==res&&le[i]<l)
                        {
                                l=le[i];
                                r=ri[i];
                        }
                }
                cout<<res<<" "<<l<<" "<<r<<"\n";
        }
        return 0;
}
