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
	int n;
	string s;
	cin >> n;
	cin >> s;
	vector<int> fi, la;
	for (int i = n - 1; i >= 0; --i) {
		if (i == n - 1 && s[i] == '1') la.push_back(i);
		else if (s[i] == '1' && s[i + 1] == '0') la.push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		if (i == 0 && s[i] == '1') fi.push_back(i);
		else if (s[i] == '1' && s[i-1] == '0') fi.push_back(i);
	}
	int ans=0;
	for (int i = 0; i < la.size(); ++i) {
		ans += (la[i] + fi[i] + 1);
	}
	cout << ans << endl;
	// cout << la.size() << fi.size() << endl;
	for (int i = 0; i < la.size(); ++i) {
		cout << string(la[i] + 1, 'A');
		cout << string(fi[la.size()-1-i], 'B');
	}
	cout << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}