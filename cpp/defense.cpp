#include<bits/stdc++.h>
#define maxn 200005
#include<fstream>
using namespace std;
int a[maxn],f[maxn],n,res;
int findd(int l,int r,int x)
{
    while(l<r)
    {
        int m=(l+r)/2;
        if (a[f[m]]<x) l=m+1;
        else r=m;
    }
    return l;
}
int main()
{
    ifstream fi("defense.inp");
    ofstream fo("defense.out");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi>>n;
    for (int i=1;i<=n;i++)
        fi>>a[i];
    for (int i=1;i<=n;i++)
    {
        if (a[i]>a[f[res]])
        {
            f[++res]=i;
        }
        else
            f[findd(1,res,a[i])]=i;
    }
    fo<<res;
    fi.close();
    //fo.close();
    return 0;
}

