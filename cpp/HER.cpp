#include<bits/stdc++.h>
#define db double
using namespace std;
db t,m,HT,HM;
char s[100005];
int n;
int main()
{
        freopen("HER.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        cin>>(s+1);
        if (n==1)
        {
                cout<<"HM";
                return 0;
        }
        int cntH=0,cntM=0;
        for (int i=1;i<n;++i)
        {
                if (s[i]=='H') ++cntH;
                else ++cntM;
        }
        if (cntH>cntM)
        {
                cout<<"H";
                return 0;
        }
        if (cntH<cntM)
        {
                cout<<"M";
                return 0;
        }

}
