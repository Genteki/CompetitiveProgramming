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
	int n, x, y;
	cin >> n >> x >> y;
	set<int> s;
	int tmp;
	for (int i = 0; i < x; ++i) {
		cin >> tmp;
		s.insert(tmp);
	}
	auto it = s.begin();
	int a = *it;
	++it;
	int b = *it;
	++it;
	if(x == 2) {	
		if (n == 4 && b - a == 2){
			cout << 2 << endl;
		} else if(b - a == 2 || (a + n - b) == 2) {
				cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
		return;
	}
	int c = -1;
	int ans = 0;
	if (b - a == 2) ans++; 
	while (it != s.end()) {
		c = *it;
		if (c - b == 2) {
			ans += 1;
		}
		ans += 1;
		b = c;
		++it;
		// cout << ans << endl;
	}
	--it;
	if (a + n - *it == 2) ans++;	
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