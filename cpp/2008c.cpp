#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
ll n;
string a[maxn],res;
string add(string a,string b)
{
    string c="";
    while(a.length()<b.length()) a='0'+a;
    while(a.length()>b.length()) b='0'+b;
    int n=a.length();
    int carry=0;
    for (int i=n-1;i>=0;i--)
    {
        int tmp=a[i]+b[i]-'0'*2+carry;
        carry=tmp/10;
        c=char(tmp%10+'0')+c;
    }
    if (carry) c='1'+c;
    return c;
}
string mul(string a,string b)
{
    string c="";
    int n=a.length();
    int m=b.length();
    int carry=0;
    for (int i=n+m-1;i>=0;i--)
    {
        int tmp=0;
        for (int j=n-1;j>=0;j--)
        if (i-j<=m&&i-j>=1)
        {
            int a1=a[j]-'0';
            int b1=b[i-j-1]-'0';
            tmp+=a1*b1;
        }
        tmp+=carry;
        carry=tmp/10;
        c=char(tmp%10+'0')+c;
    }
    while(c.length()>1&&c[0]=='0') c.erase(0,1);
    return c;
}
int main()
{
    freopen("2008c.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    a[0]='1';
    res='1';
    cin>>n;
    for (int i=1;i<=n-2;i++)
    {
        string k="";
        int tmp=n-i-1;
        while(tmp)
        {
            k=char(tmp%10+48)+k;
            tmp=tmp/10;
        }
        a[i]=mul(a[i-1],k);
        res=add(res,a[i]);
    }
    cout<<res;
    return 0;
}
