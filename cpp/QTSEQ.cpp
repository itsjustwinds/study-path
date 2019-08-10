#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
struct data
{
            ll val,cnt;
};
data res,minn,maxx;
int s[maxn],n;
ll a[maxn],b[maxn];
int main()
{
            freopen("QTSEQ.inp","r",stdin);
            cin.tie(0);
            cout.tie(0);
            scanf("%d",&n);
            for (int i=1; i<=n; ++i)
                        scanf("%d",&s[i]);
            for (int i=1; i<=n; ++i)
                        a[i]=a[i-1]+s[i];
            for (int i=n; i>=1; --i)
                        b[i]=b[i+1]+s[i];
            minn.val=b[n];
            maxx.val=b[n];
            res.val=-1;
            for (int i=n-1; i>=1; --i)
            {
                        res.val=max(res.val,abs(a[i]-maxx.val));
                        res.val=max(res.val,abs(a[i]-minn.val));
                        maxx.val=max(maxx.val,b[i]);
                        minn.val=min(minn.val,b[i]);
            }
            minn.val=b[n];
            maxx.val=b[n];
            maxx.cnt=1;
            minn.cnt=1;
            res.cnt=0;
            for (int i=n-1; i>=1; --i)
            {
                        if (minn.val==maxx.val)
                        {
                                    if (maxx.val==0)
                                    {
                                                if (abs(a[i])==res.val) res.cnt+=maxx.cnt;
                                    }
                                    else
                                    {
                                                int tmp=max(abs(a[i]-maxx.val),abs(a[i]-minn.val));
                                                if (tmp==res.val) res.cnt+=maxx.cnt;
                                    }
                        }
                        else{
                                    if (abs(a[i]-minn.val)==res.val) res.cnt+=minn.cnt;
                                    if (abs(a[i]-maxx.val)==res.val) res.cnt+=maxx.cnt;
                        }
                        if (maxx.val<b[i])
                        {
                                    maxx.val=b[i];
                                    maxx.cnt=1;
                        }
                        else if (maxx.val==b[i]) ++maxx.cnt;
                        if (minn.val>b[i])
                        {
                                    minn.val=b[i];
                                    minn.cnt=1;
                        }
                        else if (minn.val==b[i]) ++minn.cnt;
            }
            printf("%lld %lld",res.val,res.cnt);
            return 0;
}
