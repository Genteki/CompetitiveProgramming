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
	int n, ans;
	cin >> n;
	ans = n;
	vector<int> a(n);
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) a[i] = s[i]=='1';
	vector<int> b(n+1), c(n+1), d(n+1);
	b[0] = 0; c[n] = 0;
	for (int i = 0; i < n; ++i) {
		b[i + 1] = b[i] + (1 - a[i]);
		c[n - 1 - i] = c[n - i] + a[n - 1 - i]; 
	}
	for (int i = 0; i < n + 1; ++i) {
		// cout << (b[i] >= (i+1)/2) << (c[i] >= (n-i+1)/2) << " ";
		c[i] = (b[i] >= (i+1)/2) && (c[i] >= (n-i+1)/2);
	}
	if (n % 2 == 0) {
		int mid = n / 2;
		for (int i = 0; i <= mid; ++i) {
			int l = mid - i;
			int r = mid + i;
			if (c[l]) {
				ans = l; break;
			} else if (c[r]) {
				ans = r; break;
			}
		}
	} else {
		float mid = n / 2.0;
		for (int i = 0; i <= mid; ++i) {
			int l = int(mid - i - 0.5);
			int r = int(mid + i + 0.5);
			if (c[l]) {
				ans = l;
				break;
			} else if (c[r]) {
				ans = r;
				break;
			}
		}
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