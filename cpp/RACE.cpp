#include<bits/stdc++.h>
#define maxn 100005
#define fs first
#define sc second
using namespace std;
int n,p1,p2,dd[maxn],cnt,ddb[maxn];
typedef pair<int,int> II;
II a[maxn],b[maxn],res[maxn];
int main()
{
        freopen("RACE.inp","r",stdin);
        freopen("RACE.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for (int i=1;i<=n;++i)
        {
                cin>>a[i].fs;
                a[i].sc=i;
        }
        for (int i=1;i<=n;++i)
        {
                cin>>b[i].fs;
                b[i].sc=i;
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        p1=1;
        p2=1;
        while(p1<=n)
        {
                if (a[p1].fs>b[p2].fs)
                {
                        dd[p1]=1;
                        ++cnt;
                        res[cnt].fs=p1;
                        res[cnt].sc=p2;
                        p1++;
                        p2++;
                        continue;
                }
                p1++;
        }
        res[cnt+1].sc=n+1;
        for (int i=cnt;i>=1;--i)
        {
                int now=res[i+1].sc-1;
                for (int j=now;j>res[i].sc;--i)
                if (a[res[i].fs].fs>b[j].fs)
                {
                        res[i].sc=j;
                        break;
                }
        }
        for (int i=1;i<=cnt;++i)
                ddb[res[i].sc]=1;
        for (int i=1;i<=cnt;++i)
        {
                int p1=res[i].fs;
                int p2=res[i].sc;
                cout<<a[p1].sc<<" "<<b[p2].sc<<"\n";
        }
        int conti=1;
        for (int i=n;i>=1;--i)
        if (!dd[i])
        {
                int tmp=0;
                for (int j=conti;j<=n;++j)
                if (!ddb[j])
                {
                        ddb[j]=1;
                        tmp=j;
                        conti=j;
                        break;
                }
                cout<<a[i].sc<<" "<<b[tmp].sc<<"\n";
        }
        return 0;
}
