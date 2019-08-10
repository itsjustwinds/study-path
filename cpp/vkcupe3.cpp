#include <bits/stdc++.h>

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) ((int)(x).size())

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int inf = 1e9 + 5;
const int mod = 1e9 + 7;
const ll INF = 4e18 + 5;

char s[200200];
int n, m;
ll pw[200200], pref[200200], suff[200200];

int main() {
    freopen("vkcupe.inp","r",stdin);
	scanf("%s %d", s + 1, &m);
	n = strlen(s + 1);

	pw[0] = 1;
	for(int i = 1; i <= n; ++i) {
		pw[i] = pw[i-1] * 10 % m;
	}
	for(int i = n; i >= 1; --i) {
		int dig = s[i] - '0';
		suff[i] = ((dig * pw[n - i] % m) + suff[i+1]) % m;
	}
	ll ans = inf;
	for(int i = 1; i <= n; ++i) {
		int dig = s[i] - '0';
		if(dig != 0)
			ans = min(ans, ((suff[i] * pw[i-1]) % m + pref[i-1]) % m);
		pref[i] = (pref[i-1] * 10 + dig) % m;
	}
	cout << ans;

	return 0;
}
