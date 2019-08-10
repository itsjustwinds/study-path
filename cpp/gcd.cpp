#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
#include<fstream>
using namespace std;
ifstream fi("gcd.inp");
ofstream fo("gcd.out");
int n,a[maxn],lef[maxn],righ[maxn];
typedef pair<int,int> II;
int gcd(int a,int b)
{
    if (a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
    //freopen("gcd.inp","r",stdin);
    //freopen("gcd.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi>>n;
    for (int i=1;i<=n;i++)
        fi>>a[i];
    lef[1]=a[1];
    for (int i=2;i<=n-1;i++)
        lef[i]=gcd(lef[i-1],a[i]);
    righ[n]=a[n];
    for (int i=n-1;i>=2;i--)
        righ[i]=gcd(righ[i+1],a[i]);
    II res=II(righ[2],1);
    if (res.fs<lef[n-1]) res=II(lef[n-1],n);
    for (int i=2;i<=n-1;i++)
    {
        int tmp=gcd(lef[i-1],righ[i+1]);
        if (tmp>res.fs)res=II(tmp,i);
    }
    fo<<res.sc<<" "<<res.fs;
    fi.close();
    return 0;
}
