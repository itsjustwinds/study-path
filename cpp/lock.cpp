#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
char s[maxn];
int n,x,y,u,d,l,r,xx,yy;
int main()
{
        freopen("LOCK.inp","r",stdin);
        freopen("LOCK.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        cin>>(s+1);
        n=strlen(s+1);
        cin>>xx>>yy;
        if (xx>0) l=0;else r=0;
        if (yy>0) d=0;else u=0;
        x=abs(xx);
        y=abs(yy);
        for (int i=1;i<=n;++i)
        {
                if (s[i]=='L'&&xx<=0&&x>0)
                {
                        x--;
                        l=i;
                }
                if (s[i]=='R'&&xx>0&&x>0)
                {
                        x--;
                        r=i;
                }
                if (s[i]=='D'&&yy<0&&y>0)
                {
                        y--;
                        d=i;
                }
                if (s[i]=='U'&&yy>0&&y>0)
                {
                        y--;
                        u=i;
                }
        }
        if (x!=0||y!=0) cout<<-1;
        else cout<<l<<" "<<u<<" "<<r<<" "<<d;
}
