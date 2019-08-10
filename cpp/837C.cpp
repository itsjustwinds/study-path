#include<bits/stdc++.h>
#define maxn 105
using namespace std;
struct data
{
            int n,m;
};
data a[maxn];
int n,m,xa,xb,res;
int check(int i,int j)
{
           if (xb-a[i].m>=a[j].m&&a[i].n<=xa&&a[j].n<=xa) return 1;
           if (xb-a[i].m>=a[j].n&&a[i].n<=xa&&a[j].m<=xa) return 1;
           if (xa-a[i].n>=a[j].n&&a[i].m<=xb&&a[j].m<=xb) return 1;
           if (xa-a[i].n>=a[j].m&&a[i].m<=xb&&a[j].n<=xb) return 1;

           if (xb-a[i].n>=a[j].m&&a[i].m<=xa&&a[j].n<=xa) return 1;
           if (xb-a[i].n>=a[j].n&&a[i].m<=xa&&a[j].m<=xa) return 1;
           if (xa-a[i].m>=a[j].n&&a[i].n<=xb&&a[j].m<=xb) return 1;
           if (xa-a[i].m>=a[j].m&&a[i].n<=xb&&a[j].n<=xb) return 1;
            return 0;
}
int main()
{
            //freopen("837C.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>n>>xa>>xb;
            for (int i=1;i<=n;++i)
                        cin>>a[i].n>>a[i].m;
            for (int i=1;i<n;++i)
                        for(int j=i+1;j<=n;++j)
            if (check(i,j))
            {
                        res=max(res,a[i].n*a[i].m+a[j].n*a[j].m);
            }
            cout<<res;
            return 0;
}
