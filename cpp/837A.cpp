#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
char s[maxn];
int res,n;
int main()
{
            //freopen("837A.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n;
            while(cin>>(s+1))
            {
                        n=strlen(s+1);
                        int d=0;
                        for (int i=1;i<=n;++i)
                        if (s[i]-'A'>=0&&s[i]-'A'<='Z'-'A')++d;
                        res=max(res,d);
            }
            cout<<res;
            return 0;
}
