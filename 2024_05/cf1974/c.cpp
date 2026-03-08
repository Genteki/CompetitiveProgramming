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
	int n ;
	cin >> n;
	vector<i64> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	i64 ans = 0;
	i64 h0 = 0;

	map<i64, i64> mp;
	for(int i = 0; i < n - 2; ++i) {
		ans += mp[(a[i]<<40)+ (a[i+1]<<20) + h0];
		ans += mp[(h0<<40)+ (a[i+1]<<20)+ a[i+2]];
		ans += mp[(a[i]<<40)+ (h0<<20) + a[i+2]];
		ans -= (mp[(a[i] << 40) + (a[i+1]<<20) + a[i+2]]*3);
		mp[(a[i]<<40)+ (a[i+1]<<20) + h0]++;
		mp[(h0<<40)+ (a[i+1]<<20)+ a[i+2]]++;
		mp[(a[i]<<40)+ (h0<<20) + a[i+2]]++;
		mp[(a[i] << 40) + (a[i+1]<<20) + a[i+2]]++;
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