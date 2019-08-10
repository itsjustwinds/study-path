#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn],cnt[maxn],n;
int main()
{
        freopen("DEXTERITY.inp","r",stdin);
        freopen("DEXTERITY.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
                cin>>a[i];
        for (int i=1;i<=n;++i)
                cnt[i]=2;
        for (int i=3;i<=n;++i)
        {
                if (a[i]>a[i-1]&&a[i]>a[i-2]&&cnt[i-1]>0&&cnt[i-2]>0)
                {
                        int tmp=a[i];
                        swap(a[i],a[i-1]);
                        swap(a[i-1],a[i-2]);
                        a[i-2]=tmp;
                        cnt[i]=cnt[i-1]-1;
                        cnt[i-1]=cnt[i-2]-1;
                        cnt[i-2]=0;
                }
                if (a[i-1]>a[i-2]&&cnt[i-1]>0&&cnt[i-2]>0)
                {
                        swap(cnt[i-1],cnt[i-2]);
                        cnt[i-1]--;
                        cnt[i-2]--;
                        swap(a[i-1],a[i-2]);
                }
        }
        if (a[n]>a[n-1]&&cnt[n]>0&&cnt[n-1]>0) swap(a[n],a[n-1]);
        for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}
