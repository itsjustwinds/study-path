#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,a[maxn];
struct data{
	int val,lazy;
};
struct node{
	int id,val;
};
struct cmp{
	bool operator ()(node a,node b){
		return a.val<b.val;
	}
};
priority_queue<node,vector<node>,cmp > q;
int chain[maxn],root,pos[maxn],trc[maxn],New[maxn],head[maxn],cnt,Nchild[maxn],dem,high[maxn];
vector<int > e[maxn];
data st[4*maxn];
void dfs(int u){
	Nchild[u]++;
	for (int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if (v==trc[u]) continue;
		trc[v]=u;
		dfs(v);
		Nchild[u]+=Nchild[v];
	}
	if (Nchild[u]==1){
		q.push({u,a[u]});
	}
}
void hld(int u){
	if (head[cnt]==0) head[cnt]=u;
	++dem;
	New[dem]=u;pos[u]=dem;
	chain[u]=cnt;
	int vtx=-1;
	for (int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if (v==trc[u]) continue;
		if (vtx==-1||Nchild[v]>Nchild[vtx]) vtx=v;
	}
	if(vtx!=-1) hld(vtx);
	for (int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if (v==trc[u]||v==vtx) continue;
		++cnt;
		high[cnt]=high[chain[u]]+1;
		hld(v);
	}
}
void down(int id){
	int t=st[id].lazy;
	st[id].lazy=0;
	st[id*2].lazy+=t;
	st[id*2].val+=t;
	st[id*2+1].lazy+=t;
	st[id*2+1].val+=t;
}
void build(int id,int l,int r){
	if (l==r){
		st[id].val=a[New[l]];
		return;
	}
	int m=(l+r)>>1;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	st[id].val=min(st[id*2].val,st[id*2+1].val);
}
int get(int id,int l,int r,int i,int j){
	if (l>j||r<i) return 1e9;
	if (l>=i&&r<=j){
		return st[id].val;
	}
	down(id);
	int m=(l+r)>>1;
	return min(get(id*2,l,m,i,j),get(id*2+1,m+1,r,i,j));
}
void update(int id,int l,int r,int i,int j,int val){
	if (l>j||r<i) return;
	if (l>=i&&r<=j){
		st[id].val+=val;
		st[id].lazy+=val;
		return;
	}
	down(id);
	int m=(l+r)>>1;
	update(id*2,l,m,i,j,val);
	update(id*2+1,m+1,r,i,j,val);
	st[id].val=min(st[id*2].val,st[id*2+1].val);
}
int lca(int u,int v){
	while(chain[u]!=chain[v]){
		if (high[chain[u]]>high[chain[v]]) u=trc[head[chain[u]]];
		else v=trc[head[chain[v]]];
	}
	if (pos[u]>pos[v]) return v;
	else return u;
}
int getmin(int u,int w){
	int minn=1e9;
	while(1){
		int cu=chain[u],cw=chain[w];
		if (cu==cw){
			minn=min(minn,get(1,1,n,pos[w],pos[u]));
			return minn;
		}
		minn=min(minn,get(1,1,n,pos[head[cu]],pos[u]));
		u=trc[head[cu]];
	}
}
void updatemin(int u,int w,int val){
	while(1){
		int cu=chain[u],cw=chain[w];
		if (cu==cw){
			update(1,1,n,pos[w],pos[u],val);
			return;
		}
		update(1,1,n,pos[head[cu]],pos[u],val);
		u=trc[head[cu]];
	}
}
int main(){
	freopen("B.inp","r",stdin);
	cin.tie(0);
	cout.tie(0);
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if (n==2){
		if (a[1]!=a[2]) cout<<"NO";
		else cout<<"YES";
		return 0;
	}
	for (int i=2;i<=n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i=1;i<=n;++i)
	if (e[i].size()>1) {
		root=i;
		break;
	}
	cnt=1;
	dfs(root);
	hld(root);
	build(1,1,n);
	while(1){
		node u=q.top();
		q.pop();
		node v=q.top();
		q.pop();
		if (v.val==0) break;
		int w=lca(u.id,v.id);
		int minn=getmin(u.id,w);
		minn=getmin(v.id,w);
		if (minn<=0) break;
		updatemin(u.id,w,-minn);
		updatemin(v.id,w,-minn);
		updatemin(w,w,minn);
		u.val-=minn;
		v.val-=minn;
		q.push(u);
		q.push(v);
	}
	int ok=1;
	for (int i=1;i<=n;++i)
    if (get(1,1,n,i,i)>0) {
        ok=0;
        break;
    }
	if (ok) cout<<"YES";
	else cout<<"NO";
}
