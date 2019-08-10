#include <bits/stdc++.h>
#define oo 10000000000000005
using namespace std;
int x,y,a[10],b[10],dem1,dem2;
long long resmax,resmin;
void try1(int i,int n,int m,long long tong)
{
    if (i<dem1+dem2)
    {
        if (n<=dem1) try1(i+1,n+1,m,tong*10+a[n]);
        if (m<=dem2) try1(i+1,n,m+1,tong*10+b[m]);
        return;
    }
    if (m==dem2+1)
    {
        resmax=max(resmax,tong*10+a[n]);
        resmin=min(resmin,tong*10+a[n]);
    }
    if (n==dem1+1)
    {
        resmax=max(resmax,tong*10+b[m]);
        resmin=min(resmin,tong*10+b[m]);
    }
}
int main()
{
    //freopen("MERGENUM.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>x>>y;
    while (x>0)
    {
        dem1++;
        a[dem1]=x % 10;
        x=x/10;
    }
    while (y>0)
    {
        dem2++;
        b[dem2]=y % 10;
        y=y/10;
    }
    for (int i=1;i<=dem1/2;i++)
    {
        int t=a[i];
        a[i]=a[dem1-i+1];
        a[dem1-i+1]=t;
    }
    for (int i=1;i<=dem2/2;i++)
    {
        int t=b[i];
        b[i]=b[dem2-i+1];
        b[dem2-i+1]=t;
    }
    resmax=-oo;
    resmin=oo;
    try1(1,1,1,0);
    cout<<resmin<<"\n";
    cout<<resmax;
    return 0;
}
