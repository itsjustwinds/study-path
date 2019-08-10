#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 3005
#define ll long long
#define base 37
using namespace std;
int hashS[maxn],n,m,res[15],power[maxn],b,f[maxn][maxn][15];
char s[maxn];
int get(int i,int j)
{
    return ((ll)hashS[j]-((ll)hashS[i-1]*power[j-i+1])%mod+mod)%mod;
}
void sub2()
{
    int res=0;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=i; j++)
        {
            if (get(j,i)==get(i+1,i+i-j+1))
            {
                res=max(res,i-j+1);
                break;
            }
        }
    cout<<res<<"\n";
}
void sub1()
{
    int res=0;
    for (int j=1; j<=m; j++)
    {
        for (int i=1; i<=j; i++)
        {
            int cnt=0;
            for (int k=i; k<=j; k++)
                if (s[k]!=s[j+1+k-i])
                    cnt++;
            if (cnt<=b) res=max(res,j-i+1);
        }
    }
    cout<<res<<"\n";
}
void sub3()
{
    int res=0;

    for (int i=1; i<=m; i++)
        for (int j=i; j<=m; j++)
            if (j+(j-i+1)<=m)
            {
                for (int k=0; k<=b; k++)
                    if (f[i][j+1][k]>=j-i+1)
                    {
                        res=max(res,j-i+1);
                    }
            }
            else break;
    cout<<res<<"\n";
}
int main()
{
    freopen("virus.inp","r",stdin);
    freopen("virus.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>(s+1);
    power[0]=1;
    m=strlen(s+1);
    for (int i=1; i<=m; i++)
        power[i]=((ll)power[i-1]*base)%mod;
    for (int i=1; i<=m; i++)
    {
        hashS[i]=((ll)hashS[i-1]*base+s[i]-'a')%mod;
    }
    for (int i=m; i>=1; i--)
        for (int j=i+1; j<=m; j++)
        {
                if (s[i]==s[j]) f[i][j][0]=f[i+1][j+1][0]+1;
            for (int k=1; k<=min(10,min(m-i+1,m-j+1)); k++)
                if (s[i]==s[j])
                {
                    f[i][j][k]=f[i+1][j+1][k]+1;
                }
                else f[i][j][k]=f[i+1][j+1][k-1]+1;
        }
    for (int i=1; i<=n; i++)
    {
        cin>>b;
        //if (m<=300) sub1();
        //else if (b==0) sub2();
        sub3();
    }
}

