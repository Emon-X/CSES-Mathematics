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

typedef vector<vector<ll>> matrix;

matrix mul(const matrix &res, const matrix &base, ll n)
{
    matrix ans(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = (ans[i][j] + res[i][k] * base[k][j]) % mod;
            }
        }
    }
    return ans;
}

matrix matrix_mul(matrix base, ll exp, ll n)
{
    matrix ans(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        ans[i][i] = 1;

    while (exp)
    {
        if (exp & 1)
            ans = mul(ans, base, n);
        base = mul(base, base, n);
        exp >>= 1;
    }
    return ans;
}

ll solve(ll n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (n <= 6)
    {
        ll ans = 0;
        for (int i = 1; i <= 6; i++)
        {
            if (n - i >= 0)
                ans += solve(n - i) % mod;
        }
        return ans;
    }
    ll sz = 6;
    matrix trans(sz, vector<ll>(sz, 0));
    for (int i = 0; i < sz; i++)
        trans[0][i] = 1;
    for (int i = 1; i < sz; i++)
        trans[i][i - 1] = 1;

    matrix res = matrix_mul(trans, n - 6, sz);
    vector<ll> base = {solve(6), solve(5), solve(4), solve(3), solve(2), solve(1)};
    ll ans = 0;

    for (int i = 0; i < sz; i++)
    {
        ans = (ans + res[0][i] * base[i]) % mod;
    }
    return ans;
}

void domain_expension()
{
    ll n;
    cin >> n;

    cout << solve(n) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}