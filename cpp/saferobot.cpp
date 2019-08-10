#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y;
int ok,ok2;
char s[10000];
int main()
{
    //freopen("saferobot.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test)
    {
        test--;
        cin>>n>>m;
        cin>>(s+1);
        ok=0;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            {
                if (ok==1) break;
                x=i;
                y=j;
                ok2=1;
                int slen=strlen(s+1);
                for (int k=1; k<=slen; k++)
                {
                    if (s[k]=='L')
                    {
                        y-=1;
                        if (x<1||x>n||y<1||y>m)
                        {
                            ok2=0;
                            break;
                        }
                    }
                    if (s[k]=='R')
                    {
                        y+=1;
                        if (x<1||x>n||y<1||y>m)
                        {
                            ok2=0;
                            break;
                        }
                    }
                    if (s[k]=='U')
                    {
                        x-=1;
                        if (x<1||x>n||y<1||y>m)
                        {
                            ok2=0;
                            break;
                        }
                    }
                    if (s[k]=='D')
                    {
                        x+=1;
                        if (x<1||x>n||y<1||y>m)
                        {
                            ok2=0;
                            break;
                        }
                    }
                }
                if (ok2==1)
                {
                ok=1;
                cout<<"safe"<<"\n";
                }
            }
        if (ok==0) cout<<"unsafe"<<"\n";
    }
        return 0;
}
