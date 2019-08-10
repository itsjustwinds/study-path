#include<bits/stdc++.h>
using namespace std;
char s[100005],dd[100005];
int n,dem;
int main()
{
    freopen("D:\\C++\\TST\\w33b.inp","r",stdin);
    freopen("D:\\C++\\TST\\w33b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int res=0;
        cin>>(s+1);
        n=strlen(s+1);
        res=0;
        int trc=0;
        int sau=0;
        for (int i=1; i<=n; i++)
            if (s[i] == '1')
            {
                if (sau) res++;
                trc = 1;
                sau = 0;
            }
            else
            {
                if (s[i] == '0')
                {
                    if (trc) sau = 1;
                }
                else
                {
                    trc = 0;
                    sau = 0;
                }
            }
        cout<<res<<"\n";
    }
    return 0;
}
