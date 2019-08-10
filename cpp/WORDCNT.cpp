#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
string s;
int a[maxn],n,res;
int main()
{
    freopen("WORDCNT.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    getline(cin,s);
    while(test)
    {
        test--;
        getline(cin,s);
        n=0;
        res=0;
        string str;
        stringstream sin(s);
        while(sin>>str)
        {
            a[++n]=str.length();
            //a[++n]=atoi(str.c_str());
        }
        int now=1;
        for (int i=2;i<=n;i++)
            if (a[i]==a[i-1])
        {
            now++;
        }
        else{
            res=max(res,now);
            now=1;
        }
        if (a[n]==a[n-1]) res=max(res,now);
        cout<<res<<"\n";
    }
    return 0;
}
