#include <bits/stdc++.h>
#include <direct.h>
using namespace std;
#define N 100001
#define K 51

const long long MOD = 1e9 + 7;
long long f[N][K];

void init() {
    for (int i = 1;i<=50; i++) f[0][i] = 0;
    for (int i = 1; i<N; i++) {
        f[i][0] = f[i-1][0];
        long long pow = 1;
        for (int j = 1; j<K; j++) {
            pow = (pow * i) % MOD;
            f[i][j] = (f[i-1][j] + pow) % MOD;
        }
    }
}
int main()
{
    freopen("C11CAL.inp","r",stdin);
    //freopen("C11CAL.out","w",stdout);
    init();
    int n,k;
    for (int i = 0; i<K; i++) {
        char * ss;
        itoa(i,ss,10);
        //cout<<ss;
        char * s1 = "C:\\MyName\\Test";
        //strcat(s1,ss);
        //mkdir(s1);
    }
    while (cin>>n>>k) {
        cout<<f[n][k]<<endl;
    }
}

