#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int a[maxn],n;
int main()
{
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        for (int i=1;i<=n;++i)
            cin>>a[i];
        sort(a+1,a+n+1);
        cout<<a[n]-a[1]<<"\n";
    }
}
