#include<bits/stdc++.h>
using namespace std;
int res,kA,kB,mA,mB;
int main()
{
        freopen("PAIRING.inp","r",stdin);
        freopen("PAIRING.out","w",stdout);//a
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>kA>>mA>>kB>>mB;
        int t=min(mA,mB);
        mA-=t;
        mB-=t;
        if (mA<mB) swap(mA,mB);
        kA%=2;
        kB%=2;
        if (mA!=0&&kA)
        {
                kA--;
                ++res;
                mA--;
        }
        if (mA!=0&&kB)
        {
                kB--;
                ++res;
                mA--;
        }
        res+=mA;
        cout<<res;
        return 0;
}
