#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll res[15],f[15];
int ok[15];
int n;
void tinh (int n)
{
            memset(f,0,sizeof(f));
            f[0]=1;
            f[1]=1;
            for (int i=1; i<=n; ++i)
            {
                        f[i]=f[i-1]*i;
                        for (int j=i-1; j>=2; --j)
                        {
                                    f[j]*=(j+1);
                        }
            }
            ll kq=0;
            for (int i=1; i<=n; ++i)
                        kq+=f[i];
            res[n]=kq;
}
int main()
{
            freopen("COND.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            f[0]=1;
            while(cin>>n)
            {
                        if (n==-1)
                        {
                                    return 0;
                        }
                        if (res[n]==0) tinh(n);
                        cout<<res[n]<<"\n";
            }
            return 0;
}
