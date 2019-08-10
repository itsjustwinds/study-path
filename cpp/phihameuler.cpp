#include<bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 11;
int n;
int sieve[MN];         // Sàng số nguyên tố. Sau khi sàng:
// - sieve[i] = 0 nếu i là số nguyên tố
// - ngược lại sieve[i] = một ước bất kỳ của i.
pair<int,int> pk[MN];  // Nếu i có dạng p^k, pk[i] = {p, k}.
// Ngược lại, pk[i] = {-1, 0}
int ndiv[MN];          // ndiv[i] = Số ước của i.

int main()
{
    // Sàng số nguyên tố
    freopen("euler.inp","r",stdin);
    freopen("euler.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 2; i <= 1000; i++)  // số không nguyên tố có 1 ước <= 10^3.
        if (!sieve[i])
        {
            for (int j = i*i; j <= 1000000; j += i)
                sieve[j] = i;
        }

    ndiv[1] = 1;

    for (int i = 2; i <= 1000000; i++)
    {
        if (!sieve[i])
        {
            // i là số nguyên tố.
            pk[i] = make_pair(i, 1);
            ndiv[i] = 2;
        }
        else
        {
            int p = sieve[i];  // p là ước bất kỳ của i.

            if (pk[i/p].first == p)    // i = p^k
            {
                pk[i] = make_pair(p, pk[i/p].second + 1);
                ndiv[i] = pk[i].second + 1;  // ndiv[p^k] = k+1.
            }
            else
            {
                pk[i] = make_pair(-1, 0);
                // Phân tích i = u*v, với gcd(u, v) = 1.
                int u = i, v = 1;
                while (u % p == 0)
                {
                    u /= p;
                    v = v * p;
                }
                ndiv[i] = ndiv[u] * ndiv[v];
            }
        }
    }
    for (int i=1; i<=n; i++)
        cout<<i<<" "<<ndiv[i]<<"\n";
    return 0;
}
