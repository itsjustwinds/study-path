#include<bits/stdc++.h>
#define maxn 2000005
using namespace std;
int n,a[maxn],k,dd[maxn];
char sk[maxn];
int main()
{
        //freopen("828c.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;i++)
        {
                cin>>(sk+1)>>k;
                int len=strlen(sk+1);
                int trc=0;
                while(k--)
                {
                        int x;
                        cin>>x;
                        for (int j=max(x,trc);j<=x+len-1;j++)
                        {
                                a[j]=sk[j-x+1]-'a';
                                dd[j]=1;
                        }
                        trc=x+len-1;
                }
        }
        int now=maxn-1;
        while(dd[now]==0) now--;
        for (int i=1;i<=now;i++)
        {
                if (a[i]!=0) cout<< char(a[i]+'a');
                else cout<<"a";
        }
        return 0;
}
