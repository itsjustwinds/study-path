#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int d1,d2;
char a,b;
ll res;
int main()
{
        freopen("VMRR.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        getline(cin,s);
        cin>>a;
        cin>>b;
        for (int i=0;i<(int)s.length();++i)
        {
                if (s[i]==b)
                {
                        res+=d1;
                }
                if (s[i]==a) ++d1;
        }
        cout<<res;
        return 0;
}
