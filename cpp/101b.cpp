#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
int n,a[maxn];
typedef pair<int,int> II;
int sc[maxn],res,sl[maxn],lsc,lsl,rsc,rsl,dc,dl,ac,acc,acl;
int main()
{
    freopen("101b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        for (int i=1;i<=n;i++)
        {
            int tmp;
            if (i%2) tmp=0;
                else tmp=1;
            if (a[i]%2!=tmp)
            {
                if (tmp)
                {
                    sc[++rsc]=a[i]-2;
                    if (a[i]-2>0) acc++;
                    dc+=max(0,a[i]-2);
                }
                else
                {
                    sl[++rsl]=a[i]-1;
                    if (a[i]-1>0) acl++;
                    dl+=max(0,a[i]-1);
                }
            }
        }
        else
        {
            if (a[i]%2) ac+=a[i]-1;
            else ac+=a[i]-2;
        }
        sort(sc+1,sc+rsc+1);
        sort(sl+1,sl+rsl+1);
        dc-=acc;
        lsl+=acc;
        dl-=acl;
        lsc+=acl;
    }
    return 0;
}
