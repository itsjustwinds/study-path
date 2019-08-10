#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("D:\\C++\\huy\\LCS2X.inp","r",stdin);
    freopen("D:\\C++\\huy\\LCS2X.ans","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,m,n,i,j,a[1505],b[1505],c[1505],cur,prev;
    scanf("%d",&t);
    while(t--)
    {
        memset(c,0,sizeof(c));
        scanf("%d%d",&m,&n);
        for(i=0;i<m;++i) scanf("%d",&a[i]);
        for(i=0;i<n;++i)
        scanf("%d",&b[i]);
        for(i=0;i<m;++i)
        {
            cur=0;
            for(j=0;j<n;++j)
            {
                prev=cur;
                if(2*b[j]<=a[i]) cur=max(cur,c[j]);
                if(a[i]==b[j]) c[j]=max(c[j],prev+1);
            }
        }
        cur=0;
        for(i=0;i<n;++i) cur=max(cur,c[i]);
        cout<<cur<<"\n";
    }
}
