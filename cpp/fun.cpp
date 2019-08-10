#include<bits/stdc++.h>
#define mod 777777777
using namespace std;
string s;
int operator %(const string &a,int k)
{
    int res=0;
    for (int i=0; i<(int)a.length(); i++)
    {
        res=(res*10+a[i]-'0')%k;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    s="8713374954086219";
    cout<<s%2;
    return 0;
}
