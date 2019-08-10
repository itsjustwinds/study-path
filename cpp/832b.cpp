#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int dd[30],n,m;
char s[maxn],t[maxn];
int main()
{
            freopen("832b.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>(s+1);
            n=strlen(s+1);
            for (int i=1;i<=n;++i)
                        dd[s[i]-'a']=1;
            cin>>(s+1);
            n=strlen(s+1);
            int test;
            cin>>test;
            while(test--)
            {
                        cin>>(t+1);
                        m=strlen(t+1);
                        int d1=1;
                        int d2=1;
                        int check=1;
                        while(d1<=n)
                        {
                                    if (s[d1]==t[d2])
                                    {
                                                ++d1;
                                                ++d2;
                                                continue;
                                    }
                                    if (s[d1]=='?'&&dd[t[d2]-'a'])
                                    {
                                                ++d1;
                                                ++d2;
                                                continue;
                                    }
                                    if (s[d1]=='*')
                                    {
                                                int tmp=m-n;
                                                if (tmp<0)
                                                {
                                                            ++d1;
                                                            continue;
                                                }
                                                int ok=1;
                                                for (int j=0;j<=tmp;++j)
                                                if (dd[t[d2+j]-'a'])
                                                {
                                                            ok=0;
                                                            break;
                                                }
                                                if (ok){
                                                            ++d1;
                                                            d2+=tmp+1;
                                                            continue;
                                                }
                                    }
                                    check=0;
                                    cout<<"NO\n";
                                    break;
                        }
                        if (check&&d2==m+1)
                        {
                                    cout<<"YES\n";
                        }else if (check)cout<<"NO\n";
            }
}
