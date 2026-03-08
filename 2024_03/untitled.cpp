// 1944 A
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
	if (k >= (n - 1 )) {
		cout << 1 << endl;
	}
	else {
		while (k > 0) {
			k = k - (n - 1);
			if (k >= 0) {
				n --;
			}
		}
		cout << n << endl;
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