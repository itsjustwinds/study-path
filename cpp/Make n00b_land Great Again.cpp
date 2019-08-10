#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
using namespace std;
template<typename T> inline void read(T &x)
{
        char c;
        bool neg = false;
        while (!isdigit(c = getchar()) && c != '-');
        x = 0;
        if (c == '-')
        {
                neg = true;
                c = getchar();
        }
        do
        {
                x = x * 10 + c - '0';
        }
        while (isdigit(c = getchar()));
        if (neg) x = -x;
}
template<typename T> inline void write(T x)
{
        if (x < 0)
        {
                putchar('-');
                write(-x);
                return;
        }
        if (x < 10)
        {
                putchar(char(x + 48));
        }
        else
        {
                write(x/10);
                putchar(char(48 + x%10));
        }
}
template<typename T> inline void writeln(T x)
{
        write(x);
        putchar('\n');
}
ll need[maxn];
struct data{
	ll val,lazy;
};
data st[4*maxn];
int n,m,qX[maxn],qF[maxn],qD[maxn],Nchild[maxn],pos[maxn],chain[maxn],cnt,dem,head[maxn],trc[maxn],q,res[maxn];
vector<int > owners[maxn],e[maxn],check[maxn];
int l[maxn],r[maxn],tail[maxn];
void dfs(int u){
	Nchild[u]=1;
	for (int i=0;i<e[u].size();++i){
		int v=e[u][i];
		trc[v]=u;
		dfs(v);
		Nchild[u]+=Nchild[v];
	}
}
void hld(int u){
	if (head[cnt]==0) head[cnt]=u;
	pos[u]=++dem;
	chain[u]=cnt;
	int vtx=-1;
	for (int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if (vtx==-1||Nchild[v]>Nchild[vtx]) vtx=v;
	}
	if (vtx!=-1) hld(vtx);
	for (int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if (v==vtx) continue;
		++cnt;
		hld(v);
	}
	tail[u]=dem;
}
void reset(){
	for (int i=1;i<=4*n;++i){
		st[i].val=0;
		st[i].lazy=0;
	}
}
void update(int id,int l,int r,int i,int j,int x){
	if (st[id].lazy!=0){
		st[id].val+=1ll*st[id].lazy*(r-l+1);
		if (l!=r){
			st[id*2].lazy+=st[id].lazy;
			st[id*2+1].lazy+=st[id].lazy;
		}
		st[id].lazy=0;
	}
	if (l>r||l>j||r<i) return;
	if (l>=i&&r<=j){
		st[id].val+=1ll*x*(r-l+1);
		if (l!=r){
            st[id*2].lazy+=x;
            st[id*2+1].lazy+=x;
		}
		return;
	}
	int m=(l+r)>>1;
	update(id*2,l,m,i,j,x);
	update(id*2+1,m+1,r,i,j,x);
	st[id].val=st[id*2].val+st[id*2+1].val;
}
ll get(int id,int l,int r,int i,int j){
	if (st[id].lazy!=0){
		st[id].val+=1ll*st[id].lazy*(r-l+1);
		if (l!=r){
			st[id*2].lazy+=st[id].lazy;
			st[id*2+1].lazy+=st[id].lazy;
		}
		st[id].lazy=0;
	}
	if (l>r||l>j||r<i) return 0;
	if (l>=i&&r<=j){
		return st[id].val;
	}
	int m=(l+r)>>1;
	return get(id*2,l,m,i,j)+get(id*2+1,m+1,r,i,j);
}
ll getval(int u){
	int w=1;
	ll res=0;
	while(1){
		int cu=chain[u];
		int cw=chain[w];
		if (cu==cw){
			res+=get(1,1,n,pos[w],pos[u]);
			return res;
		}
		res+=get(1,1,n,pos[head[cu]],pos[u]);
		u=trc[head[cu]];
	}
}
void apply(int i){
	int u=qX[i];
	int F=qF[i];
	int D=qD[i];
	update(1,1,n,pos[u],pos[u],F);
	update(1,1,n,pos[u]+1,tail[u],D);
}
int main(){
	freopen("Make n00b_land Great Again.inp","r",stdin);
	//ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read(n);read(m);
	for (int i=2;i<=n;++i){
		int x;
		read(x);
		e[x].push_back(i);
	}
	for (int i=1;i<=n;++i){
		int x;
		read(x);
		owners[x].push_back(i);
	}
	for (int i=1;i<=m;++i) read(need[i]);
	dfs(1);
	cnt=1;
	hld(1);
	read(q);
	for (int i=1;i<=q;++i){
        read(qX[i]);read(qF[i]);read(qD[i]);
	}
	int change=1;
	for (int i=1;i<=m;++i) {
		res[i]=-1;
		l[i]=1,r[i]=q;
	}
	while(change){
		change=0;
		for (int i=1;i<=q;++i)
			check[i].clear();
		for (int i=1;i<=m;++i)
		if (l[i]<=r[i]) {
			change=1;
			check[(l[i]+r[i])>>1].push_back(i);
		}
		reset();
        int D=0;
		for (int i=1;i<=q;++i){
            if (D==m) break;
			apply(i);
			for (int j=0;j<check[i].size();++j){
				int id=check[i][j];
				++D;
				ll sum=0;
				for (int k=0;k<owners[id].size();++k){
					int x=owners[id][k];
					sum+=getval(x);
					if (sum>=need[id]) break;
				}
				if (sum>=need[id]){
					res[id]=i;
					r[id]=i-1;
				}
				else l[id]=i+1;
			}
		}
	}
	for (int i=1;i<=m;++i)
    if (res[i]!=-1)writeln(res[i]);
    else printf("rekt\n");
    return 0;
}
