#include<bits/stdc++.h>
#define maxn 55
#define mod 1000000
using namespace std;
int n,L,NextA[maxn][maxn],NextB[maxn][maxn],f[maxn][maxn][maxn];
char s[10][maxn],t[10][maxn];
int A[maxn],B[maxn];
void createNextA(){
	for (int len=0;len<L;++len)
		for (int x=0;x<32;++x){
			if (x==A[len+1]){
				NextA[len][x]=len+1;
				continue;
			}
			for (int Newlen=len-1;Newlen>=1;--Newlen){
				int ok=1;
				for (int i=Newlen;i>=1;--i)
				if (A[i]!=A[len-(Newlen-i+1)+1]) ok=0;
				if (ok){
					NextA[len][x]=Newlen;
					break;
				}
			}
		}
}
void createNextB(){
	for (int len=0;len<L;++len)
		for (int x=0;x<32;++x){
			if (x==B[len+1]){
				NextB[len][x]=len+1;
				continue;
			}
			for (int Newlen=len-1;Newlen>=1;--Newlen){
				int ok=1;
				for (int i=Newlen;i>=1;--i)
				if (B[i]!=B[len-(Newlen-i+1)+1]) ok=0;
				if (ok){
					NextB[len][x]=Newlen;
					break;
				}
			}
		}
}
int main(){
	freopen("SP15_A.inp","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>L;
	if(N==0||L==0){
		cout<<0;
		return 0;
	}
	for (int i=1;i<=5;++i)
		for (int j=1;j<=L;++j)
			cin>>s[i][j];
	for (int i=1;i<=5;++i)
		for (int j=1;j<=L;++j)
			cin>>t[i][j];
	for (int j=1;j<=L;++j){
		int mask=0;
		for (int i=1;i<=5;++i)
		if (s[i][j]=='#') mask^=1<<(i-1);
		A[j]=mask;
	}
	for (int j=1;j<=L;++j){
		int mask=0;
		for (int i=1;i<=5;++i)
		if(t[i][j]=='#') mask^=1<<(i-1);
		B[j]=mask;
	}
	createNextA();
	createNextB();
	f[0][0][0]=1;
	for (int i=0;i<=n;++i)
		for (int len1=0;len1<len;++len1)
			for (int len2=0;len2<len;++len2){
				if (f[i][len1][len2]==0) continue;
				for (int x=0;x<32;++x){
					int Newlen1=NextA[len1][x];
					int Newlen2=NextB[len2][x];
					f[i+1][Newlen1][Newlen2]=(f[i+1][Newlen1][Newlen2]+f[i][len1][len2])%mod;
				}
			}
	
}