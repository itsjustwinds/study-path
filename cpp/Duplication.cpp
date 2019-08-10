#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("Duplication.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    s="0";
    while(s.length()<=1005)
    {
        string t="";
        for (int i=0;i<s.length();i++)
            t=t+char((1-(s[i]-'0'))+'0');
        s=s+t;
    }
    int i_love_u;
    cin>>i_love_u;
    while(i_love_u--)
    {
        int x;
        cin>>x;
        cout<<s[x]<<"\n";
    }
    return 0;
}
