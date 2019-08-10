#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
char s[maxn],t[maxn];
int n,m,st;
int main()
{
        freopen("PASSWORD.inp","r",stdin);
        //freopen("PASSWORD.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        cin>>(t+1);
        n=strlen(s+1);
        m=strlen(t+1);
        st=n-m+1;
        for (int i=0;i<=n-st;++i)
        if (s[i]==t[i])
        {
                if (i==2)
                {
                        int ok=1;
                }
                int x=0,y=0;
                for (int j=i+1;j<=i+st;++j)
                        x=x+s[j]-'0';
                y=t[i+1]-'0';
                if (x==y)
                {
                        cout<<i+1<<" "<<i+st;
                        return 0;
                }
                int now=1;
                while(y*10+t[i+now+1]-'0'<=9000000&&i+st+now<=n&&i+now+1<=m)
                {
                        x=x+s[i+st+now]-'0';
                        y=y*10+t[i+now+1]-'0';
                        if (x==y)
                        {
                                cout<<i+1<<" "<<i+st+now;
                                return 0;
                        }
                        ++now;
                }
        }
        else break;
}
