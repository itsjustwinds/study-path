#include<bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
int m,dem1,dem2,a[50];
typedef pair<int,int> II;
II f1[5000000],f2[5000000];
void dfs1(int i,int s,int d)
{
    if (i==18) return;
    dfs1(i+1,s,d);
    f1[++dem1]=II(s+a[i],d+1);
    dfs1(i+1,s+a[i],d+1);
}
void dfs2(int i,int s,int d)
{
    if (i==35) return;
    dfs2(i+1,s,d);
    f2[++dem2]=II(s+a[i],d+1);
    dfs2(i+1,s+a[i],d+1);
}
int findd(int l,int r,int x)
{
    int kq=-100000000;
    while(l<=r)
    {
        int m=(l+r)/2;
        if (f2[m].fs>x) r=m-1;
        if (f2[m].fs==x)
        {
            kq=m;
            l=m+1;
        }
        if (f2[m].fs<x) l=m+1;
    }
    return kq;
}
int main()
{
    freopen("coin34.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    a[1]=2;a[2]=3;a[3]=5;
    for (int i=4;i<=34;i++)
        a[i]=a[i-1]+a[i-2]+a[i-3];
        dfs1(1,0,0);
        dfs2(18,0,0);
    sort(f1+1,f1+dem1+1);
    sort(f2+1,f2+dem2+1);
    int test;
    cin>>test;
    int l=test;
    while(test)
    {
        test--;
        cin>>m;
        int res=-1;
        for (int i=1;i<=dem1;i++)
            if (f1[i].fs<=m)
        {
            int t=findd(0,dem2,m-f1[i].fs);
            if (t!=-100000000)
            res=max(res,f1[i].sc+f2[t].sc);
        }
        else break;
        cout<<"Case #"<<l-test<<": "<<res<<"\n";
    }
    return 0;
}
