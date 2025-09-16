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

ll sumAp(ll L, ll R)
{
    ll c = (R - L + 1) % mod;
    ll s = (((L + R) % mod) * (c % mod)) % mod;

    ll inv2 = (mod + 1) / 2;

    return (s * inv2) % mod;
}

void domain_expension()
{
    ll n;
    cin >> n;
    ll sq = sqrtl(n);
    // ans = summation of (n/i)*i for i = 1 to n;
    ll sum = 0;
    // for small i
    for (int i = 1; i <= sq; i++)
    {
        ll cnt = n / i;
        sum = (sum % mod + ((cnt % mod) * (i % mod)) % mod) % mod;
    }
    // for large i

    for (int v = 1; v <= sq; v++)
    {
        ll L = (n / (v + 1)) + 1;
        ll R = n / v;

        if (L <= sq)
            L = L + 1;
        if (L <= R)
        {
            ll cnt = sumAp(L, R);
            ll contribution = ((v%mod)*(cnt%mod))%mod;

            sum = (sum%mod + contribution %mod)%mod;
        }
    }
    cout << sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}