#include<bits/stdc++.h>
#define maxn 100
using namespace std;
string s[maxn];
int n,res,m;
int main()
{
    //freopen("798b.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>s[i];
    m=s[1].length();
    res=1000000000;
    for (int i=1; i<=n; i++)
    {
        int tmp=0;
        for (int j=1; j<=n; j++)
            if (j!=i)
            {
                if (s[j]==s[i]) continue;
                string gg=s[j];
                int ok=0;
                for (int k=0; k<m-1; k++)
                {
                    char d=s[j][0];
                    s[j].erase(0,1);
                    s[j]=s[j]+d;
                    tmp++;
                    if (s[j]==s[i])
                    {
                        s[j]=gg;
                        ok=1;
                        break;
                    }
                }
                if (s[j]!=s[i]&&ok!=1)
                {
                    cout<<-1;
                    return 0;
                }
            }
        res=min(res,tmp);
    }
    cout<<res;
    return 0;
}
