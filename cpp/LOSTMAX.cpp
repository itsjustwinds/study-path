#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int a[maxn],n,m;
string s;
int main()
{
            freopen("LOSTMAX.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int test;
            cin>>test;
            getline(cin,s);
            while(test--)
            {
                        n=0;
                        m=0;
                        getline(cin,s);
                        for (int i=0;i<(int)s.length();++i)
                        {
                                    if (s[i]!=' ')
                                    {
                                                m=m*10+s[i]-'0';
                                    }
                                    else
                                    {
                                                a[++n]=m;
                                                m=0;
                                    }
                        }
                        a[++n]=m;
                        sort(a+1,a+n+1);
                        n--;
                        if (a[n+1]==n) cout<<a[n]<<"\n";
                        else cout<<a[n+1]<<"\n";
            }
            return 0;
}
