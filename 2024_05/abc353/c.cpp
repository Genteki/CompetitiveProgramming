// c.cpp

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
	vector<i64> a(n);
	i64 ans = 0;
	i64 div = 1e8;
	for (auto &ai : a) cin >> ai;
	for (int i = 0; i < n; ++i) {
		ans += (a[i] * (n - 1));
	}
	sort(a.begin(), a.end());
	int i = 0, j = n - 1;
	i64 p = 0;
	for(; i <n; ++i) {
		while (j >= 0 && a[i] + a[j] >= div) {
			--j;
		}
		p += (n - 1 - max(j, i));
	}
	ans -= (p*div);
	// cout << p << endl;/
	cout << ans << endl;

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}