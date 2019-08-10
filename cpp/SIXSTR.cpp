#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
char s[maxn];
int n;
long long d[7],res;
int main()
{
        //freopen("SIXSTR.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        n=strlen(s+1);
        for (int i=1;i<=n;++i)
        {
                long long tmp[7];
                for (int j=0;j<=5;++j)
                        tmp[j]=0;
                for (int j=0;j<=5;++j)
                {
                        int x=(j*10+s[i]-'0')%6;
                        if (x==0) res+=d[j];
                        tmp[x]+=d[j];
                }
                swap(d,tmp);
                if (s[i]=='0')
                {
                        ++res;
                }
                else
                {
                        d[(s[i]-'0')%6]++;
                        if (s[i]=='6') ++res;
                }
        }
        cout<<res;
        return 0;
}
