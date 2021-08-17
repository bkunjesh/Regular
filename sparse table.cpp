//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;

int n;

const int N = 4e5 + 5; // size of aaray

template <class T>

class SparseTable
{
public:
    //call constructor
    SparseTable(vector<T> data, T (*combine)(T obj1, T obj2));

    SparseTable(T ar[], T n, T (*combine)(T obj1, T obj2));

    T query(int l, int r);

private:
    vector<vector<T>> sp;

    void build(vector<T> data);

    int maxN;

    T(*combine)
    (T obj1, T obj2);
};

template <class T>
SparseTable<T>::SparseTable(vector<T> data, T (*combine)(T obj1, T obj2))
{
    this->combine = combine;
    maxN = log2(data.size()) + 1;

    build(data);
}

template <class T>
SparseTable<T>::SparseTable(T ar[], T n, T (*combine)(T obj1, T obj2))
{
    this->combine = combine;
    maxN = log2(n) + 1;

    vector<T> data;

    for (int i = 0; i < n; i++)
        data.push_back(ar[i]);
    build(data);
}

template <class T>
void SparseTable<T>::build(vector<T> data)
{
    int n = data.size();
    sp.resize(n, vector<T>(maxN));

    for (int i = 0; i < n; i++)
        sp[i][0] = data[i];

    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            sp[i][j] = combine(sp[i][j - 1], sp[i + (1 << j - 1)][j - 1]);
        }
    }
}

template <class T>
T SparseTable<T>::query(int l, int r)
{
    int diff = (r - l + 1);

    diff = log2(diff);

    int x = (r - (1 << diff) + 1);

    return combine(sp[l][diff], sp[x][diff]);
}
int comp(int a, int b)
{
    return __gcd(a, b);
}


void solve()
{
    int i, j;

    cin >> n;
    int arr[2 * n];
    f(i, n) cin >> arr[i], arr[i + n] = arr[i];
    n = 2 * n;

    SparseTable<int> s(arr, n, comp);

    // cout << query(0, 1) << endl;
    auto check = [&](int x)
    {
        int tmp = s.query(0, x);
        for (int i = 1; i < n / 2; i++)
        {
            if (s.query(i, i + x) != tmp)
                return 0;
        }
        return 1;
    };
    int l = 0;
    int h = n / 2, ans = 0;
    // cout << check(4) << endl;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (check(mid))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif