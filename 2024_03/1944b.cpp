// #include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <vector>
#include <regex>

using namespace std;

typedef long long i64;

const int inf = 0x3f3f3f3f;
// memset(a, 0x3f, sizeof(a))

void solve() {
	int n, k;

	cin >> n >> k;
	vector<int> a(n), b(n);
	for (auto &ai : a) cin >> ai; sort(a.begin(), a.end());
	for (auto &bi : b) cin >> bi; sort(b.begin(), b.end());
	if (n == k) {
		for (auto li : a) cout << li << " "; cout << endl;
		for (auto ri : b) cout << ri << " "; cout << endl;
	    return;
	}

	vector<int> l(2*k), r(2*k);
	unordered_set<int> ls, rs, lrs;
	vector<int> ll, rr, lr;
	int i = 0; int j = 0;
	while(i < n && j < n) {
		if (a[i] == b[j]) {
			lr.push_back(a[i]);
			++i; ++j;
		} else {
			while (i < n-1 && a[i] == a[i+1]) {
				ll.push_back(a[i]);
				i += 2;
			}
			while (j < n - 1 && b[j] == b[j+1]) {
				rr.push_back(b[j]);
				j += 2;
			}
		}
	}

	while (i < n) {
		ll.push_back(a[i]);
		i += 2;
	}
	while (j < n) {
		rr.push_back(b[j]);
		j += 2;
	}

	// for (auto li : ll) cout << li << " "; cout << endl;
	// for (auto ri : rr) cout << ri << " "; cout << endl;
	// for (auto lri : lr) cout << lri << " "; cout << endl;
	int x = 0;
	for (int i = 0; i < ll.size(); ++i) {
		if (x < 2 * k){
			l[x] = ll[i];
			l[x+1] = ll[i];
			r[x] = rr[i];
			r[x+1] = rr[i];
			x += 2;
		} else {
			break;
		}
	}
	for (int i = 0; i < lr.size(); ++i) {
		if (x < 2 * k) {
			l[x] = lr[i]; r[x] = lr[i];
			x++;
		} else {
			break;
		}
	}
	// cout << "l size" << l.size() << endl;
	// cout << "l size" << r.size() << endl;
	for (auto li : l) cout << li << " "; cout << endl;
	for (auto ri : r) cout << ri << " "; cout << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int test_cases;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();

    }
}