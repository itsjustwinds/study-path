#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
            freopen("MOVE_to.inp","r",stdin);
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin>>a>>b>>c>>d;
            if (a==b&&c==d)
            {
                        cout<<0;
                        return 0;
            }
            int tmp1=abs(a-b)%2;
            int tmp2=abs(c-d)%2;
            if (tmp1!=tmp2)
            {
                        cout<<-1;
                        return 0;
            }
            if (a-b==c-d)
            {
                        cout<<1;
                        return 0;
            }
            if (a+b==c+d)
            {
                        cout<<1;
                        return 0;
            }
            cout<<2;
            return 0;
}
