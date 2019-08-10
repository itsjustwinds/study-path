#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n,a[maxn],dd[maxn],cnt,sum,now;
long long res;
vector<int> bit[34];
int getbit(int n,int k)
{
            return ((n>>(k-1))&1);
}
int get(int n)
{
            for (int i=1; i<=32; ++i)
            {
                        int k=getbit(n,i);
                        if (k==0)
                        {
                                    for (int j=0; j<(int)bit[i].size(); ++j)
                                    {
                                                int v=bit[i][j];
                                                if (dd[v]!=now)
                                                {
                                                            --sum;
                                                            dd[v]=i;
                                                }
                                                if (sum==0) return 0;
                                    }
                        }
            }
            return sum;
}
void update(int n)
{
            for (int i=1; i<=32; ++i)
            {
                        int k=getbit(n,i);
                        if (k==1) bit[i].push_back(now);
            }
}
int main()
{
            freopen("MAXOR.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int test;
            cin>>test;
            while(test--)
            {
                        cnt=1;
                        cin>>n;
                        res=0;
                        for (int i=1; i<=n; ++i)
                                    cin>>a[i];
                        for (int i=2; i<=n; ++i)
                                    for (int j=1; j<i; ++j)
                                    {
                                                if ((a[i]|a[j])<=max(a[i],a[j])) ++res;
                                    }
                        cout<<res<<"\n";
            }
            return 0;
}
