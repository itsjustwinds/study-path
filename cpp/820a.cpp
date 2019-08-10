#include<bits/stdc++.h>
using namespace std;
int n,minn,maxx,a,r,res;
int main()
{
        //freopen("820a.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>minn>>maxx>>a>>r;
        int s=minn;
        int dem=0;
        int now=0;
        while(now<n)
        {
                res++;
                now+=s;
                if (dem) now-=r;
                if (now>=n) break;
                dem++;
                if (s+a<=maxx)s+=a;
                else s=maxx;
        }
        cout<<res;
        return 0;
}
