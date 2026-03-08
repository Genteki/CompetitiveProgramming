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
	k--;
	vector<int> a(n);
	for (auto & ai : a) {
		cin >> ai;
	}
	int c = a[k];
	int fir = -1, sec = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] > a[k]) {
			if (fir == -1) {
				fir = i;
			} else if (sec == -1) {
				sec = i;
				break;
			}
		}
	}
	int ans;

	if (fir == -1) {
		ans = n - 1;
	} else if (k == 0) {
 		ans = fir - 1;
	} else if (fir == 0) {
		if (sec == -1 || sec > k) ans = k - 1;
		else ans = sec - 1;
	} else {
		int a1 = fir - 1;
		int a2;
		if (sec != -1 && sec < k) {
			int st = min(k, fir);
			int ed = k;
			a2 = abs(ed - st);
		}
		else a2 = abs(fir - k);

		ans = max(a1, a2);
	}
	cout << ans << endl;
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