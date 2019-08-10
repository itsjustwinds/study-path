#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
#define ll long long
using namespace std;
int n;
typedef pair<int,int> II;
II a[maxn];
bool cmp(II a,II b)
{
        double tmp1=a.sc/a.fs;
        double tmp2=b.sc/b.fs;
        return tmp1>tmp2;
}
ll sum,res;
int main()
{
        freopen("flower.inp","r",stdin);
        //freopen("flowers.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;i++)
        {
                cin>>a[i].fs>>a[i].sc;
                sum+=a[i].sc;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i++)
        {
                sum-=a[i].sc;
                if (i==n) break;
                res+=sum*2*a[i].fs;
        }
        cout<<res;
}
