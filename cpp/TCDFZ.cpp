#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,res;
ll d2,d5;
void tinh(int n)
{
            while(n%2==0)
            {
                        d2++;
                        n/=2;
            }
            while(n%5==0)
            {
                        d5++;
                        n/=5;
            }
            res=((ll)res*n)%10;
}
int power(ll n)
{
            if (n==1) return 2;
            if (n==0) return 1;
            int tmp=power(n>>1);
            tmp=((ll)tmp*tmp)%10;
            if (n&1) tmp=((ll)tmp*2)%10;
            return tmp;
}
int main()
{
            freopen("TCDFZ.inp","r",stdin);
            ios::sync_with_stdio(0);
            cout.tie(0);
            cin.tie(0);
            cin>>n;
            res=1;
            for (int i=1;i*i<=n;++i)
            {
                        tinh(i);
                        if (i*i!=n&&n%i==0)
                                    tinh(n/i);
            }
            res=((ll)res*power(d2-d5))%10;
            cout<<res;
            return 0;
}
