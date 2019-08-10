#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,ok,l,r;
struct matrix
{
    int n,m;
    string h[5][5];
};
string f;
matrix a;
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
    for (int i=n-1; i>=0; i--)
    {
        int tmp=a[i]+b[i]-2*48+nho;
        if (tmp>=10) nho=1;
        else nho=0;
        res=char(tmp%10+48)+res;
    }
    if (nho==1) res="1"+res;
    return res;
}
string mul(string a, string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len; i>=0; i--)
    {
        int tmp=0;
        for(int j=n-1; j>=0; j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
        tmp+=carry;
        carry=tmp/10;
        res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}
matrix operator * (matrix a,matrix b)
{
    matrix c;
    c.n=a.n;
    c.m=b.m;
    for (int i=1; i<=c.n; i++)
        for (int j=1; j<=c.m; j++)
        {
            c.h[i][j]="0";
            for (int k=1; k<=a.m; k++)
                c.h[i][j]=add(c.h[i][j],mul(a.h[i][k],b.h[k][j]));
        }
    return c;
}
matrix power(int n)
{
    if (n==1) return a;
    matrix tmp=power(n/2);
    tmp=tmp*tmp;
    if (n%2==1) tmp=tmp*a;
    return tmp;
}
int main()
{
    freopen("lrf.inp","r",stdin);
    //freopen("lrf.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    a.n=2;
    a.m=2;
    a.h[1][1]="0";
    a.h[1][2]="1";
    a.h[2][1]="1";
    a.h[2][2]="1";
    while (t)
    {
        t--;
        cin>>n>>l>>r;
        cin>>f;
        ok=0;
        matrix tmp=power(n-1);
        for (int i=l; i<r; i++)
        {
            for (int j=i+1; j<=r; j++)
            {
                matrix temp;
                temp.n=2;
                temp.m=1;
                temp.h[1][1]=char(i+48);
                temp.h[2][1]=char(j+48);
                matrix res;
                res=tmp*temp;
                if (res.h[1][1]==f)
                {
                    cout<<"YES"<<"\n";
                    ok=1;
                }
                if (ok==1) break;
            }
            if (ok==1) break;
        }
        if (ok==0) cout<<"NO"<<"\n";
    }
    return 0;
}
