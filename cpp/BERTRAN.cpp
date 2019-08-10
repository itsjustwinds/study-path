    #include <bits/stdc++.h>
    #define maxn 10000005
    using namespace std;
    int f[maxn],n,a[maxn],dem;
    long long res;
    int main()
    {
        freopen("bertran.inp","r",stdin);
        freopen("bertran.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        for (int i=2;i<=2*maxn;i++)
        if (f[i]==0)
        {
            int d=1;
            while(d*i<=2*maxn)
            {
                f[i*d]=i;
                d++;
            }
        }
        while (cin>>n)
        {
            res=0;
            for (int i=n+1;i<2*n;i++)
                if (f[i]==i)
                res++;
            cout<<res<<"\n";
        }
        return 0;
    }
