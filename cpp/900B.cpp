#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int dd[maxn],a,b,r,res,c;
int main()
{
    freopen("900B.inp","r",stdin);
    cin>>a>>b>>c;
    a%=b;
    if (a*10/b==c)
    {
        cout<<1;
        return 0;
    }
    r=a;
    int res=0;
    while(1)
    {
        ++res;
        int tmp=r*10/b;
        if (tmp==c)
        {
            cout<<res;
            return 0;
        }
        r=r*10%b;
        if (dd[r])
        {
            cout<<-1;
            return 0;
        }
        dd[r]=1;
    }
}
