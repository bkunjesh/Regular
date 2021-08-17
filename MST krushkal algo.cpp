#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define jaldi_chal                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define tr(c, i) for (auto i = (c).begin(); i != (c).end(); i++)
#define REP(i, k) for (ll i = 0; i < k; i++)
#define REW(i, a, b) for (ll i = a; i <= b; i++)
#define MOD 1000000007
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define inf 1e10
#define endl "\n"
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
ll power(ll a, ll b);
ll parent[100001];
vector<pair<ll, pair<ll, ll>>> arr;
ll find(ll a)
{
    if (parent[a] < 0)
        return a;

    return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
    parent[b] += parent[a];
    parent[a] = b;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    jaldi_chal
        ll t = 1,
           i;
    // cin >> t;
    while (t--)
    {
        memset(parent, -1, sizeof(parent));

        ll n, m, q;
        cin >> n >> m;

        REW(i, 1, m)
        {
            ll u, v, w;
            cin >> u >> v >> w;

            arr.push_back({w, {u, v}});
        }

        sort(all(arr));

        ll ans = 0;

        for (ll i = 0; i < arr.size(); i++)
        {

            ll cost = arr[i].F;

            ll u = arr[i].S.F;

            ll v = arr[i].S.S;

            if (find(u) != find(v))
            {
                Union(find(u), find(v));
                ans += cost;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

ll power(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b % 2)
            b--, res = res * a;
        else
            b = b / 2, a *= a;
    }
    return res;
}