#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int a[maxn],b[maxn],n,res,n1,n2;
int main()
{
        //freopen("MMAX.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        res=-1e9;
        for (int i=1;i<=n;++i)
        {
                int x;
                cin>>x;
                if (x>0) a[++n1]=x;
                if (x==0) res=0;
                if (x<0) b[++n2]=x;
        }
        sort(a+1,a+n1+1);
        sort(b+1,b+n2+1);
        int tmp=1;
        if (n1>=2) for (int i=n1;i>=max(1,n1-2);--i)
                tmp*=a[i];
        res=max(res,tmp);
        tmp=1;
        if (n2>=2)for (int i=1;i<=min(n2,2);++i)
                tmp*=b[i];
        res=max(res,tmp);
        if (n1)res=max(res,tmp*a[n1]);
        cout<<res;
}
