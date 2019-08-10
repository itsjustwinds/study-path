#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int negative;
void fix(string &a,string &b)
{
    while (a.length()<b.length())
    {
        a="0"+a;
    }
        while (a.length()>b.length())
    {
        b="0"+b;
    }
}
string add(string a,string b)
{
    string res="";
    fix(a,b);
    int n=a.length();
    int nho=0;
    for (int i=n-1;i>=0;i--)
    {
        int tmp=a[i]+b[i]-2*48+nho;
        if (tmp>=10) nho=1;
        else nho=0;
        res=char(tmp%10+48)+res;
    }
    if (nho==1) res="1"+res;
    return res;
}
string sub(string a,string b)
{
    fix(a,b);
    if (a<b)
    {
        negative=1;
        swap(a,b);
    }
    string res="";
    int nho=0;
    int n=a.length();
    for (int i=n-1;i>=0;i--)
    {
        int tmp=a[i]-b[i]-nho;
        if (tmp<0)
        {
            tmp+=10;
            nho=1;
        }
        else nho=0;
        res=char(tmp+48)+res;
    }
    while (res[0]=='0'&&res.length()>1) res.erase(0,1);
    if (negative==1) res="-"+res;
    return res;
}
int main()
{
    freopen("abc.inp","r",stdin);
    //freopen("abc.out","w",stdout;);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    cin>>b;
    cin>>c;
    for (int i=0;i<a.length();i++)
        if (a[i]=='?')
    {
        d=sub(c,b);
        cout<<d[i];
        return 0;
    }
    for (int i=0;i<b.length();i++)
        if (b[i]=='?')
    {
        d=sub(c,a);
        cout<<d[i];
        return 0;
    }
    for (int i=0;i<c.length();i++)
        if (c[i]=='?')
    {
        d=add(a,b);
        cout<<d[i];
        return 0;
    }
}
