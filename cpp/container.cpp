#include<bits/stdc++.h>
#include<fstream>
#define ll long long
#define maxn 1000005
using namespace std;
ifstream fi("container.inp");
ofstream fo("container.out");
typedef pair<int,int> II;
ll a[maxn];
ll n,res;
int main()
{
    //freopen("container.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi>>n;
    for (int i=1;i<=n;i++)
        fi>>a[i];
    int i=1,j=n;
    res=min(a[i],a[j])*(n-1);
    while(i<j)
    {
        if (a[i]<a[j])
        {
            i++;
            res=max(res,min(a[i],a[j])*(j-i));
        }
        else
        {
            j--;
            res=max(res,min(a[i],a[j])*(j-i));
        }
    }
    fo<<res;
    fi.close();
    return 0;
}

