#include<iostream>
#include<vector>
//using namespace std;
#define left(i) (2*i)
#define right(i) (2*i+1)
#define parent(i) ((i)/2)
template<class T>
class SegmentTree
{
private:
	T* tree;
	void buildTree(std::vector<T> data);
	int segTreeSize;
	T valueForExtraNodes;
	T (*combine)(T obj1, T obj2);

public:
	SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
	T query(int l, int r);
	void update(int idx, T val);
};

template<class T> SegmentTree<T>::SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2))
{
	segTreeSize = 2 * data.size();
	this->combine = combine;
	valueForExtraNodes = value;
	buildTree(data);

}

template<class T> void SegmentTree<T>::buildTree(std::vector<T> data)
{
	int n = data.size();
	tree = new T[segTreeSize];
	//std::cout << segTreeSize << "\n";
	for (int i = segTreeSize - 1; i > 0; i--)
	{
		if (i >= n)
		{
			tree[i] = data[i - n];
			//std::cout << data[i - n] << "\n";
		}
		else
		{
			tree[i] = combine(tree[left(i)], tree[right(i)]);
		}
	}
	//for (int i = 0; i < segTreeSize; i++)
	//	std::cout << tree[i] << "\n";
}

template<class T> T SegmentTree<T>::query(int l, int r)
{
	int n = segTreeSize / 2;
	l += n;
	r += n;
	int ans = valueForExtraNodes;
	while (l < r)
	{
		if (l & 1)
		{
			ans = combine(ans, tree[l]);
			l++;
		}
		if (r & 1)
		{
			r--;
			ans = combine(ans, tree[r]);
		}
		l /= 2;
		r /= 2;
	}
	return ans;
}
template<class T> void SegmentTree<T>::update(int idx, T val)
{
	int n = segTreeSize / 2;
	idx = idx + n;
	tree[idx] = val;
	while (idx > 0)
	{
		idx >>= 1;
		tree[idx] = combine(tree[left(idx)], tree[right(idx)]);
	}

}
int maxi(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	std::vector<int> a = {2, 6, 10, 4, 7, 28, 9, 11, 6, 33};
	int n = a.size();
	SegmentTree<int> seg(a, 0, maxi);
	std::cout << seg.query(1, 2) << "\n";
	seg.update(3, 100);
	std::cout << seg.query(1, 3) << "\n";

}