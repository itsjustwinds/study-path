#include<bits/stdc++.h>
#define maxn 200005
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
II a[maxn],now;
int n,m,res;
int tmp(II a,II b)
{
    if (a.fs==b.fs) return a.sc>b.sc;
    return a.fs<b.fs;
}
int main()
{
    //freopen("sheeps.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        a[i]=II(x,y);
    }
    sort(a+1,a+m+1);
    for (int i=1; i<=m; i++)
    {
        if (a[i].fs>=now.fs&&a[i].fs<=now.sc)
        {
            if (a[i].sc<=now.sc)
            {
                now.fs=max(now.fs,a[i].fs);
                now.sc=min(now.sc,a[i].sc);
            }
            else
            {
                res++;
                now.fs=max(now.sc+1,a[i].fs);
                now.sc=max(now.sc,a[i].sc);
            }
        }
        else if(a[i].fs>now.sc)
        {
            res++;
            now.fs=a[i].fs;
            now.sc=a[i].sc;
        }
        else if (a[i].fs<now.fs)
        {
            if (a[i].sc<now.fs)
            {
                res--;
                now.fs=a[i].fs;
                now.sc=a[i].sc;
            }
            else if (a[i].sc<=now.sc)
            {
                now.fs=max(now.fs,a[i].sc+1);
            }
        }
    }
    cout<<res;
    return 0;
}
