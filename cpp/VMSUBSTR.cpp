#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
char s[maxn];
int cnt[105],n,f[105][105],res,sum;
int main()
{
        freopen("VMSUBSTR.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        cin>>(s+1);
        cnt[s[1]-'A']++;
        for (int i=2;i<=n;i++)
        {
                int x=s[i-1]-'A';
                int y=s[i]-'A';
                cnt[y]++;
                f[x][y]++;
        }
        int test;
        cin>>test;
        while(test--)
        {
                char t[105];
                cin>>(t+1);
                int len=strlen(t+1);
                res=0;
                sum=0;
                for (int i=1;i<=len;i++)
                {
                        int k=t[i]-'A';
                        res+=cnt[k];
                }
                for (int i=1;i<=len;i++)
                {
                        int x=t[i]-'A';
                        for (int j=1;j<=len;j++)
                        {
                                int y=t[j]-'A';
                                sum+=f[x][y];
                        }
                }
                cout<<max(0,res-sum)<<"\n";
        }
        return 0;
}
