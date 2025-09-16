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
    ll n;
    cin >> n;
    vector<ll> s(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        mp[s[i]]++;
    }
    ll ans = 0;
    sort(all(s));

    for (int i = 0; i < n; i++)
    {
        mp[s[i]]--;
        ll bad = 0;
        for (int x = 2; x * x <= s[i]; x++)
        {
            for (int j = x; j <= 20; j += x)
            {
                bad += mp[j];
            }
            ll y = n/x;
            if(y==x) continue;
            for (int j = y; j <= 20; j += y)
            {
                bad += mp[j];
            }
        }
        ll x = n - i - 1;
        if (s[i] == 1)
        {
            ans += (n - i - 1);
            continue;
        }
        ans += (x - bad);
        // cout << (x-bad) << " ";
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