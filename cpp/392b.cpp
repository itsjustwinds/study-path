#include <bits/stdc++.h>
using namespace std;
string s;
char a[5];
int res[5];
bool check;
bool kt(int i,string sk)
{
    if (i>=4)
        return((s[i]!=s[i-1])&&(s[i]!=s[i-2])&&(s[i]!=s[i-3])&&(s[i-1]!=s[i-2])&&(s[i-1]!=s[i-3])&&s[i-2]!=s[i-3]);
    if (i=3)
        return ((s[i]!=s[i-1])&&(s[i]!=s[i-2])&&s[i-1]!=s[i-2]);
    if (i=2)
        return ((s[i]!=s[i-1]));
    return (true);
}
void result
{
    for (int i=1;i<=4;i++)
        cout<<res[i]<<" ";
}
void try(int i,string sk)
{
    if (check==true) return;
    if ((s[i]!="!") && kt(i,sk+s[i])==true)
    {
        if (i=)
        {
            result;
            check=true;
        };
        else try(i+1,s[k]+s[i]);
        if (check==true) return;
    };
    else if (s[i]=="!")
    {
        for (int j=1;j<=4;j++)
        if (kt(i,sk+a[j])==true)
        {
            res[j]++;
            if (i=)
            {
                result;
                check:=true;
            };
            else try(i+1,s[k]+a[j]);
            res[j]--;
            if (check==true) return;
        }
    }
}
int main()
{
    freopen("392b.inp","r",stdin);
    freopen("392b.out","w",stdout);
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    check=false;
    a[1]='R';
    a[2]='B';
    a[3]='Y';
    a[4]='G';
    try(1,"");
}
