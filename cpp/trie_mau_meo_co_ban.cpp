//PN
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
struct Tnode{
    int stop,cnt,P;
    int child[10];
};
    int n,m;
    Tnode trie[1000100];
    int nt=0,root;

    char s[11];
    int dem[11];

    int lt[11];

    map<string,long long> d;
int addnode()
{
    ++nt;
    for(int i=0; i<=9; ++i) trie[nt].child[i]=0;
    trie[nt].P=trie[nt].stop=trie[nt].cnt=0;
    return nt;
}
void addword(int u)
{
    int sl=-1;
    int s[15];
    do{
        s[++sl]=u%10;
        u/=10;
    } while(u);
    while(sl<9) s[++sl]=0;

    int r=root;
    for(int i=9; i>=0; --i)
    {
        int k=s[i];
        if(trie[r].child[k]==0)
        {
            int l=addnode();
            trie[r].child[k]=l;
            trie[l].P=r;
        }
        r=trie[r].child[k];
    }
    trie[r].stop++;
    trie[r].cnt++;
    while(r!=root)
    {
        r=trie[r].P;
        trie[r].cnt++;
    }
}
long long calc(int pos, int r)
{
    if(pos==0) return trie[r].cnt;

    long long ans=0;
    if(s[pos]!='?') {
        int tong=0;
        for(int k=9; k>s[pos]-'0'; --k)
            tong+=trie[trie[r].child[k]].cnt;
        ans+=(long long)tong*lt[dem[pos]];

        if(trie[r].child[s[pos]-'0']) ans+=calc(pos-1,trie[r].child[s[pos]-'0']);
    } else {
        int tong=0;
        for(int k=9; k>=0; --k)
        {
            ans+=(long long)tong*lt[dem[pos-1]];
            if(trie[r].child[k])
                ans+=calc(pos-1,trie[r].child[k]);
            tong+=trie[trie[r].child[k]].cnt;
        }
    }
    return ans;
}
void lam()
{
    cin>>(s+1);
    int n=strlen(s+1);
    reverse(s+1,s+n+1);
    while(n<10) s[++n]='0';

    string ph="";
    for(int i=1; i<=n; ++i)
    {
        dem[i]=dem[i-1];
        if(s[i]=='?') dem[i]++;
        ph=ph+s[i];
    }
    if(d.find(ph)!=d.end()) {cout<<d[ph]<<"\n"; return;}
    long long ans=calc(10,root);
    d[ph]=ans;
    cout<<ans<<"\n";
}
int main()
{
    //freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    root=addnode();
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        int a; cin>>a;
        addword(a);
    }
    lt[0]=1;
    for(int i=1; i<=9; ++i) lt[i]=lt[i-1]*10;
    while(m--) lam();
}
