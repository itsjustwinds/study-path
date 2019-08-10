#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
map<char,int> m;
int n;
char s[maxn];
int main(){
    //freopen("980A.inp","r",stdin);
    cin>>(s+1);
    n=strlen(s+1);
    m['a']=1;m['e']=1;m['i']=1;m['o']=1;m['u']=1;
    for (int i=1;i<=9;i+=2)
        m[char(i+'0')]=1;
    int res=0;
    for (int i=1;i<=n;++i)
        if (m[s[i]])++res;
    cout<<res;
}
