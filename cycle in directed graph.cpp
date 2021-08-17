#include <bits/stdc++.h>
using namespace std;
#define int long long //delete if causing problems
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
const int inf = 1e18;
int power(int a, int b);
vector<int> arr[200001];
map<pair<int, int>, int> index;
int color[200001], parent[200001];
string ans(200001, '0');

int solve(int cycle_start, int cycle_end)
{
    // dbg(cycle_start);
    // dbg(cycle_end);

    int len = 1;
    while (cycle_start != cycle_end)
    {
        len++;
        cycle_start = parent[cycle_start];
    }
    //  dbg(len);

    if (len % 2)
        return true;
    else
        return false;
}

bool check(int node)
{
    //dbg(node);

    color[node] = 1;

    for (auto x : arr[node])
    {
        if (color[x] == 0)
        {
            parent[x] = node;

            if (check(x))
                return true;
        }
        else if (x != parent[node] && color[x] == 1)
        {
            // dbg(node);
            // dbg(x);

            if (solve(node, x))
                return true;
        }
    }

    color[node] = 2;

    return false;
}

signed main()
{
    fast int t = 1;
    //cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            index[{u, v}] = i;
            index[{v, u}] = -i;

            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        if (check(1))
        {
            cout << "NO" << endl;
        }
        else
        {
        }
    }
    return 0;
}

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2)
            b--, res = res * a;
        else
            b = b / 2, a *= a;
    }
    return res;
}

/*
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
*/