#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int h[maxn],l[maxn],n;
int main()
{
    freopen("frogs.inp","r",stdin);
    freopen("frogs.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>h[i];
    for (int i=0;i<n;i++)
        cin>>l[i];
    for (int i=0;i<n;i++)
    {
        int k=l[i];
        int res=h[i],j=i+1;
        while(k>0)
        {
            if (j==n)
            {
                res=-1;
                break;
            }
            if (res<h[j])
            {
                k--;
                res=h[j];
            }
            j++;
        }
        cout<<res<<" ";
    }
    return 0;
}
