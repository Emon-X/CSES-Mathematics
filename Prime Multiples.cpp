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

void domain_expension()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> primes(k);
    for (int i = 0; i < k; i++)
        cin >> primes[i];

    ll ans = n;

    for (int mask = 0; mask < (1LL << k); mask++)
    {
        vector<ll> p;
        for (int i = 0; i < k; i++)
        {
            if (mask & (1LL << i))
            {
                p.push_back(primes[i]);
            }
        }
        ll product = 1;
        for (int i = 0; i < p.size(); i++)
        {
            if (product > (n / p[i]))
            {
                product = n + 1;
                break;
            }
            product *= p[i];
        }
        if (p.size() % 2==0)
            ans -= (n / product);
        else
            ans += (n / product);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}