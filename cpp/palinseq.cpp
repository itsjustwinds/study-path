#include<bits/stdc++.h>
#include<fstream>
#define maxn 1000005
#define ll long long
using namespace std;
ifstream fi("palinseq.inp");
ofstream fo("palinseq.out");
ll l,r,n,a[maxn],sl,sr,res;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi>>n;
    for (int i=1;i<=n;i++)
        fi>>a[i];
    sl=a[1];sr=a[n];
    l=1;r=n;
    while(l<r)
    {
        if (sl<sr)
        {
            sl+=a[++l];res++;
        }
        else if (sl>sr)
        {
            sr+=a[--r];
            res++;
        }
        else
        {
            sl=a[++l];
            sr=a[--r];
        }
    }
    fo<<res;
    fi.close();
    return 0;
}
