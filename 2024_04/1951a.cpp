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
	string s;
	cin >> s;
	int single = 0;
	int duo = 0;
	int tri = 0;
	s.insert(0, "0");
	s.insert(n+1, "0");
	for (int i = 1; i < n + 1; ++i) {
		if (s[i] == '1') {
			if (s[i-1] == '0' && s[i+1] == '0') {
				single++;
			} else if (s[i + 1] == '1') {
				int x = 1;
				while (s[i+1] == '1') {
					++i;
					++x;
				}
				if (x % 2 == 0) {
					duo += (x / 2);
				} else if (x % 2 == 1) {
					++tri;
				}
			}
		}
	}
	// cout << s << endl;
	bool ans = false;
	// cout << single << " " << duo << " " << tri << endl;
	if ((tri + single) % 2 == 1) {
		ans = false;
	} else if (duo == 1) {
		if (tri >= 1) {
			if (single >= 1) {
				ans = true;
			} else {
				ans = false;
			}
		} else {
			if (single >= 2) {
				ans = true;
			} else {
				ans =false;
			}
		}
	} else if (duo == 0) {
		if (tri >= 1) {
			ans = true;
		} else {
			ans = true;
		}
	} else {
		ans = true;
	}
	if (ans) {
		cout << "YES" << endl;
	} else {
		cout << "NO" <<endl;
	}
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