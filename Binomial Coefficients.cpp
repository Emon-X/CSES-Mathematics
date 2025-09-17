#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pp pop_back()
#define mod 1000000007
#define ha cout << "YES\n"
#define na cout << "NO\n"
#define endl "\n"
#define N 2000005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
// Template for ordered set
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<ll> ft(N), inv_ft(N);

ll bin(ll base, ll p)
{
    ll res = 1;
    while (p > 0)
    {
        if (p % 2)
            res = (res * base) % mod;
        base = (base * base) % mod;
        p /= 2;
    }
    return res;
}

void pre()
{
    ft[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        ft[i] = (ft[i - 1] * i) % mod;
    }
    inv_ft[N - 1] = bin(ft[N - 1], mod - 2); // Inverse of ft[N-1] using Fermat's Little Theorem
    for (int i = N - 2; i >= 0; --i)
    {
        inv_ft[i] = inv_ft[i + 1] * (i + 1) % mod;
    }
}
ll binomial(ll n, ll k)
{
    if (k > n || k < 0)
        return 0;
    return ft[n] * inv_ft[k] % mod * inv_ft[n - k] % mod;
}

void domain_expansion()
{
    ll n,k;
    cin >> n >> k;

    cout << binomial(n,k) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        domain_expansion();
    }
    return 0;
}