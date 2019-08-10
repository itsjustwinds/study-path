#include<bits/stdc++.h>
#define maxn 200005
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
int res,a[maxn],n,MAX[maxn],b;
int main(){
	freopen("signal.inp","r",stdin);
	//freopen("signal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	read(n);read(b);
	for (int i=1;i<=n;++i)
		read(a[i]);
	MAX[n]=a[n];
	for (int i=n-1;i>=1;--i)
		MAX[i]=max(MAX[i+1],a[i]);
	int M=a[1];
	res=-1;
	for (int i=2;i<n;++i){
		if (M-a[i]>=b&&MAX[i+1]-a[i]>=b) res=max(res,M+MAX[i+1]-2*a[i]);
		M=max(M,a[i]);
	}
	write(res);
}
