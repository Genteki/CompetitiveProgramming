#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

class SegmentTree {
   public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 0, 0, n - 1);
    }

    int query(int l, int r) { return query(0, 0, n - 1, l, r); }

   private:
    int n;
    vector<int> tree;

    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;  // XOR with 0 has no effect
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_query = query(2 * node + 1, start, mid, l, r);
        int right_query = query(2 * node + 2, mid + 1, end, l, r);
        return left_query ^ right_query;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    // Segment tree to compute XOR in any subarray
    SegmentTree st(a);

    vector<int> xor_values;

    // Collect XOR values for subarrays of length >= 2
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            xor_values.push_back(st.query(i, j));
        }
    }

    // Sort the XOR values
    sort(xor_values.begin(), xor_values.end());

    // Output the k-th smallest XOR value
    cout << xor_values[k - 1] << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}