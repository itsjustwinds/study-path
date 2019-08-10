#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct data
{
            int a,b;
};
data a[maxn],f[maxn];
int n,now;
bool operator > (data a,data b)
{
            return a.a>b.a&&a.b>b.b;
}
int get(int l,int r, data x)
{
            int kq=0;
            while(l<=r)
            {
                        int m=(l+r)>>1;
                        if (x>f[m])
                        {
                                    kq=m;
                                    l=m+1;
                        }
                        else r=m-1;
            }
            return kq;
}
int main()
{
            freopen("LIS2VN.inp","r",stdin);
            scanf("%d",&n);
            for (int i=1;i<=n;++i)
            {
                        scanf("%d %d",&a[i].a,&a[i].b);
            }
            int now=0;
            for (int i=1;i<=n;++i)
            {
                        f[i].a=1111111111;
                        f[i].b=1111111111;
            }
            f[0].a=-1111111111;
            f[0].b=-1111111111;
            for (int i=1;i<=n;++i)
            {
                        /*if (a[i]>f[now])
                        {
                                    f[++now]=a[i];
                                    continue;
                        }*/
                        int k=get(1,now,a[i]);
                        if (f[k+1]>a[i])
                        {
                                    f[k+1]=a[i];
                                    now=max(now,k+1);
                        }
            }
            printf("%d",now);
            return 0;
}
