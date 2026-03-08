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
	int a,b,c;
	cin >> a >> b >> c;
	if (a + 1 != c) {
		cout << -1 << endl;
		return;
	}
	int d = 0, e = a;
	while(e > 0) {
		e = e / 2;
		d++;
	}
	int r = pow(2, d) - 1 - a;
	int p = b + c;
	int q = p - r;
	int ans;
	if (q > 0) {
		 ans = ceil(log2(a + 1)) + (q+a) / (a+1);
	}else {
		 ans = ceil(log2(a+1));
	}
	cout << ans-1 << endl;

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