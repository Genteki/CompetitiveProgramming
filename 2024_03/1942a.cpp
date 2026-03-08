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
	if (n == k) {
		for (int i = 0; i < n; ++i) cout << "1 ";
	} else if (k == 1) {
		for (int i = 0; i < n - 1; ++i) {
			cout << "1 ";
		}
		cout << "2";
	} else {
		cout << "-1";
	}
	cout << "\n";
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
