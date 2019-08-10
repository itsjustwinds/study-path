#include<bits/stdc++.h>
using namespace std;
int f[50];
char s[1000];
long long res;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s+1;
    int n=strlen(s+1);
    for (int i=1;i<=n;i++)
        f[s[i]-'a']=1;
    for (int i=0;i<='z'-'a';i++)
        if (f[i]==1) res++;
    cout<<res;
}
