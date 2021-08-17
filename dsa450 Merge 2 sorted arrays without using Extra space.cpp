//@ikung
#include <bits/stdc++.h>
using namespace std;
// #define int long long
// const int inf = 1e18;
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

const int N = 200005;

int n;

void heapify(int b[], int m, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;
    if (l < m && b[l] < b[smallest])
        smallest = l;
    if (r < m && b[r] < b[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(b[i], b[smallest]);
        heapify(b, m, smallest);
    }
}
void mergeMethod1(int a[], int b[], int n, int m)
{

    for (int i = m - 1; i >= 0; i--)
    {
        heapify(b, m, i);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[0])
        {
            swap(a[i], b[0]);
            heapify(b, m, 0);
        }
    }
    sort(b, b + m);
}

void mergeMethod2(int a[], int b[], int n, int m)
{
    auto nextGap = [&](int gap)
    {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    };
    int gap = n + m, i = 0, j = 0;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (i = 0; i + gap < n; i++)
        {
            if (a[i + gap] < a[i])
                swap(a[i], a[i + gap]);
        }
        j = gap > n ? gap - n : 0;
        for (; i < n && j < m; i++, j++)
        {
            if (b[j] < a[i])
                swap(b[j], a[i]);
        }
        for (j = 0; j + gap < m; j++)
        {
            if (b[j + gap] < b[j])
                swap(b[j], b[j + gap]);
        }
    }
}
void mergeMethod3(int a[], int b[], int n, int m)
{
    int i, j, k, mx = 0;
    for (i = 0; i < n; i++)
    {
        mx = max(mx, a[i]);
    }
    for (i = 0; i < m; i++)
    {
        mx = max(mx, b[i]);
    }
    mx++;
    i = 0, j = 0, k = 0;
    while (i < n && j < m && k < (n + m))
    {
        int originala = a[i] % mx;
        int originalb = b[j] % mx;
        if (originala <= originalb)
        {
            if (k < n)
            {
                a[k] += originala * mx;
            }
            else
            {
                b[k - n] += originala * mx;
            }
            i++;
            k++;
        }
        else
        {
            if (k < n)
            {
                a[k] += originalb * mx;
            }
            else
            {
                b[k - n] += originalb * mx;
            }
            j++;
            k++;
        }
    }
    while (i < n)
    {
        int originala = a[i] % mx;

        if (k < n)
        {
            a[k] += originala * mx;
        }
        else
        {
            b[k - n] += originala * mx;
        }
        i++;
        k++;
    }
    while (j < m)
    {
        int originalb = b[j] % mx;

        if (k < n)
        {
            a[k] += originalb * mx;
        }
        else
        {
            b[k - n] += originalb * mx;
        }
        j++;
        k++;
    }
    for (i = 0; i < n; i++)
        a[i] /= mx;
    for (j = 0; j < m; j++)
        b[j] /= mx;
}
void solve()
{
    int i, j, k, m;
    cin >> n >> m;
    int a[n], b[m];
    f(i, n) cin >> a[i];
    f(i, m) cin >> b[i];

    mergeMethod3(a, b, n, m);

    f(i, n) cout << a[i] << " ";
    f(i, m) cout << b[i] << " ";

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