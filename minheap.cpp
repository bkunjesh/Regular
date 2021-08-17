//@ikung
#include <bits/stdc++.h>
using namespace std;

class minHeap
{
public:
    vector<pair<int, int>> vec;

    minHeap()
    {
        build_max_heap();
    }

    void build_max_heap()
    {
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            heapify(i, vec.size());
        }
    }

    void heapify(int ind, int n)
    {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int smaller = ind;
        if (left < n && vec[smaller].second > vec[left].second)
        {
            smaller = left;
        }
        if (right < n && vec[smaller].second > vec[right].second)
        {
            smaller = right;
        }
        if (smaller != ind)
        {
            swap(vec[smaller], vec[ind]);
            heapify(smaller, n);
        }
    }

    void insert(pair<int, int> p)
    {
        vec.push_back(p);

        int ind = vec.size() - 1;
        int parent = (ind - 1) / 2;
        while (parent >= 0 && vec[ind].second < vec[parent].second)
        {
            swap(vec[parent], vec[ind]);
            ind = parent;
            parent = (ind - 1) / 2;
        }
    }

    void print()
    {
        cout << "vec: ";
        for (auto x : vec)
            cout << "(" << x.first << "," << x.second << ") ";
        cout << endl;
    }

    pair<int, int> extractMin()
    {
        if (vec.size() == 0)
            return {-1, -1};
        pair<int, int> res = vec[0];
        swap(vec[0], vec[vec.size() - 1]);
        vec.erase(--vec.end());
        heapify(0, vec.size());
        cout << "Min ele: " << res.first << "," << res.second << endl;
        return res;
    }

    int getSize()
    {
        cout << "size of heap: " << vec.size() << endl;
        return vec.size();
    }
    void heapsort()
    {

        for (int i = vec.size() - 1; i >= 0; i--)
        {
            swap(vec[i], vec[0]);
            heapify(0, i);
        }
    }
};

void solve()
{
    minHeap h;
    h.insert(make_pair(5, 9));
    h.insert({10, 7});
    h.insert({1, 19});
    h.insert({0, 5});
    h.print();
    auto mn = h.extractMin();
    mn = h.extractMin();
    mn = h.extractMin();
    h.print();

    h.insert({101, 117});
    h.insert({11, 19});
    h.insert({340, 15});

    mn = h.extractMin();
    mn = h.extractMin();

    h.print();
    h.getSize();

    h.insert({101, 117});
    h.insert({11, 19});
    h.insert(make_pair(5, 9));
    h.insert({10, 7});
    h.insert({1, 19});
    h.insert({0, 5});
    h.insert({340, 15});

    h.getSize();
    h.heapsort();
    h.print();

    return;
}

signed main()
{
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
