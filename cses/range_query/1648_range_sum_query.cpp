#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

template<class T>
struct FenwickTree {
    int _size;
    vector<T> bit;

    FenwickTree() : _size(0) {}
    explicit FenwickTree(int n) : _size(n) { bit.assign(n, 0);}
    explicit FenwickTree(const vector<T> &a) : _size(a.size()) {
        bit.assign(_size, 0);
        for (int i = 0; i < _size; ++i) {
            add(i, a[i]);
        }
    }
    void add(int idx, T delta) {
        assert(idx >= 0 && idx < _size);
        for (; idx < _size; idx = idx | (idx + 1)) {
            bit[idx] += delta;
        }
    }



    T sum(int l, int r) {
        assert(r >= 0 && r < _size);
        assert(l >= 0 && l < _size);

        return sum(r) - sum(l-1);
    }

private:
    T sum(int r) {
        T ret = 0;
        while (r >= 0) {
            ret += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }
};

void solve() {
    int n, q;
    cin >>n >> q;
    vector<i64> a(n);
    input(a);
    FenwickTree<i64> ft(a);
    while(q--) {
        int b;
        cin >> b;
        if (b == 2) {
            int l, r;
            cin >> l >> r;
            cerr << l << " " << r << endl;
            i64 ans = ft.sum(l-1, r-1);
            cout << ans<< endl;
        } else {
            i64 idx, val;
            cin >> idx >> val;
            --idx;
            i64 delta = val - a[idx];
            ft.add(idx, delta);
            a[idx] = val;
        }
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}