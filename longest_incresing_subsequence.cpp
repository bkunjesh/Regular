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

int n;

void solve()
{
    int i, j, k;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    f(i, n)
    {
        if (s[i] == '0')
            a[i] = 0;
        else
            a[i] = 1;
        // (a[i]==0)?zcnt++:ocnt++;
    }
    vector<int> d;
    for (int i = 0; i < n; i++)
    {

        vector<int>::iterator it = upper_bound(d.begin(), d.end(), a[i]);
        if (it == d.end())
            d.push_back(a[i]);
        else
            *it = a[i];
    }
    
    cout << n - d.size() << endl;
    
    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}