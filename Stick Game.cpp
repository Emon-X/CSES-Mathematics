#include<bits/stdc++.h>
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
    ll n,k;
    cin >> n >> k;
    vector<char>s(n+1,'L');
    vector<ll>v(k);
    for(int i=0;i<k;i++){
        ll y;
        cin >> y;
        s[y]='W';
        v[i]=y;
    }
    for(int i=1;i<=n;i++){
        if(s[i]=='W') continue;
        bool ok = false;
        for(int j=0;j<k;j++){
            if(i-v[j]>=1 && s[i-v[j]]=='L'){
                ok=true;
                break;
            }
        }
        if(ok) s[i]='W';
        else s[i]='L';
    }
    for(int i=1;i<=n;i++) cout << s[i];cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}