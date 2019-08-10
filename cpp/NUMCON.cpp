#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n;
string s[maxn];
bool cmp(string a,string b)
{
        for (int i=0;i<min(a.length(),b.length());++i)
        if (a[i]!=b[i]) return a[i]>b[i];
        if (a.length()>b.length())
        {
                for (int i=b.length();i<a.length();++i)
                if (a[i]!=b[0]) return a[i]>b[0];
        }
        else
        {
                for (int i=a.length();i<b.length();++i)
                if (b[i]!=a[0]) return b[i]<a[0];
        }
        return 0;
}
string T;
int main()
{
        freopen("NUMCON.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        while(cin>>T)
        {
                s[++n]=T;
        }
        sort(s+1,s+n+1,cmp);
        for (int i=1;i<=n;++i)
                cout<<s[i];
        return 0;
}
