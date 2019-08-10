#include<bits/stdc++.h>
#define maxn 2000005
using namespace std;
int f[maxn],dd[maxn];
int main()
{
        freopen("DDB.inp","r",stdin);
        freopen("DDB.out","w",stdout);
        for (int i=2;i*i<maxn;++i)
        if (!dd[i])
        {
                for (int j=i*i;j<maxn;j+=i)
                dd[j]=1;
        }
        for (int i=1;i<maxn;++i)
        {
                f[i]=f[i-1];
                if (!dd[i]) f[i]++;
        }
        int test;
        cin>>test;
        while(test--)
        {
                int n;
                scanf("%d",&n);
                printf("%d\n",f[2*n]-f[n]);
        }
        return 0;
}
