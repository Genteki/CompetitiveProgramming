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
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(21, 0));
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		for (int i = 0; i < 21; ++i) {
			if ((x & (1<<i)) == (1 << i)) {
				a[j][i] = 1;
			}
		}
	}


	int low = 0;
	int high = n;
	while(high - 1 > low) {
		int mid = (high + low + 1) / 2;
		vector<int> p(21, 0);
		for (int i = 0; i < mid; ++i) {
			for (int j = 0; j < 21; ++j) {
				p[j] += a[i][j];
			}
		}
		auto q = p;
		bool flag = true;
		for (int i = mid; i < n; ++i) {
			for (int j = 0; j < 21; ++j) {
				q[j] += (a[i][j] - a[i-mid][j]);
				if (bool(p[j]) != (bool)q[j]) {
					flag=false;
					break;
				}
			}
			// if (q != p) {
			// 	cout << " false:" << i << endl;
			// 	flag = false;
			// 	break;
			// }
		}

		if (flag == false) {
			low = mid;
		} else {
			high = mid;
		}
		// cout << " " << low << " " << high << endl;
	}
	cout << high << endl;
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