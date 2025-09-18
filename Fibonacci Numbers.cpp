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
#define endl "\n"
#define N 1000005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
// Template for ordered set
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<ll> ft(N), inv_ft(N);

// Matrix Exponentitaion

ll fibonacci(ll n)
{
    if (n == 0)
        return 0;
    ll a = 0, b = 1;
    ll mask = 1LL << (63 - __builtin_clzll(n));
    for (; mask; mask >>= 1)
    {
        ll na = (a * ((2 * b % mod - a) + mod) % mod) % mod;
        ll nb = ((a * a) % mod + (b * b) % mod) % mod;

        if (n & mask)
        {
            a = nb;
            b = (na + nb) % mod;
        }
        else
        {
            a = na, b = nb;
        }
    }
    return a;
}

void domain_expansion()
{
    ll n;
    cin >> n;
    cout << fibonacci(n) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        domain_expansion();
    }
    return 0;
}