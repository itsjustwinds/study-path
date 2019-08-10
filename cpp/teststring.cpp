#include<bits/stdc++.h>
using namespace std;
int n;
long long a[1000];
char s[1000000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    gets(s);
    char* st=strtok(s," ");
    while (st!=NULL)
    {
        sscanf(st,"%d",&a[++n]);
        st=strtok(NULL," ");
    }
    for (int i=n; i>=1; --i)
        cout<<a[i]<<" ";
    return 0;
}
