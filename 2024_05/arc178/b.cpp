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
const i64 module = 998244353;
// memset(a, 0x3f, sizeof(a))

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    // base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; // exp = exp / 2
        base = (base * base) % mod; // Change base to base^2
    }
    return result;
}


void solve() {
	int a,b,c;
	cin >> a >> b >> c;

	i64 ans;
	if (c - max(a, b) > 1 || c < max(a, b)) {
		 cout << 0 << endl;
		 return;
	}

	int x = min(a,b), y = max(a,b);
	a = x;
	b = y;
	
	i64 a_min = modExp(10, x-1, module);
	i64 a_max = modExp(10, x, module);
	i64 b_max = modExp(10, y, module);
	i64 b_min = modExp(10, y-1, module);
	if (c == b) {
		if (a < b) {
			i64 ami = (b_max - b_min - a_min) ;
			i64 ama = (b_max - b_min - (a_max - 1)) ;
			i64 ans1 = ami + ama;
			i64 ans2 = (a_max - a_min) % module; 

			ans = (ans1 * ans2 / 2) % module + module;

		} else if (a == b) {
			i64 ab_min = (b_max - b_min - b_min);
			i64 ab_max = 1;
			i64 d = (ab_min - ab_max) % module + 1;
			i64 w = (ab_min + ab_max) % module;
			ans = (d * w / 2) % module + module;
		}
	}
	else {
		if (b > a) {
			i64 ma = (a_max - a_min);
			i64 ans2 = (ma + 1);
			ans = (ma * ans2 / 2) % module + module;
		} else {
			i64 ma = (a_max - a_min);
			i64 from1 = a_min;
			i64 to1 = (a_max-a_min);
			i64 x1 = (from1 + to1) ;
			i64 x2 = (to1 - from1 + 1) ;
			i64 ans1 = (x1 * x2 / 2) % module;

			i64 ans2 = ma * (a_min-1) % module;
			// cout << from1 << " " << to1 << endl;

			ans = (ans1 + ans2) % module + module;
		}
	}
	cout << (ans % module) << endl;

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