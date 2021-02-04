//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
const int N=505;

int n;
vector<vector<int>> g(N, vector<int>(N, inf)),dist(N,vector<int>(N,0));

void solve()
{
    int i, j, k;
    int m, q, a, b, c;
    cin >> n >> m >> q;
    f(i, m) cin >> a >> b >> c, g[a][b] = g[b][a] = min(c,g[a][b]), g[a][a] = 0, g[b][b] = 0;
    dist = g;

    
    for (k = 1; k <= n; k++)
    {
        for (j = 1; j <= n; j++)
        {
            for (i = 1; i <= n; i++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--)
    {
        cin >> i >> j;
        int ans = (dist[i][j] == inf) ? -1 : dist[i][j];
        cout << ans << endl;
    }

        return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}