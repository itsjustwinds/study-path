#include<bits/stdc++.h>
#define maxn 105
#define ll long long
using namespace std;
struct data
{
        int p,d;
};
data a[maxn];
int n,za,zb,tmp;
bool cmp(const data &a,const data &b)
{
        return a.p<b.p;
}
void tinh(int i,ll t,int w)
{
        if (i==n+1)
        {
                ++tmp;
                return;
        }
        if (t*a[i].p>w)
        {
                ++tmp;
                return;
        }
        for (int j=0;j<=a[i].d;++j)
        {
                if (j!=0)t=1ll*t*a[i].p;
                if (t>w) return;
                tinh(i+1,t,w);
        }
}
int main()
{
        freopen("USAB.inp","r",stdin);
        freopen("USAB.out","w",stdout);
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
                scanf("%d%d",&a[i].p,&a[i].d);
        sort(a+1,a+n+1,cmp);
        int test=3;
        while(test--)
        {
                cin>>za>>zb;
                tmp=0;
                tinh(1,1,zb);
                int tb=tmp;
                if (za==1)
                {
                        printf("%d\n",tb);
                        continue;
                }
                tmp=0;
                tinh(1,1,za-1);
                int ta=tmp;
                printf("%d\n",tb-ta);
        }
}
