#include<bits/stdc++.h>
using namespace std;
string f[1000];
char s[10000000];
int main()
{
    freopen("chubacsi.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f[0]="@";f[1]="8";f[2]="("; f[3]="|)";f[4]="3";f[5]="#";f[6]="6";f[7]="[-]";
    f[8]="|";f[9]="_|";f[10]="|<";f[11]="1";f[12]="[]\/[]";f[13]="[]\[]";f[14]="0";
    f[15]="|D";f[16]="(,)";f[17]="|Z";f[18]="$";f[19]="']['";f[20]="|_|";f[21]="\/";
    f[22]="\/\/";f[23]="}{";f[24]="`/";f[25]="2";
    gets(s+1);
    int n=strlen(s+1);
    for (int i=1;i<=n;i++)
        if (s[i]<=90&&s[i]>=65)
        cout<<f[s[i]-'A'];
        else if (s[i]<=122&&s[i]>=97) cout<<f[s[i]-'a'];
        else cout<<s[i];
    return 0;
}
