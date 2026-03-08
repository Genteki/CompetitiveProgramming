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


	int c = -1;
	int ans = 0;
	int t_intvl = 0;
	int f_intvl = 0;

	if (n == 4 && x == 2) {
		if (y >= 1) {
			cout << 2 << endl;
		}  else if (b - a == 2) {
			cout << 2 << endl;
		} else {
			cout << 0 << endl;
		}
		return;
	} 
	

	if (b - a == 2) ans++; 
	else if (b - a == 3) t_intvl++;
	else if (b - a == 4) f_intvl++;
	while (it != s.end()) {
		c = *it;
		if (c - b == 2) {
			ans += 1;
		}
		ans += 1;
		if (c - b == 3) t_intvl++;
		else if (c - b == 4) f_intvl++;
		b = c;
		++it;
		cout << ans << endl;
	}
	--it;
	if (a + n - *it == 2) ans++;
	else if ( a + n - *it == 3) t_intvl++;
	else if (a + n - *it == 4) f_intvl++;

	if (y > f_intvl) {
		ans = ans + f_intvl * 3 + min(t_intvl, x- f_intvl) * 2;
	} else {
		ans = ans + y * 3;
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