//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = ((res % mod) * (a % mod)) % mod;
        }
        n >>= 1;
        a = ((a % mod) * (a % mod)) % mod;
    }
    return res;
}
int n;
void solve()
{
    int i, j, k;

    cin >> n;
    cout << (mod + power(27, n) - power(7, n)) % mod << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif