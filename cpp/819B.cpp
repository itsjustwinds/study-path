#include<bits/stdc++.h>
#define maxn 105
#define fs first
#define sc second
#define ll long long
using namespace std;
int b[maxn],n;
struct data
{
        int val,pos;
};
data a[maxn];
bool cmp(data a,data b)
{
        return a.val<b.val;
}
int main()
{
        //freopen("819B.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i)
        {
                cin>>a[i].val;
                //sum[i]=sum[i-1]+a[i].val;
                a[i].pos=i;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
                int k=(i+1)%n;
                if (k==0) k=n;
                b[a[i].pos]=a[k].val;
        }
        for (int i=1;i<=n;++i)
                cout<<b[i]<<" ";
}
