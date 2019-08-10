#include <bits/stdc++.h>
#define maxn 10000007
using namespace std;
long long res;
int dd[2*maxn+1],ngto[2*maxn+1],np;
void ankin()
{
    for(int i=2; i<=2*maxn; ++i)
    {
        if(dd[i]==0)
        {
            dd[i]=i;
            ngto[++np]=i;
        }
        int j=1;
        while(j<=np && ngto[j]<=2*maxn/i)
        {
            dd[ngto[j]*i]=ngto[j];
            ++j;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ankin();
    for (int i=1;i<=np;i++)
        if (ngto[i]>maxn&&ngto[i]<2*maxn)
            res++;
        else if (ngto[i]>=2*maxn) break;
    cout<<res;
}

