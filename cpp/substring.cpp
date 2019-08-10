#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int dd[maxn],n,cnt,k,res,pos[maxn];
char s[maxn];
typedef pair<int,int> II;
int main()
{
    //freopen("substring.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pos['z'-'a'+1]=1000000000;
    for (char i='a';i<='z';i++)
        pos[i-'a']=1000000000;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>s[i];
    int l=1;
    for (int r=1;r<=n;r++)
    {
        if (dd[s[r]-'a']==0)
        {
            cnt++;
            dd[s[r]-'a']=1;
        }
        pos[s[r]-'a']=r;
        if (cnt==k) res=max(res,r-l+1);
        if (cnt<=k)continue;
        int tmp=1000000000;
        int temp=0;
        for (char i='a';i<='z';i++) if (pos[i-'a']<tmp&&dd[i-'a']){
            temp=i-'a';
            tmp=pos[temp];
        }
        dd[temp]=0;
        l=tmp+1;
        cnt--;
    }
    cout<<res;
    return 0;
}
