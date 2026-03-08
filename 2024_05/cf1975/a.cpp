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
	int n ;
	cin >> n;
	vector<int> a(n);
	for (auto & ai : a) cin >> ai;
	int x = 0;	
	int break_pt = -1;
	for (int i = 0; i < n-1; ++i) {
		if (a[i] > a[i+1])
			x += 1;
	}
	// cout << x << endl;
	if (x >= 2) {
		cout << "no" << endl;
	} else if (x == 1 && a.back() > a.front()) {
		cout << "no" << endl;
	} else {
		cout << "yes" << endl;
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