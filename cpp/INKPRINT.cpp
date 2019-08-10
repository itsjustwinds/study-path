#include<bits/stdc++.h>
#define ll long long
#define mod 777777777
using namespace std;
struct matrix
{
    int n,m;
    ll h[30][30];
};
ll n,d[50];
string s;
matrix a,dmcd;
string sub(string a,string b)
{
    int negative=0;
    while(a.length()<b.length()) a="0"+a;
    while(a.length()>b.length()) b="0"+b;
    int nho=0;
    string c="";
    int n=a.length();
    for (int i=n-1; i>=0; i--)
    {
        int tmp=a[i]-b[i]-nho;
        if (tmp<0)
        {
            nho=1;
            tmp+=10;
        }
        else nho=0;
        c=char(tmp%10+48)+c;
    }
    while (c[0]=='0'&&c.length()>1) c.erase(0,1);
    return c;
}
string div(string a,int k)
{
    string kq="";
    int tmp=0;
    for (int i=0; i<(int)a.length(); i++)
    {
        tmp=tmp*10+(a[i]-'0');
        kq=kq+char(tmp/k+48);
        tmp=tmp%k;
    }
    while(kq[0]=='0'&&kq.length()>1) kq.erase(0,1);
    return kq;
}
int operator %(const string &a,int k)
{
    int res=0;
    for (int i=0; i<(int)a.length(); i++)
    {
        res=(res*10+a[i]-'0')%k;
    }
    return res;
}
matrix operator *(matrix a,matrix b)
{
    matrix c;
    c.n=a.n;
    c.m=b.m;
    for (int i=1; i<=c.n; i++)
        for (int j=1; j<=c.m; j++)
        {
            c.h[i][j]=0;
            for (int k=1; k<=a.m; k++)
                c.h[i][j]=(c.h[i][j]+a.h[i][k]*b.h[k][j])%mod;
        }
    return c;
}
matrix power(matrix a,string n)
{
    //cout<<n<<" "<<n%2<<"\n";
    if (n=="1") return a;
    matrix tmp=power(a,div(n,2));
    tmp=tmp*tmp;
    if (n%2==1) tmp=tmp*a;
    return tmp;
}
int main()
{
    freopen("INKPRINT.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    for (int i=1; i<=n; i++)
        cin>>d[i];
    a.n=n+1;
    a.m=n+1;
    for (int i=2; i<=n+1; i++)
        a.h[i-1][i]=1;
    for (int i=1; i<=n; i++)
        a.h[n+1][n-d[i]+2]++;
    dmcd.n=n+1;
    dmcd.m=1;
    dmcd.h[0][1]=1;
    for (int i=0; i<=n; i++)
        if (dmcd.h[i][1]!=0)
        {
            for (int j=1; j<=n; j++)
                if (i+d[j]<=n+1)
                    dmcd.h[i+d[j]][1]+=dmcd.h[i][1];
        }
    string l="";
    int la=n+1;
    while(la)
    {
        l=char(la%10+48)+l;
        la=la/10;
    }
    if (s.length()<l.length()||(s.length()==l.length()&&s<=l))
    {
        int k=0;
        for (int i=0; i<(int)s.length(); i++)
            k=k*10+s[i]-'0';
        cout<<dmcd.h[k][1];
        return 0;
    }
    l="";
    while(n)
    {
        l=char(n%10+'0')+l;
        n=n/10;
    }
    string f=sub(sub(s,l),"1");
    matrix tmp=power(a,f);
    matrix res=tmp*dmcd;
    int ans=res.h[res.n][1];
    cout<<ans;
    return 0;
}
