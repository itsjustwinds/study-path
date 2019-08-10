#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
int m,b,cnt;
double res;
int main()
{
        freopen("821b.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>m>>b;
        for (int i=0; i<=b; i++)
        {
                int x=i*m;
                int y=-(x/m)+b;
                double tmp=0;
                if (y!=0)tmp+=((y*y+y)*y)/2;
                tmp+=x*(x+1)/2;
                res=max(res,tmp);
        }
        cout<<(ll)res;
        return 0;
}
