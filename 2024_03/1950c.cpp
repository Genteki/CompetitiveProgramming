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
	string t;
	cin >> t;
	int h1 = t[0] - '0';
	int h2 = t[1] - '0';
	int m1 = t[3] - '0';
	int m2 = t[4] - '0';
	bool ispm = ((h1 * 10 + h2) / 12 >= 1);
	if (ispm) {
		if (h1 == 1 && h2 == 2) {
			h1 = 1;
		}
		else if (h2 >= 2) {
			h2 = h2 - 2;
			h1 = h1 - 1;
		} else {
			h2 += 8; h1 -=2;
		}
	} else {
		if (h1 == 0 && h2 == 0) {
			h1 = 1;
			h2 = 2;
		}
	}
	cout << h1 << h2 << ":" << m1 << m2;
	if (ispm) cout << " PM\n";
	else cout << " AM\n";
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