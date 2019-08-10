#include<bits/stdc++.h>
#define maxx 40000
#define maxy 20000
using namespace std;
int n,x,y;
int main()
{
    //freopen("earth.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    x=0;
    y=0;
    for (int i=1; i<=n; i++)
    {
        char s;
        int k;
        cin>>s>>k;
        if (s=='N')
        {
            if (y+k<=maxy)
            {
                y+=k;
            }
            else y=k-(maxy-y);
        }
        if (s=='S')
        {
            if (y-k>=0)
            {
                y-=k;
            }
            else y=maxy-(k-y);
        }
        if (s=='W')
        {
            if (x-k>=0)
            {
                x-=k;
            }
            else x=maxx-(k-x);
        }
        if (s=='E')
        {
            if (x+k<=maxx)
            {
                x+=k;
            }
            else x=k-(maxx-x);
        }
    }
    if (x==0&&y==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
