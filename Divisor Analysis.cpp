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
#define N 200005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
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

void domain_expension()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    ll div_num = 1;
    for (int i = 0; i < n; i++) {
        ll x, k;
        cin >> x >> k;
        v[i] = {x, k};
        div_num = div_num * (k + 1) % mod;
    }
    ll sum = 1;
    for (auto [x, k] : v) {
        ll numer = (bin(x, k + 1) - 1 + mod) % mod;
        ll denom = bin(x - 1, mod - 2);
        sum = sum * numer % mod * denom % mod;
    }
    ll prod_exp = 1;
    for (auto [x, k] : v) {
        prod_exp = prod_exp * (k + 1) % (mod - 1);
    }
    ll product = 1;
    if (prod_exp % 2 == 0) {
        ll half_exp = prod_exp / 2;
        for (auto [x, k] : v) {
            ll exp = (k * half_exp) % (mod - 1);
            product = product * bin(x, exp) % mod;
        }
    } else {
       
        ll half_exp = prod_exp / 2;
        for (auto [x, k] : v) {
            ll exp = (k * half_exp) % (mod - 1);
            product = product * bin(x, exp) % mod;
        }
        ll sqrtn = 1;
        for (auto [x, k] : v) {
            if (k % 2 == 1) {
                sqrtn = sqrtn * bin(x, (k + 1) / 2) % mod;
            } else {
                sqrtn = sqrtn * bin(x, k / 2) % mod;
            }
        }
        product = product * sqrtn % mod;
    }
    cout << div_num << " " << sum << " " << product << endl;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}