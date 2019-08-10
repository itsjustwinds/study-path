#include<bits/stdc++.h>
using namespace std;
string s;
string add (string a,string b)
{
    while (a.length()<b.length()) a='0'+a;
    while (a.length()>b.length()) b='0'+b;
    int n=a.length();
    int nho=0;
    string res="";
    for (int i=n-1;i>=0;i--)
    {
        int tmp=a[i]+b[i]-2*48+nho;
        nho=tmp/10;
        res=char(tmp%10+48)+res;
    }
    if (nho==1) res='1'+res;
    return res;
}
int main()
{
    freopen("next.inp","r",stdin);
    //freopen("next.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while (t)
    {
        t--;
        cin>>s;
        cout<<add(s,"1");
        cout<<"\n";
    }
    return 0;
}
