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
const int inf = 1e17;
const int ninf = -1e17;
const int N = 2509;

int n;
class triplet
{
public:
    int scr, dest, weight;
    triplet(int src, int dest, int weight)
    {
        this->scr = src;
        this->dest = dest;
        this->weight = weight;
    }
};

vector<triplet> edges;
vector<int> dist(N, inf);
void solve()
{
    int i, j, k, a, b, c;
    int m;
    cin >> n >> m;
    f(i, m)
    {
        cin >> a >> b >> c;
        edges.push_back(triplet(a, b, -c));
    }
    dist[1] = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (auto edge : edges)
        {
            int src = edge.scr;
            int dest = edge.dest;
            int wt = edge.weight;
            if (dist[src] == inf)
                continue;
            dist[dest] = min(dist[dest], dist[src] + wt);
            
        }
    }

    for (i = 0; i < n; i++)
    {
        for (auto edge : edges)
        {
            int src = edge.scr;
            int dest = edge.dest;
            int wt = edge.weight;

            if (dist[src] == inf)
                continue;

            if (dist[src] + wt < dist[dest])
                dist[dest] = ninf;
        }
    }

    if (dist[n] != ninf)
        cout << -dist[n] << endl;
    else
        cout << -1 << endl;

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