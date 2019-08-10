#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
ll res;
char s[maxn];
int n;
ll cal_1()
{
        vector<int >d;
        d.clear();
        d.resize(n);
        int l=0,r=0;
        ll res=0;
        for (int i=0;i<n;++i)
        {
                int k=0;
                if (i<=r) k=min(r-i,d[r-i+l]);
                while(i-k-1>=0&&i+k+1<n&&s[i-k-1]==s[i+k+1])++k;
                d[i]=k;
                res+=d[i];
                if (i+k>r) {
                        l=i-k,r=i+k;
                }
        }
        return res;
}
ll cal_2()
{
        vector<int >d;
        d.clear();
        d.resize(n);
        int l=0,r=-1;
        ll res=0;
        for (int i=0;i<n;++i)
        {
                int k=0;
                if (i<=r) k=min(r-i+1,d[r-i+l+1]);
                while(i-k-1>=0&&i+k<n&&s[i-k-1]==s[i+k])++k;
                d[i]=k;
                res+=d[i];
                if (i+k-1>r)
                {
                        l=i-k,r=i+k-1;
                }
        }
        return res;
}
int main()
{
        freopen("ALL_PAL.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>s;
        n=strlen(s);
        res+=cal_1();
        res+=cal_2();
        res+=n;
        cout<<res;
        return 0;
}
