// a.cpp
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
	int a,b,c,d,e,f; // 1, 5, 10, 50, 100, 500
	cin >> a >> b >> c >> d >> e >> f;
	int n;
	cin >> n;
	std::vector<int> x(n);
	for (int & xi : x) cin >> xi;

	for (int xi : x) {
		while(xi >= 500 && f > 0) {
			f--;
			xi -= 500;
		}
		while (xi >= 100 && e > 0) {
			xi -= 100;
			e--;
		}
		while (xi >= 50 && d > 0) {
			d--;
			xi -= 50;
		}
		while (xi >= 10 && c > 0) {
			c --;
			xi -= 10;
		}
		while (xi >= 5 && b > 0) {
			b--;
			xi -= 5;
		}
		while (xi >= 1 && a > 0) {
			a--;
			xi --;
		}
		if (xi != 0) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes" << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}