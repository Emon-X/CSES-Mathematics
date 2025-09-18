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
#define N 1000005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
// Template for ordered set
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<ll> ft(N), inv_ft(N);

ll dp[N];

ll disarrange(ll n)
{

    // Base cases
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if(dp[n]!=-1) return dp[n];

    // countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
    return dp[n] = ((n - 1 % mod) * (disarrange(n - 1) % mod + disarrange(n - 2) % mod) % mod) % mod;
}

void domain_expansion()
{
    ll n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << disarrange(n) << endl;
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