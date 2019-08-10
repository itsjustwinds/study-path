#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
int a[maxn],n,dd[300],res,cnt,ok;
int gcd(int a,int b)
{
    if (a%b==0) return b;
    return gcd(b,a%b);
}
void dfs(int i,int s1,int s2)
{
    if (i==n+1)
    {
        if (s1!=0&&s2!=0) res=max(res,min(s1,s2));
        return;
    }
    if (s1==0) dfs(i+1,a[i],s2);
    else dfs(i+1,gcd(a[i],s1),s2);
    if (s2==0) dfs(i+1,s1,a[i]);
    else dfs(i+1,s1,gcd(s2,a[i]));
}
void sub1()
{
    res=0;
    dfs(1,0,0);
    cout<<res<<"\n";
}
void sub2()
{
    res=1;
    int maxx=1;
    for (int i=1;i<=n;i++)
        maxx=max(maxx,a[i]);
    for (int i=2; i<=maxx-1; i++)
    {
        cnt=0;
        for (int j=1; j<=n; j++)
            dd[j]=0;
        for (int j=1; j<=n; j++)
            if (a[j]%i==0)
            {
                dd[j]=1;
            }
        for (int j=i+1; j<=maxx; j++)
        {
            ok=1;
            for (int k=1; k<=n; k++)
                if (dd[k]==0&&a[k]%j!=0)
                {
                    ok=0;
                    break;
                }
            if (ok==1)
            {
                res=i;
                break;
            }
        }
    }
    cout<<res<<"\n";
}
int main()
{
    freopen("vo17lan.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test)
    {
        test--;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        if (n<=15) sub1();
        else if (n<=100) sub2();
    }
    return 0;
}
