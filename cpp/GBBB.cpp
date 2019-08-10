#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int a[maxn],n,cnt[maxn],res;
int main()
{
        freopen("GBBB.inp","r",stdin);
        cin.tie(0);
        cout.tie(0);
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
        {
                scanf("%d",&a[i]);
        }
        for (int i=1;i<=n;++i)
        {
                if (cnt[a[i]+1]!=0)
                {
                        cnt[a[i]]++;
                        cnt[a[i]+1]--;
                }
                else
                {
                        ++res;
                        cnt[a[i]]++;
                }
        }
        printf("%d",res);
        return 0;
}
