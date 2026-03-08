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
	i64 n;
	cin >> n;
	i64 s=0;
	set<string> li;
	for (int i = 0; i < n; ++i) {
		int x; string name;
		cin >> name >> x;
		s+=x;

		li.insert(name);
	}
	int p = s % n;
	// cout << s << " " << n << endl;
	auto lii = li.begin();
	for (; p > 0; --p) {
		// cout << *lii << " ";
		++lii;
	}
	cout << *lii << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}