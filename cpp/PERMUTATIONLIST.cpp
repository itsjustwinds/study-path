#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int n,k,res[maxn],bit[maxn],dd[maxn],m;
int get(int u)
{
    int kq=0;
    while(u)
    {
        kq=max(kq,bit[u]);
        u-=u&(-u);
    }
    return kq;
}
void update(int u)
{
    while(u<=maxn)
    {
        bit[u]+=1;
        u+=u&(-u);
    }
}
int main()
{
    freopen("PERMUTATIONLIST.INP","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        int tmp=k/(n-i+1)+1;
        k%=(n-i+1);
        int tmp1=get(tmp+i-1);
        tmp+=tmp1;
        res[i]=tmp;
        dd[tmp]=1;
        update(tmp+1);
        if (k==0)
        {
            int dem=i;
            for (int j=1;j<=n;j++)
            {
                if (!dd[j])
                    res[++dem]=j;
                if (dem==m) break;
            }
            break;
        }
    }
    for (int i=1;i<=m;i++)
        cout<<res[i]<<" ";
    return 0;
}
