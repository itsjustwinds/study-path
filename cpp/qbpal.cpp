#include <bits/stdc++.h>
#define maxn 150
using namespace std;
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

typedef vector<int> vi;
const int BASE=10000;
vi f[maxn][maxn];
char s[maxn];

void fix(vi &a)
{
    a.push_back(0);
    f0(i,a.size()-1)
    {
        a[i+1]+=a[i]/BASE;
        a[i]%=BASE;
        if (a[i]<0)
        {
            a[i]+=BASE;
            a[i+1]--;
        }
    }
    while (a.size()>=2 && a.back()==0) a.pop_back();
}

void operator += (vi &a, const vi &b)
{
    a.resize(max(a.size(), b.size()));
    f0(i,b.size()) a[i]+=b[i];
    fix(a);
}

vi to_vi(int x)
{
    return vi(1,x);
}

void operator -= (vi &a, const vi &b)
{
    f0(i,b.size()) a[i]-=b[i];
    fix(a);
}
vi operator + (vi a, const vi &b)
{
    a+=b;
    return a;
}
vi operator - (vi a, const vi &b)
{
    a-=b;
    return a;
}
ostream& operator << (ostream& cout, const vi &a){
    printf("%d", a.back());
    for (int i=(int)a.size()-2; i>=0; i--)
    printf("%04d", a[i]);
    return cout;
}
int main()
{
    freopen("qbpal.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s+1;
    int n=strlen(s+1);
    for (int i=1;i<=n;i++)
        f[i][i]=to_vi(1);
    //for (int i=2;i<=n;i++)
     //   f[i][i-1]=to_vi(0);
    for (int i=1; i<=n-1; i++)
        for (int j=1; j<=n-i; j++)
        {
            int k=i+j;
            f[j][k]=f[j+1][k]+f[j][k-1]+to_vi(1);
            if (s[j]!=s[k]) f[j][k]=f[j][k]-f[j+1][k-1]-to_vi(1);
        }
    cout<<f[1][n];
    return 0;
}
