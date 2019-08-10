#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll sum,d;
int res,a[maxn],n,dem,nex[maxn];
int main()
{
        freopen("893D.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>d;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i];
                if (a[i]==0) ++dem;
        }
        a[0]=-1e9;
        a[n+1]=-1e9;
        for (int i=n;i>=1;--i)
        {
                if (a[i]==0)
                {
                        nex[i]=i+1;
                        while(a[i-1]==0)
                        {nex[i-1]=nex[i];
                        i--;
                        }
                }
        }
        //d--;
        for (int i=1;i<=n;++i)
        {
                if (a[i])
                {
                        sum=min(sum+a[i],d);
                }
                if(a[i]==0)
                {
                        dem-=nex[i]-i;
                        int t=a[nex[i]];
                        if (sum>d-t)
                        {
                                cout<<-1;
                                return 0;
                        }
                        if (sum<0)
                        {
                                sum=min(d-t,d);
                                ++res;
                                if (sum<0)
                                {
                                        cout<<-1;
                                        return 0;
                                }
                        }
                        if (sum<d-t&&dem>0)
                        {
                                ++res;
                                sum=d-t;
                        }
                }
        }
        cout<<res;
        return 0;
}
