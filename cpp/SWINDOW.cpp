#include<bits/stdc++.h>
#define maxn 2000005
using namespace std;
string s,p;
vector<char> z;
int n,m,k,res,sZ[maxn],l,r,dd[maxn],dem;
int get(int l,int r,int x)
{
    int kq=0;
    while(l<=r)
    {
        int m=(l+r)>>1;
        if (dd[m]>=x)
        {
            kq=m;
            r=m-1;
        }
        else l=m+1;
    }
    return dd[kq];
}
int main()
{
    freopen("SWINDOW.inp","r",stdin);
    //freopen("SWINDOW.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    z.push_back('#');
    getline(cin,s);
    getline(cin,p);
    m=p.length();
    cin>>k;
    for (int i=0;i<p.length();i++)
        z.push_back(p[i]);
    z.push_back('#');
    for (int i=0;i<s.length();i++)
        z.push_back(s[i]);
    n=z.size()-1;
    l=r=0;
    for (int i=2;i<=n;++i)
        {
            sZ[i]=max(0,min(sZ[i-l+1],r-i+1));
            while(i+sZ[i]<=n&&z[i+sZ[i]]==z[sZ[i]+1]) sZ[i]++;
            if (sZ[i]>=m) dd[++dem]=i;
            if (i+sZ[i]-1>r)
            {
                r=i+sZ[i]-1;
                l=i;
            }
        }
    for (int i=m+2;i<=n;++i)
    {
        char tmp=z[i];
        int fc=get(1,dem,i);
        if (fc==0) continue;
        if (fc>i+k-m) continue;
        res++;
    }
    cout<<res;
    return 0;
}

