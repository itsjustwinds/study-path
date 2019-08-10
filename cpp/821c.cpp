#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int a[maxn],ok,n,cnt,res,now;
int main()
{
        //freopen("821c.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ok=0;
        now=1;
        cin>>n;
        for (int i=1;i<=2*n;i++)
        {
                char s[10];
                cin>>(s+1);
                if (s[1]=='r')
                {
                        if (a[cnt]==now) cnt--;
                        else if (ok) cnt--;
                        else
                        {
                                res++;
                                cnt--;
                                ok=1;
                        }
                        now++;
                }
                else
                {
                        int x;
                        cin>>x;
                        a[++cnt]=x;
                        if (x>now) ok=0;
                }
        }
        cout<<res;
        return 0;
}
