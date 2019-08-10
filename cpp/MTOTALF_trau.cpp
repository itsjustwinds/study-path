#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MX 52
#define INF 100000000

int n;
bool vis[MX];
int cap[MX][MX];


/*int aug(int u,int T,int minCap)
{
	if(u==T)
		return minCap;
	if(vis[u])
		return 0;
	vis[u] = true;
	for(int v = 0;v<=MX;v++)
		if(cap[u][v]>0)
		{
			int f = aug(v,T,min(minCap,cap[u][v]));
			if(f>0)
			{
				cap[u][v]-=f;
				cap[v][u]+=f;
				return f;
			}
		}
	return 0;
}*/


int aug(int source,int sink)
{
	int where,path_cap,next,prev,chk;
	queue<int> Q;
	Q.push(source);
	vis[source]=true;
	int from[MX]={-1};
	chk=0;
	while(!Q.empty())
	{
		where = Q.front();
		Q.pop();
		for(next=0;next<MX;next++)
		{
			if(!vis[next] && cap[where][next]>0)
			{
				Q.push(next);
				vis[next]=true;
				from[next] = where;
				if(next==sink)
				{
					chk=1;
					break;
				}
			}
		}
		if(chk)
			break;
	}
	where = sink;
	path_cap = INF;
	while(from[where] > -1)
	{
		prev = from[where];
		path_cap = min(path_cap, cap[prev][where]);
		where = prev;
	}
	if(where==source)
	{
		where = sink;
		while(from[where] > -1)
		{
			prev = from[where];
			cap[prev][where] -= path_cap;
			cap[where][prev] += path_cap;
			where = prev;
		}
	}
	if(path_cap==INF)
		return 0;
	else
		return path_cap;
}



int maxFlow(int S,int T)
{
	int flow = 0;
	memset(vis,false,sizeof vis);
	while(1)
	{
		int f = aug(S,T);
		if(f==0) break;
		flow+=f;
		memset(vis,false,sizeof vis);
	}
	return flow;
}



int main()
{
    freopen("D:\\C++\\TST\\MTOTALF.inp","r",stdin);
    //freopen("D:\\C++\\TST\\MTOTALF.ans","w",stdout);
	char a,b;
	int c;
	scanf("%d",&n);
	memset(cap,0,sizeof cap);
	for(int i=0;i<n;i++)
	{
		scanf("%*c%c%*c%c%i",&a,&b,&c);
		if(a >= 'a' && a <= 'z')
			a += 'Z' + 1 - 'a';
		if(b >= 'a' && b <= 'z')
			b += 'Z' + 1 - 'a';
		cap[a - 'A'][b - 'A'] += c;
		cap[b - 'A'][a - 'A'] += c;
	}
	printf("%d\n",maxFlow(0,25));
	return 0;
}
