#include<bits/stdc++.h>
#include<fstream>
#define ll long long
using namespace std;
ifstream fi("folding.inp");
ofstream fo("folding.out");
ll a1,b1,k[100],a2,b2;
int main()
{
    //freopen("folding.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi>>a1>>b1;
    fi>>a2>>b2;
    if (max(a1,b1)<a2||max(a1,b1)<b2)
    {
        fo<<-1;
        return 0;
    }
    k[0]=1;
    for (int i=1; i<=30; i++)
        k[i]=k[i-1]*2;
    ll res1=0;
    if (a1>=a2&&b1>=b2)
    {
        for (int i=0; i<=30; i++)
            if (a1/k[i]<=a2)
            {
                res1+=i;
                break;
            }
        for (int i=0; i<=30; i++)
            if (b1/k[i]<=b2)
            {
                res1+=i;
                break;
            }
    }
    else res1=10000000;
    ll res2=0;
    if (a1>=b2&&b1>=a2)
    {
        for (int i=1; i<=30; i++)
            if (a1/k[i]<=b2)
            {
                res2+=i;
                break;
            }
        for (int i=1; i<=30; i++)
            if (b1/k[i]<=a2)
            {
                res2+=i;
                break;
            }
    }
    else res2=10000000;
    fo<<min(res1,res2);
    return 0;
}
