#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int s1,s2,n;
int main()
{
        //freopen("893A.inp","r",stdin);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        s1=1;s2=2;
        for (int i=1;i<=n;++i)
        {
                int x;
                cin>>x;
                int k;
                if (s1+s2==3) k=3;
                else if (s1+s2==5) k=1;
                else if (s1+s2==4) k=2;
                if (x==s1) s2=k;
                else if (x==s2) s1=k;
                else
                {
                        cout<<"NO";
                        return 0;
                }
        }
        cout<<"YES";
        return 0;
}
