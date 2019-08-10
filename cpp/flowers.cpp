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
        return a.sc>b.sc;
}
ll sum1,sum2,res;
int main()
{
        freopen("flower.inp","r",stdin);
        freopen("flower.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;i++)
        {
                cin>>a[i].fs>>a[i].sc;
                sum2+=a[i].sc;
                sum1+=a[i].fs;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i++)
        {
                sum2-=a[i].sc;
                sum1-=a[i].fs;
                if (i==n) break;
                res+=sum2*2*a[i].fs;
        }
        cout<<res;
}

