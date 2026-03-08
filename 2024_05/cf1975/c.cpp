// b.cpp
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
	vector<int> a(n);
	for (auto & ai : a) cin >> ai;
	
	if (n == 2) {
		cout << min(a[0], a[1]) << endl;
		return;
	} 
	int ans = -1;
	for (int i = 0; i < n - 2; ++i) {
		int x = max(a[i], a[i+2]);
		int y = max(a[i], a[i+1]);
		int z = max(a[i+1], a[i+2]);
		int p = min(x,min(y,z));
		ans =max(p, ans);
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