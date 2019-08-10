#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
template<typename T> inline void read(T &x)
{
        char c;
        bool neg = false;
        while (!isdigit(c = getchar()) && c != '-');
        x = 0;
        if (c == '-')
        {
                neg = true;
                c = getchar();
        }
        do
        {
                x = x * 10 + c - '0';
        }
        while (isdigit(c = getchar()));
        if (neg) x = -x;
}
template<typename T> inline void write(T x)
{
        if (x < 0)
        {
                putchar('-');
                write(-x);
                return;
        }
        if (x < 10)
        {
                putchar(char(x + 48));
        }
        else
        {
                write(x/10);
                putchar(char(48 + x%10));
        }
}
template<typename T> inline void writeln(T x)
{
        write(x);
        putchar('\n');
}
int n,a[maxn],A,B;
ll res;
vector<int > P;
void pt(int x)
{
        for (int i=2;i*i<=x;++i)
        {
                if (x%i==0)
                {
                        while(x%i==0) x/=i;
                        P.push_back(i);
                }
        }
        if (x>1) P.push_back(x);
}
ll f[maxn][3];
void solve(int k)
{
        for (int i=1;i<=n;++i)
                for (int j=0;j<=2;++j)
                f[i][j]=1e16;
        //f[1][0]
        if (a[1]%k==0) f[1][0]=0;
        else if ((a[1]+1)%k==0||(a[1]-1)%k==0) f[1][0]=B;
        //f[1][1]
        f[1][1]=A;
        //f[1][2]
        f[1][2]=A;
        for(int i=2;i<=n;++i)
        {
                //f[i][0]
                if (a[i]%k==0) f[i][0]=f[i-1][0];
                else if ((a[i]+1)%k==0||(a[i]-1)%k==0) f[i][0]=f[i-1][0]+B;
                //f[i][1]
                f[i][1]=min(f[i-1][1],f[i-1][0])+A;
                //f[i][2]
                if (a[i]%k==0) f[i][2]=min(f[i-1][2],f[i-1][1]);
                else if ((a[i]-1)%k==0||(a[i]+1)%k==0) f[i][2]=min(f[i-1][2],f[i-1][1])+B;
        }
        res=min(res,min(f[n][0],min(f[n][1],f[n][2])));
}
int main()
{
        //freopen("624D.inp","r",stdin);
        //ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        read(n);read(A);read(B);
        for (int i=1;i<=n;++i)
                read(a[i]);
        res=1e18;
        pt(a[1]);pt(a[1]+1);pt(a[1]-1);
        pt(a[n]);pt(a[n]+1);pt(a[n]-1);
        sort(P.begin(),P.end());
        solve(P[0]);
        for (int i=1;i<P.size();++i)
        {
                if (P[i]==P[i-1]) continue;
                solve(P[i]);
        }
        write(res);
}
