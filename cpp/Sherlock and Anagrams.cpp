#include<bits/stdc++.h>
#define maxn 105
using namespace std;
struct data
{
    int d[30];
};
map<data,int > m;
bool operator <(data a,data b)
{
    for (int i=0;i<=25;++i)
        if (a.d[i]!=b.d[i]) return a.d[i]<b.d[i];
    return 0;
}
char s[maxn];
int n;
long long res;
data f[maxn];
data operator -(data a,data b)
{
    data c;
    for (int i=0;i<=25;++i)
        c.d[i]=a.d[i]-b.d[i];
    return c;
}
int main()
{
    freopen("Sherlock and Anagrams.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        res=0;
        cin>>(s+1);
        n=strlen(s+1);
        for (int i=1;i<=n;++i)
        {
            f[i]=f[i-1];
            f[i].d[s[i]-'a']++;
        }
        for (int len=1;len<n;++len)
        {
            for (int i=1;i<=n-len+1;++i)
            {
                data tmp=f[i+len-1]-f[i-1];
                m[tmp]++;
                int x=m[tmp];
                res+=x-1;
            }
        }
        m.clear();
        cout<<res<<"\n";
    }
}
