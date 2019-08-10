#include <bits/stdc++.h>
#define fs first
#define sc second
#define maxn 1000000
using namespace std;
typedef pair<int,int> II;
int s,a[maxn],dem1,dem2,res,ss;
II s1[2*maxn],s2[2*maxn];
void try1(int i,int u,int t)
{
    for (int j=u; j<=17; j++)
    {
        dem1++;
        s1[dem1]=II(t+a[j],i);
        try1(i+1,j+1,t+a[j]);
    }
}
void try2(int i,int u,int t)
{
    for (int j=u; j<=34; j++)
    {
        dem2++;
        s2[dem2]=II(t+a[j],i);
        try2(i+1,j+1,t+a[j]);
    }
}
int find1(int l,int r,int k)
{
    if (l>r) return -1;
    int vt=(l+r)/2;
    if (s2[vt].fs>k) return(find1(l,vt-1,k));
    if (s2[vt].fs<k) return(find1(vt+1,r,k));
    return(max(s2[vt].sc,max(find1(l,vt-1,k),find1(vt+1,r,k))));
}
void xuly()
{
    for (int i=1; i<=dem1; i++)
        {
            int x=find1(0,dem2,s-s1[i].fs);
            //int x=-1;
            //for(int j=0;j<=dem2;j++) if(s2[j].fs==s-s1[i].fs) x=max(x,s2[j].sc);
            if (x>=0)
                res=max(res,s1[i].sc+x);
        }
}
int main()
{
    freopen("coin34.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    a[1]=2;
    a[2]=3;
    a[3]=5;
    for (int i=4; i<=34; i++)
        a[i]=a[i-1]+a[i-2]+a[i-3];
    try1(1,1,0);
    try2(1,18,0);
    sort(s2+1,s2+dem2+1);
    cin>>ss;
    for (int j=1; j<=ss; j++)
    {
        cin>>s;
        res=-1;
        xuly();
        cout<<"Case #"<<j<<": "<<res<<"\n";
    }
    return 0;
}

