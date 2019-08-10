#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
typedef pair<int,int >II;
II p[maxn];
II a[maxn];
int n,res;
int main()
{
        freopen("STORES.inp","r",stdin);
        freopen("STORES.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                int x;
                char s;
                cin>>x>>s;
                int k;
                if (s=='G') k=1;
                else k=0;
                a[i]=II(x,k);
        }
        sort(a+1,a+n+1);
        for (int i=1;i<=n;++i)
        {
                p[i]=p[i-1];
                if (a[i].sc==1) p[i].sc++;
                else p[i].fs++;
                for (int j=1;j<i;++j)
                {
                        II tmp;
                        tmp.fs=p[i].fs-p[j-1].fs;
                        tmp.sc=p[i].sc-p[j-1].sc;
                        if (tmp.fs<=tmp.sc&&(tmp.sc-tmp.fs)%2==0)
                        {
                                res=max(res,a[i].fs-a[j].fs);
                                break;
                        }
                }
        }
        cout<<res;
}
